#include <iostream>
#include <libopencor>
#include <argparse/argparse.hpp>
#include "version.h" // Include the version header

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("csim2", APP_VERSION_STRING);
    program.add_description("CSim2 is a simulation tool for CellML models.");
    program.add_epilog("csim2 --all-versions ==> Show the version of CSim2 and dependencies");
    
    // Add arguments
    program.add_argument("model")
        .help("The input model (CellML, SED-ML, or OMEX Archive) to simulate");

    program.add_argument("--about")
        .help("Show information about CSim2 and dependencies")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("--output")
        .help("Path to the output file");

    try {
        program.parse_args(argc, argv);

        // Handle the --version flag
        if (program["--about"] == true) {
            std::cout << "CSim2 version: " << APP_VERSION_STRING << std::endl;
            std::cout << "- website: https://github.com/nickerso/csim2" << std::endl;
            std::cout << "- libOpenCOR version: " << libOpenCOR::versionString() << std::endl;
            std::cout << "  - website: https://github.com/opencor/libopencor" << std::endl;
            return 0;
        }

        // Handle the --output argument
        if (program.present("--output")) {
            std::string outputPath = program.get<std::string>("--output");
            std::cout << "Output file: " << outputPath << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    auto modelFile = program.get<std::string>("model");
    
    auto file = libOpenCOR::File::create(modelFile);
    if (file->hasIssues()) {
        std::cerr << "Error: model file has issues" << std::endl;
        return 1;
    } else {
        std::cout << "Model file created successfully" << std::endl;
    }

    auto sedml = libOpenCOR::SedDocument::create(file);
    if (sedml->hasIssues()) {
        std::cerr << "Error: SED-ML document has issues" << std::endl;
        return 1;
    } else {
        std::cout << "SED-ML document created successfully" << std::endl;
    }

    auto instance = sedml->instantiate();
    if (instance->hasIssues()) {
        std::cerr << "Error: SED-ML instance has issues" << std::endl;
        return 1;
    } else {
        std::cout << "SED-ML instance created successfully" << std::endl;
    }
    
    instance->run();
    if (instance->hasIssues()) {
        std::cerr << "Error: SED-ML instance run has issues" << std::endl;
        return 1;
    } else {
        std::cout << "SED-ML instance run successfully" << std::endl;
    }
    
    auto instanceTask = instance->tasks()[0];
    auto x = instanceTask->state(0);
    auto y = instanceTask->state(1);
    auto z = instanceTask->state(2);
    std::cout << "x, y, z" << std::endl;
    for (int i = 0; i < x.size(); ++i) {
        std::cout << x[i] << ", " << y[i] << ", " << z[i] << std::endl;
    }

    return 0;
}

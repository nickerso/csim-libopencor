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
    std::cout << "Model file: " << modelFile << std::endl;

    return 0;
}

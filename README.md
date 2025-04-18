# CSim2
The old [CSim](https://github.com/nickerso/csim) project for running simulations using CellML models is based on the 
[CellML API](https://github.com/cellmlapi/cellml-api), which is problematic to build on modern systems. This tool has previously
been wrapped with a [basic API](https://github.com/nickerso/csim/blob/devel/src/api/csimsbw.h) that has been used by the 
[SED-ML Web Tools](https://sysbioapps.spdns.org/SED-ML_Web_Tools) to enable simulation of CellML models.

[libOpenCOR](https://github.com/opencor/libopencor) is a SED-ML+CellML simulation library based on 
[libCellML](https://github.com/cellml/libcellml) that is much easier to build and install. This project attempts to develop
a library that provides that minimal CSim API required for integration into the SED-ML Web Tools. It may have other uses at
some point.

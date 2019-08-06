pathgrind [![Build Status](https://travis-ci.org/codelion/pathgrind.svg?branch=master)](https://travis-ci.org/codelion/pathgrind)
=========
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.9829.svg)](https://doi.org/10.5281/zenodo.9829)

Path based Dynamic Analysis
(Works for 32-bit programs only)

Requirements
------------
- bzip2
- autoconf
- make
- gcc
- python
- gawk
- 32 bit libraries for ubuntu (sudo apt-get install ia32-libs)
- 32 bit c library for building c programs for testing with pathgrind (sudo apt-get install libc6-dev-i386)

On ubuntu you can install the dependencies using apt-get, e.g. `sudo apt-get install autoconf`

Installation
------------
$ ./install.sh
#ifndef CARVER_H
#define CARVER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <stdio.h>

class Carver
{
public:
    Carver(std::string filename);

    void carve(std::string filetype);
    std::string findFiles();

private:
    std::string _filename;
    std::string _outputfilename;
    int numoffiles;
    size_t outputsize;
};

#endif // CARVER_H

#include <iostream>
#include <string>

#include "carver.h"

int main(int argc, char *argv[])
{
    std::string filename;
    if (argc != 2) {
        std::cout << "invalid parameters" << std::endl;
        std::cout << "usage: FinlaysCarver <file>" << std::endl;
        return 0;
    } else {
        filename = argv[1];
    }

    Carver c(filename);
    c.findFiles();

    return 0;
}

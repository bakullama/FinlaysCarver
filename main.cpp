#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "invalid parameters" << std::endl;
        std::cout << "usage: FinlaysCarver <file>" << std::endl;
    } else {
        std::string filename = argv[1];
    }

    return 0;
}

#include "carver.h"
#include <stdio.h>
#include <string.h>


Carver::Carver(std::string filename)
{
    _filename = filename;
    numoffiles = 1;
}

std::string Carver::findFiles() {
    std::string files = "";
    std::ifstream filebuf(_filename, std::ios::in|std::ios::binary);
    std::string _outputfilename = _filename + std::to_string(numoffiles);


    filebuf.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize length = filebuf.gcount();
    filebuf.clear();   //  Since ignore will have set eof.
    filebuf.seekg( 0, std::ios_base::beg );

    char buffer[length];
    char tempoutput[length];
    filebuf.read(buffer, length);
    bool collecting = 0;
    int offset = 0;


    for (unsigned i = 0; i < length; i++) {
//        std::cout << std::setfill('0') << std::setw(2) << std::hex << (0xff & (unsigned int)buffer[i]) << std::endl;
        if (buffer[i] == (char)0xFF & buffer[i+1] == (char)0xD8) {
            std::cout << "JPEG SOF" << std::endl;
            collecting = 1;
        }

        if (collecting) {
            tempoutput[offset] = buffer[i];
            offset++;
        }

        if (buffer[i] == (char)0xFF & buffer[i+1] == (char)0xD9) {
            std::cout << "JPEG EOF" << std::endl;
            _outputfilename += ".jpg";
            numoffiles++;
            collecting = 0;
            tempoutput[offset] = buffer[i+1];
            offset++;
        }
    }


    char finaloutput[offset];
    unsigned long long l = sizeof(finaloutput);
    memcpy(finaloutput, tempoutput, sizeof(finaloutput));

    std::ofstream outputbuf(_outputfilename, std::ios::out|std::ios::binary);


    outputbuf.write(finaloutput, sizeof(finaloutput));

    outputbuf.close();
    filebuf.close();

    return files;
}

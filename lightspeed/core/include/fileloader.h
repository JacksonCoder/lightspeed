// fileloader.h

#ifndef FILELOADER
#define FILELOADER
#include "file.h"
#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>

namespace FileLoader {
    File* load (std::string,bool);
};

#endif

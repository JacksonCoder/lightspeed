// file.h

#ifndef FILE_H
#define FILE_H
#include <string>
#include "../globals.h"

class File : public StatusClass {
    std::string filename;
    std::string contents;
public:
    File(std::string fname,bool); // bool is for StatusClass
    void append_contents(std::string);
    std::string getContents();
    std::string get_path() { return filename; }
};

#endif

// file.h

#ifndef FILE_H
#define FILE_H
#include <string>

class File {
    bool is_open = false;
    std::string filename;
    std::string contents;
    
public:
    File(std::string fname) {
        filename = fname;
    }
    bool open() {
        return is_open;
    }
    void set_open(bool v) {
        is_open = v;
    }
    void append_contents(std::string s) {
        contents += s;
    }
    std::string getContents() {
        return contents;
    }
};

#endif

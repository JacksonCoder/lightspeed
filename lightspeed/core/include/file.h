// file.h

#ifndef FILE_H
#define FILE_H
#include <string>

class File {
    bool is_open = false;
    std::string filename;
    std::string contents;
    
public:
    File(std::string fname);
    bool open();
    void set_open(bool);
    void append_contents(std::string);
    std::string getContents();
    std::string get_path() { return filename; }
};

#endif

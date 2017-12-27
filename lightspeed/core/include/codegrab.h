#ifndef CODE_GRAB_H
#define CODE_GRAB_H
// codegrab.h
#include <string>
#include <vector>
#include <regex>
#include "fileloader.h"

class Directory {
    std::vector<File*> files;
    public:
        void appendFile(File*);
        std::vector<File*> getFiles();
};


class getSource : public ModuleObject {
    std::string path;
    bool is_file;
    //HTTPFetcher httpgetter;
    FileLoader filegetter;
    Directory src;
    public:
        getSource(std::string);
        std::string get();
        Directory results();
};

#endif

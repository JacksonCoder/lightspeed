#ifndef CODE_GRAB_H
#define CODE_GRAB_H
// codegrab.h
#include <string>
#include <vector>
#include <regex>
#include "fileloader.h"
#include "../globals.h"
//#include "network.h"
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
using namespace boost::filesystem;
class Directory {
    std::vector<File*> files;
    std::vector<Directory> subdirectories;
    public:
        void appendFile(File*);
        void appendDirectory(Directory);
        void print();
        void release();
};


class DirectoryFetcher : public ProcessClass<Directory> {
    std::string path;
    bool is_file;
    //HTTPFetcher httpgetter;
    Directory src;
    public:
        DirectoryFetcher(std::string);
        virtual void run();
        virtual Directory fetch();
};

#endif

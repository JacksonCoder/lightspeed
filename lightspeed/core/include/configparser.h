// configparser.h

#ifndef CONFIGPARSER
#define CONFIGPARSER
#include <iostream>
#include "file.h"
#include <string>
#include <cassert>
#include "../external/json.hpp"
#include "../globals.h"
using json = nlohmann::json;

class LightSpeedConfigurationParser : public ProcessClass<std::vector<std::string> > {
    json object;
    File* file_ptr;
public:
    LightSpeedConfigurationParser(File*);
    
    virtual void run();
    
    virtual std::vector<std::string> fetch();
    
};


struct ProjectFileData {
    std::string name,version,owner,build_type;
    std::vector<json> dependencies;
    std::vector<std::string> build_includes;
    bool link_cmake_deps;
    ProjectFileData(std::string,std::string,std::string,std::string,std::vector<json>,std::vector<std::string>,bool);
    ProjectFileData();
};

class ProjectFileParser : public ProcessClass<ProjectFileData> {
public:
    ProjectFileParser(File*);
    
    virtual void run();
    
    virtual ProjectFileData fetch();
};
#endif

// configparser.h
#include "../../include/configparser.h"
#include <time.h>
#include "../../include/errormanager.h"

LightSpeedConfigurationParser::LightSpeedConfigurationParser(File* f) {
        file_ptr = f;
}
    

void LightSpeedConfigurationParser::run()
{
        has_failed = true;
        // Get contents of file
        std::string filecontents = file_ptr->getContents();
        auto c = std::clock();
        try {
            object = json::parse(filecontents);
        }
        catch(...) {
            error_msg = "An exception was thrown during parsing of JSON data";
            return;
        }
        try {
            std::exception e;
            if(!object["repos"].is_array()) throw e;
        }
        catch(std::exception& e){
            ErrorManager::error("LightSpeed seems to have a configuration error. Check the configuration file for potential typos or mistakes. If the config file was generated by LightSpeed, report the bug on our Github page","parsing",true);
            return;
        }
        auto time_elapsed = double(std::clock() - c);
        json repo_list = object["repos"];
        for (auto r : repo_list) {
            result.push_back(r);
        }
        double sec = time_elapsed / CLOCKS_PER_SEC;
        std::cout.precision(10);
        std::cout << "Configuration file loaded in " << sec<< " seconds"<< std::endl;
        has_failed = false;
}

std::vector<std::string> LightSpeedConfigurationParser::fetch()
{
    return result;
}


ProjectFileParser::ProjectFileParser(File* f) {
        std::string name,version,owner,build_type;
        std::vector<json> dependencies;
        std::vector<std::string> build_includes;
        bool link_cmake_deps;
        json object;
        auto c = std::clock();
        std::string contents = f->getContents();
        try {
            object = json::parse(contents);
        }
        catch(...) {
            error_msg = "An exception was thrown during parsing of the JSON data";
            has_failed = true;
            return;
        }
        try {
            std::exception e;
            if(!(object["name"].is_string())) throw e;
            if(!(object["version"].is_string())) throw e;
            if(!(object["owner"].is_string())) throw e;
        }
        catch (std::exception& e) {
            error_msg = "There was an error parsing your package definition file. Check the file for typos";
            has_failed = true;
            return;
        }
        //Parse manifest
        name = object["name"];
        version = object["version"];
        owner = object["owner"];
        
        //Parse dependencies
        json deproot = object["dependencies"];
        if (!deproot.is_array()) {
            error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
            has_failed = true;
            return;
        }
        for (auto d : deproot) {
            if (!d.is_object() || !d["name"].is_string() || !d["version"].is_string()) {
                error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
                has_failed = true;
                return;
            }
        }
        for (auto package : deproot) {
            dependencies.push_back(package);
        }
        
        //Parse build info
        json build = object["build"];
        if(!build.is_object()) {
            error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
            has_failed = true;
            return;
        }
        json create_cmake_link = build["cmake-create-dep-file"];
        json type = build["type"];
        json include = build["include"];
        if(!create_cmake_link.is_boolean() || !type.is_string() || !include.is_array()) {
            error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
            has_failed = true;
            return;
        }
        link_cmake_deps = create_cmake_link;
        build_type = type;
        for(auto i : include) {
            if(!i.is_string()) {
                error_msg = "There was an error parsing the dependencies for your project. Make sure they are formatted correctly";
                has_failed = true;
                return;
            }
            build_includes.push_back(i);
        }
        
        result = ProjectFileData(
                name, version, owner, build_type,
                dependencies,
                build_includes,
                link_cmake_deps
                 );
}

void ProjectFileParser::run()
{
    
}

ProjectFileData ProjectFileParser::fetch()
{
    return result;
}



ProjectFileData::ProjectFileData(std::string name, std::string version, std::string owner, std::string build_type, std::vector<json> dependencies, std::vector<std::string> build_includes, bool link_cmake_deps)
{
    this->name = name;
    this->version = version;
    this->build_type = build_type;
    this->dependencies = dependencies;
    this->build_includes = build_includes;
    this->link_cmake_deps = link_cmake_deps;
}

ProjectFileData::ProjectFileData()
{
    
}


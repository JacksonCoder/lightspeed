#include "../../include/codegrab.h"

getSource::getSource(std::string path) { //Note: path always a slash after it
    this->path = path;
    auto r = std::regex_search(path,std::regex("^http"));
    is_file = !r;
}

std::string getSource::get() {
    if (!is_file) {
        std::cout << "Network interfacing is not implemented yet." << std::endl;
        return "";
    }
    // It's a local directory: start reading from it
    
    //
    // Note: Boost has not yet been linked into this project: therefore, directory reading is not currently implemented.
    //
    
    //Instead, attempt to read package file
    File* package_file = filegetter.load(path + "LightSpeed.json",true);
    if(!package_file->open()) return "";
    else return package_file->getContents();
}

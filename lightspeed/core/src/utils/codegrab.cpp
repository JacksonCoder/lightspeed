#include "../../include/codegrab.h"
#include "../../include/network.h"

Directory getDirectory(std::string path) {
    Directory src;
    directory_iterator di(path);
    for(auto& file : boost::make_iterator_range(di,{})) {
        if(is_directory(file)) {
            src.appendDirectory(getDirectory(file.path().generic_string()));
        }
        else {
            src.appendFile(FileLoader::load(file.path().generic_string(),true));
        }
    }
    return src;
}

void Directory::appendFile(File* f)
{
    files.push_back(f);
}

void Directory::appendDirectory(Directory d) {
    subdirectories.push_back(d);
}

void Directory::print() {
    for(auto f :files) {
        std::cout << f->get_path() << std::endl;
    }
    for(auto d : subdirectories) {
        d.print();
    }
}

void Directory::release() {
    for(auto f : files) {
        delete f;
    }
    for(auto d : subdirectories) {
        d.release();
    }
}


DirectoryFetcher::DirectoryFetcher(std::string) { //Note: path always a slash after it
    this->path = path;
    auto r = std::regex_search(path,std::regex("^http"));
    is_file = !r;
}

DirectoryFetcher::~DirectoryFetcher() {
    src.release();
}

void DirectoryFetcher::run() {
    if (!is_file) {
        HTTPFetcher http(path,true);
        std::cout << "Fetching package from URL: " + path << std::endl;
        http.run();
        src = http.fetch();
        return;
    }
    // It's a local directory: start reading from it
    
    //Attempt to read package file first (to make sure it's a package):
    File* package_file = FileLoader::load(path + "LightSpeed.json",true);
    if(!package_file->stable()) {
        std::cout << "The specified package path does not contain a package descriptor file 'LightSpeed.json' in it: invalid package" << std::endl;
        has_failed = true;
        return;
    }
    src = getDirectory(path);
}

Directory DirectoryFetcher::fetch() {
    return src;
}

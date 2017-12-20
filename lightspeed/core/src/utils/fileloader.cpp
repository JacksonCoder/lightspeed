#include "../../include/fileloader.h"

File* FileLoader::load(std::string fname, bool cwd)  {
    if(cwd) {
        fname = get_current_dir_name() + std::string("/") + fname;
    }
    File* f = new File(fname);
    std::ifstream f_read;
    try {
        f_read.open(fname);
    }
    catch(...) {
        f->set_open(false);
        return f;
    }
    if (!f_read.is_open()) {
        f->set_open(false);
        return f;
    }
    std::string buffer;
    while (!f_read.eof())
    {
        std::getline(f_read,buffer);
        f->append_contents(buffer);
    }
    f->set_open(true);
    return f;
}

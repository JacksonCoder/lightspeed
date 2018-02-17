#include "../../include/fileloader.h"

File* FileLoader::load(std::string fname, bool cwd)  {
    if(cwd) {
        fname = get_current_dir_name() + std::string("/") + fname;
    }
    File* f = new File(fname,true);
    std::ifstream f_read(fname);
    try {
        if(!f_read) {
            std::cout << 'h' << std::endl;
            f->set_stable(false);
            return f;
        }
    }
    catch(...) {
        f->set_stable(false);
        return f;
    }
    if (!f_read.is_open()) {
        f->set_stable(false);
        return f;
    }
    std::string buffer;
    while (!f_read.eof())
    {
        std::getline(f_read,buffer);
        f->append_contents(buffer);
    }
    f->set_stable(true);
    f_read.close();
    return f;
}

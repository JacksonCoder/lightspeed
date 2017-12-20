#include "../../include/file.h"

File::File(std::string fname) {
    filename = fname;
}

bool File::open() {
    return is_open;
}

void File::set_open(bool v) {
        is_open = v;
}

void File::append_contents(std::string s) {
    contents += s;
}

std::string File::getContents() {
    return contents;
}

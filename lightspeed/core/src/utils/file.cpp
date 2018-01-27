#include "../../include/file.h"

File::File(std::string fname, bool open) {
    filename = fname;
    is_stable = open;
}

void File::append_contents(std::string s) {
    contents += s;
}

std::string File::getContents() {
    return contents;
}

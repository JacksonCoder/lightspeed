
#include "../../globals.h"

std::vector<std::string> CMD_OPTIONS  = { 
    "help",
    "version",
    "build",
    "create",
    "install",
    "load",
    "search",
    "remove",
    "repo",
    "status",
    "sandbox"
};

const std::string LS_VERSION = "0.1";

std::map<char,std::string> SANDBOX_OPTIONS = {
    {'c',"compilation"},
    {'u',"utils"},
    {'n',"network"},
    {'p',"parsing"}
};

template <typename T>
bool ProcessClass<T>::did_fail() {
    return has_failed;
}
template <typename T>
std::string ProcessClass<T>::get_error() {
    return error_msg;
}

bool StatusClass::stable()
{
    return is_stable;
}

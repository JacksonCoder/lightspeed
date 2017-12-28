
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
    "status"
};

const std::string LS_VERSION = "0.1";

std::map<char,std::string> SANDBOX_OPTIONS = {
    {'c',"compilation"},
    {'u',"utils"},
    {'n',"network"},
    {'p',"parsing"}
};

bool ModuleObject::did_fail() {
    return has_failed;
}

void ModuleObject::set_fail(bool val)
{
    has_failed = val;
}

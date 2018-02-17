#include "../../../globals.h"

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
bool StatusClass::stable()
{
    return is_stable;
}

void StatusClass::stability_update()
{
    
}

void StatusClass::set_stable(bool v)
{
    is_stable = v;
}

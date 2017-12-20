
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
    {'u',"utils"}
};

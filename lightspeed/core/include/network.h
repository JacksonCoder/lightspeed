#ifndef NETWORK_H
#define NETWORK_H

#include "codegrab.h"

class HTTPConnection : public ModuleObject {
    Directory download_res;
    std::string checksum,url;
public:
    HTTPConnection(std::string); //first arg is url
    ~HTTPConnection();
    void fetch(bool); //first arg is show loading bar
};

#endif

#ifndef NETWORK_H
#define NETWORK_H

#include <curl/curl.h>
#include "codegrab.h"
#include "file.h"

class HTTPConnection : public ModuleObject {
    Directory download_res;
    std::string checksum,url;
public:
    HTTPConnection(std::string); //first arg is url
    ~HTTPConnection();
    void fetch(bool,std::string); //first arg is show loading bar
    Directory getResult() { return download_res; }
};

#endif

#ifndef NETWORK_H
#define NETWORK_H

#include <curl/curl.h>
#include "codegrab.h"
#include "file.h"
#include "errormanager.h"

extern bool network_success;

class HTTPConnection : public ModuleObject {
    Directory download_res;
    std::string checksum,url;
public:
    HTTPConnection(std::string); //first arg is url
    ~HTTPConnection();
    void fetch(bool,std::string); //first arg is show loading bar
    Directory getResult() { return download_res; }
};

size_t set_write_data(void*,size_t,size_t,std::string*);

void displayBar(int,bool);

std::string fetch_file(std::string,bool);

#endif

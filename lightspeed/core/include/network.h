#ifndef NETWORK_H
#define NETWORK_H

#include <curl/curl.h>
#include "codegrab.h"
#include "file.h"
#include "errormanager.h"

extern bool network_success;

class HTTPFetcher : public ProcessClass<Directory> {
    std::string url;
    bool use_loading_bar;
public:
    HTTPFetcher(std::string,bool);
    ~HTTPFetcher();
    virtual void run();
    virtual Directory fetch();
};

size_t set_write_data(void*,size_t,size_t,std::string*);

void displayBar(int,bool);

std::string fetch_file(std::string,bool);

#endif

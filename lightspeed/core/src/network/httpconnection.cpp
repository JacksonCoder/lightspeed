#include "../../include/network.h"

bool network_success;

HTTPConnection::HTTPConnection(std::string path) {
    url = path;
}

HTTPConnection::~HTTPConnection()
{
    download_res.release();
}

void HTTPConnection::fetch(bool use_loading_bar,std::string dest)
{    
    // Run scan of files to download

    // Start download process
    
    std::string file = fetch_file(this->url,use_loading_bar);
    
    if(!network_success) {
        set_fail(true);
        return;
    }
    else {
        set_fail(false);
    }
    
    File* f = new File("download_result");
    f->append_contents(file);
    download_res.appendFile(f);
}


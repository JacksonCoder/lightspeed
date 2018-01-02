#include "../../include/network.h"

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
    
    File* f = new File("download_result");
    f->append_contents(file);
    download_res.appendFile(f);
}


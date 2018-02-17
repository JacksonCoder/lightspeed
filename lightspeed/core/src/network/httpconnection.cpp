#include "../../include/network.h"

bool network_success;

HTTPFetcher::HTTPFetcher(std::string path, bool loading_bar) {
    url = path;
    use_loading_bar = loading_bar;
}

HTTPFetcher::~HTTPFetcher()
{
    result.release();
}

void HTTPFetcher::run()
{    
    // Run scan of files to download

    // Start download process
    
    std::string file = fetch_file(this->url,use_loading_bar);
    
    if(!network_success) {
        has_failed = true;
        return;
    }
    else {
        has_failed = false;
    }
    
    File* f = new File("result",true);
    f->append_contents(file);
    result.appendFile(f);
}

Directory HTTPFetcher::fetch()
{
    return result;
}



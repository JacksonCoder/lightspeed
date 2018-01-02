#include "../../include/network.h"

std::string return_str;

size_t set_write_data(void* buffer, size_t size, size_t nmemb, std::string* userp)
{
    
    size_t newLength = size*nmemb;
    size_t oldLength = userp->size();
    try
    {
        userp->resize(oldLength + newLength);
    }
    catch(std::bad_alloc &e)
    {
        //handle memory problem
        return 0;
    }

    std::copy((char*)buffer,(char*)buffer+newLength,userp->begin()+oldLength);
    return size*nmemb;
}

void displayBar(int percent, bool first_time) {
    //Bar is 102 characters long, plus 4 characters for the time display
    
    // Clear display
    std::cout << std::flush;
    if(!first_time) for (int i = 0; i < 106; i++) {
        std::cout << "\b";
    } else { std::cout << "\n";}
    std::cout << std::flush;
    std::cout << "[";
    for(int i = 0; i < percent-1; i++) {
        std::cout << "-";
    }
    std::cout << ">";
    for(int i = 0; i < 99 - percent; i++) {
        std::cout<< "_";
    }
    std::cout << "]";
    int percentLen = std::to_string(percent).length();
    std::cout << percent << "%";
    for(int i = 0; i < 3 - percentLen;i++) std::cout << " ";
    std::cout << std::flush;
}

std::string fetch_file(std::string path,bool display_bar) {
    CURLcode res;
    std::string return_s;
    auto curl = curl_easy_init();
    if(curl) {
        if(display_bar) displayBar(1,true);
        curl_easy_setopt(curl,CURLOPT_URL,path.c_str());
        if(display_bar) displayBar(25,false);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,set_write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,&return_str);
        if(display_bar) displayBar(50,false);
        res = curl_easy_perform(curl);
        if(display_bar) displayBar(100,false);
        return_s = return_str;
        curl_easy_cleanup(curl);
        if(res != 0) {
            //Network connectivity issue
        }
    } else {
        // Network connectivity issue
    }
    return return_s;
}



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


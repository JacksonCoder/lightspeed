#include "../../include/network.h"

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

HTTPConnection::HTTPConnection(std::string path) {
    url = path;
}

HTTPConnection::~HTTPConnection()
{
    download_res.release();
}

void HTTPConnection::fetch(bool use_loading_bar)
{
    unsigned int progress = 1; // For loading purposes
    displayBar(progress,true);
    for(;progress <= 100;progress += 5) {
        displayBar(progress,false);
        sleep(1);
    }
    displayBar(100,false);
}


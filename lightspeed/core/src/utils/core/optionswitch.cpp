#include "../../../include/optionswitch.h"

void OptionSwitch::dispatch(EState* env)
{
    std::tuple<std::vector<std::string> > local_conf = env->get_state();
    std::string option = env->get_option();
    if ( option == "help" || option == "version") {
        help();
        return;
    }
    if (option == "status") {
        std::cout << "Checking state of current project..." << std::endl;
        env->stability_update();
        if(env->stable()) {
            std::cout << "Global configuration file is stable." << std::endl;
        } else {
            std::cout << "Global configuration file is not stable." << std::endl;
        }
        return;
    }
    if (option == "sandbox") {
        std::cout << "Welcome to the LightSpeed beta sandbox! Test potential features here!" << std::endl;
        for(auto s : SANDBOX_OPTIONS) {
            std::cout << s.first << " -> " << s.second << std::endl;
        }
        std::cout << "Please select a beta feature to test:";
        char c;
        std::cin >> c;
        if(SANDBOX_OPTIONS[c] == "compilation") {
            //Run compilation
            std::cout << "--- Starting compilation sandbox ---" << std::endl;
            std::cout << "Enter CMake version:";
            std::string v; std::cin >> v;
            std::cout <<"Enter a list of file paths (enter '!' to stop entering items:";
            std::string buffer;
            std::vector<std::string> libraries;
            while(buffer != "!") {
                std::cin >> buffer;
                if(buffer != "!")
                    libraries.push_back(buffer);
            }
            env->set_config_state(v,libraries,{});
            std::cout<<"Generating CMake linkage file..." << std::endl;
            auto compiler = CMakeGenerator(env);
            compiler.run();
            std::cout << "Done.\nResult:\n" << compiler.fetch();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "utils") {
            // Run utils demo
            std::cout<< "Enter directory (file or HTTP):";
            std::string file;
            std::cin >> file;
            DirectoryFetcher source_grabber(file);
            source_grabber.run();
            source_grabber.fetch().print();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "network") {
            // No current network features
            std::string path;
            std::cout << "Enter URL:";
            std::cin >> path;
            HTTPFetcher h(path,true);
            std::cout << "Directory output:" << std::endl;
            h.run();
            std::cout << std::endl << "Result:" << std::endl;
            if (h.did_fail()) std::cout << "There was an error trying to connect" << std::endl;
            h.fetch().print();
            return;
        }
        if(SANDBOX_OPTIONS[c] == "parsing") {
            // No current parsing features
            std::cout << "Enter file location of package file:";
            std::string loc;std::cin>>loc;
            ProjectFileParser parser = ProjectFileParser(FileLoader::load(loc,true));
            if(parser.did_fail()) {
                ErrorManager::error(parser.get_error(),"parsing",false);
            }
            std::cout << "File parsed successfully. Details:" << std::endl;
            
            std::cout << "List of dependencies:\n";
            ProjectFileData pfd = parser.fetch();
            for(auto j : pfd.dependencies) {
                std::cout << j << std::endl;
            }
            std::cout << "Build information:\n";
            std::cout << "Should generate CMake linkage file: " << pfd.link_cmake_deps << std::endl;
            std::cout << "Build system: " << pfd.build_type << std::endl;
            std::cout << "Directories/files to include:" << std::endl;
            for(auto i : pfd.build_includes) {
                std::cout << i << std::endl;
            }
            return;
        }
    }
    ErrorManager::error(option + " is not a valid command. Run `lightspeed-bin help` for a list of commands","optionswitch",true); // This shouldn't be run, but we should catch things if they do somehow get there.
}

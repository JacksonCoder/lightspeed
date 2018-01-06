// Main testing file: contains all tests for LightSpeed
#include "gtest/gtest.h"
#include "lsincludebundle.h"

//
// Utils testing
//

TEST(Utils,InputHandlerFailsOnNoArguments) {
    char* args[1];
    args[0] = "lightspeed";
    InputHandle i = InputHandle(1,args);
    ASSERT_TRUE(i.did_fail());
}

TEST(Utils,FailsOnNonexistentFile) {

}

TEST(Utils,FailsOnNoLightSpeedJSON) {
    
}


//
// Compilation testing
//

TEST(Compilation,CanBuildFileCorrectly) {
    EState* env = new EState();
    CMakeGenerator* cmakeg = new CMakeGenerator(env);
    env->set_config_state("2.6",{},{});
    cmakeg->compile();
    std::string result = cmakeg->get_output();
    ASSERT_TRUE(std::regex_search(result,std::regex("cmake_minimum_required")));
    std::string examplelibrarypath = "some/random/library/path";
    env->set_config_state("2.6",{examplelibrarypath},{});
    cmakeg->compile();
    result = cmakeg->get_output();
    ASSERT_TRUE(std::regex_search(result,std::regex("set")));
    ASSERT_TRUE(std::regex_search(result,std::regex(examplelibrarypath)));
    ASSERT_TRUE(std::regex_search(result,std::regex("cmake_minimum_required")));
    //Add more tests as time goes on
    
    
    delete cmakeg;
    delete env;
}

TEST(Compilation,FailsOnNullInput) {
    EState* env = new EState();
    CMakeGenerator* cmakeg = new CMakeGenerator(env);
    //Don't run set_config_state
    
    cmakeg->compile();
    //ASSERT_TRUE(cmakeg->has_failed()); //Do this after inheritance is added.
}

//
// Network testing
//

TEST(Network,IsConnectedToInternet) {

}

TEST(Network,CanCorrectlyFetchFile) {
    
}

TEST(Network,FailsWithInvalidURL) {
    
}

TEST(Network,FailsWithInvalidPath) {
    
}

TEST(Network,NetworkBarPrintsCorrectly) {
    /*
    // Redirect STDOUT
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
    displayBar(1,true);
    std::cout.rdbuf(old);
    ASSERT_TRUE(buffer.str()=="\n[>__________________________________________________________________________________________________]1%  ");
    std::cout << std::flush;
    */
    std::stringstream buffer2;
    std::streambuf * old2 = std::cout.rdbuf(buffer2.rdbuf());
    displayBar(5,true);
    std::cout.rdbuf(old2);
    ASSERT_TRUE(buffer2.str()=="\n[---->______________________________________________________________________________________________]5%  ");
    std::cout << std::flush;
    std::stringstream buffer3;
    std::streambuf * old3 = std::cout.rdbuf(buffer3.rdbuf());
    displayBar(100,true);
    std::cout.rdbuf(old3);
    ASSERT_TRUE(buffer3.str()=="\n[--------------------------------------------------------------------------------------------------->]100%");
    std::cout << std::flush;
}


//
// Parsing testing
//


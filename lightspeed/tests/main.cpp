// Main testing file: contains all tests for LightSpeed
#include "gtest/gtest.h"
#include "lsincludebundle.h"
TEST(InputHandling,FailsOnNoArguments) {
    char* args[] = {"lightspeed",""};
    InputHandle i = InputHandle(1,args);
    //ASSERT_TRUE(EState(i).has_failed()); //Do this after inheritance is added
}

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


cmake_minimum_required(VERSION 3.18)

# set the project name and version
project(NorthStar VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip 
)

FetchContent_MakeAvailable(googletest)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
enable_testing(googletest)

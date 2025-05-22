cmake_minimum_required(VERSION 3.30)
project(PhoneBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhoneBook main.cpp
        TXTToJSON.hpp
        JSONOutput.hpp
        userInterface.hpp
        Getline.hpp
)

cmake_minimum_required(VERSION 3.10)

project( MyString )

add_executable(string src/main.cpp src/MyString.cpp)

include_directories(include)
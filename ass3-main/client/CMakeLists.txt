cmake_minimum_required(VERSION 3.16.3)

project(Client)
find_package(Threads)

add_executable(Client main.cpp CsvReader.h CsvReader.cpp Client.cpp Client.h)

target_link_libraries(Client ${CMAKE_THREAD_LIBS_INIT})
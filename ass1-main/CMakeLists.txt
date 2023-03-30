cmake_minimum_required(VERSION 3.20)
project(ass1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ass1 main.cpp Flower.h Flower.cpp main.h CsvReader.cpp CsvReader.h
        Classifier.h)

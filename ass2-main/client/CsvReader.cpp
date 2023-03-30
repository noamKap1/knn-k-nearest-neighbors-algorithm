#include <fstream>
#include <sstream>
#include "CsvReader.h"
#include <iostream>
//Read a csv file and return a matrix of its lines
std::vector<std::vector<std::string>> readFromCSV(const std::string &path) {
    std::ifstream fin(path);
    if (!fin.is_open()){
        std::cout << "cannot open the file" << std::endl;
    }
    std::vector<std::vector<std::string>> data;
    std::string line;
    while (fin.good()) {
        std::getline(fin, line);
        std::stringstream ss(line);
        std::vector<std::string> row = stringSplitter(line, ',');
        if (!row.empty())
            data.push_back(row);
    }
    return data;
}

//Write to a csv file
void writeToCSV(const std::string &path, const std::vector<std::string> &data) {
    std::ofstream fout(path);

    for (const std::string &line: data) {
        fout << line << std::endl;
    }
}

std::vector<std::string> stringSplitter(const std::string &string, const char c) {
    std::stringstream stringStream(string);
    std::string str;
    std::vector<std::string> vector;
    while (std::getline(stringStream, str, c)) {
        vector.push_back(str);
    }
    return vector;
}
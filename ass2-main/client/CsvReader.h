#ifndef ASS2_CSVREADER_H
#define ASS2_CSVREADER_H

#include "vector"
#include "string"

std::vector<std::vector<std::string> > readFromCSV(const std::string &path);

void writeToCSV(const std::string &filePath, const std::vector<std::string> &dataVector);

std::vector<std::string> stringSplitter(const std::string &, char);


#endif //ASS2_CSVREADER_H

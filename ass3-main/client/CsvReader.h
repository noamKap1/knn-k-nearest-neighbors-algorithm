#ifndef CLIENT_CSVREADER_H
#define CLIENT_CSVREADER_H

#include "vector"
#include "string"

namespace CsvReader {
    std::vector<std::vector<std::string> > readFromCSV(const std::string &path);

    void writeToCSV(const std::string &filePath, const std::vector<std::string> &dataVector);

    std::vector<std::string> stringSplitter(const std::string &, const char);

    std::string readFile(const std::string &);

    std::vector<std::vector<std::string>> readCSV(const std::string &);

    void writeFile(const std::string &path, const std::string &content);

    std::string recv(int);

    void send(int, const std::string &);
}
#endif //CLIENT_CSVREADER_H

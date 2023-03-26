#include "Utils.h"
#include <fstream>
#include <sstream>
#include <vector>
 namespace reader {
     std::vector<int> *readArrayFromFile(const std::string &filename) {
         using namespace std;
         string line;
         fstream newFile;
         newFile.open(filename, ios::in);
         getline(newFile, line);
         if (line.empty()) {
             throw invalid_argument("Bad file format");
         }
         int count = stoi(line);
         auto* vector = new std::vector<int>();
         getline(newFile, line);
         stringstream stream(line);
         string element;
         for (int i = 0; i < count; i++) {
             if (stream >> element) {
                 vector->push_back(stoi(element));
             } else {
                 throw invalid_argument("Bad file format");
             }
         }
         return vector;
     }
 }
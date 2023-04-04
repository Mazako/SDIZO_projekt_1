#include "Utils.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <random>

namespace sdizoUtils {
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
        if (count <= 0) {
            throw invalid_argument("Too small length of array");
        }
        auto *vector = new std::vector<int>();
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

    double calculate_avg(std::vector<long> *elements) {
        double total = .0;
        int n = 0;
        for (long element: *elements) {
            total += (double) element;
            n++;
        }
        return total / (double) n;
    }

    void writeArrayToCsvFile(std::vector<double> *results, std::string fileName, std::vector<std::string> &headers) {
        using namespace std;
        string csv = "";
        fstream file;
        file.open(fileName, ios::out);
        for (int i = 0; i < headers.size(); i++) {
            string &header = headers.at(i);
            csv += i == headers.size() - 1 ?  header : header + ";";
        }
        csv += "\n";
        for (int i = 0; i < results->size(); i++) {
            string result = std::to_string(results->at(i));
            csv += i == results->size() - 1 ?  result : result + ";";
        }
        csv += "\n";
        file << csv;
    }

    int getRandomInt() {
        std::random_device device;
        std::mt19937 rng(device());
        std::uniform_int_distribution<> distribution(0, INT32_MAX);
        return distribution(rng);
    }
}
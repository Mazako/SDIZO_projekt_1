#ifndef MAIN_UTILS_H
#define MAIN_UTILS_H
#include <string>
#include <vector>

namespace sdizoUtils {
    std::vector<int> *readArrayFromFile(const std::string &filename);
    double calculate_avg(std::vector<long> *elements);
    void writeArrayToCsvFile(std::vector<double> *results, std::string fileName, std::vector<std::string> &headers);
    int getRandomInt();
}

#endif //MAIN_UTILS_H

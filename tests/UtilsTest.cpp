#include <gtest/gtest.h>
#include "utils/Utils.h"

TEST(AverageTest, test) {
    std::vector<long> vector {1, 2, 3, 4, 5};
    int avg = reader::calculate_avg(&vector);
    ASSERT_EQ(avg, 3);
}

TEST(RandTest, test) {
    while (true) {
        std::cout << reader::getRandomInt() << std::endl;
    }
}
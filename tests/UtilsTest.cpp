#include <gtest/gtest.h>
#include "utils/Utils.h"

TEST(AverageTest, test) {
    std::vector<long> vector {1, 2, 3, 4, 5};
    int avg = sdizoUtils::calculate_avg(&vector);
    ASSERT_EQ(avg, 3);
}

TEST(RandTest, test) {
    int value = 0;
    while (value != 100) {
        value = sdizoUtils::getRandomInt();
    }
}
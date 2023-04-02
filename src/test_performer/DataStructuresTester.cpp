#include "DataStructuresTester.h"
#include <chrono>
#include <iostream>
#include "utils/Utils.h"

const std::vector<int> DataStructuresTester::ARRAY_AND_LIST_TEST_RANGES(
        {100, 500, 1000, 10000, 50000} //100000, 250000, 500000, 750000, 1000000, 1500000}
);

const int DataStructuresTester::TEST_REPEATS = 20;

DataStructuresTester::DataStructuresTester() {
}

DataStructuresTester::~DataStructuresTester() {

}

void DataStructuresTester::dynamicArrayStartInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN START OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(0, reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_add_start.csv",
                                headers
    );

}

void DataStructuresTester::dynamicArrayMiddleInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(size / 2, reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_add_mid.csv",
                                headers
    );
}

void DataStructuresTester::dynamicArrayEndInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN END OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(size - 1 ,reader::getRandomInt());
            size++;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_add_end.csv",
                                headers
    );

}

void DataStructuresTester::dynamicArrayStartDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN START OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(0);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_delete_start.csv",
                                headers
    );

}

void DataStructuresTester::dynamicArrayMiddleDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(size / 2);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_delete_mid.csv",
                                headers
    );

}

void DataStructuresTester::dynamicArrayEndDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
        auto *array = new DynamicArray();
        while (size > array->size) {
            array->add(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(size - 1);
            size--;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            std::cout << time << std::endl;
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }

    reader::writeArrayToCsvFile(&testResults,
                                "dynamic_array_delete_end.csv",
                                headers
    );

}

void DataStructuresTester::dynamicArrayAllTests() {
    this->dynamicArrayStartInsertionTest();
    this->dynamicArrayMiddleInsertionTest();
    this->dynamicArrayEndInsertionTest();
    this->dynamicArrayStartDeletionTest();
    this->dynamicArrayMiddleDeletionTest();
    this->dynamicArrayEndDeletionTest();
}



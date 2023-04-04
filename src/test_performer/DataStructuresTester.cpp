#include "DataStructuresTester.h"
#include <chrono>
#include <iostream>
#include "utils/Utils.h"

const std::vector<int> DataStructuresTester::RANGES(
        {500, 1000, 10000, 50000, 100000, 250000, 500000}
);

const int DataStructuresTester::TEST_REPEATS = 200;

DataStructuresTester::DataStructuresTester() {
}

DataStructuresTester::~DataStructuresTester() {

}

void DataStructuresTester::dynamicArrayStartInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *array = new DynamicArray();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN START OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(0, sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "dynamic_array_add_start.csv",
                                    headers
    );

}

void DataStructuresTester::dynamicArrayMiddleInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    auto *array = new DynamicArray();
    for (int size: RANGES) {
        std::cout << "INSERTION IN MID OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(size / 2, sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "dynamic_array_add_mid.csv",
                                    headers
    );
}

void DataStructuresTester::dynamicArrayEndInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *array = new DynamicArray();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN END OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->addAt(size - 1, sdizoUtils::getRandomInt());
            size++;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "dynamic_array_add_end.csv",
                                    headers
    );

}

void DataStructuresTester::dynamicArrayStartDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    auto *array = new DynamicArray();
    for (int size: RANGES) {
        std::cout << "DELETION IN START OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(0);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "dynamic_array_delete_start.csv",
                                    headers
    );

}

void DataStructuresTester::dynamicArrayMiddleDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    auto *array = new DynamicArray();
    for (int size: RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(size / 2);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "dynamic_array_delete_mid.csv",
                                    headers
    );

}

void DataStructuresTester::dynamicArrayEndDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResults;
    auto *array = new DynamicArray();
    for (int size: RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size << ")" << std::endl;
        while (size > array->size) {
            array->add(sdizoUtils::getRandomInt());
        }
        std::cout << array->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            array->remove(size - 1);
            size--;
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
    sdizoUtils::writeArrayToCsvFile(&testResults,
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

//DOUBLE LINKED LIST SECTOR
void DataStructuresTester::doubleLinkedListStartInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN START OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->unshift(sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_add_start.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListEndInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN END OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->push(sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_add_end.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListMiddleInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN MID OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->addAt(size / 2, sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_add_mid.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListStartDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "DELETION IN START OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->shift();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(sdizoUtils::getRandomInt());
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_delete_start.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListEndDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "DELETION IN END OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->pop();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(sdizoUtils::getRandomInt());
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_delete_end.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListMiddleDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN END OF DOUBLE LINKED LIST TEST (" << size << ")" << std::endl;
        while (size > list->size) {
            list->push(sdizoUtils::getRandomInt());
        }
        std::cout << list->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->removeAt(size / 2);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(sdizoUtils::getRandomInt());
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "double_linked_list_delete_mid.csv",
                                    headers
    );
}

void DataStructuresTester::doubleLinkedListAllTests() {
    this->doubleLinkedListStartInsertionTest();
    this->doubleLinkedListMiddleInsertionTest();
    this->doubleLinkedListEndInsertionTest();
    this->doubleLinkedListStartDeletionTest();
    this->doubleLinkedListMiddleDeletionTest();
    this->doubleLinkedListEndDeletionTest();
}

// MAX HEAP TESTS
void DataStructuresTester::maxHeapInsertTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *heap = new MaxHeap();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN MAX HEAP TEST (" << size << ")" << std::endl;
        while (size > heap->getSize()) {
            heap->insert(sdizoUtils::getRandomInt());
        }
        std::cout << heap->getSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            heap->insert(sdizoUtils::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            heap->removeMax();
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete heap;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "max_heap_insert_test.csv",
                                    headers
    );
}

void DataStructuresTester::maxHeapDeleteTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *heap = new MaxHeap();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN MAX HEAP TEST (" << size << ")" << std::endl;
        while (size > heap->getSize()) {
            heap->insert(sdizoUtils::getRandomInt());
        }
        std::cout << heap->getSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            heap->removeMax();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            heap->insert(sdizoUtils::getRandomInt());
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete heap;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "max_heap_delete_test.csv",
                                    headers
    );
}

void DataStructuresTester::maxHeapAllTests() {
    this->maxHeapInsertTest();
    this->maxHeapDeleteTest();
}

void DataStructuresTester::binarySearchTreeInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN BINARY SEARCH TREE TEST (" << size << ")" << std::endl;
        while (size > bst->size) {
            try {
                bst->insertNode(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        int value;
        while (true) {
            try {
                bst->insertNode(value);
                bst->deleteNode(value);
                break;
            } catch (std::exception &e) {
                continue;
            }
        }
        for (int i = 0; i < TEST_REPEATS; i++) {
            try {
                auto start = high_resolution_clock::now();
                bst->insertNode(value);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);
                long time = duration.count();
                measuredTimes.push_back(time);
            } catch (std::exception &e) {
                i--;
                continue;
            }
            bst->deleteNode(value);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "bst_insert_test.csv",
                                    headers
    );
}

void DataStructuresTester::binarySearchTreeDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "DELETION IN BINARY SEARCH TREE TEST (" << size << ")" << std::endl;
        while (size > bst->size) {
            try {
                bst->insertNode(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = sdizoUtils::getRandomInt();
            try {
                bst->insertNode(value);
            } catch (std::exception &e) {
                i--;
                continue;
            }
            auto start = high_resolution_clock::now();
            bst->deleteNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            bst->insertNode(value);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "bst_delete_test.csv",
                                    headers
    );
}

void DataStructuresTester::binarySearchTreeSearchingTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "SEARCHING IN BINARY SEARCH TREE TEST (" << size << ")" << std::endl;
        while (size > bst->size) {
            try {
                bst->insertNode(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = sdizoUtils::getRandomInt();
            try {
                bst->insertNode(value);
            } catch (std::exception &e) {
                i--;
                continue;
            }
            auto start = high_resolution_clock::now();
            bst->findNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            bst->deleteNode(value);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "bst_search_test.csv",
                                    headers
    );
}

void DataStructuresTester::binarySearchTreeAllTests() {
    this->binarySearchTreeInsertionTest();
    this->binarySearchTreeDeletionTest();
    this->binarySearchTreeSearchingTest();
}

// RED BLACK TREE

void DataStructuresTester::redBlackTreeInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "INSERTION IN RED BLACK TREE TEST (" << size << ")" << std::endl;
        while (rbt->size < size) {
            try {
                rbt->insert(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        int value = sdizoUtils::getRandomInt();
        while (true) {
            try {
                rbt->insert(value);
                rbt->deleteNode(value);
                break;
            } catch (std::exception &e) {
                continue;
            }
        }
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = steady_clock::now();
            rbt->insert(value);
            auto end = steady_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            rbt->deleteNode(value);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "rbt_insert_test.csv",
                                    headers
    );
}

void DataStructuresTester::redBlackTreeSearchingTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "SEARCHING IN RED BLACK TREE TEST (" << size << ")" << std::endl;
        while (rbt->size < size) {
            try {
                rbt->insert(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = sdizoUtils::getRandomInt();
            try {
                rbt->insert(value);
            } catch (std::exception& e) {
                i--;
                continue;
            }
            auto start = high_resolution_clock::now();
            rbt->findNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            rbt->deleteNode(value);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "rbt_delete_test.csv",
                                    headers
    );
}

void DataStructuresTester::redBlackTreeDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    for (int size: RANGES) {
        std::cout << "DELETION IN RED BLACK TREE TEST (" << size << ")" << std::endl;
        while (rbt->size < size) {
            try {
                rbt->insert(sdizoUtils::getRandomInt());
            } catch (std::exception &e) {
                continue;
            }
        }
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = sdizoUtils::getRandomInt();
            try {
                rbt->insert(value);
            } catch (std::exception& e) {
                i--;
                continue;
            }            auto start = high_resolution_clock::now();
            rbt->deleteNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = sdizoUtils::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    sdizoUtils::writeArrayToCsvFile(&testResults,
                                    "rbt_search_test.csv",
                                    headers
    );
}

void DataStructuresTester::redBlackTreeAllTests() {
    this->redBlackTreeInsertionTest();
    this->redBlackTreeSearchingTest();
    this->redBlackTreeDeletionTest();
}


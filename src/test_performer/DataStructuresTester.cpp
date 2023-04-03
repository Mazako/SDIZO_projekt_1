#include "DataStructuresTester.h"
#include <chrono>
#include <iostream>
#include "utils/Utils.h"

const std::vector<int> DataStructuresTester::ARRAY_AND_LIST_TEST_RANGES(
        {500, 1000, 10000}//, 50000} //100000, 250000, 500000, 750000, 1000000, 1500000}
);

const int DataStructuresTester::TEST_REPEATS = 200;

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
    auto *array = new DynamicArray();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN START OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

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
    auto *array = new DynamicArray();
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

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
    auto *array = new DynamicArray();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN END OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
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
    auto *array = new DynamicArray();
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN START OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
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
    auto *array = new DynamicArray();
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;

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
    auto *array = new DynamicArray();
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN MID OF DYNAMIC ARRAY TEST (" << size <<")" << std::endl;
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
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete array;
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
//DOUBLE LINKED LIST SECTOR
void DataStructuresTester::doubleLinkedListStartInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN START OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->unshift(reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
                                "double_linked_list_add_start.csv",
                                headers
    );
}

void DataStructuresTester::doubleLinkedListEndInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN END OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->unshift(reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
                                "double_linked_list_add_end.csv",
                                headers
    );
}

void DataStructuresTester::doubleLinkedListMiddleInsertionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN MID OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->addAt(size / 2 ,reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
                                "double_linked_list_add_mid.csv",
                                headers
    );
}

void DataStructuresTester::doubleLinkedListStartDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN START OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->shift();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(reader::getRandomInt());
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
                                "double_linked_list_delete_start.csv",
                                headers
    );
}

void DataStructuresTester::doubleLinkedListEndDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN END OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->pop();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(reader::getRandomInt());
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
                                "double_linked_list_delete_end.csv",
                                headers
    );
}

void DataStructuresTester::doubleLinkedListMiddleDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *list = new DoubleLinkedList();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN END OF DOUBLE LINKED LIST TEST (" << size <<")" << std::endl;
        while (size > list->size) {
            list->push(reader::getRandomInt());
        }
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            list->pop();
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            list->push(reader::getRandomInt());
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete list;

    reader::writeArrayToCsvFile(&testResults,
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
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *heap = new MaxHeap();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN MAX HEAP TEST (" << size <<")" << std::endl;
        while (size > heap->getSize()) {
            heap->insert(reader::getRandomInt());
        }
        std::cout << heap->getSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            auto start = high_resolution_clock::now();
            heap->insert(reader::getRandomInt());
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            heap->removeMax();
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete heap;

    reader::writeArrayToCsvFile(&testResults,
                                "max_heap_insert_test.csv",
                                headers
    );
}

void DataStructuresTester::maxHeapDeleteTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *heap = new MaxHeap();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN MAX HEAP TEST (" << size <<")" << std::endl;
        while (size > heap->getSize()) {
            heap->insert(reader::getRandomInt());
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
            heap->insert(reader::getRandomInt());
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete heap;

    reader::writeArrayToCsvFile(&testResults,
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
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN BINARY SEARCH TREE TEST (" << size <<")" << std::endl;
        while (size > bst->size) {
            bst->insertNode(reader::getRandomInt());
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = reader::getRandomInt();
            auto start = high_resolution_clock::now();
            bst->insertNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            bst->deleteNode(value);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    reader::writeArrayToCsvFile(&testResults,
                                "bst_insert_test.csv",
                                headers
    );
}

void DataStructuresTester::binarySearchTreeDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN BINARY SEARCH TREE TEST (" << size <<")" << std::endl;
        while (size > bst->size) {
            bst->insertNode(reader::getRandomInt());
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = reader::getRandomInt();
            bst->insertNode(value);
            auto start = high_resolution_clock::now();
            bst->deleteNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            bst->insertNode(value);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    reader::writeArrayToCsvFile(&testResults,
                                "bst_delete_test.csv",
                                headers
    );
}

void DataStructuresTester::binarySearchTreeSearchingTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *bst = new BinarySearchTree();
    std::vector<double> testResults;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "SEARCHING IN BINARY SEARCH TREE TEST (" << size <<")" << std::endl;
        while (size > bst->size) {
            bst->insertNode(reader::getRandomInt());
        }
        std::cout << bst->size << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = reader::getRandomInt();
            bst->insertNode(value);
            auto start = high_resolution_clock::now();
            auto* node = bst->findNode(value);
//            if (node != nullptr) {
//                std::cout << "ESSA" << std::endl;
//            } else {
//                std::cout << "CHUj" << std::endl;
//
//            }
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            bst->deleteNode(value);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete bst;

    reader::writeArrayToCsvFile(&testResults,
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
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    int prevSize = 0;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "INSERTION IN RED BLACK TREE TEST (" << size <<")" << std::endl;
        for (int i = prevSize; i < size; i++) {
            rbt->insert(i);
        }
        prevSize = size;
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = prevSize + reader::getRandomInt();
            auto start = high_resolution_clock::now();
            rbt->insert(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            rbt->deleteNode(value);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    reader::writeArrayToCsvFile(&testResults,
                                "rbt_insert_test.csv",
                                headers
    );
}

void DataStructuresTester::redBlackTreeSearchingTest(){
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    int prevSize = 0;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "SEARCHING IN RED BLACK TREE TEST (" << size <<")" << std::endl;
        for (int i = prevSize; i < size; i++) {
            rbt->insert(i);
        }
        prevSize = size;
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = prevSize + reader::getRandomInt();
            rbt->insert(value);
            auto start = high_resolution_clock::now();
            rbt->findNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
            rbt->deleteNode(value);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    reader::writeArrayToCsvFile(&testResults,
                                "rbt_delete_test.csv",
                                headers
    );
}

void DataStructuresTester::redBlackTreeDeletionTest() {
    using namespace std::chrono;
    std::vector<std::string> headers;
    for (const auto &item: ARRAY_AND_LIST_TEST_RANGES) {
        headers.push_back(std::to_string(item));
    }
    auto *rbt = new RedBlackTree();
    std::vector<double> testResults;
    int prevSize = 0;
    for (int size: ARRAY_AND_LIST_TEST_RANGES) {
        std::cout << "DELETION IN RED BLACK TREE TEST (" << size <<")" << std::endl;
        for (int i = prevSize; i < size; i++) {
            rbt->insert(i);
        }
        prevSize = size;
        std::cout << rbt->getRealSize() << std::endl;
        std::vector<long> measuredTimes;
        for (int i = 0; i < TEST_REPEATS; i++) {
            int value = prevSize + reader::getRandomInt();
            rbt->insert(value);
            auto start = high_resolution_clock::now();
            rbt->deleteNode(value);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            long time = duration.count();
            measuredTimes.push_back(time);
        }
        double result = reader::calculate_avg(&measuredTimes);
        testResults.push_back(result);
    }
    delete rbt;

    reader::writeArrayToCsvFile(&testResults,
                                "rbt_search_test.csv",
                                headers
    );
}

void DataStructuresTester::redBlackTreeAllTests() {
    this->redBlackTreeInsertionTest();
    this->redBlackTreeSearchingTest();
    this->redBlackTreeDeletionTest();
}


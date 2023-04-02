#include <iostream>
#include <vector>
#include "dynamic_array/client/DynamicArrayClient.h"
#include "double_linked_list/client/DoubleLinkedListClient.h"
#include "heap/client/MaxHeapClient.h"
#include "binary_search_tree/client/BstClient.h"
#include "red_black_tree/client/RbTreeClient.h"
#include "test_performer/DataStructuresTester.h"

void startDynamicArrayClient();

void startDoubleLinkedListClient();

void startHeapClient();

void startBstClient();

void startRbTreeClient();

void quit();

void mainPlaceHolder();

void printMenuItems();

int main() {
    auto *tester = new DataStructuresTester();
    tester->dynamicArrayAllTests();
//    std::vector<void (*)()> menuItems = {
//            startDynamicArrayClient,
//            startDoubleLinkedListClient,
//            startHeapClient,
//            startBstClient,
//            startRbTreeClient,
//            quit,
//    };
//    int option;
//    void (*selectedFunction)() = nullptr;
//    do {
//        mainPlaceHolder();
//        printMenuItems();
//        std::cin >> option;
//        getchar();
//        option--;
//        if (option >= menuItems.size()) {
//            std::cerr << "nie ma takiej opcji." << std::endl;
//            continue;
//        }
//        selectedFunction = menuItems[option];
//        selectedFunction();
//    } while (selectedFunction != quit);

}

void printMenuItems() {
    std::cout << "1) Klient dynamicznej tablicy" << std::endl;
    std::cout << "2) Klient listy podwojnie wiazanej" << std::endl;
    std::cout << "3) Klient kopca" << std::endl;
    std::cout << "4) Klient drzewa BST" << std::endl;
    std::cout << "5) Klient drzewa czerwono-czarnego" << std::endl;
    std::cout << "6) Wyjdz z programu" << std::endl;
    std::cout << "Wybierz opcje:" << std::endl;
}

void startDynamicArrayClient() {
    auto *dynamicArrayClient = new DynamicArrayClient();
    dynamicArrayClient->startMainLoop();
    delete dynamicArrayClient;
}

void startDoubleLinkedListClient() {
    auto *doubleLinkedListClient = new DoubleLinkedListClient();
    doubleLinkedListClient->startMainLoop();
    delete doubleLinkedListClient;
}

void startHeapClient() {
    auto *maxHeapClient = new MaxHeapClient();
    maxHeapClient->startMainLoop();
    delete maxHeapClient;
}

void startBstClient() {
    auto *bstClient = new BstClient();
    bstClient->startMainLoop();
    delete bstClient;
}

void startRbTreeClient() {
    auto *rbClient = new RbTreeClient();
    rbClient->startMainLoop();
    delete rbClient;
}

void quit() {

}

void mainPlaceHolder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Menu glowne";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

//
// Created by micha on 25.03.2023.
//

#include <iostream>
#include <vector>
#include "DynamicArrayClient.h"

DynamicArrayClient::DynamicArrayClient() {
    this->array = new DynamicArray();
}

DynamicArrayClient::~DynamicArrayClient() {
    delete this->array;
}

void DynamicArrayClient::startMainLoop() {
    bool active = true;
    int option;
    do {
        printPlaceholder();
        printArray();
        printMenu();
        std::cin >> option;
        getchar();
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                addAtIndex();
                break;
            case 3:
                remove();
                break;
            case 4:
                readFromFile();
                break;
            case 5:
                active = false;
                break;
            default:
                std::cout << "nie ma takiej opcji" << std::endl;
        }
    } while (active);
}

void DynamicArrayClient::printArray() {
    std::cout << "Tablica: ";
    this->array->printArray();
}

void DynamicArrayClient::printMenu() {
    std::cout << "1) dodaj wartosc" << std::endl;
    std::cout << "2) dodaj wartosc na danym indekie" << std::endl;
    std::cout << "3) usun wartosc na danym indeksie" << std::endl;
    std::cout << "4) Wczytaj tablice z pliku" << std::endl;
    std::cout << "5) Wyjdz" << std::endl;
}

void DynamicArrayClient::add() {
    std::cout << "XD";
}

void DynamicArrayClient::addAtIndex() {

}

void DynamicArrayClient::readFromFile() {

}

void DynamicArrayClient::remove() {

}

void DynamicArrayClient::printPlaceholder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Tablica dynamiczna";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

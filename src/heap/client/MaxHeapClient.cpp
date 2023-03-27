#include <iostream>
#include <string>
#include "MaxHeapClient.h"
#include "utils/Utils.h"

void MaxHeapClient::printMenu() {
    std::cout << "1) Dodaj wartosc" << std::endl;
    std::cout << "2) Usun najwieksza wartosc" << std::endl;
    std::cout << "3) Wczytaj kopiec z pliku" << std::endl;
    std::cout << "4) Wyjdz" << std::endl;
}

void MaxHeapClient::startMainLoop() {
    bool active = true;
    int option;
    do {
        printPlaceholder();
        printHeap();
        printMenu();
        std::cin >> option;
        getchar();
        switch (option) {
            case 1:
                addToHeap();
                break;
            case 2:
                removeMaxFromHeap();
                break;
            case 3:
                readHeapFromFile();
                break;
            case 4:
                active = false;
                break;
            default:
                std::cerr << "nie ma takiej opcji" << std::endl;
        }
    } while (active);

}

void MaxHeapClient::addToHeap() {
    using namespace std;
    int value;
    cout << "Podaj liczbe:";
    cin >> value;
    getchar();
    this->heap->insert(value);
}

void MaxHeapClient::printPlaceholder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Maksymalny kopiec binarny";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

MaxHeapClient::MaxHeapClient() {
    this->heap = new MaxHeap();
}

MaxHeapClient::~MaxHeapClient() {
    delete this->heap;
}

void MaxHeapClient::printHeap() {
    this->heap->printHeap();
}

void MaxHeapClient::removeMaxFromHeap() {
    try {
        int value = this->heap->removeMax();
        std::cout << "Usunieto wartosc: " << value << std::endl;
    } catch (std::logic_error &e) {
        std::cerr << "Kopiec jest pusty." << std::endl;
    }
}

void MaxHeapClient::readHeapFromFile() {
    using namespace std;
    string filename;
    cout << "Podaj nazwe pliku:";
    getline(cin, filename);
    try {
        auto *vector = reader::readArrayFromFile(filename);
        delete this->heap;
        this->heap = new MaxHeap();
        for (int value: *vector) {
            this->heap->insert(value);
        }
        delete vector;
    } catch (exception &e) {
        cerr << "Cos poszlo nie tak z wczytaniem pliku" << endl;
    }
}

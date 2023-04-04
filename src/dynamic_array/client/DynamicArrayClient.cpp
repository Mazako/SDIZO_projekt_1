#include <iostream>
#include <string>
#include "DynamicArrayClient.h"
#include "utils/Utils.h"

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
                std::cerr << "nie ma takiej opcji" << std::endl;
        }
    } while (active);
}

void DynamicArrayClient::printArray() {
    std::cout << "Tablica: ";
    this->array->printArray();
}

void DynamicArrayClient::printMenu() {
    std::cout << "1) Dodaj wartosc" << std::endl;
    std::cout << "2) Dodaj wartosc na danym indekie" << std::endl;
    std::cout << "3) Usun wartosc na danym indeksie" << std::endl;
    std::cout << "4) Wczytaj tablice z pliku" << std::endl;
    std::cout << "5) Wyjdz" << std::endl;
}

void DynamicArrayClient::add() {
    using namespace std;
    int value;
    cout << "Podaj liczbe:";
    cin >> value;
    getchar();
    array->add(value);
}

void DynamicArrayClient::addAtIndex() {
    using namespace std;
    int value;
    int index;
    cout << "Podaj liczbe:";
    cin >> value;
    cout << "Podaj indeks:";
    cin >> index;
    getchar();
    try {
        array->addAt(index, value);
    } catch (const invalid_argument& e) {
        cerr << "Podano za duzy indeks" << endl;
    }
}

void DynamicArrayClient::readFromFile() {
    using namespace std;
    cout << "Podaj nazwe pliku:" << endl;
    string filename;
    getline(cin, filename);
    try {
        auto result = sdizoUtils::readArrayFromFile(filename);
        delete this->array;
        this->array = new DynamicArray();
        for (int i: *result) {
            this->array->add(i);
        }
        delete result;
    } catch (exception &) {
        cerr << "cos poszlo nie tak z wczytaniem pliku" << endl;
    }
}

void DynamicArrayClient::remove() {
    using namespace std;
    int index;
    cout << "Podaj indeks do usuniecia:";
    cin >> index;
    getchar();
    try {
        int removed = array->remove(index);
        cout << "Usunieto wartosc " << removed << endl;
    } catch (invalid_argument& e) {
        cerr << "Podano za duzy indeks" << endl;
    }
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

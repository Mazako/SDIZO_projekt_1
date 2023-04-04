#include "DoubleLinkedListClient.h"
#include "utils/Utils.h"
#include <iostream>
DoubleLinkedListClient::DoubleLinkedListClient() {
    this->list = new DoubleLinkedList();
}

DoubleLinkedListClient::~DoubleLinkedListClient() {
    delete this->list;
}

void DoubleLinkedListClient::printMenu() {
    using namespace std;
    cout << "1) Dodaj liczbe na poczatek listy" << endl;
    cout << "2) Dodaj liczbe na koniec listy" << endl;
    cout << "3) Usun liczbe z poczatku listy" << endl;
    cout << "4) Usun liczbe z koncu listy" << endl;
    cout << "5) Dodaj liczbe na podany indeks" << endl;
    cout << "6) Usun liczbe z podanego indeksu" << endl;
    cout << "7) Wczytaj liste z pliku" << endl;
    cout << "8) Wyjdz" << endl;
}

void DoubleLinkedListClient::startMainLoop() {
    bool active = true;
    int option;
    do {
        printPlaceholder();
        printList();
        printMenu();
        std::cin >> option;
        getchar();
        switch (option) {
            case 1:
                addAtStart();
                break;
            case 2:
                addAtEnd();
                break;
            case 3:
                removeFromStart();
                break;
            case 4:
                removeFromEnd();
                break;
            case 5:
                addAnywhere();
                break;
            case 6:
                removeAnywhere();
                break;
            case 7:
                readFromFile();
                break;
            case 8:
                active = false;
                break;
            default:
                std::cout << "nie ma takiej opcji" << std::endl;
        }
    } while (active);
}

void DoubleLinkedListClient::printPlaceholder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Lista podwojnie wiazana";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

}

void DoubleLinkedListClient::printList() {
    using namespace std;
    cout << "Lista: ";
    this->list->printList();
    cout << "Lista odwrocona: ";
    this->list->printReversed();
    cout << endl;
}

void DoubleLinkedListClient::addAtStart() {
    using namespace std;
    int value;
    cout << "Podaj liczbe:";
    cin >> value;
    getchar();
    this->list->push(value);
}

void DoubleLinkedListClient::addAtEnd() {
    using namespace std;
    int value;
    cout << "Podaj liczbe:";
    cin >> value;
    getchar();
    this->list->unshift(value);
}

void DoubleLinkedListClient::removeFromStart() {
    this->list->shift();
}

void DoubleLinkedListClient::removeFromEnd() {
    this->list->pop();
}

void DoubleLinkedListClient::addAnywhere() {
    using namespace std;
    int value;
    int index;
    cout << "Podaj liczbe:";
    cin >> value;
    cout << "Podaj indeks:";
    cin >> index;
    getchar();
    try {
        this->list->addAt(index, value);
    } catch (exception &e) {
        cerr << "Podano zly indeks" << endl;
    }
}

void DoubleLinkedListClient::removeAnywhere() {
    using namespace std;
    int index;
    cout << "Podaj indeks:";
    cin >> index;
    getchar();
    try {
        this->list->removeAt(index);
    } catch (exception &e) {
        cerr << "Podano zly indeks" << endl;
    }
}

void DoubleLinkedListClient::readFromFile() {
    using namespace std;
    cout << "Podaj nazwe pliku:" << endl;
    string filename;
    getline(cin, filename);
    try {
        auto result = sdizoUtils::readArrayFromFile(filename);
        delete this->list;
        this->list = new DoubleLinkedList();
        for (int i : *result) {
            list->push(i);
        }
        delete result;
    } catch (exception &) {
        cerr << "cos poszlo nie tak z wczytaniem pliku" << endl;
    }
}





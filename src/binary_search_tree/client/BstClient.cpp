#include "BstClient.h"
#include <iostream>
#include "utils/Utils.h"

void BstClient::printMenu() {
    std::cout << "1) Dodaj wartosc" << std::endl;
    std::cout << "2) Usun wartosc" << std::endl;
    std::cout << "3) Wczytaj drzewo z pliku" << std::endl;
    std::cout << "4) Wyjdz" << std::endl;

}

void BstClient::startMainLoop() {
    bool active = true;
    int option;
    do {
        printPlaceholder();
        printTree();
        printMenu();
        std::cin >> option;
        getchar();
        switch (option) {
            case 1:
                insertNode();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                readTreeFromFile();
                break;
            case 4:
                active = false;
                break;
            default:
                std::cerr << "nie ma takiej opcji" << std::endl;
        }
    } while (active);


}

void BstClient::printTree() {
    this->bst->printTreeDiagram();
}

void BstClient::printPlaceholder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Binarne drzewo przeszukiwan";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

}

BstClient::BstClient() {
    this->bst = new BinarySearchTree();
}

BstClient::~BstClient() {
    delete this->bst;
}

void BstClient::insertNode() {
    using namespace std;
    int value;
    cout << "Wpisz wartosc:";
    cin >> value;
    this->bst->insertNode(value);
}

void BstClient::deleteNode() {
    using namespace std;
    int value;
    cout << "Wpisz wartosc do usuniecia:";
    cin >> value;
    try {
        this->bst->deleteNode(value);
    } catch (invalid_argument &e) {
        cerr << "Nie znaleziono takiego klucza" << endl;
    }
}

void BstClient::readTreeFromFile() {
    using namespace std;
    string filename;
    cout << "Podaj nazwe pliku:";
    getline(cin, filename);
    try {
        auto *vector = reader::readArrayFromFile(filename);
        delete this->bst;
        this->bst = new BinarySearchTree();
        for (int value: *vector) {
            this->bst->insertNode(value);
        }
        delete vector;
    } catch (exception &e) {
        cerr << "Cos poszlo nie tak z wczytaniem pliku" << endl;
    }

}


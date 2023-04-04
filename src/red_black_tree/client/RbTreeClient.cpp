#include "RbTreeClient.h"
#include <iostream>
#include "utils/Utils.h"

void RbTreeClient::printMenu() {
    std::cout << "1) Dodaj wartosc" << std::endl;
    std::cout << "2) Usun wartosc" << std::endl;
    std::cout << "3) Wczytaj drzewo z pliku" << std::endl;
    std::cout << "4) Wyjdz" << std::endl;

}

void RbTreeClient::startMainLoop() {
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

void RbTreeClient::printTree() {
    this->tree->printTreeDiagram();
}

void RbTreeClient::printPlaceholder() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "Drzewo czerwono-czarne";
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

}

RbTreeClient::RbTreeClient() {
    this->tree = new RedBlackTree();
}

RbTreeClient::~RbTreeClient() {
    delete this->tree;
}

void RbTreeClient::insertNode() {
    using namespace std;
    int value;
    cout << "Wpisz wartosc:";
    cin >> value;
    try {
        this->tree->insert(value);
    } catch (exception &e) {
        cout << "Podana wartosc juz istnieje" << endl;
    }
}

void RbTreeClient::deleteNode() {
    using namespace std;
    int value;
    cout << "Wpisz wartosc do usuniecia:";
    cin >> value;
    try {
        this->tree->deleteNode(value);
    } catch (invalid_argument &e) {
        cerr << "Nie znaleziono takiego klucza" << endl;
    }
}

void RbTreeClient::readTreeFromFile() {
    using namespace std;
    string filename;
    cout << "Podaj nazwe pliku:";
    getline(cin, filename);
    try {
        auto *vector = sdizoUtils::readArrayFromFile(filename);
        delete this->tree;
        this->tree = new RedBlackTree();
        for (int value: *vector) {
            this->tree->insert(value);
        }
        delete vector;
    } catch (exception &e) {
        cerr << "Cos poszlo nie tak z wczytaniem pliku" << endl;
    }

}


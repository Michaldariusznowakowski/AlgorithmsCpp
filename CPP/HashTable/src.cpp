#include <iostream>
#include <string>

class Node {
public:
    std::string Key = "";
    std::string Value = "";
};

class HashTable {
private:
    Node** array;
    unsigned int size = 0;
    unsigned int capacity = 0;
    unsigned int gethash(std::string data) {
        unsigned int key = 0;
        for (char i : (data)) {
            key += i;
        }
        return key % (this->capacity);
    }
    void ExtendCapacity(unsigned int X = 2) {
        unsigned int oldcapacity = this->capacity;
        this->capacity *= X + 1;
        Node** NewArrayCopy = new Node * [oldcapacity];
        Node** NewArray = new Node * [this->capacity];
        for (unsigned int i = 0; i < this->capacity; i++) {
            NewArray[i] = nullptr;
        }
        for (unsigned int i = 0; i < oldcapacity; i++) {
            NewArrayCopy[i] = (this->array)[i];
        }
        this->array = NewArray;
        for (unsigned int i = 0; i < oldcapacity; i++) {
            add(NewArrayCopy[i]);
        }
    }
    void add(Node* Node) {
        unsigned int key = this->gethash(Node->Key);
        if ((this->size) > (this->capacity)) { ExtendCapacity(); }
        unsigned int i = 0;
        for (unsigned int i = 0; i < this->capacity; i++) {
            if ((this->array)[key + i] == nullptr) {
                (this->array)[key + i] = Node;
                break;
            }
            if (i == this->capacity) { ExtendCapacity(); i = 0; }
        }
    }
public:
    unsigned int getHash(std::string data) {
        return gethash(data);
    }
    HashTable(unsigned int c) {
        this->capacity = c;
        (this->array) = new Node * [c];
        for (unsigned int i = 0; i < c; i++) {
            (this->array)[i] = nullptr;
        }
    }
    void clear() {
        for (unsigned int i = 0; i < (this->size); i++) {
            delete (this->array)[i];
        }
    }
    unsigned int getSize(void) {
        return this->size;
    }
    unsigned int getCapacity(void) {
        return this->capacity;
    }
    void add(std::string key, std::string data) {
        Node* newNode = new Node;
        newNode->Key = key;
        newNode->Value = data;
        this->add(newNode);
        (this->size) += 1;
    }
    std::string devOut(void) {
        std::string out = "";
        for (unsigned int i = 0; i < capacity; i++) {
            if (this->array[i] == nullptr) {
                out = out + "ID:" + std::to_string(i) + "\tEmpty\n";
            }
            else {
                out += "ID:" + std::to_string(i) + "\tKey=" + this->array[i]->Key + "\tDATA=" + this->array[i]->Value + "\n";
            }
        }
        return out;

    }
    Node* find(std::string Data) {
        unsigned int hash = gethash(Data);
        
        for (unsigned int i = hash; i < (this->capacity); i++) {
            if ((this->array)[hash] == nullptr) { return nullptr; }
            if ((this->array[hash]->Key) == Data) {
                return (this->array[hash]);
            }
        }
    }

    };
    int main()
    {
        HashTable *Test = new HashTable(8);
        Test->add("Klucz1","Wartosc klucza 1");
        Test->add("Klucz2", "Wartosc klucza 2");
        Test->add("Klucz3", "Wartosc klucza 3");
        Test->add("Klucz4", "Wartosc klucza 4");
        Test->add("Klucz5", "Wartosc klucza 5");
        Test->add("Klucz6", "Wartosc klucza 6");
        Test->add("Klucz7", "Wartosc klucza 7");
        Test->add("Klucz8", "Wartosc klucza 8");
        Test->add("Random1-123adsdsa545", "Wartosc klucza R 1");
        Test->add("Random2-1231123123asdadscx3545", "Wartosc klucza R 2");
        Test->add("Random3-1231123213123545", "Wartosc klucza R 3");
        Test->add("Random4-123123123545", "Wartosc klucza R 4");
        Test->add("Random5-123132412323545", "Wartosc klucza R 5");
        Test->add("Random6-12312asdasdas3545", "Wartosc klucza R 6");
        Test->add("Random7-1231231233545", "Wartosc klucza R 7");
        Test->add("Random8-134xcz23432545", "Wartosc klucza R 8");
        std::cout<<(Test->find("Klucz1")->Value);
        std::cout << std::endl << Test->devOut();
}

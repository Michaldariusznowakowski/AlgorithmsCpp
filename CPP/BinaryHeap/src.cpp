#include <iostream>
#include <string>
class BinaryHeap {
private:
    unsigned int capacity = 0;
    unsigned int size = 0;
    int** array;
    void ExtendCapacity(unsigned int X = 2) {
        unsigned int oldcapacity = this->capacity;
        this->capacity *= X + 1;
        int** NewArray = new int* [this->capacity];
        for (unsigned int i = 0; i < this->capacity; i++) {
            NewArray[i] = nullptr;
        }
        for (unsigned int i = 0; i < oldcapacity; i++) {
            NewArray[i] = (this->array)[i];
        }
        this->array = NewArray;
    }
    void shiftUp(int current) {
        int parent = floor((current - 1) / 2);
        while ((parent >= 0) && (current >= 0) && (*(this->array[parent]) < *(this->array[current]))) {
            int* tmpPtr = (this->array[current]);
            this->array[current] = this->array[parent];
            this->array[parent] = tmpPtr;
            current = parent;
            parent = floor((current - 1) / 2);

        }
    }
    void shiftDown() {
        int* ptr = nullptr;
        unsigned int current = 0;
        unsigned int leftc;
        unsigned int rightc;
        bool correct = false;
        while (!correct) {
            correct = true;
            leftc = floor(2 * current);
            rightc = floor(2 * current + 1);
            if ((leftc < this->size) && (*(this->array[leftc]) < *(this->array[current]))) {
                ptr = array[leftc];
                this->array[leftc] = this->array[current];
                this->array[current] = ptr;
                current = leftc;
                correct = false;
            }
            if ((rightc < this->size) && (*(this->array[rightc]) > *(this->array[current]))) {
                ptr = array[rightc];
                this->array[rightc] = this->array[current];
                this->array[current] = ptr;
                current = rightc;
                correct = false;
            }
        }
    }

public:
    BinaryHeap(unsigned int capacity) {
        this->capacity = capacity;
        this->array = new int* [capacity];
        for (unsigned int i = 0; i < this->capacity; i++) {
            this->array[i] = nullptr;
        }
    }
    std::string devOut(void) {
        std::string out = "\n";
        for (unsigned int i = 0; i < (this->size); i++) {
            out += std::to_string(*(this->array[i])) + "\n";
        }
        return out;
    }
    void insert(int data) {
        if (this->size >= this->capacity) {
            ExtendCapacity();
        }
        int* newdata = new int;
        *newdata = data;
        unsigned int current = (this->size);
        this->array[current] = newdata; // dodaj na koniec
        this->shiftUp(current);
        this->size++;
    }
    int* pop(void) {
        if (this->size == 0) { return nullptr; } //pusta zwróć null
        int* out = this->array[0];
        if (this->size == 1) { this->size--; this->array[0] = nullptr; return out; } // jeden element

        int* ptr=this->array[this->size-1];  // usuń root i wstaw do niego ostatni element
        this->array[this->size-1] = nullptr;
        this->array[0] = ptr;
        this->size--;
        shiftDown();
        return out;
    }
    void clear(void) {
        for (unsigned int i = 0; i < this->size; i++) {
            delete this->array[i];
            this->array[i] = nullptr;
        }
        this->size = 0;
    }
};
int main(){
    BinaryHeap *Test = new BinaryHeap(5);
    unsigned int i[10] = {10,20,30,40,50,60,70,80,90,100 };
    for (unsigned int o : i) {
        Test->insert(o);//std::cout << Test->devOut()<<std::endl;

    }
    std::cout << Test->devOut()<<std::endl;
    std::cout << *(Test->pop())<<std::endl;
    std::cout << Test->devOut()<<std::endl;
}
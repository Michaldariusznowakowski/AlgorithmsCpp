#include <iostream>
#include <string>
#include <time.h>
template <typename T>
class Node {
    public:
        T* Data = nullptr;
        Node* Next = nullptr;
        Node* Prev = nullptr;
        Node(T *Da=nullptr, Node* Ne=nullptr, Node* Pr=nullptr) {
            this->Data = Da;
            this->Next = Ne;
            this->Prev = Pr;
        }
        ~Node() {
            delete this->Data;
        }
};
template <typename T>
class LinkedList {
private:
    char Sorted = -1;
    Node<T>* Head = nullptr;
    Node<T>* Tail = nullptr;
    unsigned long long int Size=0;
public:
    static bool Asc(T F, T S) { if (F > S) { return true; } else { return false; } }
    static bool Desc(T F, T S) { if (F < S) { return true; } else { return false; } }
    char isSorted() { return (this->Sorted); }
    unsigned long long int getSize() { return this->Size; }
    void rmFirst() {
        if ((this->Head) != nullptr) {
            if (Head->Next == nullptr) {
                delete this->Head;
                this->Head = nullptr;
                this->Tail = nullptr;
            }
            else {
                Node<T>* Point = nullptr;
                (this->Head)->Next->Prev = nullptr;
                Point = this->Head;
                this->Head = (this->Head)->Next;
                delete Point;
            }
        }
    }
    void rmLast() {
        if ((this->Tail) != nullptr) {
            if ((this->Tail)->Prev == nullptr) {
                delete this->Tail;
                this->Head = nullptr;
                this->Tail = nullptr;
            }
            else {
                Node<T>* Point = nullptr;
                (this->Tail)->Prev->Next = nullptr;
                Point = (this->Tail);
                this->Tail = (this->Tail)->Prev;
                delete Point;
            }
        }
    }
    void clear() { while ((this->Size)--) { rmLast(); } }
    Node<T>* operator[](unsigned long long int i){
         if (i < (this->Size)) {
             return nullptr;
         }
         else {
             Node<T>* Point = nullptr;
             if ((this->Size) / 2 > i) { // tak -> szukaj od konca, Nie -> szukaj od początku
                 i = (this->Size) - i; // poprawa indeksu, teraz szukamy od konca
                 Point = this->Tail;
                 for (int k = 0; k <= i; k++) {
                     Point = Point->Prev;
                 }
                 return Point;
             }
             else {
                 Point = this->Head;
                 for (int k = 0; k <= i; k++) {
                     Point = Point->Next;
                 }
                 return Point;
             }
         }
    }
   bool set(Node<T>* Point, T Da) {
        if (Point == nullptr) {
            return false;
        }
        else {
            *(Point->Data) = Da;
            return true;
        }
    }
    bool set(unsigned long long int i,T Da) {
         set((this->operator[](i)), Da);
    }
     T* getData(unsigned long long int i=0) { // zwraca dane, jeżeli poza zakresem wywołuje błąd
        if(i > (this->Size)) { throw "Cannot find"; }
        return ((this)[i])->Data;
     }
    void addLast(T Da){
        this->Sorted = -1;
        this->Size++;
        T* Data = new T ;
        *Data = Da;
        Node<T>* Point = new Node<T>(Data);
        if (this->Tail == nullptr) {
            this->Head = Point;
            this->Tail = Point;
        }
        else {
            this->Tail->Next = Point;
            Point->Prev = this->Tail;
            this->Tail = Point;
        }   
    }
    void addFirst(T Da) {
        this->Sorted = -1;
        this->Size++;
        T* Data = new T;
        *Data = Da;
        Node<T>* Point = new Node<T>(Data);
        if (this->Head == nullptr) {
            this->Head = Point;
            this->Tail = Point;
        }
        else {
            this->Head->Prev = Point;
            Point->Next = this->Head;
            this->Head = Point;
        }
    }
    void BubbleSort(bool (*func)(T, T)=Asc) {
        if (func == Asc) { this->Sorted = 1; }
        else { this->Sorted = 2; }
        bool sorted = false;
        Node<T> * Point=(this->Head);
        while (!sorted) {
            Point = (this->Head);
            sorted = true;
            for (int i = 0; i < (this->Size)-1; i++) {
                if ( func(*(Point->Data), *(Point->Next->Data))) {
                    T* Tmp = Point->Data;
                    Point->Data = Point->Next->Data;
                    Point->Next->Data = Tmp;
                    sorted = false;
                }
                Point = Point->Next;
            }
        }
    }
    std::string devOut() {
        if (this->Head == nullptr) {
            throw "List is empty";
        }
        Node<T>* Point = this->Head;
        unsigned long long int lenght = this->Size;
        std::string Output;
        Output += "\n LinkedList DevOut \n";
        Output += "\n Size:" + std::to_string(this->Size);
        for (int i = 0; i < (this->Size); i++){
            if (i % 2 == 0) { Output += "\n"; }
            Output += "\t " + std::to_string(i) + ":" + std::to_string(*(Point->Data));
            Point = Point->Next;
        }
        return Output;
    }
    void addSorted(T Data, bool (*func)(T, T) = Asc) {
        if (this->Head == nullptr) { this->addFirst(Data); return; }
        if ( (this->Sorted == -1) | ((this->Sorted == 2) & (func == Asc)) | ((this->Sorted == 1) & (func == Desc))) {
            this->BubbleSort(func);
        }
        if (func(*(this->Head->Data), Data)) {
            this->addFirst(Data);
        }
        else {
            this->Size++;
            Node <T>* Point = this->Head;
            while (Point->Next != nullptr) {
                if (func(*(Point->Data), Data)) { break; }
                Point = Point->Next;
            }
            T* Da = new T;
            *Da = Data;
            Node <T>* NewNode = new Node<T>(Da);
            NewNode->Prev = Point;
            if (Point->Next != nullptr) { NewNode->Next = Point->Next; }
            Point->Next = NewNode;
        }
        if (func == Asc) { this->Sorted = 1; }else { this->Sorted = 2; }
    }

    LinkedList() {}
    ~LinkedList() {
        this->Clear();
    }
};



int main()
{
    LinkedList<int>* Test = new LinkedList<int>();
    clock_t time = clock();
    Test->addFirst(11);
    clock_t time2 = clock();
    std::cout << "Czas dodania elementu:" << std::to_string(time2-time) << std::endl;
    Test->addFirst(6666);
    Test->addLast(3);
    Test->addLast(2);
    Test->addLast(1);
    std::cout<<Test->devOut();
    time = clock();
    Test->BubbleSort();
    time2 = clock();
    std::cout << std::endl << "Czas sortowania:" << std::to_string(time2-time)<< std::endl;
    Test->addSorted(5);
    std::cout << Test->devOut();
    Test->addSorted(10, LinkedList<int>::Desc);
    std::cout << Test->devOut();
    //Test->BubbleSort(LinkedList<int>::Desc);
    std::cout << Test->devOut();
}


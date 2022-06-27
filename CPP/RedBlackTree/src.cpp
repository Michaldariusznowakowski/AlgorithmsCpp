#include <iostream>
#include <string>
#define BLACK 'B'
#define RED 'R'

template <typename T>
class Node {
public:
    T* Data = nullptr;
    long Key = NULL;
    char Color = BLACK;
    Node <T>* Up = nullptr;
    Node <T>* Left = nullptr;
    Node <T>* Right = nullptr;
    ~Node() {
        if (this->Data != nullptr) {
            delete this->Data;
        }
    }
};
template <typename T>
class BST {
private:
    Node <T>* Root = nullptr;
    Node <T>* insertBst(long InKey,T InData) {
        Node <T>* NewNode = new Node<T>;
        NewNode->Key = InKey;
        T* NewData = new T;
        *NewData = InData;
        NewNode->Data = NewData;
        if (this->Root == nullptr) {
            this->Root = NewNode;
            return NewNode;
        }
        Node <T>* Pointer = this->Root;
        Node <T>* PointerBefore = nullptr;
        bool Left = true; // true left, false right
        while (Pointer!=nullptr) {
            PointerBefore = Pointer;
            if (Pointer->Key == InKey) {
                return nullptr;
            }
            if (Pointer->Key < InKey) {
                Left = true;
                Pointer=Pointer->Left;
            }
            else {
                Left = false;
                Pointer=Pointer->Right;
            }
        }
        if (Left) { PointerBefore->Left = NewNode; }
        else { PointerBefore->Right = NewNode; }
        NewNode->Up = PointerBefore;
        return NewNode;
    }
public:
    Node <T>* getRoot() { return this->Root; }
    bool add(T InData,long InKey) {
        Node <T>* Pointer = insertBst(InKey, InData);
        if (Pointer == nullptr) { return false; }
        Pointer->Color = RED;
	if(Pointer->Up == nullptr){
        if (Pointer->Up == nullptr || Pointer->Up->Up == nullptr) { return true; }
        while ((Pointer != this->Root) && (Pointer->Up->Color == RED)) {
            if ((Pointer->Up->Up!=nullptr)&&(Pointer->Up == Pointer->Up->Up->Left->Left)) {
                if (Pointer->Up->Up->Right->Color == RED) {
                    Pointer->Up->Color = BLACK;
                    Pointer->Up->Up->Right->Color = BLACK;
                        Pointer->Up->Up->Color=BLACK;
                }
            }
            else {
                if (Pointer == Pointer->Up->Right) {
                    rotateLeft(Pointer->Up->Up, Pointer->Up, Pointer);
                    Pointer = Pointer->Up;
                }
                Pointer->Up->Color = BLACK;
                Pointer->Up->Up->Color = RED;
                rotateRight(Pointer->Up->Up->Up, Pointer->Up->Up, Pointer->Up);
            }
        }
    }
    std::string scanPreorder(Node <T>* Ptr) {
        std::string Output = "";
        if (Ptr != nullptr) {
            Output += std::to_string(*(Ptr->Data)) + "\t";
            Output+= scanPreorder(Ptr->Left);
            Output+= scanPreorder(Ptr->Right);
        }
        return Output;
    }
    std::string scanInorder(Node <T>* Ptr) {
        std::string Output = "";
        if (Ptr != nullptr) {
            Output += scanInorder(Ptr->Left);
            Output += std::to_string(*(Ptr->Data)) + "\t";
            Output += scanInorder(Ptr->Right);
        }
        return Output;
    }
    Node <T>* find(long int InKey) {
        bool Found = false;
        Node<T>* Point = this->Root;
        while ((Point != nullptr) & ~Found) {
            if (Point->Key == InKey) {
                Found = true;
            }else if(Point->Key < InKey){
                Point = Point->Right;
            }
            else {
                Point = Point->Left;
            }
        }
        if (Found == false) {
            return nullptr;
        }
        return Point;
    }
    void rotateLeft(Node <T>* Grandfather, Node <T>* Parent, Node<T>* Child) {
        if (Grandfather != nullptr) {
            if (Grandfather->Left == Parent) {
                Grandfather->Left = Child;
            }
            else {
                Grandfather->Right = Child;
            }
        }
        else {
            this->Root = Child;
            Node <T>* Tmp = Child->Left;
            Child->Left = Parent;
            Parent->Right = Tmp;
        }
    }
    void clear(Node <T>* Pointer){
        if (Pointer->Left != nullptr) { clear(Pointer->Left); }
        if (Pointer->Right != nullptr) { clear(Pointer->Right); }
        if (Pointer->Up == nullptr) { this->Root = nullptr; }
        if (Pointer != nullptr) { delete Pointer; };
    }
    long int getHeight(Node <T>* Pointer) {
        if (Pointer == nullptr) { return 0; }
        long int hl = 0;
        long int hr = 0;
        if (Pointer->Right != nullptr) {
            hr = getHeight(Pointer->Right);
        }
        if (Pointer->Left != nullptr) {
            hl = getHeight(Pointer->Left);
        }
        if (hl > hr) {
            return hl + 1;
        }
        else {
            return hr + 1;
        }
    }
    void rotateRight(Node <T>* Grandfather, Node <T>* Parent, Node<T>* Child) {
        if(Grandfather!=nullptr){
            if (Grandfather->Right == Parent) {
                Grandfather->Right = Child;
            }
            else {
                Grandfather->Left = Child;
            }
        }
        else {
            this->Root = Child;
            Node <T>* Tmp = Child->Right;
            Child->Right = Parent;
            Parent->Left = Tmp;
        }
    }
};
int main() {
    BST<int>* Test = new BST<int>;
    Test->add(5,1);
    Test->add(10,3);
    std::cout << Test->scanInorder(Test->getRoot()) << std::endl;
    Test->add(12, 4);
    Test->add(13, 2);
    std::cout << Test->scanInorder(Test->getRoot()) << std::endl;
    Test->add(14, 10);
    Test->add(15, 9);
    std::cout << Test->scanInorder(Test->getRoot()) << std::endl;
    std::cout << "Height:" << Test->getHeight(Test->getRoot());
    return 1;

}
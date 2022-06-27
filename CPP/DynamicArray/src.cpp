#include <iostream>
#include <string>
#include <time.h>
template <typename T>
class DynTab{
    private:
    unsigned int size=0;
    unsigned int capacity=1;
    T* array;
    void ExtendCapacity(unsigned int X=2){
        capacity*=X;
        T* NewArray=new T[capacity];
        for(int i=0;i<size;i++){
        (NewArray)[i]=(this->array)[i];
        }
        delete this->array;
        this->array=NewArray;
    
    }
    public:
    static bool Asc(T F, T S){if(F>S){return true;}else{return false;}}
    static bool Desc(T F, T S){if(F<S){return true;}else{return false;}}
    unsigned int GetCapacity(){return this->capacity;}
    unsigned int GetSize(){return this->size;}
    void AddLast(T A){
        this->size++;
        if(this->size>this->capacity){ExtendCapacity();}
        (this->array)[size]=A;
    }
    T operator[](unsigned int i){
        if(i>size){throw "Could not find element";}
         return (this->array)[i];
    }
    void Set(unsigned int i,T Data){
        while(i >= (this->capacity) ){
            ExtendCapacity();
        }
        for(int o=this->size;o<i;o++){
             (this->array)[o]=0;
        }
         if(i>this->size){this->size=i;}
        (this->array)[i]=Data;
    }
    void Clear(){
        this->capacity=1;
        this->size=0;
        delete this->array;
        this->array=nullptr;
        this->array=new T[capacity];
    }
    std::string DevOut(unsigned int Q){
        if(Q>capacity){throw "Out of range";}
        std::string output;
        output+="\n --------------------------------------------------------------------------------------";
        output+="\n \t Dynamic Table Output";
        output+="\n \t Size:"+std::to_string(this->size)+"\t Capacity:"+std::to_string(this->capacity);
        output+="\n --------------------------------------------------------------------------------------";
        output+="\n \t Printing Content ("+std::to_string(Q)+"): \n";
        for(int i=0,k=1; i<=Q; i++){
            output+=" \t id:"+std::to_string(i)+"="+std::to_string((this->array)[i]);
            if(k>=4){output+="\n";k=1;}else{k++;}
        }
        output+="\n -------------------------------------------------------------------------------------- \n";
        return output;
    }
    void BubbleSort(bool (*func)(T,T)){ //Test->BubbleSort(DynTab<int>::Desc); Test->BubbleSort(DynTab<int>::Asc);
        bool sorted=false;
        T Tmp;
        while(!sorted){
            sorted=true;
            for(int i=0;i<this->size;i++){
                if( func((this->array)[i],(this->array)[i+1])){
                    Tmp=(this->array)[i];
                    (this->array)[i]=(this->array)[i+1];
                    (this->array)[i+1]=Tmp;
                    sorted=false;
                }
            }
        }
    }
    DynTab(){
        this->array=new T[capacity];
    }
    ~DynTab(){
        delete this->array;
    }
};

void Random(int I,DynTab<int> *A){
    const int MAX_R=10000;
    std::srand (time(nullptr));
    for(int k=1; k<=I;k++){
       A->AddLast( (std::rand() % (MAX_R+1))  );
    }
}
void Random(int I,DynTab<char> *A){
    const int ARRAY_SIZE=26;
    std::srand(time(nullptr));
    const char X[ARRAY_SIZE]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int k=1; k<=I;k++){
       A->AddLast( X[(std::rand() % (ARRAY_SIZE+1))] );
    }
}

int main(){
    
   
    try{
        double worst1=0.0;
        DynTab<int>* Test=new DynTab<int>();
        clock_t time = clock();
        Test->AddLast(666);
        clock_t time2 = clock();
        std::cout<<"Losowe 20 elementów int";
       
        Random(20,Test);
        clock_t time3 = clock();
        std::cout<<Test->DevOut(Test->GetSize());
        Test->BubbleSort(DynTab<int>::Asc);
        std::cout<<Test->DevOut(Test->GetSize());
        Test->BubbleSort(DynTab<int>::Desc);
        std::cout<<Test->DevOut(Test->GetSize());
        Test->Clear();
        std::cout<<Test->DevOut(Test->GetSize());
        Test->Set(5,10);
        std::cout<<std::endl;
        std::cout<<(*Test)[5];
        std::cout<<std::endl;
        std::cout<<Test->DevOut(Test->GetSize());
        delete Test;
        Test=nullptr;
        DynTab<char>* TestC=new DynTab<char>();
        std::cout<<"\n Losowe 20 elementów char";
        Random(20,TestC);
        std::cout<<TestC->DevOut(TestC->GetSize());
        TestC->BubbleSort(DynTab<char>::Asc);
        std::cout<<TestC->DevOut(TestC->GetSize());
        TestC->BubbleSort(DynTab<char>::Desc);
        std::cout<<TestC->DevOut(TestC->GetSize());
        TestC->Clear();
        std::cout<<TestC->DevOut(TestC->GetSize());
        TestC->Set(5,109);
        std::cout<<std::endl;
        std::cout<<(*TestC)[5];
        std::cout<<std::endl;
        std::cout<<TestC->DevOut(TestC->GetSize());
        delete TestC;
        TestC=nullptr;
        std::cout<<"\n Dodawanie 1 elementu: "<<std::to_string(time2-time);
        std::cout<<"\n Dodawanie 20 elementu: "<<std::to_string(time3-time2);
    }
    catch(char const* e){
        std::cout<< "\n" << e << "\n";
    }
}
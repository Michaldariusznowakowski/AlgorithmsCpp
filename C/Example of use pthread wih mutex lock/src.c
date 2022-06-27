#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <float.h>

// Globals
struct args {
    size_t first;
    size_t last;
};
char * helpInfo="This program can calculate the value of PI. \n You can see how threads can boost performance of programs. \n Usage: getpi [INTEGER->SERIES] [INTEGER->NUMBER OF THREADS] \n Allowed range:  1 < SERIES < 1000000\n \t\t 1 < THREADS < min(100,n)";
pthread_t threadPid[1000000];
pthread_mutex_t lock;
double sum = 0;

// Function to calculate pi by first and last 
double getPi(size_t first, size_t last){
    double localSum=0;
    for (size_t i = first; i <= last; i++)
    {
        localSum=localSum+(((double)(1))/((double)(i*i)));
    }
    return localSum;
}
// Function to send to threads
void* calcThings(void *input)
{
    pthread_t id = pthread_self();
    size_t first=((struct args*)input)->first;
    size_t last=((struct args*)input)->last;
    free(input);
    printf("Thread #%lu size=%li first=%li \n",id,last-first+1,first);
    double localSum=getPi(first,last);

//  Lock this part ( need to update sum now )
    pthread_mutex_lock(&lock);
    sum=sum+localSum;
    pthread_mutex_unlock(&lock);
    printf("Thread #%lu sum=%f \n", id, localSum);

    return NULL;
}

int main(int argc, char **argv){
//  input data validation 
// only two numbers are allowed
    if(argc != 3){
        fprintf(stderr,"%s \n","Please enter only two integers!");
        fprintf(stderr,"%s \n",helpInfo);
        return -1;

    }
 // lets checkout if there are only digits inside input
    for(int i=1;i<argc;i++){
        for(int j=0;argv[i][j]!='\0';j++){
            if(!isdigit(argv[i][j])){
                fprintf(stderr,"%s \n","Detected unknown character! Expected only digits! ");
                fprintf(stderr,"%s \n",helpInfo);
                return -1;
            }
        }
    }
// we can convert input to variables with 100% sure that will be without errors
    char * pEnd;
    size_t n=0;
    size_t w=0; 
    n=strtol(argv[1],&pEnd,10);
    w=strtol(argv[2],&pEnd,10);
    int min = 100;
//  check if user typed numbers in correct range
    if(n<100){min=n;}
    if ((n < 1) || (n > 1000000) || (w < 1) || (w > (min))){
        fprintf(stderr, "%s \n", "Please enter numbers in correct range!");
        return -1;
    }
//  check if thread amount can be splitted equally
    int err=0;
    int odd=0;
    size_t spc=n/w;
    if(n%w != 0){
        odd=1;
    }else{
        odd=0;
    }
//  it is time to create some threads

    for (size_t i = 0; i < w; i++){
        struct args *ar = (struct args *)malloc(sizeof(struct args)); // we need two variables so we use struct to store first and last number
        if(i==0){ar->first=1;}else{ar->first=spc*i+1;}
        if(odd==1 && i==(w-1)){ar->last=ar->first+spc-1+(n%w);}else{ar->last=ar->first+spc-1;}
       // printf("%li First %li Last %li \n",i,ar->first,ar->last); //dev check
        err = pthread_create(&(threadPid[i]), NULL, &calcThings, (void *)ar);
        if(err != 0){
            fprintf(stderr, "%s %li \n", "Error! Cannot create thread:",i);
            return -1;
        }
    }
    clock_t startTime, endTime;
    double totalTime;
    startTime=clock();
    for (size_t i = 0; i < w; i++){
        err = pthread_join(threadPid[i], NULL);
        if(err != 0){
            fprintf(stderr, "%s %li \n", "Error! Thread is not responding:",i);
            return -1;
        }
    }
    endTime=clock();
    totalTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    sum=sqrt(sum*6);
    printf("w/Threads: PI=%.*e time=%fs\n", 20,sum, totalTime);
    double sum2=0;
    startTime=clock();
    sum2=getPi(1,n);
    sum2=sqrt(sum2*6);
    endTime=clock();
    totalTime=(double)(endTime-startTime)/CLOCKS_PER_SEC;
    printf("wo/Threads: PI=%.*e time=%fs\n", 20,sum2, totalTime);
    if(fabs(sum2-sum)>(double)(0.0000000000000000000001)){fprintf(stderr,"\n%s\n","UNKNOWN ERROR!, results are not the same!");}
    return 0;
}
#include <iostream>
#include <complex>
#include <cmath>
#include <string>
#include <time.h>
double pi = 2*acos(0.0);

std::complex<double>* DFT(double* sequence, size_t lenght){
        using namespace std;
        complex<double> *output = new complex<double>[lenght];
        for (size_t i = 0; i < lenght; i++)
        {
            double imag = 0;
            double real = 0;
            for (size_t n = 0; n < lenght; n++)
            {
                double theta = (2 * pi * i * n / lenght);
                real = real + sequence[n] * cos(theta);
                imag = imag + sequence[n] * sin(-theta);
            }
            output[i] = complex<double>(real, imag);
        }
        return output;
    }

std::complex<double> *FFT(double *sequence, size_t lenght)
{
    using namespace std;
    size_t halfLen = lenght/2;
    complex<double> *output = new complex<double>[lenght];
    if (lenght <= 1) {
        
        for (int i = 0; i < lenght; i++) {
            output[i] = sequence[i];
        }
        return output;
    }
    double *odd = new double[halfLen];
    double *even = new double[halfLen];
    int i = 0;
    int k = 0;
    while(i < lenght){
        odd[k]=sequence[i+1];
        even[k]=sequence[i];
        k++;
        i+=2;
    }

    complex<double> *oddResult = FFT(odd, halfLen);
    complex<double> *evenResult = FFT(even,halfLen);
    
    
    for (size_t i = 0; i < halfLen; ++i){
        double theta =  2* pi *  i / lenght;
        complex<double> x = complex(cos(theta),-sin(theta)) * oddResult[i];
        output[i + halfLen] = evenResult[i] - x; 
        output[i] = evenResult[i] + x;
    }
    return output;
}


void printComplex(std::complex<double>* data, size_t lenght){
    if(data==nullptr || lenght<1){
        fprintf(stderr,"%s \n", "Error cannot printComplex expected data, got nullptr!");
        return;
    }
    for (size_t i = 0; i < lenght; i++)
    {
        printf("(%f)\t+\ti(%f)\n", data[i].real(), data[i].imag());
    }
}

int main(int argc, char const *argv[])
{
    if(argc>1){
        double* input = new double[argc-1];
        for (size_t i = 1; i < argc; i++)
        {
            try
            {
                input[i-1]=atof(argv[i]);       
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        size_t lenght=argc-1;
        std::cout<<"DFT \n";
        time_t clock1=clock();
        std::complex<double>* cdft=DFT(input,lenght);
        time_t clock2=clock();
        printComplex(cdft,lenght);
        double time1 = ( clock1 - clock2 ) / ( double ) CLOCKS_PER_SEC * 1000.0;
        printf ("DFT time [ms] : %f \n", time ) ;
        std::cout<<"FFT \n";
        std::complex<double>* cfft=FFT(input,lenght);
        printComplex(cfft,lenght);;
        double time2 = ( clock1 - clock2 ) / ( double ) CLOCKS_PER_SEC * 1000.0;
        printf ("DFT time [ms] : %f \n", time1 ) ;
        printf ("FFT time [ms] : %f \n", time2 ) ;
        delete[] cfft;
        delete[] cdft; 
        return 0;
    }
    size_t lenght=4444;
    double* f = new double[lenght];
     for (size_t i = 0; i <= lenght; i++)
     {
         f[i]=(double)pow(2,i+1);
         //f[i]=2*i;
     }
        std::cout<<"DFT \n";
        time_t clock1=clock();
        std::complex<double>* cdft=DFT(f,lenght);
        time_t clock2=clock();
        double time1 = ( clock1 - clock2 )  ;
        printComplex(cdft,lenght);
        std::cout<<"FFT \n";
        clock1=clock();
        std::complex<double>* cfft=FFT(f,lenght);
        clock2=clock();
        double time2 = ( clock1 - clock2 ) ;
        printComplex(cfft,lenght);;
        printf ("DFT time [ms] : %f \n", time1 ) ;
        printf ("FFT time [ms] : %f \n", time2 ) ;
        delete[] cfft;
        delete[] cdft; 
    return 0;
}
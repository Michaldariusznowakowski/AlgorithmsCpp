from re import L
from matplotlib import pyplot as plt
import numpy as np
import numpy.fft as fft
#*********************************************************************************************#
# constant
fm=15
fn=fm**2
fs=2*fn
Tc=4

#*********************************************************************************************#

N=Tc*fs # ilość próbek przypadających na cały sygnał
k=np.arange(0,N,1)
t=k/fs 


abc=np.array(['A','B','C'])
#A)1>kA>0   B) 12>kA>2 C) kA>20
kA=np.array([0.5,5,22])
#A)kP<1     B)pi>kP>0  C)kP>2*pi
kP=np.array([0.1,1+np.pi,3*np.pi])
#A)kF<1     B)pi>kF>0  C)kF>2*pi
kF=np.array([0.3,np.pi+1.2,4*np.pi])

#*********************************************************************************************#

def m(t):
    return np.sin(2*np.pi*fm*t)

def plot_data(x,y,title,x_label,y_label):
    plt.close()
    plt.plot(x,y)
    plt.title(title)
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.savefig("./"+title+".png")



def complex_modulo(z):
    return np.sqrt(np.real(z)**2 + np.imag(z)**2)
def convert_to_decibels(z):
    return 10*np.log10(z)

def zA(t,numer,f):
    return (kA[numer]*m(t)+1)*np.cos(2*np.pi*f*t)
def zP(t,numer,f):
    return np.cos(2*np.pi*f*t+kP[numer]*m(t))
def zF(t,numer,f):
    return np.cos(2*np.pi*f*t+(kF[numer]/fm)*m(t))
def getHalf(x):
    return x[:int(len(x)/2)]

#*********************************************************************************************#

#Deklaracja tablicy dla signal N
signal_zA_N, signal_zP_N, signal_zF_N = [],[],[]
#Deklaracja tablicy dla signal M
signal_zA_M, signal_zP_M, signal_zF_M = [],[],[] 
for i in range(0,3):
##### Sygnał Obliczanie dla N
    signal_zA_N.append(zA(t,i,fn))
    signal_zP_N.append(zP(t,i,fn))
    signal_zF_N.append(zF(t,i,fn))
##### Sygnał Obliczanie dla M
    signal_zA_M.append(zA(t,i,fm))
    signal_zP_M.append(zP(t,i,fm))
    signal_zF_M.append(zF(t,i,fm))

#*********************************************************************************************#

#Deklaracja tablicy dla fft M
fft_zA_M, fft_zP_M, fft_zF_M = [],[],[] 
#Deklaracja tablicy dla fft N
fft_zA_N, fft_zP_N, fft_zF_N = [],[],[]
for i in range(0,3):
#### FFT Obliczanie dla N
    fft_zA_M.append(fft.fft(signal_zA_M[i]))
    fft_zP_M.append(fft.fft(signal_zP_M[i]))
    fft_zF_M.append(fft.fft(signal_zF_M[i]))
#### FFT Obliczanie dla M
    fft_zA_N.append(fft.fft(signal_zA_N[i]))
    fft_zP_N.append(fft.fft(signal_zP_N[i]))
    fft_zF_N.append(fft.fft(signal_zF_N[i]))

#*********************************************************************************************#

#Deklaracja tablicy dla widmo N
widmo_zA_N, widmo_zP_N, widmo_zF_N = [],[],[]
#Deklaracja tablicy dla widmo M
widmo_zA_M, widmo_zP_M, widmo_zF_M = [],[],[]
for i in range(0,3):
# Widmo w decybelach Obliczenia dla N
    widmo_zA_N.append(convert_to_decibels(complex_modulo(getHalf(fft_zA_N[i]))))
    widmo_zP_N.append(convert_to_decibels(complex_modulo(getHalf(fft_zP_N[i]))))
    widmo_zF_N.append(convert_to_decibels(complex_modulo(getHalf(fft_zF_N[i]))))
#### Widmo w decybelach Obliczenia dla M
    widmo_zA_M.append(convert_to_decibels(complex_modulo(getHalf(fft_zA_M[i]))))
    widmo_zP_M.append(convert_to_decibels(complex_modulo(getHalf(fft_zP_M[i]))))
    widmo_zF_M.append(convert_to_decibels(complex_modulo(getHalf(fft_zF_M[i]))))

#*********************************************************************************************#

#dziedzina 
fk=getHalf(k)

#*********************************************************************************************#
def getBandwidth(x,y,db):
    yMax=max(y)
    zakres=[]
    for i in x:
        if y[i]>=yMax-db and y[i]<=yMax:
            zakres.append(i)
    fmin=9999
    fmax=-99999
    for i in range(0,len(zakres)):
        if x[zakres[i]]<fmin:
            fmin=x[zakres[i]]
        if x[zakres[i]]>fmax:
            fmax=x[zakres[i]]
    if(fmin==9999 or fmax==-99999):
        return "Brak"
    return str(fmax-fmin)
    
##remove first element of list
#for i in range(0,3):
#    widmo_zA_N[i]=widmo_zA_N[i][1:]
#    widmo_zP_N[i]=widmo_zP_N[i][1:]
#    widmo_zF_N[i]=widmo_zF_N[i][1:]
#    widmo_zA_M[i]=widmo_zA_M[i][1:]
#    widmo_zP_M[i]=widmo_zP_M[i][1:]
#    widmo_zF_M[i]=widmo_zF_M[i][1:]
#fk=fk[1:]


for i in range(0,3):
#### PLOT dla N
    plot_data(fk,widmo_zA_N[i],abc[i]+") widmo_zA_N 3db_"+getBandwidth(fk,widmo_zA_N[i],3)+" 6db_"+getBandwidth(fk,widmo_zA_N[i],6)+" 12db_"+ getBandwidth(fk,widmo_zA_N[i],12),'[f]','[dB]')
    plot_data(fk,widmo_zP_N[i],abc[i]+") widmo_zP_N 3db_"+getBandwidth(fk,widmo_zP_N[i],3)+" 6db_"+getBandwidth(fk,widmo_zP_N[i],6)+" 12db_"+ getBandwidth(fk,widmo_zP_N[i],12),'[f]','[dB]')
    plot_data(fk,widmo_zF_N[i],abc[i]+") widmo_zF_N 3db_"+getBandwidth(fk,widmo_zF_N[i],3)+" 6db_"+getBandwidth(fk,widmo_zF_N[i],6)+" 12db_"+ getBandwidth(fk,widmo_zF_N[i],12),'[f]','[dB]')

#### PLOT dla M
    plot_data(fk,widmo_zA_M[i],abc[i]+") widmo_zA_M 3db_"+getBandwidth(fk,widmo_zA_M[i],3)+" 6db_"+getBandwidth(fk,widmo_zA_M[i],6)+" 12db_"+ getBandwidth(fk,widmo_zA_M[i],12),'[f]','[dB]')
    plot_data(fk,widmo_zP_M[i],abc[i]+") widmo_zP_M 3db_"+getBandwidth(fk,widmo_zP_M[i],3)+" 6db_"+getBandwidth(fk,widmo_zP_M[i],6)+" 12db_"+ getBandwidth(fk,widmo_zP_M[i],12),'[f]','[dB]')
    plot_data(fk,widmo_zF_M[i],abc[i]+") widmo_zF_M 3db_"+getBandwidth(fk,widmo_zF_M[i],3)+" 6db_"+getBandwidth(fk,widmo_zF_M[i],6)+" 12db_"+ getBandwidth(fk,widmo_zF_M[i],12),'[f]','[dB]')
    
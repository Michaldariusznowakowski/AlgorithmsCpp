from os import times
import numpy as np
from matplotlib import pyplot as plot
import threading
import time

def dftMT(Arr):
    lock = threading.Lock()
    ArrLen=len(Arr)
    output=np.ndarray(ArrLen, dtype=np.complex128)
    t=[]
    for i in range(0,ArrLen,1):
        t.append(threading.Thread(target=dftForK,args=(Arr,i,output,lock)))
        t[i].start()
    for i in range(0,ArrLen,1):
        t[i].join()
    return output
def dftForK(Arr,k,output,lock):
    ArrLen=len(Arr)
    n=np.arange(0,ArrLen,1)
    out=(np.sum(Arr*np.e**(-2j*np.pi*k*n/ArrLen)))
    lock.acquire()
    output[k]=out
    lock.release()
def dft(Arr):
    ArrLen=len(Arr)
    tmp2=[]
    for k in range(0,ArrLen):
        tmp=0
        for n in range(0,ArrLen):
            tmp=tmp+(Arr[n]*np.e**(-2j*np.pi*k*n/ArrLen))
        tmp2.append(tmp)
    return tmp2 
def complex_modulo(z):
    return np.sqrt((np.real(z)**2+np.imag(z)**2))
def convert_to_decibels(z):
    return 10*np.log10(z)
Tc=1 #czas
#fs=53 #częstotliwość
f=53 # zmienna wlasna
fs=1000
N=Tc*fs # ilość próbek przypadających na cały sygnał
k=np.arange(0,N+1,1)
def x(t):
    return np.sin(2*np.pi*f*t)
t=k/fs 
Y=x(t)
X=t
tStart=time.time()
ArrDft=dft(Y)
tEnd=time.time()
kLast=int(N/2-1)
kh=np.arange(0,kLast,1,dtype=int)
ArrDft=ArrDft[:kLast]
ArrCM=complex_modulo(ArrDft)
ArrDB=convert_to_decibels(ArrCM)
fig , (ax1, ax2,ax3) = plot.subplots(3)
fig.set_size_inches(10,10)
fig.suptitle("Cwiczenie 2 Bez wielu wątków sekundy->"+str(tEnd-tStart)) 
ax3.set_ylabel("Magnitude DB") 
ax3.set_xlabel("Frequency [Hz]") 
ax3.plot(kh,ArrDB) 
ax2.set_ylabel("Magnitude") 
ax2.set_xlabel("Frequency [Hz]") 
ax2.plot(kh,ArrCM) 
ax1.plot(X,Y) 
ax1.set_ylabel("Amplitude") 
ax1.set_xlabel("Time") 
plot.show()
plot.close()

tStart=time.time()
ArrDft=dftMT(Y)
tEnd=time.time()
kLast=int(N/2-1)
kh=np.arange(0,kLast,1,dtype=int)
ArrDft=ArrDft[:kLast]
ArrCM=complex_modulo(ArrDft)
ArrDB=convert_to_decibels(ArrCM)

fig , (ax1, ax2,ax3) = plot.subplots(3)
fig.suptitle("Cwiczenie 2  wiele wątków sekundy->"+str(tEnd-tStart)) 
fig.set_size_inches(10,10)
ax3.set_ylabel("Magnitude DB") 
ax3.set_xlabel("Frequency [Hz]") 
ax3.plot(kh,ArrDB) 
ax2.set_ylabel("Magnitude") 
ax2.set_xlabel("Frequency [Hz]") 
ax2.plot(kh,ArrCM) 
ax1.plot(X,Y) 
ax1.set_ylabel("Amplitude") 
ax1.set_xlabel("Time") 
plot.show()

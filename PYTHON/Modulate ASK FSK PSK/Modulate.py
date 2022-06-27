import numpy as np
class Modulate:
    def __init__(self,A1,A2,Tb,fs,fn,fn1,fn2):
        self.A1=A1
        self.A2=A2
        self.Tb=Tb
        self.fs=fs
        self.fn=fn
        self.fn1=fn1
        self.fn2=fn2
        
    def toAsk(self,b):
        Tc=len(b)*self.Tb
        k=np.arange(1,(Tc*self.fs)+1,1)
        t=k/self.fs
        PointsInOneBit=int(self.Tb*self.fs) # to int

        output=[]
        i=0
        for bit in b:
            if(bit==1):
                for _ in range(PointsInOneBit):
                    output.append(self.A2*np.sin(2*np.pi*self.fn*t[i]))
                    i+=1
            if(bit==0):
                for _ in range(PointsInOneBit):
                    output.append(self.A1*np.sin(2*np.pi*self.fn*t[i]))
                    i+=1

        return output
    def toFSK(self,b):
        Tc=len(b)*self.Tb
        k=np.arange(1,(Tc*self.fs)+1,1)
        t=k/self.fs
        PointsInOneBit=int(self.Tb*self.fs)
        output=[]
        i=0
        for bit in b:
            if(bit==1):
                for _ in range(PointsInOneBit):
                    output.append(np.sin(2*np.pi*self.fn2*t[i]))
                    i+=1
            if(bit==0):
                for _ in range(PointsInOneBit):
                    output.append(np.sin(2*np.pi*self.fn1*t[i]))
                    i+=1
        return output
    def toPSK(self,b):
        Tc=len(b)*self.Tb
        k=np.arange(1,(Tc*self.fs)+1,1)
        t=k/self.fs
        PointsInOneBit=int(self.Tb*self.fs)
        output=[]
        i=0
        for bit in b:
            if(bit==1):
                for _ in range(PointsInOneBit):
                    output.append(np.sin(2*np.pi*self.fn*t[i]+np.pi))
                    i+=1
            if(bit==0):
                for _ in range(PointsInOneBit):
                    output.append(np.sin(2*np.pi*self.fn*t[i]))
                    i+=1
        return output

    def pskToBits(self,data,SkipFilter=False,SkipIntegral=False):
        lenData=len(data)
        t=np.arange(1,lenData+1,1)/self.fs
        wzorcowy=self.A1*np.sin(2*np.pi*self.fn*t)
        sygnal=data*wzorcowy
        if SkipIntegral:
            return sygnal
        integral=[]
        pointsForBit=int(self.Tb*self.fs)
        i=0
        while i < lenData:
            tmp=[]
            tmpTime=[]
            for _ in range(pointsForBit):
                tmp.append(sygnal[i])
                tmpTime.append(t[i])
                i+=1
            integral.append(np.trapz(tmp,tmpTime))
        if SkipFilter:
            return integral
        output=[]
        for i in integral:
            if i<0:
                output.append(1)
            else:
                output.append(0)
        return output
    def askToBits(self,data,SkipFilter=False,SkipIntegral=False):
        lenData=len(data)
        t=np.arange(1,lenData+1,1)/self.fs
        wzorcowy=self.A1*np.sin(2*np.pi*self.fn*t)
        sygnal=data*wzorcowy
        if SkipIntegral:
            return sygnal
        integral=[]
        pointsForBit=int(self.Tb*self.fs)
        i=0
        while i < lenData:
            tmp=[]
            tmpTime=[]
            for _ in range(pointsForBit):
                tmp.append(sygnal[i])
                tmpTime.append(t[i])
                i+=1
            integral.append(np.trapz(tmp,tmpTime))
        if SkipFilter:
            return integral
        h=np.mean(integral)
        output=[]
        for i in integral:
            if i>h:
                output.append(0)
            else:
                output.append(1)
        return output
    def fskToBits(self,data,SkipFilter=False,SkipIntegral=False):
        lenData=len(data)
        t=np.arange(1,lenData+1,1)/self.fs
        wzorcowy=self.A1*np.sin(2*np.pi*self.fn1*t)
        wzorcowy2=self.A1*np.sin(2*np.pi*self.fn2*t+np.pi)
        sygnal=data*wzorcowy
        sygnal2=data*wzorcowy2
        if SkipIntegral:
            return sygnal,sygnal2
        integral=[]
        integral2=[]
        pointsForBit=int(self.Tb*self.fs)
        i=0
        while i < lenData:
            tmp=[]
            tmp2=[]
            tmpTime=[]
            for _ in range(pointsForBit):
                tmp.append(sygnal[i])
                tmp2.append(sygnal2[i])
                tmpTime.append(t[i])
                i+=1
            integral.append(np.trapz(tmp,tmpTime))
            integral2.append(np.trapz(tmp2,tmpTime))

            sumOfintegral=integral*-1+integral2
        if SkipFilter:
            return sumOfintegral
        output=[]
        for i in sumOfintegral:
            if i>0:
                output.append(0)
            else:
                output.append(1)
        return output

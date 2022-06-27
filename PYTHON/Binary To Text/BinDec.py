import numpy as np
class BinDec:
    def encode(self,string):
        char=''
        charDec=0
        lista=[]
        cBin=0
        for c in string:
            charDec=ord(c)
            if charDec>32 and charDec<127:
                cbin=bin(charDec)[2:]
                for i in cbin:
                    lista.append(int(i))
        return lista
    def decode(self,arr):
        out=""
        bin=""
        tmp=0
        for i in arr:
            bin+=str(i)
            tmp+=1
            if tmp ==7:
                if(np.sum(tmp)==0):
                    bin=""
                    tmp=0
                    continue
                try:
                    out+=chr(int(bin,2))
                except:
                    return "ERROR"
                bin=""
                tmp=0

        return out


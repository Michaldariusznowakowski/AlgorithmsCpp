import numpy as np
class Hamming:
    def _matrixOfBits(self,numOftestBits):
        matrixofBits=np.zeros((2**numOftestBits-1,numOftestBits))
        for i in range(0,2**numOftestBits-1,1):
            b=bin(i+1)[2:]
            x=[]
            for j in range(0,len(b),1):
                x.insert(0,int(b[j]))
            for j in range(0,len(x),1):
                matrixofBits[i][j]=int(x[j])
        matrixofBits=matrixofBits.astype(int)
        return matrixofBits
    def _xor(self,a,b):
        if a==b:
            return 0
        else:
            return 1
    def _numOftestBits(self,lenBits):
        numOftestBits=[]
        for i in range(0,lenBits,1):
            if 2**i <= lenBits:
                numOftestBits.append((2**i)-1)
        return numOftestBits
    def _getC(self,numOftestBits,bits,matrixofBits,Skip_C_Assign=False):
        if Skip_C_Assign==False:
            tmp=0
            c=np.zeros(len(numOftestBits)+len(bits))
            for i in range(0,len(c),1):
                if np.isin(i,numOftestBits):
                    c[i]=-1
                else: 
                    c[i]=bits[tmp]
                    tmp+=1
        else:
            c=np.copy(bits)


        next=0
        for i in range(0,len(c),1):
            if np.isin(i,numOftestBits) == False:
                    continue
            tmp=-1
            for j in range(0,len(c),1):
                if np.isin(j,numOftestBits):
                    continue
                if(matrixofBits[j][next]==1):             
                    if tmp==-1:
                        tmp=c[j]
                    else:
                        tmp=self._xor(tmp,c[j])
            c[i]=int(tmp)
            next+=1
        return c
    def encode_multiple(self,bits):
        tmp=[]
        output=[]
        out=[]
        j=0
        #copy bits to bitsC numpy
        bitsC=bits[:]
        while len(bitsC)%11 != 0:
            bitsC.append(0)
        for i in range(0,len(bitsC),1):
            tmp.append(bitsC[i])
            if j==10:
                j=0
                output.append(self.encode(tmp))
                tmp.clear()
            else:
                j+=1
        for i in range(0,len(output),1):
            for j in range(0,len(output[i]),1):
                out.append(int(output[i][j]))
        return out
    def decode_multiple(self,bits):
        tmp=[]
        output=[]
        out=[]
        j=0
        for i in range(0,len(bits),1):
            tmp.append(bits[i])
            if j==14:
                j=0
                output.append(self.decode(tmp))
                tmp.clear()
            else:
                j+=1
        for i in range(0,len(output),1):
            for j in range(0,len(output[i]),1):
                out.append(int(output[i][j]))
        while len(out)%7 != 0:
            out.pop()
        
        return out
    def encode(self,bits):
        numOftestBits=self._numOftestBits(len(bits))
        matrixofBits=self._matrixOfBits(len(numOftestBits))
        return self._getC(numOftestBits,bits,matrixofBits)

    def decode(self,bits,SkipToBitsConvert=False):
        numOftestBits=self._numOftestBits(len(bits))
        matrixofBits=self._matrixOfBits(len(numOftestBits))
        C=self._getC(numOftestBits,bits,matrixofBits,Skip_C_Assign=True)
        tmp=0
        j=0
        for i in range(0,len(C),1):
            if np.isin(i,numOftestBits)==False:
                continue
            else:
                tmp+=self._xor(C[i],bits[i])*2**j
                j+=1
        tmp=tmp-1
        max=0
        for i in range(0,len(numOftestBits),1):
            max+=1*2**i
        if tmp<max and tmp< len(bits) and tmp>=0:
            if bits[tmp]==1:
                bits[tmp]=0
            else:
                bits[tmp]=1
        if SkipToBitsConvert==True:
            return C
        output=[]
        for i in range(0,len(C),1):
            if np.isin(i,numOftestBits):
                continue
            else:
                output.append(int(bits[i]))
        return output
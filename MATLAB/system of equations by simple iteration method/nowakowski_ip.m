function [output] = nowakowski_ip(A,B,ACCURACY,VECTOR_START)
dlugosc=length(A);
for i=1:dlugosc
        B(i,:)=B(i,:)/A(i,i);
    A(i,:)=A(i,:)/A(i,i);

    A(i,i)=0;
end
W=-A;
Z=B;
X0=VECTOR_START;
FLAG=1;
while FLAG==1
    X1=W*X0+Z;
    if norm(X1-X0)<ACCURACY
    FLAG=0;
    end
    X0=X1;
end
output=X1;
end


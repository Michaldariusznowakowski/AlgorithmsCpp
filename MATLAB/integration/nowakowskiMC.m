function [s] = nowakowskiMC(xp,xk,yp,yk,n,fx)
%NOWAKOWSKICALKI
%wejscie
%xp poczatek przedzialu 
%xk koniec przedzialu
%n liczba strzałów
%fx funkcja rzeczywiska
%wyjście
%s pole
s=0;
gesty=[xp:0.1:xk];
plot(gesty,fx(gesty),'r');
hold on

strzalyX=xp+(xk-xp)*rand(n,1);
strzalyY=yp+(yk-yp)*rand(n,1);

for i=1:1:n
if ((0<strzalyY(i)) && (strzalyY(i)<fx(strzalyX(i)) ))
    s=s+1;
    plot(strzalyX(i),strzalyY(i),'*b');
elseif ((0>strzalyY(i)) && (strzalyY(i)>fx(strzalyX(i)) ) )
    plot(strzalyX(i),strzalyY(i),'*r');
    s=s-1;
else
    plot(strzalyX(i),strzalyY(i),'*g');
end
end
s=(abs(xk-xp)*abs(yk-yp))*(s/n);
hold off
end




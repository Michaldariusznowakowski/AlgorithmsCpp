function [s] = nowakowskiTRAPEZY(xp,xk,n,fx)
%wejscie
%xp poczatek przedzialu calkowania
%xk koniec przedzialu calkowania
%n liczba punktów przedziałowych
%fx funkcja rzeczywista
%wyjście
%s pole

s=0;
dx=(xk-xp)/n;
for i=1:1:n
s=s+fx(xp+i*dx);
end
s=(s+ ( (fx(xp)+fx(xk))/2 ) )*dx;
end
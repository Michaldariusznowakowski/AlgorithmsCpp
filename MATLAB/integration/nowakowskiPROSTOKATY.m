function [s] = nowakowskiPROSTOKATY(xp,xk,n,fx)

%wejscie
%xp poczatek przedzialu calkowania
%xk koniec przedzialu calkowania
%n liczba punktów przedziałowych
%fx funkcja rzeczywiska z której liczymy całke
%wyjście
%s pole

s=0;
h=zeros(n);
dx=(xk-xp)/n;
for i=1:1:n
h(i)=(fx(xp+i*dx));
s=s+(dx*h(i));
end

gesty=[xp:0.1:xk];
plot(gesty,fx(gesty),'r');
hold on
szerokosc=(xp);
 for i=1:1:n
     line([szerokosc,szerokosc+dx],[h(i),h(i)]); %gora
     line([szerokosc,szerokosc+dx],[0,0]); %dol
     line([szerokosc,szerokosc],[0,h(i)]); %lewo
     line([szerokosc+dx,szerokosc+dx],[0,h(i)]);%prawo
     szerokosc=(xp+i*dx);
 end
 hold off
end
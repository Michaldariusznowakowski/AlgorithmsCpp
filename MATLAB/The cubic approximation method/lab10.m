clc;
clear all;
close all;
%fun = @(x) x.^2; % wzór funkcji
fun = @(x) (1/3).*(x-3).^3+(x-4).^2 % wzór funkcji
%fun = @(x) (1/3)*x.^2-(13/7).*x+11; % wzór funkcji
%df = @(x,h) %wzór na I pochodną - jeśli jest potrzebny
%d2f = @(x,h) %wzór na II pochodną - jeśli jest potrzebny
a = 0; %lewa granica przedziału
b = 10; %prawa granica przedziału
%h = 1/2^3; %krok do obliczania pochodnych - jeśli potrzebny
%dok = 1/2^5; %dokładność - potrzebna do zatrzymania algorytmu
%w tym miejscu wstaw algorytm poszukiwania minimum
[x,i]=szescienna_nowakowski(a,b,fun);
% i – licznik iteracji
% x – wektor, w którym przechowywane są kolejne rozwiązania – współrzędna
%x, ale nie wartości funkcji (!)
disp('iteracje')
disp(i)
disp('min wartosc funkcji')
%disp(f(x(end)))
 figure
 xx=a:1:b;
 plot(fun(xx))
 figure
 plot(fun(x),'rd')
 %axis([1,i, min(fun(x)), max(fun(x))]) %dopasowanie zakresów osi
 xlabel('Iteracje')
 ylabel('Wartość funkcji')
 title(['Wartość funkcji w x_min',num2str(fun(x(end)))]),
 %x0=1;
 %options = optimset('PlotFcns',@optimplotfval);
 %x_test = fminsearch(fun,x0, options)

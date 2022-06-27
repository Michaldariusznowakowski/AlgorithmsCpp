clc;
close all;
clear;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Wybierz wzor 

%f=@(x) x^2-2;
%fy=@(x) x^2-2;
%ftol=0.001;
%a=-5;
%b=0;

fy=@(x) sin(x.^2-x+1/3)+x/2
f=@(x) sin(x^2-x+1/3)+x/2;
a=-2;
b=0;
ftol=0.001;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% cz1
%czy szerokość przedziału wpływa na szybkość działania i liczbę iteracji w metodzie
%bisekcji?
% Większa szerokość wpływa na zwiększenie iteracji i wolniejsze wykonanie
% algorytmu

% czy wybór punktu startowego wpływa na szybkość działania i liczę iteracji w metodzie
%Newtona?
% tak wpływa

% która z metod jest szybsza?
%Szybsza metoda jest newton
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

x=a:0.001:b;
y=fy(x);
plot(x,y);
hold on
hline = refline(0, 0);
hline.Color = 'k';
disp("BISEkCJA")
[x_b,n_b,czas_b]=nowakowski_bisekcja(f,a,b,ftol);
plot(x_b,f(x_b),'r*')
disp("x_b znaleziony pierwiastek") 
disp(x_b)
disp("n_b liczba iteracji potrzebna do znalezienia") 
disp(n_b)
disp("czas_b czas poszukiwania pierwiastka")
disp(czas_b)
hold off
disp("WCIŚNIJ ENTER ABY KONTYNUOWAĆ") % wciśnij enter aby pokazać wynik dla metody falsi
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp("FALSI")
[x_b,n_b,czas_b]=nowakowski_falsi(f,a,b,ftol);

x=a:0.1:b;
y=fy(x);
plot(x,y);
hold on
hline = refline(0, 0);
hline.Color = 'k';
plot(x_b,f(x_b),'r*')
disp("x_b znaleziony pierwiastek") 
disp(x_b)
disp("n_b liczba iteracji potrzebna do znalezienia") 
disp(n_b)
disp("czas_b czas poszukiwania pierwiastka")
disp(czas_b)
hold off

%%%%%%%%%%%%%%%%%%%%%%%%%%% odpo cz 2
%czy szerokość przedziału wpływa na szybkość działania i liczbę iteracji w metodzie
%regula falsi i w metodzie siecznych?
%Tak wpływa na szybkość działalnia i liczbę iteracji w obu metodach

%• która z metod jest szybsza?
% szybszą metodą jest metoda siecznych

%dla f = @(x)x.^2-2
% x_s =
% -1.4142
% n_s =
% 9
% czas_s =
% 5.7000e-06
% A
% x_r =
% -1.4140
% n_r =
% 16
% czas_r =
% 4.9200e-05

%f = @(x)sin(x.^2-x+(1/3))+(x/2)
% x_s =
% -1.0778
% n_s =
% 6
% czas_s =
% 1.2200e-05
% A
% x_r =
% -1.0780
% n_r =
% 2166
% czas_r =
% 0.0012

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear;
clc;
close all;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% W programie użyto polecenia pause aby powoli    %
% zaobserować wyniki każdego polecenia            %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                  Zadanie 1                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
xg=[-10,-8,-6,-4,-0.9,-1,0,1,0.9,4,6,8,10];
yg=[0,2,4,2,2,4,3,4,2,2,4,2,0];
xd=[-10,-5,0,5,10];
yd=[0,-1,-4,-1,0];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
xp=-10; % początek przedzialu
xk=10; % koniec przedzialu
n=1; % ilosc
fg=@(x)interp1(xg,yg,x,'linear'); % funkcja górna
fd=@(x)interp1(xd,yd,x,'linear'); % funkcja dolna
s=nowakowskiPROSTOKATY(xp,xk,n,fg); % wynik dla górnej funkcji
hold on
s2=nowakowskiPROSTOKATY(xp,xk,n,fd); % wynik dla dolnej funkcji
disp("Prostokaty dla 1")
disp(s+abs(s2)) % pole po sumie obu funkcji
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
n=10; % ilosc
fg=@(x)interp1(xg,yg,x,'linear'); % funkcja górna
fd=@(x)interp1(xd,yd,x,'linear'); % funkcja dolna
s=nowakowskiPROSTOKATY(xp,xk,n,fg); % wynik dla górnej funkcji
hold on
s2=nowakowskiPROSTOKATY(xp,xk,n,fd); % wynik dla dolnej funkcji
disp("Prostokaty dla 10")
disp(s+abs(s2)) % pole po sumie obu funkcji
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
strzaly=100
yp=0;   %początek y
yk=4;   %koniec y
s=nowakowskiMC(xp,xk,yp,yk,strzaly,fg); % pole góry
hold on
yp=-4;
yk=0;
s2=nowakowskiMC(xp,xk,yp,yk,strzaly,fd); % pole dołu
disp("MC dla 100")
disp(s+abs(s2));    % suma pól 
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
strzaly=500
yp=0;   %początek y
yk=4;   %koniec y
s=nowakowskiMC(xp,xk,yp,yk,strzaly,fg); % pole góry
hold on
yp=-4;
yk=0;
s2=nowakowskiMC(xp,xk,yp,yk,strzaly,fd); % pole dołu
disp("MC dla 500")
disp(s+abs(s2));    % suma pól 
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp("Wciśnij enter aby przejść do rozwiązania zadania nr 2")
pause;
close all;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                  Zadanie 2                      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                 %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp("MC")
s=nowakowskiMC(-pi,pi,-pi,pi,1,@(x) sin(x) );
disp("Strzały 1")
disp(s)
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
s=nowakowskiMC(-pi,pi,-pi,pi,10,@(x) sin(x) );
disp("Strzały 10")
disp(s)
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
s=nowakowskiMC(-pi,pi,-pi,pi,100,@(x) sin(x) );
disp("Strzały 100")
disp(s)
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
s=nowakowskiMC(-pi,pi,-pi,pi,1000,@(x) sin(x) );
disp("Strzały 1000")
disp(s)
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all;
disp("Trapezy")
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
k=nowakowskiTRAPEZY(0,pi,1,@(x) sin(x));
k2=nowakowskiTRAPEZY(-pi,0,1,@(x) sin(x));
disp("krok 1")
disp(single(k)+single(k2))
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
k=nowakowskiTRAPEZY(0,pi,10,@(x) sin(x));
k2=nowakowskiTRAPEZY(-pi,0,10,@(x) sin(x));
disp("krok 10")
disp(single(k)+single(k2))
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
k=nowakowskiTRAPEZY(0,pi,20,@(x) sin(x));
k2=nowakowskiTRAPEZY(-pi,0,20,@(x) sin(x));
disp("krok 20")
disp(single(k)+single(k2))
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
k=nowakowskiTRAPEZY(0,pi,30,@(x) sin(x));
k2=nowakowskiTRAPEZY(-pi,0,30,@(x) sin(x));
disp("krok 30")
disp(single(k)+single(k2))
pause;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Przy dodawaniu czasami pojawia się             %
%  błąd związany z liczbą zmiennoprzecinkową      %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
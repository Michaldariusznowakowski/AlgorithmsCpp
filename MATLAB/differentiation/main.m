clc;
clear;
close all;
disp("Zadanie 1")
df=@(x)-2*sin(2*x);
xdf=0:0.001:6;
ydf=df(xdf);
f=@(x) cos(2*x);
def=@(x,h)( f(x+h)-f(x) )/(h);
trzy=@(x,h)( f(x+h)-f(x-h) )/(2*h);
piec=@(x,h)( -1*f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h) )/(12*h);

%%%%%%%%%%%%%%%%Zadanie 1 
%%%%%%%%%%%%%%%%
subplot(3,3,1)
hold on
h=1;
x=0:h:6;
y=def(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '2pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);

%%%%%%%%%%%%%%%%
subplot(3,3,2)
hold on
h=0.5;
x=0:h:6;
y=def(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '2pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,3)
hold on
h=0.25;
x=0:h:6;
y=def(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '2pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,4)
hold on
h=1;
x=0:h:6;
y=trzy(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '2pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,5)
hold on
h=0.5;
x=0:h:6;
y=trzy(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '3pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,6)
hold on
h=0.25;
x=0:h:6;
y=trzy(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '3pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,7)
hold on
h=1;
x=0:h:6;
y=piec(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,8)
hold on
h=0.5;
x=0:h:6;
y=piec(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,9)
hold on
h=0.25;
x=0:h:6;
y=piec(x,h);
plot(x,y,'b')
plot(xdf,ydf)

m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Najlepszy jest pięciopunktowy, im mniejszy krok tym jest lepszy rezultat.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%Zadanie 2
disp("Zadanie 2")
pause;
clc;
close all;
clear;
f=@(x)sin(x)+cos(2*x);
df=@(x)cos(x)-2*sin(2*x);
xdf=0:0.001:4;
ydf=df(xdf);

wprzod=@(x,h)(-3*f(x)+4*f(x+h)-f(x+2*h))/(2*h);
centralny=@(x,h)(f(x+h)-f(x-h))/(2*h);
wstecz=@(x,h)(f(x-2*h)-4*f(x-h)+3*f(x))/(2*h);
%%%%%%%%%%%%%%%%
subplot(3,3,1)
h=0.5;
x=0:h:4;
y=wprzod(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wprzód: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,2)
h=0.25;
x=0:h:4;
y=wprzod(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wprzód: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,3)
h=0.125;
x=0:h:4;
y=wprzod(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wprzód: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,4)
h=0.5;
x=0:h:4;
y=centralny(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'centralny: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,5)
h=0.25;
y=centralny(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);

m=mse_n(df(x),y);
title ([ 'centralny: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,6)
h=0.125;
x=0:h:4;
y=centralny(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'centralny: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,7)
h=0.5;
x=0:h:4;
y=wstecz(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wstecz: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,8)
h=0.25;
y=wstecz(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wstecz: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(3,3,9)
h=0.125;
x=0:h:4;

y=wstecz(x,h);
hold on;
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ 'wstecz: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
%zadanie 3
disp("Zadanie 3")
pause;
clc;
clear all;
close all;
f=@(x)cos(4*x)-(1/2)*x;

df=@(x)-16*cos(4*x);
xdf=0:0.001:4;
ydf=df(xdf);

trzy=@(x,h)( f(x+h)-2*f(x)+f(x-h))/(h^2);
piec=@(x,h)( -1*f(x+2*h)+16*f(x+h)-30*f(x)+16*f(x-h)-f(x-2*h) )/(12*h^2);

%%%%%%%%%%%%%%%%
subplot(2,3,1)
h=1;
hold on;
x=0:h:4;
y=trzy(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '3pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(2,3,2)
h=0.5;
hold on;
x=0:h:4;
y=trzy(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '3pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(2,3,3)
h=0.25;
hold on;
x=0:h:4;
y=trzy(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '3pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(2,3,4)
h=1;
hold on;
x=0:h:4;
y=piec(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(2,3,5)
h=0.5;
hold on;
x=0:h:4;
y=piec(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%
subplot(2,3,6)
h=0.25;
hold on;
x=0:h:4;
y=piec(x,h);
plot(x,y,'b');
plot(xdf,ydf);
m=mse_n(df(x),y);
title ([ '5pkt: h = ', num2str(h) ,' blad : ', num2str(m)]);
%%%%%%%%%%%%%%%%%%%%
% Najlepszy jest 5 punktowy im mniejszy krok tym wynik jest dokładniejszy
%%%%%%%%%%%%%%%%%%%


clc;
clear;
dane=load("dane.txt");
A=dane(1:end,1:end-1);
B=dane(1:end,end:end);
x=[0.1;-0.01;0.00001];
%x=[0;0;0];
wynik = nowakowski_ip(A,B,0.001,x);
disp(wynik)%
n=100;
A100=rand(n)+eye(n)*n;
B100(:,1)=A100(:,1);
n=200;
A200=rand(n)+eye(n)*n;
B200(:,1)=A200(:,1);
%nowakowski_ip(A100,B100,0.001,0)
disp('Next ')
%nowakowski_ip(A200,B200,0.001,0)
disp('Next ')
%nowakowski_ip(A100,B100,0.001,-10)
disp('Next ')
%nowakowski_ip(A200,B200,0.001,-10)
disp('Next ')
%nowakowski_ip(A100,B100,0.001,10)
disp('Next ')
nowakowski_ip(A200,B200,0.001,10)
function [x,y,fmin,time,counter] = nowakowski_metoda_spadku(f, x0, y0, dok,lamb)
time=0;
tic;
h=0.125;
dfx=@(x,y) (f(x+h,y)-f(x-h,y))/(2*h);
dfy=@(x,y) (f(x,y+h)-f(x,y-h))/(2*h);
%trojkat grad to wektor pochodnych
i=2;
x(1)=x0;
y(1)=y0;
while 1
    grad(1,1)=dfx(x(i-1),y(i-1));
    grad(2,1)=dfy(x(i-1),y(i-1));
    hesjan(1,1)=(dfy(x(i-1),y(i-1)+h)-dfy(x(i-1),y(i-1)-h))/(2*h);
    hesjan(1,2)=dfy(x(i-1),y(i-1));
    hesjan(2,1)=(dfx(x(i-1),y(i-1)+h)-dfx(x(i-1),y(i-1)-h))/(2*h);
    hesjan(2,2)=dfx(x(i-1),y(i-1));
    a=( transpose(grad)*grad )/(transpose(grad)*hesjan*grad);
    x(i)=x(i-1)-a*grad(1,1);
    y(i)=y(i-1)-a*grad(2,1);

    if grad(1,1) < dok && grad(2,1) < dok
        break
    end
    i=i+1;
end
fmin=f(x(i),y(i));
counter=i-1;
time=toc;
end
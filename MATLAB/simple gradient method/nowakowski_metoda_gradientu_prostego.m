function [x,y,fmin,time,counter] = nowakowski_metoda_gradientu_prostego(funkcja, x0, y0, dok,lamb)
time=0;
tic;
h=0.125;
px=@(x,y) (funkcja(x+h,y)-funkcja(x-h,y))/(2*h);
py=@(x,y) (funkcja(x,y+h)-funkcja(x,y-h))/(2*h);
i=2;
x(1)=x0;
y(1)=y0
while 1
    gradientX=px(x(i-1),y(i-1));
    gradientY=py(x(i-1),y(i-1));
    ax=lamb/abs(gradientX);
    ay=lamb/abs(gradientY);
    x(i)=x(i-1)-ax*gradientX;
    y(i)=y(i-1)-ax*gradientY;
    if gradientX < dok && gradientY < dok
        break
    end
    i=i+1;
end
fmin=funkcja(x(i),y(i));
counter=i-1;
time=toc;
end


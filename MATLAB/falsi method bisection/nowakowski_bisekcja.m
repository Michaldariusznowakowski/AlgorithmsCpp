function [x_b,n_b,czas_b] = nowakowski_bisekcja(f,a,b,ftol)
x_b=0;
n_b=0;
czas_b=0;
tic

a_y=f(a);
b_y=f(b);

stop=0;
if ((a_y*b_y) > 0)
    disp("ERROR")
    stop=1;
else
    x0=((a+b)/2);
end
counter=0;
while (stop == 0)
    counter=counter+1;
    x0=((a+b)/2);
    if (abs(a-x0) < ftol)
        stop=1;
     break;
    end
    x0_y=f(x0);
    if (abs(x0_y) < ftol)
        stop=1;
        break;
    end
    if ((x0_y*a_y) < 0)
    b=x0;
    else
        a=x0;
        a_y=x0_y;
    end
end
x_b=x0;
n_b=counter;
czas_b=toc;
end


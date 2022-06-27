function [x_r, n_r, czas_r] = nowakowski_falsi(f,a,b,ftol)
x_r=0;
n_r=0;
tic
czas_r=0;
%2 poch

d2f=@(x)(f(x+ftol)-2*f(x)+f(x-ftol) )/(ftol^2);
d2fa=d2f(a);
fa=f(a);
d2fb=d2f(b);
fb=f(b);
if(sign(fa) && sign(d2fa))
    disp("A");
    xs=a;
    x0=b;
else
    disp("B");
    xs=b;
    x0=a;
end
counter=0;
while(abs(f(x0))>ftol)
    counter=counter+1;
    x0=x0-((f(x0))/(f(xs)-f(x0)))*(xs-x0);

end
x_r=x0;
n_r=counter;
czas_r=toc;
end


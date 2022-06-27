function [wynik,iteracje] = szescienna_nowakowski(a,b,f)
h=0.25;
iteracje=0;
fpochodna=@(x)( -1*f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h) )/(12*h);
working=1;
oldxm=-1;
xm=0;
wynik=zeros(1);
if fpochodna(a) < 0 && fpochodna(b) > 0
    while working==1
        iteracje=iteracje+1;
        oldxm=xm;
        Z=( ( 3*(f(a)-f(b)) ) / (b-a) )+fpochodna(a)+fpochodna(b);
        Q=sqrt(Z^2-fpochodna(a)*fpochodna(b));
        xm=b-( (fpochodna(b) + Q - Z)/ (fpochodna(b)-fpochodna(a)+2*Q))*(b-a);
        if fpochodna(xm)<0
            a=xm;
        else
            b=xm;
        end
        
         if(abs(oldxm-xm)<0.01)
            working=0; 
         else
             wynik(iteracje)=xm;
         end
        
    end
end
end


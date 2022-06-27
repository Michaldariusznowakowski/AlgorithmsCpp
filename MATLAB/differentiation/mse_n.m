function [ms] = mse_n(d,p)
n=length(d);
for i=1:1:n
    ms=(d(i)-p(i))^2;
end
ms=(1/n)*(ms);
end


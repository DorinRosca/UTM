function y=integr1(x,y);
y=(x.^(3/2).*(x+y).^(2)+y.*exp(x+y)).^(1/2);
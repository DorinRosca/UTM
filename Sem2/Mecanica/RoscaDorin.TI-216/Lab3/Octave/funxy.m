function[x,y] = funxy(t)
x = t.*exp(-t).*sin(t);
y = 1.-cos(t);
endfunction
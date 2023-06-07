function[x,y,z] = funxy(t)
x = (t.^2.+1).*sin(2).*t;
y = t.*cos(t);
z = 1.5.*t;
endfunction

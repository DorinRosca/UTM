function dq = diferentiala4(t,q)
h=5;
w0=15;
H0=5;
p=6;
dq = zeros(2,1);
dq(1) = q(2);
dq(2) = -2.*h.*q(2)-w0.^2.*q(1)+H0.*sin(p*t);
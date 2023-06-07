function dq = diferentiala32(t,q)
H0=5;
w0=15;
p=17;
dq = zeros(2,1);
dq(1) = q(2);
dq(2) = -w0.^2.*q(1)+H0.*sin(p.*t);
end
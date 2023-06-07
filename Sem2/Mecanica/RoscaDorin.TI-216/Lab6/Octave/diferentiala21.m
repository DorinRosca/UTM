function dq = diferentiala2(t,q)
h=6;
w0=6;
dq = zeros(2,1);
dq(1) = q(2);
dq(2) = -2.*h.*q(2)-w0.^2*q(1);
end
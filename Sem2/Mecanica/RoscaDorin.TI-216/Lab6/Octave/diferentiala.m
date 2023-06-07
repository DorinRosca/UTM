function dq = diferentiala(t,q)
w0=7;
dq = zeros(2,1);
dq(1) = q(2);
dq(2) = -w0.^2.*q(1);
  end

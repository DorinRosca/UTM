close all
%Laboratorul 6
%Rosca Dorin
%Exercitiul 4
% a)Oscilatii libere in lipsa rezistentei mediului
%graficul dependentei parametrului de pozitia x=x(t)
t=[0;10];
qo=[0;3];
[t,q]=ode23(@diferentiala,t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii libere in lipsa rezistentei');
grid on

%Determinarea caracteristicilor dinamice
disp('Oscilatii libere in lipsa rezistentei mediului')
%Amplitudinea
x0=3;
w0=7;
v0=9;
A=sqrt(x0^2+(v0^2/w0^2))
%Faza Initiala
Epsilon=atan(w0*x0/v0)
%Perioada
T=2*pi/w0
%Frecventa
f=1/T
% b)Oscilatii libere in prezenta rezistentei mediului
%1)h<w0
%graficul dependentei parametrului de pozitia x=x(t)
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23(@diferentiala2,t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii libere in prezenta rezistentei mediului,h<w0');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii libere in prezenta rezistentei mediului,h<w0')
%Frecventa Ciclica
h=3;
w0=6;
w=sqrt(w0^2-h^2)
%Ampitudinea
A2=sqrt(x0^2+((v0+h*x0)^2/w^2))
%Faza initiala
Epsilon2=atan((w*x0)/(v0+h*x0))
%Perioada
T2=2*pi/w
%Frecventa
f2=1/ T2 
%Decrementul de amortizare
eta=exp(-h*T)
%Decrementul logaritmic de amortizare
decrementul=h*T
%2)h=w0
%graficul dependentei parametrului de pozitia x=x(t)
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23(@diferentiala21,t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii libere in prezenta rezistentei mediului,h=w0');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii libere in prezenta rezistentei mediului,h=w0')
%Frecventa Ciclica
h=6;
w0=6;
w=sqrt(w0^2-h^2)
%Ampitudinea
A2=sqrt(x0^2+((v0+h*x0)^2/w^2))
%Faza initiala
Epsilon2=atan((w*x0)/(v0+h*x0))
%Perioada
T2=2*pi/w
%Frecventa
f2=1/ T2 
%Decrementul de amortizare
eta=exp(-h*T)
%Decrementul logaritmic de amortizare
decrementul=h*T
%3)h>w0
%graficul dependentei parametrului de pozitia x=x(t)
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23(@diferentiala22,t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii libere in prezenta rezistentei mediului,h>w0');
grid on
disp('Oscilatii libere in prezenta rezistentei mediului,h>w0')
%Determinarea caracteristicilor dinamice
%Frecventa Ciclica
h=10;
w0=6;
w=sqrt(w0^2-h^2)
%Ampitudinea
A2=sqrt(x0^2+((v0+h*x0)^2/w^2))
%Faza initiala
Epsilon2=atan((w*x0)/(v0+h*x0))
%Perioada
T2=2*pi/w
%Frecventa
f2=1/ T2 
%Decrementul de amortizare
eta=exp(-h*T)
%Decrementul logaritmic de amortizare
decrementul=h*T


% c)Oscilatii fortate in lipsa rezistentei mediului
%1)p!=w0
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23('diferentiala3',t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii fortate in lipsa rezistentei mediului,p!=w0');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii fortate in lipsa rezistentei mediului,p!=w0')
H0=5;
w0=15;
p=5;
A3=H0./abs(w0.^2-p.^2)
%2)p aproximativ=w0
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23('diferentiala32',t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii fortate in lipsa rezistentei mediului,p aproximativ=w0');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii fortate in lipsa rezistentei mediului,paproximativ=w0')
H0=5;
w0=15;
p=17;
A3=H0./abs(w0.^2-p.^2)
%3)p=w0
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23('diferentiala33',t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii fortate in lipsa rezistentei mediului');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii fortate in lipsa rezistentei mediului,p=w0')
disp('p=w0')
H0=5;
w0=15;
p=15;
A3=H0./abs(w0.^2-p.^2)
% d)Oscilatii fortate in prezenta rezistentei mediului
figure()
t=[0;10];
qo=[0;3];
[t,q]=ode23(@diferentiala4,t,qo);
plot(t,q(:,1),'-');
set(gca,'fontsize',20);
title('Oscilatii fortate in prezenta rezistentei mediului');
grid on
%Determinarea caracteristicilor dinamice
disp('Oscilatii fortate in prezenta rezistentei mediului')

grid; grid minor;
h=5;H0=5; w0=15; p=6;
A4=H0./sqrt((w0.^2-p.^2)+4.*h.^2*p.^2)
Defazajul=atan(2.*h.*p)./(w0.^2-p.^2)
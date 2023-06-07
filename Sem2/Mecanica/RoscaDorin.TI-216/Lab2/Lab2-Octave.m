 %Rosca Dorin,TI-216,Varianta-14
%Lab nr2.Grafica in Octave
%Ex1...Teorie....In Raport
%Ex2
close all
x=[-pi:0.05:4*pi];
f=x.*sin(x.^2);
g=(x.^2).*cos(x);
%a)In ferestre diferite
%construirea graficului functiei f
figure(1)
plot(x,f,'k-','linewidth',2)
legend('f(x)=x*sin(x^2)','fontSize',20)
set(gca, 'fontSize', 25);
title('\it Functia f(x)')
xlabel('x'); ylabel('y');
grid;grid minor

figure(2)
plot(x,g,'b-','linewidth',2)
title('{\it  Functia g(x)}')
set(gca, 'fontSize', 25);
legend('g(x)=(x^2)*cos(x)')
xlabel('x');ylabel('y');
grid;grid minor
%b)

figure(3)
plot(x,f,'k-','linewidth',2)
hold on
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it Functiile f(x) si g(x)}')
legend('f(x)=x*sin(x^2)','g(x)=(x^2)*cos(x)')
xlabel('x');ylabel('y')
grid;grid minor
%c1-intr-o fereastra pe axe diferite orizontal
figure(4)
subplot(3,1,1)
plot(x,f,'k-','linewidth',2)
set(gca, 'fontSize', 25);
title('\it Functia f(x)')
xlabel('x');xlabel('y')
grid;
grid minor
subplot(3,1,2)
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it  Functia g(x)}')
xlabel('x');ylabel('y')
grid;grid minor
subplot(3,1,3)
plot(x,f,'k-','linewidth',2)
hold on
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it Functiile f(x) si g(x)}')
legend('f(x)=x*sin(x^2)','g(x)=(x^2)*cos(x)','fontSize',20)
xlabel('x');ylabel('y')
grid;grid minor
%c2-intr-o fereastra pe axe diferite vertical
figure(5)
subplot(1,3,1)
plot(x,f,'k-','linewidth',2)
set(gca, 'fontSize', 25);
title('\it Functia f(x)')
xlabel('x');xlabel('y');
grid;
grid minor
subplot(1,3,2)
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it  Functia g(x)}')
xlabel('x');ylabel('y')
grid;grid minor
subplot(1,3,3)
plot(x,f,'k-','linewidth',2)
hold on
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it Functiile f(x) si g(x)}')
legend('f(x)=x*sin(x^2)','g(x)=(x^2)*cos(x)')
xlabel('x');ylabel('y')
grid;grid minor
%c2-intr-o fereastra pe axe diferite vertical
figure(6)
subplot(2,2,1)
plot(x,f,'k-','linewidth',2)
set(gca, 'fontSize', 25);
title('\it Functia f(x)')
xlabel('x');xlabel('y')
grid;
grid minor
subplot(2,2,3)
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it  Functia g(x)}')
xlabel('x');ylabel('y');
grid;grid minor
subplot(2,2,[2,4])
plot(x,f,'k-','linewidth',2)
set(gca, 'fontSize', 25);
%hold on
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it Functiile f(x) si g(x)}')
legend('f(x)=x*sin(x^2)','g(x)=(x^2)*cos(x)')
xlabel('x');ylabel('y')
grid;grid minor
figure(7)
subplot(2,2,3)
plot(x,f,'k-','linewidth',2)
set(gca, 'fontSize', 25);
title('\it Functia f(x)')
xlabel('x');xlabel('y')
grid;
grid minor
subplot(2,2,4)
plot(x,g,'b-','linewidth',2)
set(gca, 'fontSize', 25);
title('{\it  Functia g(x)}')
xlabel('x');ylabel('y')
grid;grid minor
subplot(2,2,[1,2])
set(gca, 'fontSize', 25);
plot(x,f,'k-','linewidth',2)
hold on
set(gca, 'fontSize', 25);
plot(x,g,'b-','linewidth',2)
title('{\it Functiile f(x) si g(x)}')
legend('f(x)=x*sin(x^2)','g(x)=(x^2)*cos(x)','fontSize',20)
xlabel('x');ylabel('y')
grid;grid minor
pause
%Exercitiul 3
%utilizand functia mesh
%[x,y]=mesh(0:0.05:pi,1:0.05:5);
[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(8)
mesh(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia mesh:','fontSize',20);
%utilizand functia surf

[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(9)
surf(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia surf:','fontSize',20);
%utilizand functia meshc

[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(10)
meshc(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia meshc:','fontSize',20);
%utilizand functia surfc
[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(11)
surfc(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia surf c:','fontSize',20);
%utilizand functia contour
[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(12)
contour(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia contour:','fontSize',20);
%utilizand functia contourf
[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(13)
contourf(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia contourf:','fontSize',20);
%utilizand functia contour3
[x,y]=meshgrid(-pi:0.05:pi,-1:0.05:1);
z=2.*x.*sin(x.*y).*log(y.+2);
figure(14)
contour3(x,y,z);
title('Graficul Functiei de 2 variabile uitilizand functia contour3:','fontSize',20);
%Rosca Dorin
%Laboratorul 3
%Exercitiul 2
%a)Graficul traiectoriei si pozitia punctului
t = [0:0.02:4*pi];
[x,y]= funxy(t);
close all
figure()
plot(x,y,'k-','linewidth',2)
set(gca,'fontsize',20);
title('Traiectoria Punctului');
xlabel('x, cm');ylabel('y, cm');
grid;grid minor;
t1 = rand(1)*(4*pi);
[x1,y1] = funxy(t1);
hold on
plot(x1,y1,'r*','linewidth',2)
disp(['Pentru Momentul de Timp t1=',num2str(t1),'sec'])
disp(['x1=',num2str(x1),'cm'])
disp(['y1=',num2str(y1),'cm'])
%b)Calcule Simbolice  
syms t 
[x,y] = funxy(t);
%Viteza
vx = diff(x); vy = diff(y); v = sqrt(vx^2+vy^2) ;
%Acceleratia
ax = diff(vx);ay = diff(vy);
a = sqrt(ax^2+ay^2);
%Acceleratia Tangentiala
at=abs((vx*ax+vy*ay)/v);
%Acceleratia Normala
an=sqrt(a^2-at^2);
%Raza de Curbura
ro=(v^2)/an;
%b)Calcule Numerice
t=t1;
%Viteza
v1x=eval(vx);
v1y=eval(vy);
v1=eval(x);
%Acceleratia
a1x=eval(ax);
a1y=eval(ay);
a1=eval(a);
%Acceleratia tangentiala
a1t=eval(at);
%Acceleratia Normala
a1n=eval(an);
%Raza de curbura
ro1=eval(ro);
%d)Viteza
disp(['v1x = ',num2str(v1x),'cm/s']) 
disp(['v1y = ',num2str(v1y),'cm/s']) 
disp(['v1 = ',num2str(v1),'cm/s']) 
%Acceleratia
disp(['a1x = ',num2str(a1x),'cm/s^2']) 
disp(['a1y = ',num2str(a1y),'cm/s^2']) 
disp(['a1 = ',num2str(a1),'cm/s^2']) 
%Acceleratia Tangentiala
disp(['a1t = ',num2str(a1t),'cm/s^2']) 
%Acceleratia Normala
disp(['a1n = ',num2str(a1n),'cm/s^2']) 
%Raza de Curbura
disp(['ro1 = ',num2str(ro1),'cm/s^2']) 
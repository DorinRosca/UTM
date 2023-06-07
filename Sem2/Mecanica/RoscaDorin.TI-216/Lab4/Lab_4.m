%Laborator 4
%Rosca Dorin
% Exercitiul 2
n=0;
t = [0:0.02:7];

%a)Oscilatii armonice necoerente(w1!=w2):
% Prima oscilatie
 A1 = 2;
 w1 = pi*1.5;  
 alfa1 = pi;
 x1 = A1.*cos(w1.*t+alfa1);
% A doua oscilatie
 A2 = 4;
 w2 = pi*2;
 alfa2 = pi*0.5;
 x2 = A2.*cos(w2.*t+alfa2);
% Compunere
 x = x1+x2;
 T1 = 2*pi/w1;
 T2 = 2*pi/w2;
%//////
figure(1)
 plot(t,x1,'k-','linewidth',2, t,x2,'b-','linewidth',2, t,x,'r-','linewidth',2);
 set(gca, 'fontSize', 15);
 title('\it Oscilatii armonice necoerente(w1!=w2)')
 legend('x1','x2','x')
 grid; grid minor;
 xlabel('t, secunde');ylabel('x1,x2,x, cm')

 %b)Oscilatii armonice coerente(w1==w2)
 % Prima oscilatie
 A1 = 2;
 w1 = pi*1.5;  
 alfa1 = pi;
 x1 = A1.*cos(w1.*t+alfa1);
 % A doua oscilatie
  A2 = 4;
 w2 = w1;
 alfa2 = pi*0.5;
 x2 = A2.*cos(w2.*t+alfa2);
 % Compunerea
 x = x1+x2;
 T1 = 2*pi/w1;
 T2 = 2*pi/w2;
 figure(2)
  plot(t,x1,'k-','linewidth',2, t,x2,'b-','linewidth',2, t,x,'r-','linewidth',2);
  set(gca, 'fontSize', 15);
  title('\it Oscilatii armonice coerente(w1==w2)')
  legend('x1','x2','x')
  grid; grid minor;
  xlabel('t, secunde');ylabel('x1,x2,x, cm')
  
%c)Oscilatii armonice necoerente(oscilatii de tip bataie)
% Prima oscilatie
 A1 = 2;
 w1 = pi*1.5;  
 alfa1 = pi;
 x1 = A1.*cos(w1.*t+alfa1);
 % A doua oscilatie
  A2 = 4;
 w2 = pi*1.60;
 alfa2 = pi*0.3;
 x2 = A2.*cos(w2.*t+alfa2);
 % Compunerea
 x = x1+x2; 
 T1 = 2*pi/w1;
 T2 = 2*pi/w2;
 figure(3)
  plot(t,x1,'k-','linewidth',2, t,x2,'b-','linewidth',2, t,x,'r-','linewidth',2);
  set(gca, 'fontSize', 15);
  title('\it Oscilatii armonice necoerente(w1 aproximativ ==w2)')
  legend('x1','x2','x')
  grid; grid minor;
  xlabel('t, secunde');ylabel('x1,x2,x, cm')

%d)Oscilatii armonice coerente cu valori diferite 
 n=0;
 figure(4)
 for d_alfa = [0, pi/6, pi/4, pi/3, pi/2, 2*pi/3, 3*pi/4, 5*pi/6, pi];
  n = n + 1;   
% Prima oscilatie
  A1 = 2;
  w1 = pi*1.5;
  alfa1 = pi;
  x1 = A1.*cos(w1.*t+alfa1);
% A doua oscilatie
  A2 = 4;
  w2 = w1;
  alfa2 = alfa1+d_alfa;
  x2 = A2.*cos(w2.*t+alfa2);
% Compunerea
  x = x1+x2;
  subplot(3,3,n);
  plot(t,x1,'k-','linewidth',2, t,x2,'b-','linewidth',2, t,x,'r-','linewidth',2);
  set(gca, 'fontSize', 15);
  title({'Pentru Alfa = ' d_alfa});
  legend('x1','x2','x')
  grid; grid minor;
  xlabel('t, secunde');ylabel('x1,x2,x, cm')
endfor

% Exercitiul 3
%a)pentru w1==w2
n = 0;
 for alfa = [0, pi/6, pi/4, pi/3, pi/2, 2*pi/3, 3*pi/4, 5*pi/6, pi];
 n = n + 1;
% Prima oscilatie
 A1 = 2;
 w1 = pi*1.5;
 alfa1 = pi;
 x1 = A1.*cos(w1.*t-alfa1);
% A doua oscilatie
 A2 = 4;
 w2 = w1;
 alfa2 = alfa1-alfa;
 x2 = A2.*cos(w2.*t-alfa2);

 figure(5) 
 subplot (3, 3, n);
 plot (x1, x2);
 title ({'Pentru alfa = ' alfa});
 xlabel ('t, secunde');
 ylabel ('x, m');
end

%b)w1!=w2
n = 0;
for alfa = [0, pi/6, pi/4, pi/3, pi/2, 2*pi/3, 3*pi/4, 5*pi/6, pi];
%Prima Oscilatie
 n = n + 1;
 A1 = 2;
 w1 = pi*2;
 x1 = A1.*cos(w1.*t - alfa - (pi/2));
% A doua oscilatie 
 A2 = 4;
 w2 = pi*3;
 x2 = A2.*cos(w2.*t - alfa - (pi/2));
 figure(6);
 subplot (3, 3, n);
 plot (x1, x2);
 title({'Pentru alfa = ' alfa });
 xlabel ('t, sec');ylabel ('x, m');
end
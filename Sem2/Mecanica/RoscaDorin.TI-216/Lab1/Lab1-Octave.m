clear
clc
%Laborator Numarul 1%
%Varianta 14%
%Rosca Dorin%
%Ex.2
%2.1
x= -1.75*10^(-3)
y=3.1*pi
disp('Rezultatul intr-un rand')
Q1=((abs(x)*(1+2*x^(2)))/(100*x+coth(y)))^(2.1)+(100*x+...
coth(y)+sin(y))/(x^(2)*(1+2*x^(2)))
F2=atanh((2*x-sin(y))^(1/5)/(sqrt(abs(x-log(y)))))+...
((abs(x)*sqrt(abs(x-log(y))))/((2*x-sin(y))^(1/5)))
%2.2-Optimizare cu  variabileIntermediare 
disp('Rezultatul cu variabile intermediare')
a=1+2*x^2
b=100*x+coth(y)
m=(2*x-sin(y))^(1/5)
n=(sqrt(abs(x-log(y))))
Q1=((abs(x)*a)/b)^(2.1)+(b+sin(y))/(x^(2)*a)
F2=atanh(m/n)+(abs(x)*n)/(m)
%2.3.Diferite Formate
disp('Diferite Formate')
format short
disp('Format Short:')
Q1
F2

format long
disp('Format long:')
Q1
F2
format hex
disp('Format Hex:')
Q1
F2
disp('Comanda Whos:')
whos

pause


clear
clc
%Exercitiul 3
disp('Exercitiul 3')
a=-1
b=3
N=8
pas=(b-a)/(N-1)
x=[a:pas:b]
y=exp(-x).*(cos(x.^2)).*((x.^2)+1)
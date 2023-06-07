%Lab3
%RoscaDorin.Varianta 14
%Ex.1
x = [0:0.05:1];
z = f(x);
figure(1)
subplot(2,1,1)
plot(x,z)
set(gca,'fontsize',20);
title('Intervalul de 0.05')
subplot(2,1,2)
fplot('f',[0,1])
set(gca,'fontsize',20);
title('Intervalul ales de calculator')


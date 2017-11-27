
clear all

global m J l k r R


m=0.11;
J=1.25;
l = 1 ; % distancia entre as rodas
k = 1; 
r = 1 ; % raio das rodas
R=10;



Tsimu = 40;
passo = 1e-2; %Euler
x0=zeros(1,5)';
x0 = [0 0 0 0 0]';
b = 2;
K = 2;  
% kristic
Cx = 0.02;
Cy= 0.02;

wt=[0.1:1e-2:12];

plot(t,xrobot,t,yrobot)

%plot(wt,funcPt(wt),wt,funcTt(wt)*6,'r')
%grid

%[aux,ind]=max(funcTt(wt));

% fig1 = figure;
% subplot(2,1,1);
% plot(t,xr,t,ones(size(t))*50);
% xlabel('tempo(s)')
% ylabel('posicao X (cm')
% subplot(2,1,2);
% plot(t,yr,t,ones(size(t))*86)
% ylabel('posicao Y (cm')
% hgexport(fig1,'2DOF1')
% 
% fig2 = figure;
% subplot(2,1,1);
% plot(t,fCusto);
% xlabel('tempo(s)')
% grid on
% subplot(2,1,2);
% plot(t,theta,t,ones(size(t))*60);
% xlabel('tempo(s)')
% ylabel('Theta (deg)')
% grid on
% hgexport(fig2,'2DOF2')



% fig2 = figure;
% subplot(2,1,1);
% plot(xrobot.time,xrobot.signals.values);
% xlabel('tempo(s)')
% xlabel('x (cm)')
% grid on
% subplot(2,1,2);
% plot(yrobot.time,yrobot.signals.values);
% xlabel('tempo(s)')
% ylabel('y (cm)')
% grid on
% 
% plot(xrobot.signals.values,yrobot.signals.values);
% xlabel('x (cm)')
% ylabel('y (cm)')

% hgexport(fig2,'2DOF2')




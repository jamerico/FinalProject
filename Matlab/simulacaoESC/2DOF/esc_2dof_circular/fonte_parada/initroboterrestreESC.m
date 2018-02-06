
clear all


global m J l k r R count1 deltayold cinematico v Rr 

global xstar ystar xstarArray ystarArray


%planta
cinematico=0;
m=0.11/10;
J=1.25/10;
l = 1 ;
k = 1;
r = 1 ;
R=10;


%custo
xstar=30;
ystar=50;
xstarArray = 0;
ystarArray = 0;

%Evitando descontinuidade do atan2
count1=0;


% ESC
% esse ganho controla a velocidade de seguimento do algoritmo.
% Quanto maior for o ganho, mais rapido o algoritmo chega na fonte
Kesc = 0.02; %0.08

Rr=1;
v=1*pi*Rr; % 1 volta a cada 2 s --> w=pi


h=(v/Rr)/5; % filtro principal
N=10;




Tsimu = 50*2*400;
passo = 1e-2; %Euler
x0=zeros(1,5)';
x0(3)=-0*45*pi/180;
x0(1)=0;
x0(2)=0;

yc0=0;
deltayold=x0(2)-yc0;

%% 

% posicao robot
figure(1)
subplot(2,1,1);
plot(t,x(:,2),t,xstarArray(1:end-2)')
legend('posicao x','fonte x');
subplot(2,1,2);
plot(t,y(:,2),t,ystarArray(1:end-2)')
legend('posicao y','fonte y');

figure(2)
subplot(2,1,1);
plot(t,z(:,2),t,400*ones(1,size(t,1)))
legend('func custo ao longo do tempo','maximo');
subplot(2,1,2);
plot(t,ur(:,2))
legend('Ur');

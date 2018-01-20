
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
xstar=0;
ystar=0;
xstarArray = 0;
ystarArray = 0;

%Evitando descontinuidade do atan2
count1=0;


% ESC
Kesc = 0.06; %0.04
Rr=1;
v=1*pi*Rr; % 1 volta a cada 2 s --> w=pi


h=(v/Rr)/5; % filtro principal
N=10;




Tsimu = 50*2*400;
passo = 1e-2; %Euler
x0=zeros(1,5)';
x0(3)=-0*45*pi/180;
x0(1)=0;
x0(2)=5;

yc0=0;
deltayold=x0(2)-yc0;

%% 

plot(xRobot.time(100/passo:end),xRobot.signals.values(100/passo:end)/max(xRobot.signals.values(100/passo:end)),fCusto.time(100/passo:end),fCusto.signals.values(100/passo:end)/max(fCusto.signals.values(100/passo:end)))
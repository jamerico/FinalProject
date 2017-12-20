
clear all


global m J l k r R count1 deltayold cinematico v Rr ur1v ur2v ur3v
ur1v = [];
ur2v = [];
ur3v = [];

global xstar ystar


%planta
cinematico=0;
m=0.11/10;
J=1.25/10;
l = 1 ;
k = 1;
r = 1 ;
R=10;


%custo
xstar=10;
ystar=10;

%Evitando descontinuidade do atan2
count1=0;


% ESC
Rr=5;
% Rr=2;

v=pi*0.1; % 1 volta a cada 2 s --> w=pi


h=(v/Rr)/5; % filtro principal
N=10;




Tsimu = 50*5*2*2*4;
passo = 1e-2; %Euler
x0=zeros(1,5)';
x0(3)=-0*45*pi/180;
x0(1)=0;
x0(2)=0;

yc0=0;
deltayold=x0(2)-yc0;


function saida=fcusto(uin)
global xstar ystar xstarArray ystarArray



x=uin(1);
y=uin(2);
tNow = uin(3)*0.005;

xstar = 16*sin(tNow)^3; %0.5*tNow
ystar = 13*cos(tNow)-5*cos(2*tNow) - 2*cos(3*tNow)-cos(4*tNow); %0.5*tNow
xstarArray = [xstarArray xstar];
ystarArray = [ystarArray ystar];

saida=-(1*(x-xstar)^2+1*(y-ystar)^2)+400;
end
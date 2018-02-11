function saida=fcusto(uin)
global xstar ystar xstarArray ystarArray



x=uin(1);
y=uin(2);
tTemp = uin(3)*0.005;
persistent tInitialized;

if(uin(3)>200)
    if(not(size(tInitialized,1)))
       tInitialized = tTemp;
    end
    tNow = tTemp-tInitialized;
    
    
% coracao
    % xstar = 16*sin(tNow)^3; %0.5*tNow
    % ystar = 13*cos(tNow)-5*cos(2*tNow) - 2*cos(3*tNow)-cos(4*tNow); %0.5*tNow
    % circulo
    xstar = 10*sin(tNow); %0.5*tNow
    ystar = -10*cos(tNow)+10; %0.5*tNow
else
    xstar = 0;
    ystar = 0;
end


xstarArray = [xstarArray xstar];
ystarArray = [ystarArray ystar];

saida=-(1*(x-xstar)^2+1*(y-ystar)^2)+400;
end
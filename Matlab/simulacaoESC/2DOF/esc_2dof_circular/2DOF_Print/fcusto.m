function saida=fcusto(uin)
global xstar ystar xstarArray ystarArray

% vetor de entradas
x=uin(1);
y=uin(2);

% tempo auxiliar que dita o quao rapido a fonte se move
tNow = uin(3)*0.003;

% equacao da fonte (circular)
xstar = 10*sin(tNow); %0.5*tNow
ystar = 10*cos(tNow); %0.5*tNow

% fonte ao longo do tempo
xstarArray = [xstarArray xstar];
ystarArray = [ystarArray ystar];

% paraboloide
saida=-(1*(x-xstar)^2+1*(y-ystar)^2)+400;
end
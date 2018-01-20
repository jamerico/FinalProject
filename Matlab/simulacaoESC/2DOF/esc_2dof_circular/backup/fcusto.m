function saida=fcusto(uin)
global xstar ystar



x=uin(1);
y=uin(2);

saida=-(1*(x-xstar)^2+1*(y-ystar)^2)+400;
end
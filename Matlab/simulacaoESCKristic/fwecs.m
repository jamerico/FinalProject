function saida=fwecs(uin)
global m J l k r R


t=uin(1);
x=uin(2:6);



xc=x(1);
yc=x(2);
theta=x(3);
u=x(4);
omega=x(5);



saida=[xc yc theta]';
end
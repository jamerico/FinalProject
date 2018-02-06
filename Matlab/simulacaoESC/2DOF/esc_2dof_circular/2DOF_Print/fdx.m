function dx=fdx(uin)
global m J l k r R 

% vetor de entradas
t=uin(1);
ut=uin(2);
ur=uin(3);
x=uin(4:8);

% vetor de estados atual
xc=x(1);
yc=x(2);
theta=x(3);
u=x(4);
omega=x(5);

% modelo dinamico utilizado
dxc = u*cos(theta);
dyc = u*sin(theta);
dtheta = omega;
du = (1/m)*(k*ut/(r*R) - 2*u*k^2/(R*r^2));
domega = (l/J)*(k*ur/(r*R) - 2*l*omega*k^2/(R*r^2));

% saida
dx=[dxc dyc dtheta du domega]';

end
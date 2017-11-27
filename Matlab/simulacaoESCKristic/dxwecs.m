function dx=dxwecs(uin)
global m J l k r R

t=uin(1);
ut=uin(2);
ur=uin(3);
x=uin(4:8);


xc=x(1);
yc=x(2);
theta=x(3);
u=x(4);
omega=x(5);


%sistema completo
dxc = u*cos(theta);
dyc = u*sin(theta);
dtheta = omega;
%%dtheta = 0*omega;
du = (1/m)*(k*ut/(r*R) - 2*u*k^2/(R*r^2));
domega = (l/J)*(k*ur/(r*R) - 2*l*omega*k^2/(R*r^2));

%sistema simplificado
%dxc = (r/2*k)*ut*cos(theta);
%dyc = (r/2*k)*ut*sin(theta);
%dtheta = (r/2*k*l)*ur;

%fixando theta
%dtheta = (r/2*k*l)*ur*0;

% sistema mais simples possivel
dtheta = omega;
dxc = ut*cos(theta);
dyc = ut*sin(theta);

dx=[dxc dyc dtheta du domega]';

end
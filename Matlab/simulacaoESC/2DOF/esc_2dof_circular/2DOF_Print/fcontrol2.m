function saida=fcontrol2(uin)
global m J l k r R count1 deltayold v Rr


% dados do robo
x=uin(1);
y=uin(2);
theta=uin(3);
t=uin(6);
xr0=uin(7);
yr0=uin(8);


% deteccao da diferenca angular que independa do numero de
% voltas e do quadrante atual
deltax=x-xr0;
deltay=y-yr0;

if (deltax<0)
    if (deltay<0)
        if (deltayold>0)
            count1=count1+1;
        end
    else
         if (deltayold<0)
            count1=count1-1;
         end
    end
end

deltayold=deltay;
thetaaux=atan2(deltay,deltax)+2*pi*count1;
thetad=thetaaux-pi/2;
thetatil=theta-thetad;

% variaveis do algoritmo
D=sqrt(deltax^2+deltay^2); 
L=D-Rr;

% ganho dos controle
k2=4;k3=2*sqrt(2)*2;  

ut=v;
ur=-k2*v*L-k3*abs(v)*thetatil-v*cos(thetatil)/(L+Rr);

saida=[ut ur thetatil*180/pi L]';
end
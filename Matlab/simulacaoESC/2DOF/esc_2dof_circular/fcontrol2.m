function saida=fcontrol2(uin)
global m J l k r R count1 deltayold v Rr ur1v ur2v ur3v



x=uin(1);
y=uin(2);
theta=uin(3);
t=uin(6);
xr0=uin(7);
yr0=uin(8);


% referencia
%xr0=0;
%yr0=0;
%Rr=2;

%xr0=0.1*t;
%yr0=0.1*t;



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

if (thetatil==0) aux=1;
else
    aux=sin(thetatil)/thetatil;
end
% 


D=sqrt(deltax^2+deltay^2);
L=D-Rr;
% 
k2=0.4;
k3=0.2*sqrt(2);
% 
ut=v;
%ur=-k2*v*L*aux-k3*abs(v)*thetatil-v*cos(thetatil)/(L+Rr);

ur=-k2*v*L-k3*abs(v)*thetatil-v*cos(thetatil)/(L+Rr);
ur1v = [ur1v -k2*v*L];
ur2v = [ur2v -k3*abs(v)*thetatil];
ur3v = [ur3v -v*cos(thetatil)/(L+Rr)];

saida=[ut ur thetatil*180/pi L]';
end
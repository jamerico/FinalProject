
thetaOrig;


deltaY = 0;
deltaX = 0;
deltaYanterior = 0;
deltaXanterior = 0;
thetaAnterior = 0;
offset = 0;
max = pi;
min = -pi;
erro = 10*pi/180;

thetaAng = [];

%% valores calculados
for(i=1:1:size(thetaOrig,2))
    
    deltaYanterior = deltaY;
    deltaXanterior = deltaX;
    thetaAnterior = theta;
    
    anguloAtual = thetaOrig(1,i)*pi/180;
    primX = cos(anguloAtual);
    primY = sin(anguloAtual);
    secX = -cos(anguloAtual);
    secY = -sin(anguloAtual);
    
    deltaY = primY-secY;
    deltaX = primX-secX;
    
    % offset
    if(deltaXanterior<0 && deltaYanterior>0 && deltaX<0 && deltaY<0)
        offset = offset+1;
        min = min+2*pi*offset;
        max = max+2*pi*offset;
        
    end
    if(deltaXanterior<0 && deltaYanterior<0 && deltaX<0 && deltaY>0)
        offset = offset-1;
        min = min+2*pi*offset;
        max = max+2*pi*offset;
        
    end
    
    % theta
    theta = atan2(deltaY,deltaX)+(2*pi)*offset;
    
    thetaAng = [thetaAng theta];
    
    
    
    
end

plot(thetaOrig);
hold on
plot(thetaAng*180/pi);



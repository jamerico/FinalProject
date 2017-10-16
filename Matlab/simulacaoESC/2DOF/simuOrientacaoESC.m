
%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
freqSenoide = 10*2*pi;

ampSenoide = 20; %deg
ampSenoide2 = 20; 


plot(refXAng.signals.values)
legend('Saida planta','Referência')
grid on



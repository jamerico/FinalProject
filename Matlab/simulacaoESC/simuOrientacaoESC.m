
%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
freqSenoide = 10*2*pi;
ampSenoide = 10; %deg
sim('simulacaoOrientacaoESC.slx')

plot(refXAng.signals.values)
legend('Saida planta','Referência')
grid on



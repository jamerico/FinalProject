
%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
freqSenoide = 1.5*2*pi;
ampSenoide = 15; %deg
% sim('simulacaoOrientacaoESC.slx')

fig1 = figure(1)
subplot(2,1,1);
plot(t.signals.values,funcaoCusto.signals.values)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('Função Custo')
grid on
axis([0 60 6 11])
set(gca,'YTick',(6:1:11))
subplot(2,1,2)
plot(t.signals.values,robot.signals.values*180/pi,t.signals.values,angMaximizante.signals.values)
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('angulo (graus)')
grid on
axis([0 60 -80 400])
set(gca,'YTick',(-80:40:400))
hgexport(fig1,'simulacaoOrientacao') 

fig2 = figure(2)
subplot(2,1,1);
plot(t.signals.values,uEsc.signals.values*180/pi)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('angulo(graus)')
grid on
axis([0 60 -80 260])
set(gca,'YTick',(-80:40:260))
subplot(2,1,2)
plot(t.signals.values,diffTensaoSimu.signals.values)
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('V')
grid on

hgexport(fig2,'simulacaoOrientacaoFuncCusto') 

% save('ensaio_esc_240_movimento.mat');











%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
freqSenoide = 1.5*2*pi;
ampSenoide = 15; %deg
% sim('simulacaoOrientacaoESC.slx')
salvar = true;
label = '2Mudancas';
tSimu = 120;

fig1 = figure(1)
subplot(2,1,1);
plot(t.signals.values,funcaoCusto.signals.values)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('Função Custo')
grid on
axis([0 tSimu 6 11])
set(gca,'YTick',(6:1:11))
subplot(2,1,2)
plot(t.signals.values,robot.signals.values*180/pi,t.signals.values,angMaximizante.signals.values)
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('angulo (graus)')
grid on
axis([0 tSimu -80 400])
set(gca,'YTick',(-80:40:400))
if(salvar)
hgexport(fig1,strcat('simulacaoFuncaoCustoeOrientacao',label)) 
end



fig2 = figure(2)
subplot(2,1,1);
plot(t.signals.values,uEsc.signals.values*180/pi)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('angulo(graus)')
grid on
axis([0 tSimu -80 400])
set(gca,'YTick',(-80:40:400))
subplot(2,1,2)
plot(t.signals.values,diffTensaoSimu.signals.values)
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('V')
grid on
if(salvar)
hgexport(fig2,strcat('simulacaoOrientacaoFuncCustoTensao',label)) 
end
% save('ensaio_esc_240_movimento_1_mudanca.mat');










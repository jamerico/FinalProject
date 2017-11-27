%% real world variables
close all;
robotData = load('C:\Users\Jean\Documents\gitProjetoFinal\ensaiosSalvos\esc_3_mudancas_bruscas\roboData.txt');
signalsData = load('C:\Users\Jean\Documents\gitProjetoFinal\ensaiosSalvos\esc_3_mudancas_bruscas\signalsStream.txt');;
sinalTensao1 = robotData(:,1);
sinalTensao2 = robotData(:,2);
uPIDr = robotData(:,3);
uPIDt = robotData(:,4);
refTheta = robotData(:,5)*180/pi;
theta = robotData(:,6)*180/pi;
x = robotData(:,7);
y = robotData(:,8);
t = robotData(:,9)-robotData(1,9);
source = signalsData(:,1);
gradientStimative = signalsData(:,4);
integralEsc = signalsData(:,5);

maximizante = robotData(:,10);
refPos = robotData(:,11);
erroPos = robotData(:,12);

v1 = sinalTensao1*5/255;
v2 = sinalTensao2*5/255;

ur = v1-v2; %ur angular
ut = v1+v2; %ut linear

% dados para salvar
ensaio = 'esc_1_ref_busca_480_filtroLento';
time = date;
kp = 40;
amp=30;
freq=2;
strBase = strcat(datestr(now,'mm_dd_yyyy_HH_MM_AM'),'_',ensaio,'_','Kp_ ',num2str(kp),'_','Amp_ ',num2str(amp),'_','Freq_ ',num2str(freq));
enableSalve = false;




% posicao robot
figure(1)
plot(t,x,t,y)
legend('posicao x','posicao y');

% posicao
figure(2);
subplot(2,1,1);
plot(t,refPos,t,x);
legend('x ref','x robot');
subplot(2,1,2);
plot(t,ut);
grid on
legend('ut');
if(enableSalve)
    print('xRef_xRobot','-dpng')
end

% orientacao
fig3 = figure;
subplot(2,1,1);
%plot(t,refTheta,t,theta);
plot(t,theta,t,maximizante)
grid on
legend('ang robot', 'ang source')
subplot(2,1,2);
plot(t,ur);
grid on
legend('ur');
if(enableSalve)
    print(strcat(strBase,'_refTheta_theta'),'-dpng');
end
hgexport(fig3,'refxRobo') 



% ang robot x ang source
figure
plot(t,theta,t,maximizante)
grid on
legend('ang robot', 'ang source')
titulo='_theta_maximizante_';
grid on
if(enableSalve)
print(strcat(strBase,titulo),'-dpng');
end
hgexport(fig4,'refxRobo') 


% sinal tensao
figure
plot(t,v1,t,v2)
grid on
legend('v1','v2')
titulo='_sinal_tensao_';
if(enableSalve)
print(strcat(strBase,titulo),'-dpng');
end

% integralESC
fig4 = figure
plot(t,integralEsc*180/pi)
legend('integralESC');
titulo='_integral_ESC_';
grid on
if(enableSalve)
print(strcat(strBase,titulo),'-dpng');
end


% correcao com ganho atuador
gainAtuador = 5/255*0.05/0.0475*2;
figure
plot(t,ur,t,uPIDr*gainAtuador)


plot(t,ur+0*0.2*sin(2*pi*20*t),t,(theta-90)/30)

%% identification rules

% K = 0.8; %% Robot gain
% Kp = 55; %% proportional gain
% sim('identificacaoPlanta.slx')

% a = figure(1);
% % ang
% plot(angSimu.signals.values);
% hold on
% plot(angRobot);
% legend('ang simu','ang robot');

%intervalAngSimu = angSimu.signals.values(1:100);
%intervalAngRobot = angRobot(1:30);

% control signal
% b = figure(2);
% plot(diffTensaoSimu.signals.values);
% hold on
% plot(diffTensaoRobot);
% legend('diff tensao simu','diff tensao robot');


%intervalUSimu = diffTensaoSimu.signals.values(1:100);
%intervalURobot = angdiffTensaoRobotRobot(1:30);

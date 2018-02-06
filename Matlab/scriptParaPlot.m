%% real world variables
close all;
xrobotDataDir = 'C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ProjetoFinalQT\ProjetoFinal\roboData.txt';
signalsDataDir = 'C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ProjetoFinalQT\ProjetoFinal\signalsStream.txt';

robotData = load(xrobotDataDir);
signalsData = load(signalsDataDir);
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
xESC = signalsData(:,8);
yESC = signalsData(:,9);
filterX = signalsData(:,10);
filterY = signalsData(:,11);
    
maximizante = robotData(:,10);
refPos = robotData(:,11);
erroPos = robotData(:,12);

v1 = sinalTensao1*5/255;
v2 = sinalTensao2*5/255;

ur = v1-v2; %ur angular
ut = v1+v2; %ut linear
% dados para salvar
ensaio = 'esc_1_ref_busca_270_filtro0.1';
time = date;
kp = 45;
amp=20;
freq=1.5;
strBase = strcat(ensaio,'_','Kp_ ',num2str(kp),'_','Amp_ ',num2str(amp),'_','Freq_ ',num2str(freq));
localParaSalvamento = 'C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ensaiosSalvos';
fullDir = fullfile(localParaSalvamento,strBase);
enableSave = false;

if(enableSave)
    mkdir(localParaSalvamento,strBase)
    copyfile(xrobotDataDir,fullDir)
    copyfile(signalsDataDir,fullDir)
end

% figure;
% subplot(3,1,1);
% x = x-mean(x);
% plot(t,x)
% subplot(3,1,2);
% source = source-mean(source);
% plot(t,source)
% subplot(3,1,3)
% plot(t,x.*source)


figure;
subplot(2,1,1);
plot(t,xESC)
subplot(2,1,2);
plot(t,yESC)



figure;
subplot(3,1,1);
plot(t,x)
subplot(3,1,2);
plot(t,y)
subplot(3,1,3)
plot(t,source)

%% primeiros plots
% posicao robot
figure(1)
subplot(2,1,1);
plot(t,x,t,y)
legend('posicao x','posicao y');
subplot(2,1,2);
plot(x,y)
viscircles([157,119],10)
legend('robot','fonte');



% posicao
figure(2);
subplot(2,1,1);
plot(t,refPos,t,x);
legend('x ref','x robot');
subplot(2,1,2);
plot(t,ut);
grid on
legend('ut');
titulo = 'xRef_xRobot';
if(enableSave)
    saveas(gcf,fullfile(localParaSalvamento,strBase,titulo),'png');
end

% orientacao
figure(3);
subplot(2,1,1);
plot(t,refTheta,t,theta);
legend('theta ref','theta robot');
subplot(2,1,2);
plot(t,ur);
grid on
legend('ur');
titulo = '_refTheta_theta';
if(enableSave)
    saveas(gcf,fullfile(localParaSalvamento,strBase,titulo),'png');
end



% ang robot x ang source
figure(4)
plot(t,theta,t,maximizante)
grid on
legend('ang robot', 'ang source')
titulo='_theta_maximizante_';
grid on
if(enableSave)
    saveas(gcf,fullfile(localParaSalvamento,strBase,titulo),'png');
end

% sinal tensao
figure(5)
plot(t,v1,t,v2)
grid on
legend('v1','v2')
titulo='_sinal_tensao_';
if(enableSave)
    saveas(gcf,fullfile(localParaSalvamento,strBase,titulo),'png');

end

% integralESC
figure(6)
plot(t,integralEsc*180/pi)
legend('integralESC');
titulo='_integral_ESC_';
grid on
if(enableSave)
    saveas(gcf,fullfile(localParaSalvamento,strBase,titulo),'png');

end



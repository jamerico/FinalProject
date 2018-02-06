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







%% primeiros plots
close all

% apenas para testes
% figure(1)
% subplot(2,1,1);
% plot(t,x,t,y)
% legend('posicao x','posicao y');
% subplot(2,1,2);
% plot(x,y)
% hold on
% plot(166,212,'r*')
% legend('robot','fonte');

% axis([0 tSimu -130 850])
% set(gca,'YTick',(-500:100:100))


% posicao robot e funcao custo
figure(1)
subplot(2,1,1);
plot(t,x,t,y)
hold on
plot(t,70*sin(t*0.04)+119,t,70*cos(t*0.04)+226-70,'linewidth',1.5)
legend('posicao x','posicao y','fonte x', 'fonte y');
set(gca,'YTick',(20:40:240))
grid on
subplot(2,1,2);
plot(t,source)
grid on
legend('funcao custo');


figure(2)
subplot(2,1,1);
plot(t,x,t,y)
hold on
plot(t,70*sin(t*0.04)+119,t,70*cos(t*0.04)+226-70,'linewidth',1.5)
legend('posicao x','posicao y','fonte x', 'fonte y');
set(gca,'YTick',(20:40:240))
grid on
subplot(2,1,2);
plot(x,y,70*sin(t*0.04)+119,70*cos(t*0.04)+226-70)
legend('robot','fonte');




% sinal tensao
figure(3)
subplot(2,1,1);
plot(t,xESC,t,yESC) %offset inicial da referencia para nao partir do zero
hold on
legend('Ref x', 'Ref y');
grid on
subplot(2,1,2);
plot(t,ur,t,ut)
grid on
legend('ur','ut');





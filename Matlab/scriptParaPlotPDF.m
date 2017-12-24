%% real world variables
close all;
diretorioBase = 'G:\Dropbox\Estudos\ProjetoFinal\ensaiosSalvos\esc_1_ref_540';
xrobotDataDir = fullfile(diretorioBase,'roboData.txt');
signalsDataDir = fullfile(diretorioBase,'signalsStream.txt');

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

maximizante = robotData(:,10);
refPos = robotData(:,11);
erroPos = robotData(:,12);

v1 = sinalTensao1*5/255;
v2 = sinalTensao2*5/255;

ur = v1-v2; %ur angular
ut = v1+v2; %ut linear
% dados para salvar
nomeDoEnsaio = '1dof_1ref_540_movendo';
time = date;
kp = 45;
amp=20;
freq=1.5;
tSimu = 85;


fullDir = fullfile(diretorioBase,nomeDoEnsaio);
enableSave = true;

if(enableSave)
    mkdir(diretorioBase,nomeDoEnsaio)
    copyfile(xrobotDataDir,fullDir)
    copyfile(signalsDataDir,fullDir)
end




fig1 = figure(1);
subplot(2,1,1);
plot(t,source)
set(gca,'XTick',(0:5:tSimu))
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('Função Custo')
grid on
axis([0 tSimu -0 11])
set(gca,'YTick',(-0:1:11))
subplot(2,1,2)
plot(t,theta,t,maximizante)
set(gca,'XTick',(0:5:tSimu))
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('angulo (graus)')
grid on
axis([0 tSimu -80 600])
set(gca,'YTick',(-80:100:600))
if(enableSave)
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('experimentoFuncaoCustoeOrientacao',nomeDoEnsaio)),'epsc');
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('experimentoFuncaoCustoeOrientacao',nomeDoEnsaio)),'png');

end


fig2 = figure(2);
subplot(2,1,1);
plot(t,refTheta)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('angulo(graus)')
grid on
axis([0 tSimu -80 600])
set(gca,'YTick',(-80:100:600))
set(gca,'XTick',(0:5:tSimu))
subplot(2,1,2)
plot(t,ur)
set(gca,'XTick',(0:5:tSimu))
axis([0 tSimu -10 10])
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('V')
grid on
if(enableSave)
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('experimentoOrientacaoRefThetaETensao',nomeDoEnsaio)),'epsc');
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('experimentoOrientacaoRefThetaETensao',nomeDoEnsaio)),'png');

end





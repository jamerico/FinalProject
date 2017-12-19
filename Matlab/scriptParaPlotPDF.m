%% real world variables
close all;
diretorioBase = 'G:\Dropbox\Estudos\ProjetoFinal\ensaiosSalvos\esc_1_ref_480_brusca_filtroLentro_2hz_40deg_30kp';
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
nomeDoEnsaio = '1dof_1ref_480';
time = date;
kp = 45;
amp=20;
freq=1.5;
tSimu = 23;


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
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('Função Custo')
grid on
axis([0 tSimu -70 15])
set(gca,'YTick',(-70:10:15))
subplot(2,1,2)
plot(t,theta,t,maximizante)
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('angulo (graus)')
grid on
axis([0 tSimu -80 900])
set(gca,'YTick',(-80:100:900))
if(enableSave)
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('simulacaoFuncaoCustoeOrientacao',nomeDoEnsaio)),'eps');
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('simulacaoFuncaoCustoeOrientacao',nomeDoEnsaio)),'png');

end


fig2 = figure(2);
subplot(2,1,1);
plot(t,refTheta)
title('Figura (a)') 
xlabel('tempo (s)')
ylabel('angulo(graus)')
grid on
axis([0 tSimu -80 900])
set(gca,'YTick',(-80:100:900))
subplot(2,1,2)
plot(t,ur)
axis([0 tSimu -10 10])
title('Figura (b)') 
xlabel('tempo (s)')
ylabel('V')
grid on
if(enableSave)
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('simulacaoOrientacaoFuncCustoTensao',nomeDoEnsaio)),'eps');
    saveas(gcf,fullfile(diretorioBase,nomeDoEnsaio,strcat('simulacaoOrientacaoFuncCustoTensao',nomeDoEnsaio)),'png');

end





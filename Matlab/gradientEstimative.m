roboData = load('C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ProjetoFinalQT\ProjetoFinal\roboData.txt');
signalsEsc = load('C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ProjetoFinalQT\ProjetoFinal\signalsStream.txt');


close all

%h = 1/25;
%t = [0:h:h*(dim(1)-1)];
fig1 = figure(1);
plot(roboData(:,3)*180/pi);
hold
plot(roboData(:,4)*180/pi);

%% plot(signalsEsc(:,2)*180/pi);
plot(signalsEsc(:,1));

fig1 = figure(1);
plot(roboData(:,3)*180/pi);
hold
plot(signalsEsc(:,2)*180/pi);

legend('ang robot', 'saida highPassFilter')


fig2 = figure(2);
plot(signalsEsc(:,3)*180/pi)
hold on
plot(roboData(:,3)*180/pi);


fig2 = figure(2);
plot(signalsEsc(:,4)*180/pi)


fig3 = figure(3);
plot(signalsEsc(:,5)*180/pi)



%A(:,1) = A(:,1)*180/pi;
%dim = size(A);
%h = 1/25;
%t = [0:h:h*(dim(1)-1)];
%plot(t,A);

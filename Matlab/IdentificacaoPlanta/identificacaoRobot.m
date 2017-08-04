%% real world variables
close all;
robotData = load('C:\Users\jeant\OneDrive\Documentos\gitProjetoFinal\ProjetoFinalQT\ProjetoFinal\__roboData_saved_identificacao.txt')

% plot(robotData(:,3))
% hold on
% plot(robotData(:,4))



tensao1 = robotData(:,1)*5/255;
tensao2 = robotData(:,2)*5/255;
angRobot = robotData(:,3);
ref = robotData(:,4);
diffTensaoRobot = -tensao1+tensao2;
%% identification rules

K = 0.8; %% Robot gain
Kp = 25; %% proportional gain
sim('identificacaoPlanta.slx')

a = figure(1);
% ang
plot(angSimu.signals.values);
hold on
plot(angRobot);
legend('ang simu','ang robot');

%intervalAngSimu = angSimu.signals.values(1:100);
%intervalAngRobot = angRobot(1:30);

% control signal
b = figure(2);
plot(diffTensaoSimu.signals.values);
hold on
plot(diffTensaoRobot);
legend('diff tensao simu','diff tensao robot');


%intervalUSimu = diffTensaoSimu.signals.values(1:100);
%intervalURobot = angdiffTensaoRobotRobot(1:30);

%% real world variables
robotData = load('testfile.txt')
diffTensaoRobot = robotData(:,1);
angRobot = robotData(:,2);

%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
sim('identificacaoPlanta.slx')

a = figure(1);
% ang
plot(angSimu.signals.values);
plot(angRobot);

%intervalAngSimu = angSimu.signals.values(1:100);
%intervalAngRobot = angRobot(1:30);

% control signal
plot(diffTensaoSimu.signals.values);
plot(diffTensaoRobot);

%intervalUSimu = diffTensaoSimu.signals.values(1:100);
%intervalURobot = angdiffTensaoRobotRobot(1:30);

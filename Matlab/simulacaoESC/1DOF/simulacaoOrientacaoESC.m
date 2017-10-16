%% real world variables
robotData = load('testfile.txt')
diffTensaoRobot = robotData(:,1);
angRobot = robotData(:,2);

%% identification rules

K = 1; %% Robot gain
Kp = 10; %% proportional gain
sim('identificacaoPlanta.slx')




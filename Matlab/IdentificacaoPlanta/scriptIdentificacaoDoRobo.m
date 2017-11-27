% correcao com ganho atuador
gainAtuador = 5/255*0.05/0.0475*2;
figure
plot(t,ur,t,uPIDr*gainAtuador)


plot(t,ur+0*0.2*sin(2*pi*20*t),t,(theta-90)/30)

% identification rules

K = 0.8; %% Robot gain
Kp = 55; %% proportional gain
sim('identificacaoPlanta.slx')

a = figure(1);
% ang
plot(angSimu.signals.values);
hold on
plot(angRobot);
legend('ang simu','ang robot');

intervalAngSimu = angSimu.signals.values(1:100);
intervalAngRobot = angRobot(1:30);

% control signal 
b = figure(2);
plot(diffTensaoSimu.signals.values);
hold on
plot(diffTensaoRobot);
legend('diff tensao simu','diff tensao robot');


intervalUSimu = diffTensaoSimu.signals.values(1:100);
intervalURobot = angdiffTensaoRobot(1:30);

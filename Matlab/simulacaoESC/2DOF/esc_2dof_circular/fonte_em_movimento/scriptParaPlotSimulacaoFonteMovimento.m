%% real world variables
close all
load fonte_movimento.mat

xstar=30;
ystar=50;

%% primeiros plots
% t = t*0.01;

%% 

% funcao custo, pos robot
figure(1)
subplot(2,1,1);
plot(t,z(:,2),t,400*ones(1,size(t,1)))
ylabel('Função Custo');
xlabel('tempo(s)');
axis([0 max(t) 370 410 ])
set(gca,'XTick',[0:100:1500])
grid on
legend('funcao custo','valor maximo');
subplot(2,1,2);
plot(t,x(:,2),t,xstarArray(1,1:end-(size(xstarArray,2)-size(x(:,2),1))))
grid on
set(gca,'XTick',[0:100:1500])
set(gca,'YTick',[-20:5:30])
ylabel('Posição(cm)');
xlabel('tempo(s)');
axis([0 max(t) -20 30 ])
legend();
hold on 
plot(t,y(:,2),t,ystarArray(1,1:end-(size(ystarArray,2)-size(y(:,2),1))))
set(gca,'XTick',[0:100:1500])
grid on
legend('posicao x','fonte x','posicao y','fonte y');
saveas(gcf,'fonteMovimento_FuncaoCustoEPosicao','png');
saveas(gcf,'fonteMovimento_FuncaoCustoEPosicao','epsc');



% ref esc, tensao
figure(2)
subplot(2,1,1);
plot(t,xrefesc(:,2),t,xstarArray(1,1:end-(size(xstarArray,2)-size(x(:,2),1))),'-.b')
hold on
plot(t,yrefesc(:,2),t,ystarArray(1,1:end-(size(ystarArray,2)-size(y(:,2),1))),'-.k')
axis([0 max(t) -20 30 ])
set(gca,'YTick',[-20:5:30])
set(gca,'XTick',[0:100:1500])
grid on
legend({'referência x ', 'fonte x', 'referência y','fonte y'});
ylabel('Posição(cm)');
xlabel('tempo(s)');
subplot(2,1,2);
plot(t,ur(:,2),t,ut(:,2))
set(gca,'XTick',[0:100:1500])
axis([0 max(t) -10 10 ])
set(gca,'YTick',[-10:2:10])
legend('ur','ut');
ylabel('sinal de controle(V)');
xlabel('tempo(s)');
grid on
saveas(gcf,'fonteMovimento_RefESCeTensao','png');
saveas(gcf,'fonteMovimento_RefESCeTensao','epsc');


figure(3)
plot(x(:,2),y(:,2))
ylabel('Posição(cm)');
xlabel('Posição(cm)');
grid on
hold on
plot(xstarArray(1,1:end-(size(xstarArray,2)-size(x(:,2),1))),ystarArray(1,1:end-(size(ystarArray,2)-size(y(:,2),1))))
legend('Posicao Robô (x,y)', 'Fonte (x,y)');
saveas(gcf,'fonteMovimento_VisaoGeralMovimento','png');
saveas(gcf,'fonteMovimento_VisaoGeralMovimento','epsc');

if(false)
save fonte_movimento.mat
end




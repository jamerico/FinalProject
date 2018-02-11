load fonte_parada.mat
%% real world variables
close all;

xstar=30;
ystar=50;

%% primeiros plots
t = t/60;
%% 

% funcao custo, pos robot
figure(1)
subplot(2,1,1);
plot(t,z(:,2),t,400*ones(1,size(t,1)))
ylabel('Função Custo');
xlabel('tempo(s)');
axis([0 max(t) -3500 500 ])
set(gca,'YTick',[-3600:400:400])
grid on
legend('funcao custo','valor maximo');
subplot(2,1,2);
plot(t,x(:,2),t,xstar*ones(1,size(t,1)))
axis([0 max(t) -10 60 ])
set(gca,'YTick',[-10:10:60])
legend();
hold on 
plot(t,y(:,2),t,ystar*ones(1,size(t,1)))
grid on
legend({'posicao x','fonte x','posicao y','fonte y'},'Position',[0.74 0.15 0.1 0.1]);
ylabel('Posição(cm)');
xlabel('tempo(s)');
saveas(gcf,'fonteParada_FuncaoCustoEPosicao','png');
saveas(gcf,'fonteParada_FuncaoCustoEPosicao','epsc');




% ref esc, tensao
figure(2)
subplot(2,1,1);
plot(t,xrefesc(:,2),t,xstar*ones(1,size(t,1)),'-.b')
hold on
plot(t,yrefesc(:,2),t,ystar*ones(1,size(t,1)),'-.k')
axis([0 max(t) -10 60 ])
set(gca,'YTick',[-10:10:60])
grid on
legend({'referência x ', 'fonte x', 'referência y','fonte y'},'Position',[0.74 0.64 0.1 0.1]);
ylabel('Posição(cm)');
xlabel('tempo(s)');
subplot(2,1,2);
plot(t,ur(:,2),t,ut(:,2))
axis([0 max(t) -10 10 ])
set(gca,'YTick',[-10:2:10])
legend('ur','ur');
ylabel('sinal de controle(V)');
xlabel('tempo(s)');
grid on
saveas(gcf,'fonteParada_RefESCeTensao','png');
saveas(gcf,'fonteParada_RefESCeTensao','epsc');


figure(3)
plot(x(:,2),y(:,2))
grid on
hold on
plot(30,50,'*')
ylabel('Posição(cm)');
xlabel('Posição(cm)');
legend('Posicao Robô (x,y)', 'Fonte (x,y)');
saveas(gcf,'fonteParada_VisaoGeralMovimento','png');
saveas(gcf,'fonteParada_VisaoGeralMovimento','epsc');


if(false)
save fonte_parada.mat
end




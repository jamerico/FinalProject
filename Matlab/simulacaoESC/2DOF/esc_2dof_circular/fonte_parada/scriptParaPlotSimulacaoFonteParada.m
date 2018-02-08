load fonte_parada.mat
%% real world variables
close all;

xstar=30;
ystar=50;

%% primeiros plots

%% 

% funcao custo, pos robot
figure(1)
subplot(2,1,1);
plot(t,z(:,2),t,400*ones(1,size(t,1)))
axis([0 max(t) -3500 500 ])
grid on
legend('funcao custo','valor maximo');
subplot(2,1,2);
plot(t,x(:,2),t,xstar*ones(1,size(t,1)))
axis([0 max(t) -10 60 ])
legend();
hold on 
plot(t,y(:,2),t,ystar*ones(1,size(t,1)))
grid on
legend('posicao x','fonte x','posicao y','fonte y');
saveas(gcf,'fonteParada_FuncaoCustoValorMaximo','png');
saveas(gcf,'fonteParada_FuncaoCustoValorMaximo','epsc');



% ref esc, tensao
figure(2)
subplot(2,1,1);
plot(t,xrefesc(:,2),t,yrefesc(:,2))
axis([0 max(t) -10 60 ])
grid on
legend('posicao x','fonte x');
subplot(2,1,2);
plot(t,ur(:,2))
axis([0 max(t) -10 10 ])
legend('ur');
grid on
saveas(gcf,'fonteParada_RefESCeTensao','png');
saveas(gcf,'fonteParada_RefESCeTensao','epsc');


figure(3)
plot(x(:,2),y(:,2))
grid on
hold on
plot(30,50,'*')
legend('Posicao Robô (x,y)', 'Fonte (x,y)');
saveas(gcf,'fonteParada_VisaoGeralMovimento','png');
saveas(gcf,'fonteParada_VisaoGeralMovimento','epsc');


if(false)
save fonte_parada.mat
end




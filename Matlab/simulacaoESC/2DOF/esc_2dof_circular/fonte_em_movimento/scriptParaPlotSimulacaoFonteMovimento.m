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
axis([0 max(t) 370 410 ])
grid on
legend('funcao custo','valor maximo');
subplot(2,1,2);
plot(t,x(:,2),t,xstarArray(1,1:end-(size(xstarArray,2)-size(x(:,2),1))))
axis([0 max(t) -15 25 ])
legend();
hold on 
plot(t,y(:,2),t,ystarArray(1,1:end-(size(ystarArray,2)-size(x(:,2),1))))
grid on
legend('posicao x','fonte x','posicao y','fonte y');
saveas(gcf,'fonteMovimento_FuncaoCustoValorMaximo','png');
saveas(gcf,'fonteMovimento_FuncaoCustoValorMaximo','eps');



% ref esc, tensao
figure(2)
subplot(2,1,1);
plot(t,xrefesc(:,2),t,yrefesc(:,2))
axis([0 max(t) -20 30 ])
grid on
legend('Ref ESC x','Ref ESC y');
subplot(2,1,2);
plot(t,ur(:,2))
axis([0 max(t) -10 10 ])
legend('ur');
grid on
saveas(gcf,'fonteMovimento_RefESCeTensao','png');
saveas(gcf,'fonteMovimento_RefESCeTensao','eps');


figure(3)
plot(x(:,2),y(:,2))
grid on
hold on
plot(xrefesc(:,2),yrefesc(:,2))
legend('Posicao Robô (x,y)', 'Fonte (x,y)');
saveas(gcf,'fonteMovimento_VisaoGeralMovimento','png');
saveas(gcf,'fonteMovimento_VisaoGeralMovimento','eps');

if(false)
save fonte_movimento.mat
end




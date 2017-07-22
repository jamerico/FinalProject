% % filename = '20170116_121848.txt';
% filename = 'teste.txt';
% 
% fileID = fopen(filename,'r');
% % TimeStamp|Ticks|FrameNum|FPS|Robo|achou|trajetoria|Xd|Yd|Xa|Ya|DistMelhorPonto|velAtual|velDesejada|erroVel|angAtual|angDesejado|erroAng|
% % formatSpec = '%s | %i | %i | %f| %s| %i| %s| %i| %i| %i| %i| %f| %f| %f| %f| %f| %f| %f|';
% formatSpec = '%i| %i| %i| %i|';
% sizeA = [4 Inf];
% % A = fscanf(fileID,formatSpec)
% A = fscanf(fileID,formatSpec, sizeA)
% 
% % M = dlmread(filename,'|',1,1)
% 
% 
% filename1 = 'teste1.txt';
% fileID1 = fopen(filename1,'r');
% formatSpec = '%s | %i| %i| %i|';
% sizeA1 = [4 Inf];
% B = fscanf(fileID1,formatSpec, sizeA1)
% 
% 
% filename2 = 'teste2.txt';
% fileID2 = fopen(filename2,'r');
% formatSpec = '%s %s %s %s ';
% sizeA2 = [1 Inf];
% C = fscanf(fileID2,formatSpec, sizeA2)
% 
% filename3 = 'teste2.dat';
% fileID3 = fopen(filename3);
% formatSpec = '%s| %d| %d| %d|';
% D = textscan(fileID3,formatSpec)
% 
% 
% 
% 
% 
% 
% 
% %%
% % Condicoes encontradas
% % 1 - String n pode ser vazia a leitura de string do matlab e do inicio ate o 1
% %   espaco em branco, entao éh melhor colocar _ no lugar de vazio
% % 2 - O Xd n pode ser vazio, colocar pra quando n encontrar o -1 msm
% % OBS: colocar espaco no final de cada valor adicionado no log
% 
% 
% % filename4 = '20170116_121848.txt';
% filename4 = '20170121_145356.txt';
% fileID4 = fopen(filename4,'r');                                            %SinalDeControle2 |                                              
% % TimeStamp|Ticks|FrameNum|FPS|Robo|achou|trajetoria|Xd|Yd|Xa|Ya|DistMelhorPonto|velAtual|velDesejada|erroVel|angAtual|angDesejado|erroAng|
% formatSpec4 = '%s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s|';
% % formatSpec41 = '%s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s| %s|';
% % formatSpec = '%i| %i| %i| %i|';
% sizeA = [20 Inf];
% % A = fscanf(fileID,formatSpec)
% % ah = textscan(fileID4, formatSpec41, sizeA)
% Aas = textscan(fileID4,formatSpec4)
% 

%%
% Problemas:
% 1 - Ao menos a 1 linha da ultima colunas precisa estar preenchida
% 2 - A bosta das colunas precisam ter o mesmo tamanho no caso das strings
clear
close all
clc

% TimeStamp | Ticks | FrameNum | FPS | LogaDados | Robo | achou | trajetoria | Xd | Yd | Xa | Ya | DistMelhorPonto | velAtual | velDesejada | erroVel | SaidaControleLinear | angAtual | angDesejado | erroAng | SaidaControleAngular | SinalDeControle1 | SinalDeControle2 | 
filename = '20170212_112221.txt';
delimiterIn = '|';
headerlinesIn = 1;
dados = importdata(filename,delimiterIn,headerlinesIn);

headers = dados.textdata(1, :);


%% TRATAMENTO PARA O TAMANHO DAS COLUNAS (as q vieram como string)

stringHeaders = {'TimeStamp', 'Robo', 'trajetoria'}; % Headers do tipo String
% trajetoria aqui e o ultimo elemento string do log
for i=1:find(strcmp(dados.textdata(1, :), 'trajetoria'))
%     maxSize = size(cell2mat(dados.textdata(end, i)), 2);  % pega o tamanho do ultimo elemento da coluna
    maxSize = size(cell2mat(dados.textdata(2, i)), 2);      % pega o tamanho do primeiro elemento da coluna
    % Loop para coletar o tamanho do maior elemento da coluna
    for elemento=3:length(dados.textdata(:, 4))
        if maxSize < size(cell2mat(dados.textdata(elemento, i)), 2)
            maxSize = size(cell2mat(dados.textdata(elemento, i)), 2);
        end
    end
    
    if ismember(strtrim(headers(1, i)), stringHeaders)
        for j=1:length(dados.textdata(1:end, i)) % varre todas as linhas             
            while(maxSize > size(cell2mat(dados.textdata(j, i)), 2))
                % Pra cada linha adiciona n elementos, em que n eh a
                % diferenca entre o tamanho max da coluna e o tamanho do
                % individo em analise
                dados.textdata(j, i) = strcat(dados.textdata(j, i), '-');
            end         
        end        
    else
        for j=1:length(dados.textdata(1:end, i)) % varre todas as linhas             
            while(maxSize > size(cell2mat(dados.textdata(j, i)), 2))
                % Pra cada linha adiciona n elementos, em que n eh a
                % diferenca entre o tamanho max da coluna e o tamanho do
                % individo em analise
                %dados.textdata(j, i) = strcat(dados.textdata(j, i), '0');
                dados.textdata(j, i) = strcat('0', dados.textdata(j, i));
            end         
        end
    end    
end

strCounter = 1;
numCounter = 1;

% Varre os headers para atribuir um array pra cada um
for idx = 1:size(headers, 2)-1
        headers{2, idx} = []; % Inicializa com vazio
        isString = false;
        
        % Verifica se eh do tipo String e caso seja atribui o array de
        % string nele
        for strIdx = 1:length(stringHeaders)
            if ismember(strtrim(headers(1, idx)), stringHeaders)
                isString = true;
                headers{2, idx} = dados.textdata(2:end,strCounter);
                strCounter = strCounter + 1;
                break;
            end
            
        end
        if ~isString
            if (idx <= 8)
                temp = cell2mat(dados.textdata(2:end, idx));
                headers(2, idx) = {str2num(temp)};
                strCounter = strCounter + 1;
            else
                if numCounter <= size(dados.data, 2)
                    headers{2, idx} = dados.data(:, numCounter);
                end                
                numCounter = numCounter + 1;
            end
        end        
end


%% PLOTS


% filtrando os nomes dos carros
carros = {};
for i=1:size(headers{2, 6},1)
    if ~ismember(headers{2, 6}(i), carros)
        carros = [carros; headers{2, 6}(i)];
    end
end

containerCarros = {};
% ESTRUTURA DO CONTAINER
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%1 % Nome(1)                 | Nome(2)                 | ...
%2 % Indices(1)              | Indices(2)              | ...
%3 % Ticks(1)                | Ticks(2)                | ...
%4 % Frame(1)                | Frame(2)                | ...
%5 % FPS(1)                  | FPS(2)                  | ...
%6 % Achou(1)                | Achou(2)                | ...
%7 % Trajetoria(1)           | Trajetoria(2)           | ...
%8 % Xd(1)                   | Xd(2)                   | ...
%9 % Yd(1)                   | Yd(2)                   | ...
%10% Xa(1)                   | Xa(2)                   | ...
%11% Ya(1)                   | Ya(2)                   | ...
%12% DistMelhorPonto(1)      | DistMelhorPonto(2)      | ...
%13% velAtual(1)             | velAtual(2)             | ...
%14% velDerivadaSuja(1)      | velDerivadaSuja(2)      | ...
%15% velDesejada(1)          | velDesejada(2)          | ...
%16% erroVel(1)              | erroVel(2)              | ...
%17% SaidaControleLinear(1)  | SaidaControleLinear(2)  | ...
%18% angAtual(1)             | angAtual(2)             | ...
%19% angDesejado(1)          | angDesejado(2)          | ...
%20% erroAng(1)              | erroAng(2)              | ...
%21% SaidaControleAngular(1) | SaidaControleAngular(2) | ...
%22% SinaldeControle1(1)     | SinaldeControle1(2)     | ...
%23% SinaldeControle2(1)     | SinaldeControle2(2)     | ...
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




indicesDesnecessarios = [5, 6, 24];
for i=1:size(carros, 1)
    containerCarros{1, i}  = carros(i);
    containerCarros{2, i}  = find(strcmp(headers{2, 6}, carros(i)));
    containerCarros{3, i}  = headers{2, 2}(containerCarros{2, i});   % ticks
    containerCarros{4, i}  = headers{2, 3}(containerCarros{2, i});   % frame
    containerCarros{5, i}  = headers{2, 4}(containerCarros{2, i});   % fps
    for j=7:size(headers,2)
        if (~isempty(headers{2, j}) && ~ismember(j, indicesDesnecessarios))
            containerCarros{j-1, i} = headers{2, j}(containerCarros{2, i});
        else
            containerCarros{j-1, i} = [];
        end
    end
end

% SEPARACAO POR CARROS

set(0,'defaultfigurecolor',[1 1 1]) % muda o fundo das figuras
indicesParaNaoPlotar = [1, 2, 3, 7];
for i=1:size(carros, 1) % para cada carro plotar n figuras
    %tempo = containerCarros{3, i} - containerCarros{3, i}(1);
    tempo = containerCarros{4, i};
%     for j=1:length(containerCarros) % loop para as n figuras
%         if (~isempty(containerCarros{j, i}) && ~ismember(j, indicesParaNaoPlotar))
%             figure        
%             plot(tempo, containerCarros{j, i})
%             title(strtrim(containerCarros{1, i}))
%         end
%     end
    
%     %Plot de XxY 
%     figure
%     plot(containerCarros{8, i}, containerCarros{9, i})
%     title([ '\fontsize{12}Xd x Yd (' cell2mat(containerCarros{1, i}) ')']) 
%     figure
%     plot(containerCarros{10, i}, containerCarros{11, i})
%     title([ '\fontsize{12}Xa x Ya (' cell2mat(containerCarros{1, i}) ')'])
    
    %Plot de (XdxYd) vs (XaxYa)
    figure
    
    plot(containerCarros{8, i}, containerCarros{9, i},'-r', containerCarros{10, i}, containerCarros{11, i},'-b')
    axis([0, 640, 0, 480])
%     scatter(containerCarros{8, i}, containerCarros{9, i},'-r', containerCarros{10, i}, containerCarros{11, i},'-b')
    legend('\fontsize{8}TrajetoriaDesejada','\fontsize{8}TrajetoriaRealizada');
    title([ '\fontsize{12}TrajetoriaDesejada x TrajetoriaRealizada (' cell2mat(containerCarros{1, i}) ')'])
    
    % Plot de (Xd, Xa), (Yd, Ya) e (Angd, Anga)
    figure
    subplot(3,1,1)
%         plot(tempo, containerCarros{8, i},'-r',tempo,containerCarros{10, i},'-b',tempo,containerCarros{12, i},'-g')
        plot(tempo,containerCarros{8, i},'-r', tempo,containerCarros{10, i},'-b')
        legend('\fontsize{8}Xd','\fontsize{8}Xa');
        title(['\fontsize{12}Xd vs Xa(' cell2mat(containerCarros{1, i}) ')'])
        grid on

    subplot(3,1,2)
        plot(tempo,containerCarros{9, i},'-r', tempo,containerCarros{11, i},'-b')
        legend('\fontsize{8}Yd','\fontsize{8}Ya');
        title(['\fontsize{12}Yd vs Ya(' cell2mat(containerCarros{1, i}) ')'])
        grid on

    subplot(3,1,3)
        plot(tempo,containerCarros{19, i},'-r', tempo,containerCarros{18, i},'-b')        
        legend('\fontsize{8}AngDesejado','\fontsize{8}AngAtual');
        title(['\fontsize{12}AngDesejado vs AngAtual (' cell2mat(containerCarros{1, i}) ')'])
        grid on   
    
    % VelDesejada vs VelAtual
    figure
    %plot(tempo,containerCarros{15, i},'-r', tempo,containerCarros{14, i},'-b')
    hold on
    scatter(tempo,containerCarros{15, i});
    scatter(tempo,containerCarros{14, i});
	legend('\fontsize{8}VelDesejada','\fontsize{8}VelAtual(SUJA)');
    title([ '\fontsize{12}VelDesejada x VelAtual (' cell2mat(containerCarros{1, i}) ')'])
    
    % AngDesejado vs AngAtual
    figure    
    plot(tempo,containerCarros{19, i},'-r', tempo,containerCarros{18, i},'-b')
    legend('\fontsize{8}AngDesejado','\fontsize{8}AngAtual');
    title([ '\fontsize{12}AngDesejado x AngAtual (' cell2mat(containerCarros{1, i}) ')'])
    
    % Plot de (V1xTempo), (V2xTempo)
    if (~isempty(containerCarros{22, i}) && ~isempty(containerCarros{23, i}))
        figure
        subplot(2,1,1)
            plot(tempo,containerCarros{22, i})
            title(['\fontsize{12}Sinal de Tensão 1 (' cell2mat(containerCarros{1, i}) ')'])
            grid on

        subplot(2,1,2)
            plot(tempo,containerCarros{23, i})
            title(['\fontsize{12}Sinal de Tensão 2 (' cell2mat(containerCarros{1, i}) ')'])
            grid on
    end
        
%     % Plot de (UxTempo), (WxTempo)
%     if (~isempty(containerCarros{16, i}) && ~isempty(containerCarros{20, i}))        
%         figure
%         subplot(2,1,1)
%             plot(tempo,containerCarros{16, i})
%             title(['\fontsize{12}Saída Controle Linear U (' cell2mat(containerCarros{1, i}) ')'])
%             grid on
% 
%         subplot(2,1,2)
%             plot(tempo,containerCarros{20, i})
%             title(['\fontsize{12}Saída Controle Angular W (' cell2mat(containerCarros{1, i}) ')'])
%             grid on
%     end    
end

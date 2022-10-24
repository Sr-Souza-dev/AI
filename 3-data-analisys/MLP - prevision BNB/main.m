clear; close all; clc;

qtdCols = 3;                        %Define quantas colunas irei utilizar levando em consedaração o arquivo importado%

%Importando os dados para o programa%
data = readmatrix('C:\Users\gabri\OneDrive\Área de Trabalho\ia\matLab\bnb.csv');
data = data(4:1090, 2:17);          %Removendo coluna de datas%

%Definindo dados de atuação%
x = data(:, 1:qtdCols);             %Rows and columns (definindo variaveis de entrada)%
y = data(:,16);                     %Rows and Columns (definindo variavel de previsão)%
m = length(y);                      %Pega a quantidade de dados que temos para resultados%

%Visualizar os dados%
histogram(y,10);                    %Exibe um histograma com o range de valores possiveis e seu suposto peso%
histogram(y2,10);
%Plota varios gráficos das relações das variaveis escolhidas com a saída desejada%

%Normalize the features and transform the output%
y2 = log(1+y);                                                      %Normaliza a saída desejada%
for i = 1:1:qtdCols                                                 %Normaliza as entradas%
    x2(:,i) = (x(:,i)-min(x(:,i)))/(max(x(:,i)) - min(x(:,i)));
end
histogram(x2(:,1),10);

%Plota varios gráficos das relações das variaveis escolhidas com a saída desejada (todas normalizadas)%
for i = 1:1:qtdCols
    subplot(ceil(sqrt(qtdCols)),ceil(sqrt(qtdCols)),i);            %Define quantos grids de plot e qual a posição do plot atual no grid 
    plot(x2(:,i),y2, 'o');
    title(strcat('y/x norm Col-', num2str(i)));
end

xt = x2';                                       %Calculando a matriz transposta de entradas (pois a função de treinamento so aceita assim)%
yt = y2';                                       %Calculando a matriz transposta de saída (pois a função de treinamento so aceita assim)%

bestPercentError = 100;
bestQtdNeuron = 0;
maxNeurons = 60;

%Otimizando o numero de neuronios na camada interna (verificando o melhor resultado de acordo a qtd)%
for i = 1:1:maxNeurons                              %testando redes com de 1 até 60 neuronios na camada interna%
    %Treinando a rede neural%
    hiddenLayerSize = i;                            %Número de neurônios da camada oculta%
    net = fitnet(hiddenLayerSize);                  %Cria a rede neural com 12 neuron na camada interna <qtdCols> na camada de entrada e 1 na camada de saída%

    %Define a porcentagem de dados utilizados para as etapas de (Treino, validação e test)%
    net.divideParam.trainRation = 70/100;           %Porcentagem de treinamento%
    net.divideParam.valRation = 20/100;             %Porcentagem de validação%
    net.divideParam.testRation = 10/100;            %Porcentagem de teste%

    %Treinando o modelo%
    [net, tr] = train(net, xt, yt);                 %tr nos da informações sobre o desempenho da rede no treinamento%

    %Verificando a performance da rede neural%
    ytrain = exp(net(xt(:,tr.trainInd)))-1;
    ytrainTrue = exp(yt(tr.trainInd))-1;
    percentTrainError(i) = sqrt(mean((ytrain-ytrainTrue).^2));     %Tira o erro quadrado médio%

    yVal = exp(net(xt(:,tr.valInd)))-1;
    yValTrue = exp(yt(tr.valInd))-1;
    percentValidationError(i) = sqrt(mean((yVal-yValTrue).^2));    %Tira o erro quadrado médio%

    yTest = exp(net(xt(:,tr.testInd)))-1;
    yTestTrue = exp(yt(tr.testInd))-1;
    percentTestError(i) = sqrt(mean((yTest-yTestTrue).^2));        %Tira o erro quadrado médio%
    
    %Seleciona o melhor desempenho gerado pela rede%
    if (2*percentTestError(i) + percentValidationError(i) + percentTrainError(i))/4 < bestPercentError
        bestPercentError = (2*percentTestError(i) + percentValidationError(i) + percentTrainError(i))/4;
        bestQtdNeuron = i;
    end
end

%Plotando o gráfico que mostra a taxa de erro por qtd de neuronios%
figure(2);
title("Error/qtd of neuron");
xlabel("Número de neurônios","FontSize",14);
ylabel("Porcentagem de erro");
plot(1:maxNeurons, percentTestError,"g"); hold on;
plot(1:maxNeurons, percentValidationError,"b"); hold on;
plot(1:maxNeurons, percentTrainError,"r"); hold off;
legend("Test","Validation", "Train");


%Treinando a rede neural com a melhor qtd de neuronios%
hiddenLayerSize = bestQtdNeuron;                %Número de neurônios da camada oculta%
net = fitnet(hiddenLayerSize);                  %Cria a rede neural com 12 neuron na camada interna <qtdCols> na camada de entrada e 1 na camada de saída%

%Define a porcentagem de dados utilizados para as etapas de (Treino, validação e test)%
net.divideParam.trainRation = 70/100;           %Porcentagem de treinamento%
net.divideParam.valRation = 20/100;             %Porcentagem de validação%
net.divideParam.testRation = 10/100;            %Porcentagem de teste%

%Treinando o modelo%
[net, tr] = train(net, xt, yt);                 %tr nos da informações sobre o desempenho da rede no treinamento%

%Verificando a performance da rede neural%
ytrain = exp(net(xt(:,tr.trainInd)))-1;
ytrainTrue = exp(yt(tr.trainInd))-1;
percentTrainError = sqrt(mean((ytrain-ytrainTrue).^2));     %Tira o erro quadrado médio%

yVal = exp(net(xt(:,tr.valInd)))-1;
yValTrue = exp(yt(tr.valInd))-1;
percentValidationError = sqrt(mean((yVal-yValTrue).^2));    %Tira o erro quadrado médio%

yTest = exp(net(xt(:,tr.testInd)))-1;
yTestTrue = exp(yt(tr.testInd))-1;
percentTestError = sqrt(mean((yTest-yTestTrue).^2));        %Tira o erro quadrado médio%

%Visualizar um grafico da saida desejada com os dados previstos%
figure(3);
plot(yTestTrue, yTest,"."); hold on;
plot(yValTrue, yVal,"o"); hold on;
plot(yTestTrue, yTestTrue,"g"); hold off;
title("Saída real x Saída do modelo");
legend("'.' Test","'o' Validation", "Real Data");




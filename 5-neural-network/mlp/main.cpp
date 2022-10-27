#include "bits/stdc++.h"
#include "headers/layers.hpp"


float ativation(float x, float limiar){
	if (x>limiar) return 1;
	return 0;
}

float ativation1(float x, float limiar){
	if(x>1) return 1;
	if(x<0) return 0;
	return x;
}

float custFunc(float val){
	return 1/cosh(val);
}

int main(){
	// Definição da base de dados
	vector<vector<float>> X = {
		{0, 0, 1, 1},
		{0, 1, 0, 1}
	};
	vector<float> Out = {0, 1, 1, 0};

	// Parametros de ajuste da rede neural
	float alpha 	= 0.1;
	float limiar 	= 0.3; 
	float bias      = -1;
	int maxEpoc		= 2000;

	vector<int> qtdNeurEachLayer 						= {2, 1};
	vector<function<float(float,float)>> ativEachLayer 	= {&ativation1, &ativation};

	// Declara a rede MLP
	Layers network(X.size(), qtdNeurEachLayer.size(), alpha, qtdNeurEachLayer, ativEachLayer);
	network.print(); cout<<endl;

	// Realiza o treinamento da rede
	int epoc = 0, okay, cont;
	float eps = 1e-4;
	vector<float> input;
	while(epoc < maxEpoc){
		cont=0;
		for(int in=0; in<Out.size(); in++){
			okay = 0;

			// Define a entrada
			input.clear();
			for(int i=0; i<X.size(); i++) input.push_back(X[i][in]);
			

			// Realiza o treinamento da rede
			network.calculate(input, limiar, bias); 
			network.backPropagation(input,{Out[in]}, bias, &custFunc);

			// Verifica quantos acertos a rede teve com aquele dados
			for (int i=0; i<network.layers[network.layers.size()-1].size(); i++){
				if(abs(network.layers[network.layers.size()-1][i].out - Out[in]) < eps) okay++;
			} 
			if (okay == network.layers[network.layers.size()-1].size()) cont++;
		}
		if (cont >= Out.size()) break;
		epoc++;
	}

	// Testa a rede com valores imputados manualmente
	float inX1, inX2;
	do{
		cin>>inX1>>inX2;
		network.calculate({inX1, inX2}, limiar, bias);

		for (int i=0; i<network.layers[network.layers.size()-1].size(); i++){
			cout<<network.layers[network.layers.size()-1][i].out<<endl;
		} 
	}while(inX1 != 99);

	// Printa o estado final da rede com todos seus neuronios e pesos 
	network.print(); cout<<endl;
	printf("\n \n Epoca: %d \n\n",epoc);
}
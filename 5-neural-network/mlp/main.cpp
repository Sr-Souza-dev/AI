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
	return cos(val)/1.5;
}

int main(){
	// Definição da base de dados
	vector<float> x1 = {0, 0, 1, 1};
	vector<float> x2 = {0, 1, 0, 1};
	vector<float> Out = {0, 1, 1, 0};

	// Parametros de ajuste da rede neural
	float learn = 0.01, limiar = 0.2, bias = 0.2;
	vector<int> qtdL = {2, 1};
	vector<function<float(float,float)>> qtdFunc = {&ativation1,&ativation};

	Layers network(2, 2, 0.1, qtdL, qtdFunc);
	network.print(); cout<<endl;

	// Realiza o treinamento da rede
	int epoc = 0, okay, cont;
	float eps = 1e-4;
	while(epoc < 10000){
		cont=0;
		for(int in=0; in<x1.size(); in++){
			okay = 0;
			network.calculate({x1[in], x2[in]}, limiar);
			network.backPropagation({x1[in], x2[in]},{Out[in]}, learn, &custFunc);
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
		network.calculate({inX1, inX2}, limiar);

		for (int i=0; i<network.layers[network.layers.size()-1].size(); i++){
			cout<<network.layers[network.layers.size()-1][i].out<<endl;
		} 
	}while(inX1 != 99);

	// Printa o estado final da rede com todos seus neuronios e pesos 
	network.print(); cout<<endl;
	printf("\n \n Epoca: %d \n\n",epoc);
}
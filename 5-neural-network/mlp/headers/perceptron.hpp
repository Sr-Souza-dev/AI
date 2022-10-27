#pragma once
#include <bits/stdc++.h>

#define dbg(X) printf("Passou %d \n", X);

using namespace std;

class Perceptron{
    protected:
    vector<float> w, in;
    function<float(float,float)> ativation;

    public:
	float neuron, out, del;

    Perceptron();
	Perceptron(int inQtd, function<float(float,float)>ativation);												        // Quantidade de entradas | função de ativação

	void calculate  (vector<float> in, float limiar);																    // Vector de entrada | Limiar de Ativação
    void recalculate(vector<float> in, float alpha, vector<Perceptron> *lastLayer, function<float(float)> custFunc, bool valid);  	// Vector de entrada | Taxa de aprendizagem | Erro ponderado | função de custo | definição se é hidde

	void print();
};
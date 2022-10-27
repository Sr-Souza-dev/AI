#pragma once
#include "perceptron.hpp"

using namespace std;

class Layers{
    float alpha;

    public:
    vector<vector<Perceptron>> layers;
    
    Layers  ();
    Layers  (int inQtd, int layersQtd, float alpha, vector<int> qtdEachLay, vector<function<float(float,float)>> ativationEachLay);     // Qtd de entradas | Qtd de camadas | taxa de aprendizagem | vector qtd de neuron em cada camada | função de ativação de cada camada

    void calculate          (vector<float> in, float limiar, float bias);
    void backPropagation    (vector<float> in, vector<float> out, float bias, function<float(float)> custFunc);
    void print              ();
};
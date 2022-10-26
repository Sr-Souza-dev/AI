#include "../headers/layers.hpp"

Layers::Layers(){}
Layers::Layers(int inQtd, int layersQtd, float alpha, vector<int> qtdEachLay, vector<function<float(float,float)>> ativationEachLay){
    this->alpha = alpha;
    int qtd = layersQtd, idx;
    int inMx = 0;
    vector<Perceptron> aux;    

    idx = qtd - layersQtd;
    while(layersQtd--){
        inMx = qtdEachLay[idx];
        while (inMx--)
        {
            aux.push_back(Perceptron(inQtd,ativationEachLay[idx]));
        }  
        layers.push_back(aux);      aux.clear();
        inQtd = qtdEachLay[idx];
        idx = qtd - layersQtd;
    }
}

void Layers::calculate(vector<float> in, float limiar){
    vector<float> aux;
    for(int layer=0; layer<layers.size(); layer++){
        for(int neur=0; neur<layers[layer].size(); neur++){
            layers[layer][neur].calculate(in, limiar);
            aux.push_back(layers[layer][neur].out);
        }
        in.clear();
        in = aux;
        aux.clear();
    }
}



//void Perceptron::recalculate(vector<float> in, float alpha, float err, function<float(float)> custFunc, bool ishidde){
void Layers::backPropagation(vector<float> in, vector<float> out, float alpha, function<float(float)> custFunc){
    vector<float> curIn;
    for(int neur=0; neur<layers[layers.size()-1].size(); neur++){
        layers[layers.size()-1][neur].del = (out[neur] - layers[layers.size()-1][neur].out) * pow(custFunc(layers[layers.size()-1][neur].neuron),2);
    }

    for(int lay=layers.size()-1; lay>=0; lay--){

        if(lay>0){
            for(int neur=0; neur<layers[lay-1].size(); neur++){
                curIn.push_back(layers[lay][neur].out);
            }
        }else curIn = in;
        
        for(int neur=0; neur<layers[lay].size(); neur++){
            layers[lay][neur].recalculate(curIn, alpha, &layers[lay-1], custFunc); //Melhorar aqui
        }
        curIn.clear();
    }
}

void Layers::print(){
    for(int layer=0; layer<layers.size(); layer++){
        printf("\n ********************** Camada %d ********************** \n",layer+1);
        for(int neur=0; neur<layers[layer].size(); neur++){
            printf("Neuron: %d,%d   ->   ",layer+1,neur+1);
            layers[layer][neur].print();
        }
    }
}
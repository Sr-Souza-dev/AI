#include "../headers/perceptron.hpp"


Perceptron::Perceptron(){}
Perceptron::Perceptron(int inQtd, function<float(float,float)>ativation){
    out = 0; neuron = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.3, 0.7);

    for(int i=0; i<inQtd; i++){
        w.push_back(dist(gen));
    }
    this->ativation = ativation;
}

void Perceptron::calculate(vector<float> in, float limiar = -99){             
    float x = 0; this->in = in;
    for(int i=0; i<in.size(); i++){
        x += w[i]*in[i];
    }
    this->neuron = x;
    this->out = ativation(x, limiar);
}

void Perceptron::recalculate(vector<float> in, float alpha, vector<Perceptron> *lastLayer, function<float(float)> custFunc) {   
    for(int i=0; i<in.size(); i++){
        if(!(*lastLayer).empty()) (*lastLayer)[i].del = this->del * pow(custFunc(neuron),2) * w[i];
        w[i] +=  alpha * this->del * in[i];
    }
}

void Perceptron::print(){
    printf("In: ");
    for(auto it : in){
        printf("%.3f,  ",it);
    }printf("   ");

    printf(" Out(U): %.5f;       Out(I): %.5f;       Pesos   ->   ",neuron,out);
    for(auto it : w){
        printf("%.3f,  ",it);
    }
    printf("\n");
}
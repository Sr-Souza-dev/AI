#include "../headers/perceptron.hpp"


Perceptron::Perceptron(){}
Perceptron::Perceptron(int inQtd, function<float(float,float)>ativation){
    out = 0; neuron = 0; del = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.2, 0.6);

    for(int i=0; i<inQtd; i++){
        w.push_back(dist(gen));
    }
    this->ativation = ativation;
}

void Perceptron::calculate(vector<float> in, float limiar = -99){             
    float x = 0; this->in = in; del = 0;
    for(int i=0; i<in.size(); i++){
        x += w[i]*in[i];
    }
    this->neuron = x;
    this->out = ativation(x, limiar);
}

void Perceptron::recalculate(vector<float> in, float alpha, vector<Perceptron> *lastLayer, function<float(float)> custFunc, bool valid) {   
    for(int i=0; i<in.size(); i++){
        if(valid and i<in.size() - 1) {
           (*lastLayer).at(i).del += (this->del * pow(custFunc(neuron),2) * w[i]);
        }
        w[i] +=  alpha * this->del * in[i];
    }
}

void Perceptron::print(){
    printf("In: ");
    for(auto it : in){
        cout<<setw(10)<<setprecision(3)<<it;
    }printf("   ");


    cout<<"     Out(U):"<<setw(7)<<setprecision(3)<<neuron;
    cout<<"     Out(I):"<<setw(7)<<setprecision(3)<<out;
    cout<<"     Pesos: ";
    for(auto it : w){
        cout<<setw(7)<<setprecision(3)<<it;
    }
    printf("\n");
}
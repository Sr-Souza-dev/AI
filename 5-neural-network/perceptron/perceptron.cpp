#include "bits/stdc++.h"
using namespace std;


int ativation(float x, float limiar){
	if (x>limiar) return 1;
	return 0;
}


class Perceptron{
	vector<float> w;
public:
	Perceptron(){}
	Perceptron(int inQtd){
		for(int i=0; i<inQtd; i++){
			w.push_back(0.5);
		}
	}

	void recalculate(float err, vector<int> in, float alpha){
		for(int i=0; i<in.size(); i++){
			w[i] +=  alpha*in[i]*err;
		}
	}

	int calculate(vector<int> in, float limiar){
		float x = 0;
		for(int i=0; i<in.size(); i++){
			x += w[i]*in[i];
		}
		return ativation(x, limiar);
	}
};


int main(){
	vector<int> x1 = {0, 0, 1, 1};
	vector<int> x2 = {0, 1, 0, 1};
	vector<int> Out = {0, 0, 0, 1};

	Perceptron p(2);

	float alpha  = 0.1;
	float limiar = 0.4;

	int cont, qtd=0;
	float err=0;

	while(qtd<200){
		cont = 0; qtd++;
		for(int i=0; i<x1.size(); i++){
			err = Out[i] - p.calculate({x1[i], x2[i]}, limiar);
			if(err == 0) cont++;

			p.recalculate(err, {x1[i], x2[i]}, alpha);
		}
		if (cont>=4) break;
	}

	int inX1=0, inX2=0;

	do{
		cin>>inX1>>inX2;
		cout<< p.calculate({inX1, inX2}, limiar) << endl;

	}while(inX1 != 99);

}
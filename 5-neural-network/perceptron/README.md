# Perceptron

Para tal implementação, foi-se utilizada a linguagem computacional c++ por sua alta capacidade de desenvolvimento e consolidação dos conceitos.

Tendo em mente uma rede com um único neurônio, desenvolveu-se uma class que pudesse representa-lo, utilizando conceitos de orientação a objetos.

```cpp
class Perceptron{
	vector<float> w;
public:
	Perceptron(){}
	Perceptron(int inQtd){
		for(int i=0; i<inQtd; i++){
			w.push_back(0.3);
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

	void print(){
		cout<<"Pesos: ";
		for(auto it : w){
			cout<<setw(7)<<setprecision(3)<<it;
		}
		printf("\n");
	}
};
```

Em seguida definiu-se a função degrau como função de ativação do neurônio.

```cpp
int ativation(float x, float limiar){
	if (x>limiar) return 1;
	return 0;
}
```

Feito isso a class principal foi implementada apenas utilizando os conceitos já definidos pelo Perceptron

```cpp
int main(){
	vector<int> x1 = {0, 0, 1, 1};
	vector<int> x2 = {0, 1, 0, 1};
	vector<int> Out = {0, 1, 1, 1};

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
			p.print();
		}
		if (cont>=4) break;
	}

	int inX1=0, inX2=0;

	do{
		cin>>inX1>>inX2;
		cout<< p.calculate({inX1, inX2}, limiar) << endl;

	}while(inX1 != 99);
	cout<<"Epoc: "<<qtd<<endl;
	exit(0);
}
```

Tendo uma rede simples já implementada, realizou-se alguns testes de separação linear e não linear. Nesse contexto de definição, o neurônio é inicializado sempre com os mesmos valores de peso.

O problema de separação linear proposto foi o da porta lógica ‘or’ o qual pode ser facilmente linearmente separável. Gerando os seguintes ajustes de pesos:

1º Época

- Pesos:     0.3    0.3
- Pesos:     0.3    0.4
- Pesos:     0.4    0.4
- Pesos:     0.4    0.

2º Época

- Pesos:     0.4    0.4
- Pesos:     0.4    0.5
- Pesos:     0.5    0.5
- Pesos:     0.5    0.5

3º Época

- Pesos:     0.5    0.5
- Pesos:     0.5    0.5
- Pesos:     0.5    0.5
- Pesos:     0.5    0.5

Convergindo o resultado em apenas 3 épocas de treinamento.

Para o teste de um problema não linearmente separável, utilizou-se a função lógica ‘xor’, gerando um número indeterminado de ajustes incapazes de levar a convergência do modelo. Esse problema ocorre devido a espécie da função, tornando-o ser impossível de separar utilizando apenas uma reta, o que entra totalmente em divergência com a solução proposta, pois redes simples são capazes somente de realizar separações (classificações) por meio de funções lineares.
# Introdução
O objetivo deste diretório é resolver uma modificação do problema ja tratado no <a href="https://github.com/Sr-Souza-dev/AI/tree/main/vacuum-cleaner">código<a> já estudado (diretório 'vacuum-cleaner'), o qual deve-se limpar todas as salas que ainda estão sujas. Para isso foi desenvolvido dois códigos, um que utiliza da <a href="https://github.com/Sr-Souza-dev/AI/blob/main/search-solution(vacuum-cleaner)/roomba-BFS.py">busca em largura<a> para encontrar uma ótima solução e outro que implementa um <a href="https://github.com/Sr-Souza-dev/AI/blob/main/search-solution(vacuum-cleaner)/BFSvsReative.py">agente reativo<a> (aleatório) para realizar a comparação entre as duas soluções.

# Descrição (vacuum-cleaner)
O suposto arquivo (dirty.py) busca simular um agente que deve limpar um conjunto de 9 sala, dividas como uma matriz 3x3 que utiliza de metodologias de busca para encontrar uma melhor e mais racional racional para o problema. Seu modo de trabalho/atuação é totalmente definido e resultará sempre as mesmas respostas independente da quantidade de vezes que for executado (Ex: Se for dada a regra de 'limpar' o local ficará limpo).


## Resultado Agente de busca (BFS) x Agente Reativo (Aleatório) 
Resultados encontrados em 5 execuções do algoritmo <a href="https://github.com/Sr-Souza-dev/AI/blob/main/search-solution(vacuum-cleaner)/BFSvsReative.py">BFSvsReative.py<a>. Como o ambiente se altera em cada execução o resultado é não deterministico, podendo oferecer varias respostas diferentes em diversas tentativas


| Execução | BFS | Reativo (Aleatório) |
| -------- | --- | ------------------- |
|   1°     | 4   |          12         |
|   2°     | 7   |          11         |
|   3°     | 10  |          16         |
|   4°     | 6   |          12         |
|   5°     | 5   |          17         |


## Análise
Para este problema, há diversas metodologias de busca que encontram uma sulução viável, como exemplo,  podemos utilizar a busca em largura, custo uniforme, gulosa... O que influência na escolha da melhor metodologia de pesquisa para o devido problema são os custos computacionais e otimalidade da solução. 
Como há muitos estados possiveis, o algoritmo de busca implementado foi o não informado (devido a dificuldade de visualizar todos estados) por meio da expansão em largura (busca em largura), o qual vai expandindo as informações a medida que busca por uma solução, garantindo uma solução ótima devido ao custo unitário de todas as movimentações. Para desconsiderar a existência de loop é necessario que o problema seja modelado/tratado na forma de grafo, pois, será possível armazenar um 'histórico' dos estados já visitados.  <br>
Feita a comparação da execução dos dois agentes <a href="https://github.com/Sr-Souza-dev/AI/blob/main/search-solution(vacuum-cleaner)/BFSvsReative.py">reativo<a> (seleciona o próximo movimento aleatóriamente) e de <a href="https://github.com/Sr-Souza-dev/AI/blob/main/search-solution(vacuum-cleaner)/roomba-BFS.py">busca<a>, é possível perceber que o agente de busca encontra a solução de forma mais rápida em comparação ao agente reativo, isso ocorre devido ao conhecimento prévio do problema e da logica imposta no agente. É importante ressaltar que nem sempre isso irá acontecer, pode haver um caso em que todos passos são feitos da melhor forma possivel pelo agente reativo (devido ao seu não determinismo), gerando uma resolução menos custosa computacionalmente em comparação ao agente que utiliza a busca em largura <br>
Uma análise importante seria consideram um mundo (ambiente em que o agente esta inserido) NxN em que N é muito grande. O agente reativo pode em sua maioria apresentar um desempenho melhor em comparação ao agente de busca. Isso se dá devido ao custo exponencial do método de pesquisa utilizado pelo agente de busca, o que pode tornar alguns problemas fisicamente impossível diante dos recursos atuais. 
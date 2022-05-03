mathjax: true

# Introdução
Olá, meu nome é Gabriel Rosa. No momento, sou estudante de Engenharia de Computação no CEFET-MG. Este repositório busca armazenar todas atividades realizadas durante a execução da materia de Inteligência Artificial... Qualquer dúvida ou detalhe que deseja tratar sobre estes documentos, sinta-se a vontande para propor algo ou entrar em contato. </br> Att. Gabriel.

## Arquivos em ordem cronológica 
1. Vaccum-Cleaner (Sistema racional capaz de lipar dois compartimentos)
2. Missionary-Cannibals (Sistema racional que resolve problema do 'missionarios e canibals' através de busca em arvore)

# Resumo
## Agentes
O agente é aquele capaz de identificar o ambiente e atuar sobre ele, formando um ciclo infinito de execução: Identifica Ambiente -> Atua sobre o ambiente -> Identifica o 'novo' ambiente...

<br> 
"Racionalidade maximiza o desempenho esperado; Onisciência maximiza o desempenho REAL" <br> 

**O agente pode ter:** 

1. *Onisciência:* O agente tem infromações de todo o ambiente de atuação (sabe como o ambiente esta a cada momento).
2. *Aprendizado:* O agente já realizou determinada atividades algumas vezes e consegue fazer suposições racionais a partir da experiência em execuções futuras
3. *Autonomia:* É o agente que contém algum conhecimento prévio, conseguir realizar/obter outros conhecimento a partir disso.

<br>

**Agente Racional (PEAS)**

1. *Performance:* É uma medida quantitativa que classifica o desempenho do agente (o agente é racional se maximiza o valor da performace).
2. *Environment:* É o ambiente de atução do agente. Ex: Cozinha, transito... (Um agente deve ser capaz de identificar o ambiente e realizar algo sobre ele)
3. *Actuators:* São os componetes do agente que realizam a função de resposta. Ex: Para um carro tem-se: freio, acelerado... (Um agente racional para determinado ambiente é capaz de atuar sobre ele)
4. *Sensors:* São componetes do agente que o faz compreender/identificar o ambiente/estado em que ele esta inserido. Ex: Para um carro tem-se: velocimetro, termômetro...
<br>

<br>

**Propriedades de Ambientes de Tarefas** 

1. *Completamente observável:* Para definir se o ambiente será completamente observável, primeiramente é necessario definir os limites do ambiente, caso os sensores do agente seja capaz de contempler todo ambiente então podemos afirmar que ele está em um ambiente totalmente observável == 'onisciênte'.
2. *Parcialmente observável:* É quando os sensores do agente não conseguem contemplar todo o ambiente (ao qual ele esta inserido) ao mesmo tempo.
3. *Determinístico:* ambiente determinístico é quando o agente está prestes a realizar uma tarefa e já tem total certeza do resultado que essa ação gerará. Ex: Vai executar a limpeza de um ambiente e tem total certeza que ao final o ambiente estará limpo.
4. *Estocástico:* Ambiente estocástico é quando o agente está prestes a realizar uma tarefa e não tem total certeza do resultado que será gerado (não consegue garantir a resposta do ambiente devido a uma ação realizada). Ex: considerando um carro, ele está acelerando, mas pode cair em um buraco e parar de andar mesmo ele estando acelerando, chamamos este ambiente de estocástico.
5. *Estratégico:* Se o ambiente é determinístico exceto pelas ações de outros agentes, dizemos que o ambiente é estratégico. Ex: no caso de um carro, o agente sabe que se ele frear o carro tente a diminuir sua velocidade até parar, mas considerando um outro agente que pode pegar o carro e empurra-lo, este ambiente se torna estratégico.
6. *Estático:* O ambiente é considerado estático, quando, a partir do momento que o agente começa a atuar, o ambiente de atuação permanece o mesmo até o fim da execução.
7. *Dinâmico:* O ambiente é considerado dinâmico quando ele pode conter novo estados que não foram causados pelo agente (Ex: Considerando um aspirador de pó, enquanto ele está limpando tem algo jogando mais sujeira no ambiente).
8. *Episódico:* O ambiente episódico é quando somente o estado atual importa, o que veio antes não interfere na resposta do agente (Ex: na separação de produtos, é verificado somente qual produto o agente esta visualizando caso lixo ele manda para lixeira e caso reciclavel ele deixa passar).
9. *Sequencial:* O ambiente é considerado sequencial quando resultados anteriores influenciam na resposta atual do agente (Ex: considerando um aspirador de pó com o ambiente sequencial, ele será capaz de armazerar o estado atual da sala, não precisando visita-lá a todo momento para verificar se ela esta limpa, podendo apenas conferir em seu histórico).
10. *Discreto:* É quando há um número limitado e claramente definido de percepções e ações (Ex: Xadrez tem um número finito de estados distintos. Ações e percepções são discretas)
11. *Contínuo:* Sendo o inverso do discreto, no ambiente de estado contínuo, é quando não há um número limitado e claramente definido de percepções e ações (Ex: Estado continuo e tempo continuo. A
velocidade e localização do táxi e de outros veículos andando através de um espaço de valores contínuos e fazendo isso suavemente ao longo do tempo. Ações são também contínuos 'dobrar a direção').
<br>

**Programa x Ação do Agente**

Um agente é composto por seu código, que são os 'ifs,elses' e por sua arquitetura, que são a interconexão do código com o ambiente de atuação (meios fisícos ou lógicos).

1. *Programa do Agente*: É quando o agente utiliza somente de um único estado para realizar alguma função (algo reativo).
2. *Função do Agente*: É quando o agente utiliza de todo o historico para responder/realizar uma função.

**Agente Reativo**

1. *Agente Reativo Simples*: O agente funciona apenas se o ambiente do evento for completamente observável e a decisão correta puder ser tomada com base apenas na percepção atual (Faz somente o que foi programado, se alguma situação mudar, ele não sabe como reagir ou atuar de forma diferente. Ex: Aspirador pode nunca parar de se movimentar se os dois ambientes estiverem limpos).
2. *Agente Baseado em Modelos*: Antes de executar alguma ação, este agente recebe um conhecimento a priori que visa identificar como o mundo está no momento atual e efeitos de ações passadas aplicada ao ambiente. 
3. *Agente Baseado em Objetivo*: Sendo bem próximo ao agente baseado em modelos, esse agente possui um conhecimento a priori que é capaz de identificar o ambiente atual e analisar como sua ação afeta ao abiente antes mesmo de toma-la.
4. *Agente Baseado em Utilidade*: Tentam maximizar seu resultado, pondera a probabilidade de sucesso em relação a importância de objetivos. 
5. *Agente de Resolução de Problemas*: É um agente baseado em modelos que contém um conhecimento mais geral do problema a ser solucionado, sabe seu espaço de estados e procura nele uma solução boa (possibilitando a execução de buscas por soluções viáveis).

## Árvores de Busca
Há dois tipos de busca em arvores:
1. Não informado: Usuam somente definições do problema (como: depth-first, breadth-first...)
2. Informado: Usam conhecimento sobre o domínio (além) do problema e heurísticas (como: Greedy best-first, A*).

### Medição de desempenho de resolução de problemas e coplexidade
#### Desempenho:
1. Completeza: O algoritmo é capaz de achar a solução se ela existir.
2. Otimização: O algoritmo é capaz de encontrar uma resolução ótima. 
3. Complexidade de Tempo: É o tempo que o algoritmo gasta para encontrar determimnada solução.
4. Complexidade de espaço: É o espaço em memória que o algoritmo gata para enocntrar determinada solução.

#### Complexidade:
1. Fator de Ramificação (b): número máximo de sucessores de um nó;
2. Profundidade (d): profundidade do nodo objetivo mais raso;
3. Comprimento Trajetória (m): maior entre todas as trajetórias. 


### Breadth-First Search (Busca em largura)
A busca em largura expande sempre toda a fronteira até encontrar o resultado (meta), ou seja, ela verifica o primeiro filho do node, caso ele não seja o resultado ela o expande, em seguida ela verifica o segundo filho do node, caso ele não seja o resultado ela o expande também, fazendo isso até encontrar a meta. Gerando uma árvore com mais nós folhas devido a sua maneira de expansão e ao armazenamento dos nodos.


* *Completeza*: completo (se b é finito);
* *Otimização*: não necessariamente ótimo, a menos que o custo trajetória seja igual para todas as direções de expansão;
* *Complexidade de Tempo e espaço*: tempo e memória (profundidade da meta = d, qtd de filhos em cada nodo = $$b) -> b + b^2 + ... + b^d = O(b^d)$$. <br>

<img src="images/bfs.png" style="width: 50%">


### Uniform Cost Search (Busca de custo uniforme)
No algoritmo de busca de custo uniforme as transições de um nodo para outro são ponderadas, sendo que, atráves desse valor o algoritmo faz sua escolha de expansão, ou seja, ele expandirá sempre a fronteira que tiver menor custo em relação a raiz da árvore.

* *Completeza*: 
* *Otimização*:
* *Complexidade de Tempo*:
* *Complexidade de espaço*:

<img src="images/uniformSearch.png" style="width: 90%">


### Depth-First Search (Busca em profundidade)
Expande/percorre de um vertice até os vértices 'filhos', o mais profundo possível, para somente depois retroceder. (Seu objetivo é descer/aprofundar ao máximo respeitando uma lógica inicial até encontrar o resultado esperado). <br>
* *Completeza*: Este código pode ser considerado completo dependendo do ambiente ao qual ele está operando, caso o ambiente tenha muitos/infinitos estados ele demorará muito para encontrar uma resposta, ou nem encontrará.
* *Otimização*: Não, pois ele aceitará a primeira solução encontrada.
* *Complexidade de Tempo*: O(b^s), tal que 'b' é a quantidade de nodos filhos que um nodo tem e 's' é a profundidade da solução encontrada na arvore.
* *Complexidade de espaço*: O(b^s), tal que 'b' é a quantidade de nodos filhos que um nodo tem e 's' é a profundidade da solução encontrada na arvore. <br>
<img src="images/dfs.png" style="width: 50%">










* *Completeza*: 
* *Otimização*:
* *Complexidade de Tempo*:
* *Complexidade de espaço*:


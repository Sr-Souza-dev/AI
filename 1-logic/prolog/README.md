## Learning

**Executa o programa .pl** swipl -s program.pl
    
### Introduction
Prolog é uma linguagem lógica, o qual se importa somente com a lógica desenvolvida,
ou seja, como esses dados são tratados ou como são bescados/retornados não importa 
para execução, desde que a lógica esteja de acordo <br>

**Tipos de definição:** <br>
    variaveis   ->  Iniciadas com UpperCase ou UnderScore(UnderScore_ sozinho implica em uma variavel anônima. Ex: Nome)
    átomos      ->  São constantes, devem iniciar com LowerCase (Ex: gabriel) ou envolvidas com aspas simples('', Ex: 'gabriel','Gabriel','15') 
    inteiros    ->  Qualquer sequência numérica que não contenha ponto (. Ex: 5, 15). Caracteres ASCII entre aspas duplas ("") são tratados como lista de inteiros (Ex: "a", "gabriel")
    floats      ->  Qualquer sequência numérica com ponto (.) e pelo menos uma casa decimal (Ex: 6.9, 15.3, 20.5555)
    listas      ->  Sequência ordenada de elementos entre colchetes ([]) e separados por vírgulas (Ex: [a,b,c], [1,a,15]). Caracteres ASCII entre aspas duplas ("") são tratados como lista de inteiros (Ex: "a", "gabriel")
<br>

**Funções basicas:**
1. write()     ->  Imprime no terminal o que for passado (Ex: write("Hello World") -> Hello World)
    Caracteres especiais para impressão:
        nl, \n, \l      -> nova linha
        \r              -> retorna ao inicio da linha
        \t              -> tabulação
        \%              -> imprime o simbolo % 
2. read()      -> Realiza a leitura de dados por perifericos (teclado) e armazena em uma variavel (Ex: read(X) -> realiza a leitura do teclado e salva seu valor em X)
3. listing()   -> Função utilizada no terminal que lista todos os fatos/regras por um determinado nome (Ex: listing(loves) -> retorna todas ações realizadas com o funtor loves (loves(gabriel,daniele)))
4. assert()    -> Função utilizada no terminal que acrescenta o fato/regra como ultimo item do predicado (sequência de informação sobre o mesmo preceito) na base de conhecimento KB (Ex: assert(loves(daniele,gabriel)
5. asserta()   -> Função utilizada no terminal que acrescenta o fato/regra como primeiro item do predicado (sequência de informação sobre o mesmo preceito) na base de conhecimento KB (Ex: asserta(loves(daf,vin)
6. retract()   -> Função utilizada no terminal que remove o fato/regra da base de conhecimento KB
7. retractall()-> Função utilizada no terminal que remove todos fatos/regras da base de conhecimento KB
8. :- dynamic funtor/aridade -> para criar predicados dinâmicos (possibilita a inserção e remoção de predicados da base de dados KB)
<br>

**Para as sentenças abaixo, tem-se:**
    funtor  = Nome dado a função/operação de conhecimento
    aridade = Qtd de parametros (atomos) passados para um funtor
    Exemplo: dado o exemplo loves abaixo, tem-se que:
        funtor: loves
        aridade: 2
    **loves(gabriel, daniele).**
<br>

**Cláusula Prolog (lógica de 1º ordem)**
    :- --> (if), equivale à implicação;
    ,  --> (and), equivale a conjunção;
    ;  --> (or), equivale a disjunção;
    \+ --> (not), negação;
    \= --> (diferent) diferente;
    em que: ','(and) e ';'(or) são os conectivos da expressão logica

    Exemplo: dado o exemplo abaixo tem-se que:
        se start for chamado, então executa o que vier após ':-', 
        caso o lado direito do ':-' seja executado e todos comandos 
        forem possíveis, retornará true, caso contrario retornará false

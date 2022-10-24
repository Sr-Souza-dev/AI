parents(joao, joaquim).
parents(joao, serafina).
parents(joana, joaquim).
parents(joana, serafina).
parents(serafina, maria).
parents(serafina, ana).
parents(joaquim, marcelino).
parents(marcelino, aristides).
parents(maria, aristides).

male(joao).
male(joaquim).
male(marcelino).
male(aristides).

female(joana).
female(serafina).
female(maria).
female(ana).

siblings(X,Y)    :- mother(Z,X)     , mother(Z,Y)       , X \= Y.
sister(X,Y)      :- siblings(X,Y)   , female(X)         , X \= Y.
brother(X,Y)     :- siblings(X,Y)   , male(X)           , X \= Y.
mother(X,Y)      :- parents(X,Y)    , female(X).
father(X,Y)      :- parents(X,Y)    , male(X).
grandFather(X,Y) :- parents(X,Z)    , parents(Z,Y).
uncle(X,Y)       :- parents(Z,Y)    , siblings(Z,X).
cousin(X,Y)      :- parents(Z,X)    , parents(W,Y)      , siblings(Z,W)     , X \= Y.
son(X,Y)         :- parents(Y,X).
oneUncle(B)      :- findall(X,uncle(_,X),Y), sort(Y,A), length(A,B).


/*
    1. O Joaquim é filho do José?
        son(joaquim,jose).

    2. Quem são os filhos da Joana? 
        parents(joana,X).

    3. Quem sao os primos do Marcelino?
        cousin(X,marcelino).

    4. Quantos sobrinhos/sobrinhas com um Tio existem?
         oneUncle(B).
        
    5. Quem sao os ascendentes do Aristides? 
        parents(X,aristides).

    6. A Maria tem irmãos? E irmãs?
        brother(X, maria).
        sister(X,maria).
*/
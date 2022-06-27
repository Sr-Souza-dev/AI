:- consult(kb).

printElement(L/C) :- format('~t~a - ~a~t~20+', [L, C]).
printElement(L) :- format('~t~a~t ~t', L).
printList([]) :- format('~n', []).
printList([H|T]) :-
    printElement(H),
    printList(T).
printLists([], _).
printLists([H|T], N) :-
    M is N + 1,
    format('~d- ', M),
    printList(H),
    printLists(T, M).

chatbot():-
    format("bem vindo ao Sigaa\n\nLogin: "),
    read(L),
    format("Senha: "),
    read(P),
    login(L,P).

login(L,P):-
    sigaa(L,P)-> menu(L,P);format("Usuario ou senha incorreta").
   
menu(L,P):-
    format("
        1.Mostrar suas notas
        2.Mostrar tarefas pendentes
        3.Mostrar dados
        4.Mostrar media de desempenho,
        5.Mostrar informacoes da turma,
        6.Mostrar quais materias ainda faltam para finalizar o curso 
        7.Mostrar faltas de cada materia 
        0.Sair
        ->"),
        read(OP),
        esc(OP,L,P).

esc(0,_,_):- format("Foi um prazer ajuda-ló. Até mais!"),!.
esc(1,L,P):- answ1(L,P),!.
esc(2,L,P):- answ2(L,P),!.
esc(3,L,P):- answ3(L,P),!.
esc(4,L,P):- answ4(L,P),!.
esc(5,L,P):- answ5(L,P),!.
esc(6,L,P):- answ6(L,P),!.
esc(7,L,P):- answ7(L,P),!.
esc(_,L,P):- format("Opção inválida! \n"),exit(L,P).

answ1(L,P):-
    findall([X,Z],materia(X,L,notas,Z),K),
    printLists(K,0),
    exit(L,P).

answ2(L,P):-
    findall([X,Z],materia(X,L,tarefas,Z),K),
    printLists(K,0),
    exit(L,P).

answ3(L,P):-
    findall([X],materia(X,L,notas,_),K),
    mediadesempenho(L,M),
    format("seus dados sao 
        Login: ~t~a
        senha: ~t~a
        materias matriculadas:\n",[L,P]),
        printLists(K,0),
        format("
        media de desempenho: ~w\n ",M),
        format("Materias pendentes: "),
        pendente(L,PEND),
        printList(PEND),
        exit(L,P).

answ4(L,P):-
    mediadesempenho(L,Media),
    format("Sua media de desempenho e: ~w\n",Media),
    exit(L,P).

answ5(L,P):-
    mediadesempenho(_,Media),
    format("A media de desempenho da turma e: ~w\n",Media),
    exit(L,P).

answ6(L,P):-
    pendente(L,R),
    format("Suas materias pendentes sao: "),
    printList(R),
    exit(L,P).

answ7(L,P):-
    findall([X,Y],materia(X,L,faltas,Y),Z),
    format("Suas faltas sao:\n "),
    printLists(Z,0),
    exit(L,P).

exit(L,P):-
    format("Deseja voltar para o menu? (sim/nao) "),
    read(RES),
    (RES == sim) -> menu(L,P) ; esc(0,_,_).

mediadesempenho(L,R):-
    findall([X],materia(_,L,notas,X),List),
    soma(List,Sum),
    qtde(List,Qtd),
    R is Sum / Qtd.

qtde([],0).
qtde([_|T],S):-qtde(T,G),S is 1+G.
soma([],0).
soma([H|T],S):- soma(T,G),S is H+G. 
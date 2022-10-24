from tokenize import Token
from tabulate import tabulate
from tokenizer import Tokenizer

import glob

# Iguala a quantidade de colunas da matriz
def equal(item, idx):
    while(len(tab[item]) < idx):
        tab[item].append(0);
    tab[item].insert(0,1);

# Define a tabela que armazenara todos os dados
tab = dict()
index = 1

# define o diretório dos arquuivos
dire = "spam1"
dire2 = "ham1"
fileName = "res"

falseVal = 0


for file in glob.glob(f"./{dire}/*.eml"):
    Tokens = Tokenizer(index, tab, open(file,"r"));
    tab = Tokens.tokenizer()
    falseVal = falseVal + Tokens.valu
    index = index + 1

maxSpa = index - falseVal

for file in glob.glob(f"./{dire2}/*.eml"):
    Tokens = Tokenizer(index, tab, open(file,"r"));
    tab = Tokens.tokenizer()
    index = index + 1


word = "valid"
cont = 0
word = f"{word}, {cont} ;"
word2 = f"{cont},"

for i in tab:
    cont = cont + 1;
    word = f"{word} {i}, {cont};"
    word2 = f"{word2} {cont},"

word2 = word2 +  ";"
file1 = open(f"relationBd2.csv","w")
file1.write(word)
file2 = open(f"dtbad1.csv","w") 
file2.write(word2)
maxx = 0

for i in tab:
    equal(i, index)
    if(len(tab[i]) > maxx):
        maxx = len(tab[i])
    
for i in range(0,maxx-1):
    word = "0"
    if i > maxSpa:
        word = "1"
    for it in tab:
        word = f"{word}, {tab[it][i]}"
    word = word + ";\n"
    file2.write(word)
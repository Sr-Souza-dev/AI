tree = {
    1:[2,3,4],
    2:[5,1],
    3:[1],
    4:[5, 1],
    5:[2,4,6],
    6:[7,5],
    7:[8,6],
    8:[9,7],
    9:[8,10],
    10:[9,11],
    11:[10,12],
    12:[11,13,14],
    13:[12,15],
    14:[12,15],
    15:[13,14]
}

def bfs(tree, begin, end):
    verified = []
    current = []
    irrelevant = []
    path = []

    if (begin == end):
        print("O estado inicial já é a meta desejada")
        return

    current = tree[begin]
    verified.append(begin)

    while(len(current) > 0):
        if (end in tree[current[0]]):
            verified.append(current[0])  

            for index in range(len(verified)-1, -1, -1):
                if (verified[index] == begin):
                    print("aqui")
                    path.append(verified[index])
                elif(verified[index] in tree[verified[index-1]]):
                    path.append(verified[index])
            path = path[::-1]
            path.append(end)

            print("Você encontrou sua meta! Meta: ", end)
            print("Nodos verificados: ", verified)
            print("Path: ", path)
            
            return
        if(len(tree[current[0]]) <= 1):
            irrelevant.append(current[0])
        if (not(current[0] in verified)):
            current = current + tree[current[0]]
            verified.append(current[0])
        current.pop(0)
    
    print("Não foi encontrado soluções para este problema!")

bfs(tree, 1, 15)
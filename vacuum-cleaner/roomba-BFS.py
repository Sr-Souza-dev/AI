from enum import IntEnum

class ACTIONS(IntEnum):
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3 ,
    SUCK = 4,
    
class State:
    def __init__(self,roomba,squareMap,action = None,fatherState=None):
        self.roomba = roomba
        self.squareMap = squareMap
        self.action = action,
        self.father = fatherState
    def isThisRoot():
        return self.fatherState == False
    def __str__(self):
        string = "["+self.roomba.__str__()+","+self.squareMap.__str__()+","+self.action.__str__()+"]"
        return string 
    def __repr__(self):
        return self.__str__()
    def __eq__(self, o):
        return o != None and self.roomba == o.roomba and self.squareMap == o.squareMap
        

class DirtCleaner:
    def __init__(self,initialState,goal):
        self.state = initialState
        self.goal = goal 
        self.path = []
        self.discovered =[]
    def isGoal(self,s,printi=False):
        if printi:
            print(s.squareMap)
        return self.goal == s.squareMap
    def actions(self,s:dict):
        a = []
        roomba = s.roomba
        if roomba[0] != 0:
            a.append(ACTIONS.UP)
        if roomba[0] != 2:
            a.append(ACTIONS.DOWN)
        if roomba[1] != 0:
            a.append(ACTIONS.LEFT)
        if roomba[1] != 2:
            a.append(ACTIONS.RIGHT)
        if squareMap[roomba[0]][roomba[1]] == 1:
            a.append(ACTIONS.SUCK)
        return a
    def result(self,s,a):
        squareMap =  [row[:] for row in s.squareMap]
        roomba = s.roomba.copy()
        if a == ACTIONS.SUCK:
            squareMap[roomba[0]][roomba[1]] = 0
        elif a == ACTIONS.UP:
            roomba[0] = roomba[0] -1
        elif a == ACTIONS.DOWN:
            roomba[0] = roomba[0] +1
        elif a == ACTIONS.LEFT:
            roomba[1] = roomba[1] -1
        elif a == ACTIONS.RIGHT:
            roomba[1] = roomba[1] +1
        state = State(roomba.copy(), squareMap.copy(),a,s)
        return state
    def buscaLargura(self,estados):        
        fronteira=[]
        for s in estados:
            for a in self.actions(s):
                f = self.result(s, a)
                if f not in self.discovered:
                    self.discovered.append(f)
                    if self.isGoal(f):
                        return f 
                    else:
                        fronteira.append(f)
        if len(fronteira) == 0:
            return None
        return self.buscaLargura(fronteira)
    def getBestPath(self):
        s = self.buscaLargura([self.state])
        if s == None:
            return "Nao possui solucao"
        path = []
        
        while s != None:
            path.append(s)
            s = s.father
        return path[::-1]

    def cost(self):
        pass


squareMap = [
    [1,1,1],
    [0,0,0],
    [0,0,0]
    ]
goal = [
    [0,0,0],
    [0,0,0],
    [0,0,0]
    ]
initialState = State([1,1], squareMap)

dirty = DirtCleaner(initialState,goal)
print(dirty.getBestPath())


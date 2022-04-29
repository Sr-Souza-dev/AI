from enum import IntEnum

# Enumarations

class Sides(IntEnum):
    LEFT = 0
    RIGHT = 1

class State(IntEnum):
    DIRTY = 0
    CLEAN = 1
    UNKNOWN = -1


# Modelagem do agent
class Agent:
    def __init__(self, location):
        self.location = location
        self.history = [-1,-1]
        self.watchdog = 0
        self.score = 0

    def isAgentLocked(self):
        return self.watchdog > 3  # Checagem dupla em cada comodo
    
    def reflexVaccum(self):
        self.history[self.location] = State.CLEAN
        if environment[self.location] == State.DIRTY:
            environment[self.location] = State.CLEAN
            # Score incrementa em 4 caso limpe um comodo e decrementa 1 caso nao limpe
            self.score += 4
            self.watchdog = 0   # Watchdog reseta caso limpe algum comodo
            return "SUCK"
        elif self.location == Sides.RIGHT and self.history[Sides.LEFT] == State.UNKNOWN:
            self.location = Sides.LEFT
            self.score -= 1
            self.watchdog += 1
            return "LEFT"
        elif self.location == Sides.LEFT and self.history[Sides.RIGHT] == State.UNKNOWN:
            self.location = Sides.RIGHT
            self.score -= 1
            self.watchdog += 1
            return "RIGHT"
        else:
            self.watchdog = 4
            return "End of execution"


# Instanciacao do agente e do ambiente
# environment = [State.CLEAN, State.DIRTY]
# agent = Agent(Sides.RIGHT, environment)
media = []
for left in range(2):
    for right in range(2):
        for side in range(2):
            environment = [left, right]
            agent = Agent(side)
            print("Side agent ", side, " environment ", environment)
            while agent.isAgentLocked() == False:
                print(agent.reflexVaccum())
            print("Score:", agent.score)
            media.append(agent.score)
print("Média total:", sum(media) / len(media))

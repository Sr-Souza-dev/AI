from enum import IntEnum

# Enumarations


class Sides(IntEnum):
    LEFT = 0
    RIGHT = 1


class State(IntEnum):
    DIRTY = 0
    CLEAN = 1


# Modelagem do agent
class Agent:
    def __init__(self, location, environment):
        self.location = location
        self.watchdog = 0
        self.score = 0

    def reflexVaccum(self):
        if environment[self.location] == State.DIRTY:
            environment[self.location] = State.CLEAN
            # Score incrementa em 4 caso limpe um comodo e decrementa 1 caso nao limpe
            self.score += 4
            self.watchdog = 0   # Watchdog reseta caso limpe algum comodo
            return "SUCK"
        elif self.location == Sides.RIGHT:
            self.location = Sides.LEFT
            self.score -= 1
            self.watchdog += 1
            return "LEFT"
        else:
            self.location = Sides.RIGHT
            self.score -= 1
            self.watchdog += 1
            return "RIGHT"

    def isAgentLocked(self):
        return self.watchdog > 3  # Checagem dupla em cada comodo


# Instanciacao do agente e do ambiente
# environment = [State.CLEAN, State.DIRTY]
# agent = Agent(Sides.RIGHT, environment)
media = []
for left in range(2):
    for right in range(2):
        for side in range(2):
            environment = [left, right]
            agent = Agent(side, environment)
            print("Side agent ", side, " environment ", environment)
            while agent.isAgentLocked() == False:
                print(agent.reflexVaccum())
            print("Score:", agent.score)
            media.append(agent.score)
print("Media total:", sum(media) / len(media))

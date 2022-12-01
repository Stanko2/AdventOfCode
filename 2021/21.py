import copy


class Player:
    def __init__(self, pos, score=0):
        self.pos = pos
        self.score = score

    def __str__(self):
        return str(self.pos) + ":" + str(self.score)


class GameState:
    def __init__(self, pos1, pos2):
        self.first = Player(pos1)
        self.second = Player(pos2)
        self.firstOnTurn = True

    def __str__(self):
        return str(self.first) + ',' + str(self.second) + ',' + str(self.firstOnTurn)


states = {}
a = int(input())
b = int(input())
a -= 1
b -= 1
s = GameState(a, b)

sums = {
    3: 1,
    4: 3,
    5: 6,
    6: 7,
    7: 6,
    8: 3,
    9: 1
}


def getState(state: GameState):
    global states
    if str(state) in states:
        return states[str(state)]
    ret = [0, 0]
    for i in range(3, 10):
        a = GameState(state.first.pos, state.second.pos)
        a.first.score = state.first.score
        a.second.score = state.second.score
        if state.firstOnTurn:
            a.first.pos = (a.first.pos + i) % 10
            a.first.score += a.first.pos + 1
            if a.first.score >= 21:
                ret[0] += sums[i]
                continue
        else:
            a.second.pos = (a.second.pos + i) % 10
            a.second.score += a.second.pos + 1
            if a.second.score >= 21:
                ret[1] += sums[i]
                continue
        a.firstOnTurn = not state.firstOnTurn
        b = getState(a)
        ret[0] += b[0] * sums[i]
        ret[1] += b[1] * sums[i]
    states[str(state)] = ret
    return ret


print(getState(s))

goal = 20
beam_width = 2

def heuristic(n):
    return abs(goal - n)

states = [1]
level = 0

while True:
    print("Level", level, ":", states)

    if goal in states:
        break

    next_states = []

    for x in states:
        next_states.append(x+2)
        next_states.append(x+3)
        next_states.append(x*2)

    next_states = list(set(next_states))
    next_states.sort(key=lambda n: heuristic(n))

    states = next_states[:beam_width]
    level += 1

print("Goal reached:", goal)

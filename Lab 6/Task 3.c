import random

population_size = 6
generations = 15
mutation_rate = 0.1

def fitness(x):
    return x*x + 2*x

def to_binary(x):
    return format(x,'05b')

def to_decimal(b):
    return int(b,2)

population = [random.randint(0,31) for _ in range(population_size)]

for g in range(generations):

    population.sort(key=lambda x: fitness(x), reverse=True)

    parents = population[:2]

    p1 = to_binary(parents[0])
    p2 = to_binary(parents[1])

    point = random.randint(1,4)

    child1 = p1[:point] + p2[point:]
    child2 = p2[:point] + p1[point:]

    def mutate(ch):
        ch = list(ch)
        for i in range(len(ch)):
            if random.random() < mutation_rate:
                ch[i] = '1' if ch[i]=='0' else '0'
        return ''.join(ch)

    child1 = mutate(child1)
    child2 = mutate(child2)

    population = parents + [to_decimal(child1), to_decimal(child2)]

    while len(population) < population_size:
        population.append(random.randint(0,31))

best = max(population, key=lambda x: fitness(x))

print("Best chromosome:", to_binary(best))
print("Best x:", best)
print("Best fitness:", fitness(best))

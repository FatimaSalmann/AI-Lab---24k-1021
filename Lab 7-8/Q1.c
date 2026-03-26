# Fatima Salman 24K-1021

tree = {
    "N3":[4,7],
    "N4":[2,5],
    "N5":[1,8],
    "N6":[3,6],
    "N1":["N3","N4"],
    "N2":["N5","N6"],
    "Root":["N1","N2"]
}

visited = []

def minimax(node, depth, isMax):
    visited.append(node)

    if isinstance(node,int):
        return node

    if node in ["N3","N4","N5","N6"]:
        values = tree[node]
        return max(values)

    if isMax:
        return max(minimax(child, depth+1, False) for child in tree[node])
    else:
        return min(minimax(child, depth+1, True) for child in tree[node])

value = minimax("Root",0,True)

print("Minimax Value:",value)
print("Visited Order:",visited)

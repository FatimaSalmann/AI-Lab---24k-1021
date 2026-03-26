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

pruned = []

def alphabeta(node, alpha, beta, isMax):

    if isinstance(node,int):
        return node

    if node in ["N3","N4","N5","N6"]:
        return max(tree[node])

    if isMax:
        value = -999

        for child in tree[node]:
            value = max(value, alphabeta(child,alpha,beta,False))
            alpha = max(alpha,value)

            if beta <= alpha:
                pruned.append(child)
                break

        return value

    else:
        value = 999

        for child in tree[node]:
            value = min(value, alphabeta(child,alpha,beta,True))
            beta = min(beta,value)

            if beta <= alpha:
                pruned.append(child)
                break

        return value

print("Alpha Beta Value:", alphabeta("Root",-999,999,True))
print("Pruned Nodes:",pruned)

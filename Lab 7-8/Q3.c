# Fatima Salman 24K-1021

tree = {
    "N3":[4,7],
    "N4":[2,9],
    "N5":[1,8],
    "N6":[3,6],
    "N7":[5,10],
    "N1":["N3","N4"],
    "N2":["N5","N6","N7"],
    "Root":["N1","N2"]
}

def minimax(node,isMax):

    if isinstance(node,int):
        return node

    if node in ["N3","N4","N5","N6","N7"]:
        return max(tree[node])

    if isMax:
        return max(minimax(child,False) for child in tree[node])
    else:
        return min(minimax(child,True) for child in tree[node])

print("Updated Minimax:", minimax("Root",True))

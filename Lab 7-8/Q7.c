# Fatima Salman 24K-1021

from ortools.sat.python import cp_model

model = cp_model.CpModel()

n = 4

queens = [model.NewIntVar(0,n-1,f'q{i}') for i in range(n)]

model.AddAllDifferent(queens)

for i in range(n):
    for j in range(i+1,n):
        model.Add(queens[i] - queens[j] != i-j)
        model.Add(queens[i] - queens[j] != j-i)

solver = cp_model.CpSolver()

status = solver.Solve(model)

if status == cp_model.OPTIMAL:
    board = [[0]*n for _ in range(n)]

    for i in range(n):
        board[i][solver.Value(queens[i])] = 1

    for row in board:
        for cell in row:
            if cell==1:
                print("Q",end=" ")
            else:
                print("_",end=" ")
        print()

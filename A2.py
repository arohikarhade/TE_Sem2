def calculate_heurisitc(board, goal):
    count = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] != goal[i][j] and board[i][j] != 0:  # Modified condition
                count += 1
    return count

def printSol(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            print(board[i][j], " ", end="")
        print()

def findZero(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                return i, j  # Return immediately when zero is found
    return -1, -1  # If zero not found, return -1, -1

def solvePuzzle(start, goal):
    move1 = [0, 0, -1, 1]
    move2 = [-1, 1, 0, 0]

    currState = start
    visited = set()
    visited.add(tuple(map(tuple, currState)))  # Convert list of lists to tuple of tuples to make it hashable

    while True:
        zeroRow, zeroCol = findZero(currState)

        nextState = None
        heuristicVal = float('inf')

        for i in range(len(move1)):
            newRow = zeroRow + move1[i]
            newCol = zeroCol + move2[i]

            if 0 <= newRow < len(currState) and 0 <= newCol < len(currState[0]):
                newState = [row[:] for row in currState]  # Deep copy the current state

                temp = newState[newRow][newCol]
                newState[newRow][newCol] = 0
                newState[zeroRow][zeroCol] = temp

                hVal = calculate_heurisitc(newState, goal)
                if hVal < heuristicVal and tuple(map(tuple, newState)) not in visited:
                    nextState = newState
                    heuristicVal = hVal

        printSol(nextState)

        if nextState is None:
            print("No solution exists.")
            return
        elif nextState == goal:
            print("Goal state reached:")
            printSol(nextState)
            return
        else:
            currState = nextState
            visited.add(tuple(map(tuple, currState)))  # Convert list of lists to tuple of tuples for set


start = [[1,2,3], [5,6,0], [7,8,4]]
goal = [[1,2,3], [5,8,6], [0,7,4]]

solvePuzzle(start, goal)

















# def calculate_heurisitc(board, goal):
#     count = 0
#     for i in len(board):
#         for j in len(board):
#             if (board[i][j] == goal[i][j]) and board[i][j]!=0:
#                 count += 1
#     return count

# def printSol(board):
#     for i in len(board):
#         for j in len(board):
#             print(board[i][j], " ")
#         print("\n")

# def findZero(board):
#     for i in len(board):
#         for j in len(board):
#             if board[i][j]==0:
#                 x=i, y=j
#     return x,y

# def solvePuzzle(start, goal):
#     move1 = [0, 0, -1, 1]
#     move2 = [-1, 1, 0, 0]

#     currState = start
#     visited = set.add(currState)

#     while(True):

#         zeroRow, zeroCol = findZero(currState) 

#         nextState = [[]]
#         heuristicVal = 999
#         # 4 possibilities

#         for i in len(move1):
#             newState = currState

#             newRow = zeroRow + move1[i]
#             newCol = zeroCol + move2[i]

#             temp = newState[newRow][newCol]
#             newState[newRow][newCol] = 0
#             newState[zeroRow][zeroCol] = temp

#             hVal = calculate_heurisitc(newState)
#             if (hVal < heuristicVal and (newState not in visited)):
#                 nextState = newState
#                 heuristicVal = hVal

        



# board_initial = [[1,2,3], [5,6,0], [7,8,4]]
# board_final = [[1,2,3], [5,8,6], [0,7,4]]



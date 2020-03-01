from AlphaBetaPruning import *

def loadBoard():
    load = True if input('Would you like to play? y/n').lower() == 'y' else False
    if load:
        return None, load
    else:
        return 0

def aiTurn(board, depth):
    aiMove = AlphaBetaPruning(board, depth, AI)
    board = currentMove(board, aiMove, AI)[0]
    aiFourInRow = winCheck(board)

    return board, aiFourInRow


def aiHasWon(board):
    printBoard(board)
    print('                     ' + "Computer has won\n")
    rematch = True if input('Would you like to play again? y/n').lower() == 'y' else False
    if rematch:
        mainFunction()
    return 0

def playerTurn(board):
    Col = input('Choose a Column between 1 and 7: ')
    if not (Col.isdigit()):
        print("Please enter an integer")
        return playerTurn(board)

    playerMove = int(Col) - 1

    if playerMove < 0 or playerMove > 6:
        print("Column must be between 1 and 7")
        return playerTurn(board)

    if not (valCol(board, playerMove)):
        print("Selected column is full")
        return playerTurn(board)

    board = currentMove(board, playerMove, PLAYER)[0]
    playerWin = winCheck(board)
    return board, playerWin


def playerHasWon(board):
    printBoard(board)
    print('                    ' + "player wins\n")
    rematch = True if input('Would you like to play again? y/n').lower() == 'y' else False
    if rematch:
        mainFunction()
    return 0



def getDepth():
    depth = input('Enter level of Agent(1-3): ')
    if not (depth.isdigit()):
        print('Please enter an integer!')
        return getDepth()

    depth = int(depth, 10)

    if depth < 1 or depth > 3:
        print("Difficulty must be between 1 and 3!")
        return getDepth()

    return depth



def mainFunction():
    os.system('cls' if os.name == 'nt' else 'clear')
    board, load = loadBoard()
    if board == None:
        board = initBoard()
    printBoard(board)
    depth = getDepth()
    whileCondition = 1
    if load == True:
        whomStart = True
    else:
        whomStart = True if input('Would you like to start? y/n').lower() == 'y' else False
    if board == None:
        board = initBoard()

    while (whileCondition):
        if isFilled(board):
            print("GAME OVER\n")
            break

        if whomStart:

            board, playerWin = playerTurn(board)
            if playerWin:
                whileCondition = playerHasWon(board)
                if whileCondition == 0:
                    break

            board, aiFourInRow = aiTurn(board, depth)
            if aiFourInRow:
                whileCondition = aiHasWon(board)
                if whileCondition == 0:
                    break
            printBoard(board)


        else:

            board, aiFourInRow = aiTurn(board, depth)
            if aiFourInRow:
                whileCondition = aiHasWon(board)
                if whileCondition == 0:
                    break
            printBoard(board)

            board, playerWin = playerTurn(board)
            if playerWin:
                whileCondition = playerHasWon(board)

                if whileCondition == 0:
                    break

            printBoard(board)


mainFunction()
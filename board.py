import os
from copy import deepcopy
from utility import *




def initBoard():
    Board = []
    for i in range(HEIGHT):
        Board.append([])
        for j in range(WIDTH):
            Board[i].append(' ')
    return Board



def valRange(row, col):
    if row >= 0 and col >= 0 and row < HEIGHT and col < WIDTH:
        return True
    return False


def valCol(Board, Col):
    if Board[0][Col] == ' ':
        return True
    return False

def valMoves(Board):
    Columns = []
    for Col in range(WIDTH):
        if valCol(Board, Col):
            Columns.append(Col)
    return Columns


def isEmptyCol(col, board):
    for row in range(HEIGHT):
        if board[row][col] == ' ':
            return True
    return False

def currentMove(board, col, player):
    currentBoard = deepcopy(board)
    for row in range(5,-1,-1):
        if currentBoard[row][col] == ' ':
            currentBoard[row][col] = player
            return currentBoard, row, col

def isFilled(board):
    for row in range(HEIGHT):
        for col in range(WIDTH):
            if board[row][col]==' ': return False
    return True



def winCheck(board):

    def vertical(row, col):
        hasWon = False
        count = 0
        for rowIndex in range(row, HEIGHT):
            if board[rowIndex][col] == board[row][col]:
                count += 1
            else:
                break

        if count >= 4:
            hasWon = True

        return hasWon, count

    def horizontal(row, col):
        hasWon = False
        count = 0
        for colIndex in range(col, WIDTH):
            if board[row][colIndex] == board[row][col]:
                count += 1
            else:
                break

        if count >= 4:
            hasWon = True

        return hasWon, count

    def diagonalPos(row,col):
        slope = None
        count = 0
        colIndex = col
        for rowIndex in range(row, HEIGHT):
            if colIndex > HEIGHT:
                break
            elif board[rowIndex][colIndex] == board[row][col]:
                count += 1
            else:
                break
            colIndex += 1

        if count >= 4:
            slope = 'positive'

        return slope, count


    def diagonalNeg(row, col):

        slope = None
        count = 0
        colIndex = col
        for rowIndex in range(row, -1, -1):
            if colIndex > 6:
                break
            elif board[rowIndex][colIndex] == board[row][col]:
                count += 1
            else:
                break
            colIndex += 1

        if count >= 4:
            slope = 'negative'

        return slope, count


    def diagonal(row,col):
        posSlope , positiveCount = diagonalPos(row,col)
        negSlope , negativeCount = diagonalNeg(row,col)

        if   posSlope == 'positive' and negSlope == 'negative':
            hasWon = True
            slope = 'both'
        elif posSlope == None and negSlope == 'negative':
            hasWon = True
            slope = 'negative'
        elif posSlope == 'positive' and negSlope == None:
            hasWon = True
            slope = 'positive'
        else:
            hasWon = False
            slope = None

        return hasWon, slope, positiveCount, negativeCount



    gameOver = False


    for rowIndex in range(HEIGHT):
        for colIndex in range(WIDTH):
            if board[rowIndex][colIndex] != ' ':

                hasWon, verticalCount = vertical(rowIndex, colIndex)
                if hasWon:
                    gameOver = True

                hasWon, horizontalCount = horizontal(rowIndex, colIndex)

                if hasWon:
                    gameOver = True


                hasWon, slope , positiveCount, negativeCount = diagonal(rowIndex, colIndex)
                if hasWon:
                    gameOver = True

    return gameOver


def printBoard(Board):
    os.system('cls' if os.name == 'nt' else 'clear')
    print('')
    print('')
    print('')
    print("\t  1   2   3   4   5   6   7 ")


    for i in range(0, HEIGHT, 1):
        print("\t",end="")
        for j in range(WIDTH):
            if str(Board[i][j]) == 'x':
                print("[ " + str(Board[i][j]), end=" ")
            elif str(Board[i][j]) == 'o':
                print("[ " + str(Board[i][j]), end=" ")
            else:
                print("[ " + str(Board[i][j]), end=" ")

        print("[")
    print('')





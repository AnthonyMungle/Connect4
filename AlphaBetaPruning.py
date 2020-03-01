from board import *
from random import shuffle


def AlphaBetaPruning(board, depth, player):

    validMoves = valMoves(board)
    shuffle(validMoves)
    bestMove = validMoves[0]
    bestScore = float("-inf")


    alpha = float("-inf")
    beta = float("inf")

    if player == AI:
        opponent = PLAYER
    else:
        opponent = AI

    for move in validMoves:

        currentBoard = currentMove(board, move, player)[0]

        boardScore = min(currentBoard, depth - 1, alpha, beta, player, opponent)
        if boardScore > bestScore:
            bestScore = boardScore
            bestMove = move
    return bestMove


def min(board, depth, a, b, player, opponent):
    validMoves = []
    for col in range(7):
        if isEmptyCol(col, board):
            temp = currentMove(board, col, player)[2]
            validMoves.append(temp)
    if depth == 0 or len(validMoves) == 0 or end(board):
        return utility(board, player)
    validMoves = valMoves(board)
    beta = b
    for move in validMoves:
        boardScore = float("inf")
        if a < beta:
            currentBoard = currentMove(board, move, opponent)[0]
            boardScore = max(currentBoard, depth - 1, a, beta, player, opponent)

        if boardScore < beta:
            beta = boardScore
    return beta


def max(board, depth, a, b, player, opponent):
    validMoves = []
    for col in range(7):
        if isEmptyCol(col, board):
            temp = currentMove(board, col, player)[2]
            validMoves.append(temp)
    if depth == 0 or len(validMoves) == 0 or end(board):
        return utility(board, player)
    alpha = a
    for move in validMoves:
        boardScore = float("-inf")
        if alpha < b:
            currentBoard = currentMove(board, move, player)[0]
            boardScore = min(currentBoard, depth - 1, alpha, b, player, opponent)
        if boardScore > alpha:
            alpha = boardScore
    return alpha
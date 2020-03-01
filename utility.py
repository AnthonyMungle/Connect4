WIDTH = 7
HEIGHT = 6
AI= 'x'
PLAYER = 'o'

def countSeq(board, player, length):

    def horizontalSeq(row, col):

        count = 0
        for colIndex in range(col, WIDTH):
            if board[row][colIndex] == board[row][col]:
                count += 1
            else:
                break
        if count >= length:
            return 1
        else:
            return 0

    def verticalSeq(row, col):

        count = 0
        for rowIndex in range(row, HEIGHT):
            if board[rowIndex][col] == board[row][col]:
                count += 1
            else:
                break
        if count >= length:
            return 1
        else:
            return 0

    def negDiagonalSeq(row, col):

        count = 0
        colIndex = col
        for rowIndex in range(row, -1, -1):
            if colIndex > HEIGHT:
                break
            elif board[rowIndex][colIndex] == board[row][col]:
                count += 1
            else:
                break
            colIndex += 1
        if count >= length:
            return 1
        else:
            return 0

    def posDiagonalSeq(row, col):
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
        if count >= length:
            return 1
        else:
            return 0

    totalCount = 0

    for row in range(HEIGHT):
        for col in range(WIDTH):

            if board[row][col] == player:

                totalCount += verticalSeq(row, col)

                totalCount += horizontalSeq(row, col)

                totalCount += (posDiagonalSeq(row, col) + negDiagonalSeq(row, col))

    return totalCount

def utility(board, player):

    if player == PLAYER: opponent = AI
    else: opponent = PLAYER

    playerFour    = countSeq(board, player, 4)
    playerThree   = countSeq(board, player, 3)
    playerTwo     = countSeq(board, player, 2)
    playerScore    = playerFour*99999 + playerThree*999 + playerTwo*99

    opponentFour  = countSeq(board, opponent, 4)
    opponentThree = countSeq(board, opponent, 3)
    opponentTwo   = countSeq(board, opponent, 2)
    opponentScore  = opponentFour*99999 + opponentThree*999 + opponentTwo*99

    if opponentFour > 0:
        return float('-inf')
    else:
        return playerScore - opponentScore


def end(board):

    if countSeq(board, PLAYER, 4) >= 1:
        return True
    elif countSeq(board, PLAYER, 4) >= 1:
        return True
    else:
        return False
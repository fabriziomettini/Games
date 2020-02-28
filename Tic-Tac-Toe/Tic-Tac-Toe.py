from random import randint

#----------Print board-----------------------
def displayBoard(board):
    print(board[0] + ' | ' + board[1] + ' | ' + board[2])
    print(board[3] + ' | ' + board[4] + ' | ' + board[5])
    print(board[6] + ' | ' + board[7] + ' | ' + board[8])

#----------Check if is possible-------------
def possible(board, move):
    possible = True
    move -= 1
    if board[move] != '-':
        possible = False
    return possible

#----------Place move-----------------------
def place(board, move, x):
    move -= 1
    board[move] = x

#---------Check Columns---------------------
def checkColumns(board):
    win = False
    for i in range(3):
       if board[i] == board[i+3] == board[i+6] != '-':
           win = True
    return win

#---------Check Rows------------------------
def checkRows(board):
    win = False
    for i in [0, 3, 6]:
        if board[i] == board[i+1] == board[i+2] != '-':
           win = True
    return win

#---------Check Diagonals-------------------
def checkDiagonals(board):
    win = False
    if board[0] == board[4] == board[8] != '-':
       win = True
    if board[2] == board[4] == board[6] != '-':
       win = True
    return win

#----------Check Win Function --------------
def checkWin(board):
    win = checkColumns(board) or checkRows(board) or checkDiagonals(board)
    return win

#-----------Main---------------------------
def main():
    print('Tic-Tac-Toe')
    board = ['-' for i in range(9)]
    a = 'x'
    b = 'o'

    finished = False
    movesCounter = 0
    while (not finished) and movesCounter < 9:
        valid = False
        while not valid:
            if movesCounter % 2 == 0:
                player1Move = int(input('Enter your move (1-9): '))
                if player1Move in range(1, 10):
                    valid = possible(board, player1Move)
                if not valid:
                    print('Move not valid')
            else:
                pcMove = randint(1, 9)
                if pcMove in range(1, 10):
                    valid = possible(board, pcMove)
        if movesCounter % 2 == 0:
            place(board, player1Move, a)
        else:
            print('PC move: ' + str(pcMove))
            place(board, pcMove, b)
        movesCounter += 1
        displayBoard(board)
        finished = checkWin(board)
        
    if finished:
        if movesCounter % 2 != 0:
            print('Player 1 won')
        else:
            print('PC won')
    else:
        print('DRAW')

if __name__ == '__main__':
    main()




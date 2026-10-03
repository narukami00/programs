import math

board = [[" "]*3 for _ in range(3)]

def winner(b):
    lines=b+[[b[r][c] for r in range(3)] for c in range(3)] + [[b[i][i] for i in range(3)], [b[i][2-i] for i in range(3)]]

    for line in lines:
        if line == ["X"] * 3: return "X"
        if line == ["O"] * 3: return "O"
    return None

def full(b):
    return all(cell!=" " for row in b for cell in row)

def minimax(b, depth, is_max, alpha, beta):
    w=winner(b)
    if w=="X": return 10-depth
    if w=="O": return depth-10
    if full(b): return 0

    if is_max:
        best=-math.inf
        for r in range(3):
            for c in range(3):
                if b[r][c]==" ":
                    b[r][c]="X"
                    best=max(best, minimax(b, depth+1, False, alpha, beta))
                    b[r][c]=" "
                    alpha=max(alpha, best)
                    if beta<=alpha: return best
        return best
    else:
        best=math.inf
        for r in range(3):
            for c in range(3):
                if b[r][c]==" ":
                    b[r][c]="O"
                    best=min(best, minimax(b, depth+1, True, alpha, beta))
                    b[r][c]=" "
                    beta=min(beta, best)
                    if beta<=alpha: return best
        return best

def best_move():
    best, move = -math.inf, None
    for r in range(3):
        for c in range(3):
            if board[r][c]==" ":
                board[r][c]="X"
                score=minimax(board, 0, False, -math.inf, math.inf)
                board[r][c]=" "
                if score>best:
                    best, move=score, (r, c)
    return move

def show():
    for i, row in enumerate(board):
        print(" | ".join(row))
        if i<2: print("--+---+--")

while True:
    r, c=best_move()
    board[r][c]="X"
    print("AI plays: ")
    show()
    if winner(board) or full(board): break

    while True:
        r, c = map(int, input("Enter your move (row col): ").split())
        if 0<=r<=2 and 0<=c<=2 and board[r][c]==" ":
            break
        print("Invalid move, try again.")
    board[r][c]="O"
    show()
    if winner(board) or full(board): break

w=winner(board)
if w:
    print(f"{w} wins!") 
else:
    print("It's a draw!")
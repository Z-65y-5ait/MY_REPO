#include <stdio.h>
#include <stdbool.h>

bool verify(char board[3][3], char player);

void printBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void saisie_des_joueurs() {
    int i, j;
    char choice1, choice2;
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    printf("Enter one character between X and O: ");
    scanf(" %c", &choice1);
    if (choice1 == 'X') {
        choice2 = 'O';
    } else {
        choice1 = 'O';
        choice2 = 'X';
    }

    int role = 0;
    bool gameOver = false;
    while (!gameOver) {
        bool gamer1Turn = true;
        while (gamer1Turn) {
            do {
                printf("Gamer 1 (Player %c), enter two numbers (0-2) for row and column: ", choice1);
                scanf("%d %d", &i, &j);
            } while (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != ' ');
            board[i][j] = choice1;
            printBoard(board);
            if (verify(board, choice1)) {
                printf("Gamer 1 (Player %c) won!\n", choice1);
                gameOver = true;
                break;
            }
            gamer1Turn = false;
        }

        if (gameOver) break;

        bool gamer2Turn = true;
        while (gamer2Turn) {
            do {
                printf("Gamer 2 (Player %c), enter two numbers (0-2) for row and column: ", choice2);
                scanf("%d %d", &i, &j);
            } while (i < 0 || i > 2 || j < 0 || j > 2 || board[i][j] != ' ');
            board[i][j] = choice2;
            printBoard(board);
            if (verify(board, choice2)) {
                printf("Gamer 2 (Player %c) won!\n", choice2);
                gameOver = true;
                break;
            }
            gamer2Turn = false;
        }
        if (gameOver) 
            break;
        role++;
        if (role == 9) {
            printf("It's a draw!\n");
            gameOver = true;
        }
    }
    printf("Do you want to replay?\n");
    printf("1. YES\n");
    printf("2. NO\n");
    int r;
    scanf("%d", &r);
    switch (r) {
        case 1:
            saisie_des_joueurs();
            break;
        case 2:
            printf("Until the next time!\n");
            break;
        default:
            printf("Please enter a number 1 or 2.\n");
    }
}

bool verify(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    saisie_des_joueurs();
    return 0;
}

#include "stdio.h"
#include "conio.h"
#include<windows.h>
void setcolor(int, int);
struct Table
{
     int fa = 0;
    int player = 0;
    int go = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int winner = 0;
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
}gogo;

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}


void Schedule()
{
    
    for (gogo.fa = 0; gogo.fa < 9 && gogo.winner == 0; gogo.fa++)
    {
        
        printf("\n\n");
        printf("\t\t\t\t %c | %c | %c\n", gogo.board[0][0], gogo.board[0][1], gogo.board[0][2]);
        printf("\t\t\t\t+++*+++*+++\n");
        printf("\t\t\t\t %c | %c | %c\n", gogo.board[1][0], gogo.board[1][1], gogo.board[1][2]);
        printf("\t\t\t\t+++*+++*+++\n");
        printf("\t\t\t\t %c | %c | %c\n", gogo.board[2][0], gogo.board[2][1], gogo.board[2][2]);
        gogo.player = gogo.fa % 2 + 1;

        do {
            
            printf("\n\t\tPlayer %d, please enter the number [your] %c: ", gogo.player, (gogo.player == 1) ? 'X' : 'O');
            scanf_s("%d", &gogo.go);
            gogo.row = --gogo.go / 3;
            gogo.column = gogo.go % 3;
        } while (gogo.go < 0 || gogo.go>9 || gogo.board[gogo.row][gogo.column] > '9');
        gogo.board[gogo.row][gogo.column] = (gogo.player == 1) ? 'X' : 'O';
        setcolor(2, 0);
        if ((gogo.board[0][0] == gogo.board[1][1] && gogo.board[0][0] == gogo.board[2][2]) ||
            (gogo.board[0][2] == gogo.board[1][1] && gogo.board[0][2] == gogo.board[2][0]))
            gogo.winner = gogo.player;
        else
            for (gogo.line = 0; gogo.line <= 2; gogo.line++)
                if ((gogo.board[gogo.line][0] == gogo.board[gogo.line][1] && gogo.board[gogo.line][0] == gogo.board[gogo.line][2]) ||
                    (gogo.board[0][gogo.line] == gogo.board[1][gogo.line] && gogo.board[0][gogo.line] == gogo.board[2][gogo.line]))
                    gogo.winner = gogo.player;
    }

}
void printff()
    {
    setcolor(4, 0);
    printf("\n\n");
    printf("\t\t\t\t %c | %c | %c\n", gogo.board[0][0], gogo.board[0][1], gogo.board[0][2]);
    printf("\t\t\t\t+++*+++*+++\n");
    printf("\t\t\t\t %c | %c | %c\n", gogo.board[1][0], gogo.board[1][1], gogo.board[1][2]);
    printf("\t\t\t\t+++*+++*+++\n");
    printf("\t\t\t\t %c | %c | %c\n", gogo.board[2][0], gogo.board[2][1], gogo.board[2][2]);
    }


int main() {
   
    Schedule();
    printff(); 
    setcolor(2, 0);
    if (gogo.winner == 0)
        printf("\n\t\t\tHow boring, it is a draw\n");
    else
        printf("\n\t\tCongratulations, player %d, YOU ARE THE WINNER!\n", gogo.winner);
}

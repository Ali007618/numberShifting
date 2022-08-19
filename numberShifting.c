#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char name[50];
int moves = 400;
int input;
bool solved = 0;

void setName()
{
    int len = 0;
    printf("\n\t\tEnter your name : ");
    fgets(name, 50, stdin);
    for (; name[len] != '\0'; len++)
        ;
    name[len - 1] = '\0';
}

void intro()
{
    printf("\t\t\t\t\t\tRULE OF THIS GAME										 	                              \n");
    printf("\t1. You can move only 1 step at a time by arrow key											      \n");
    printf("\t\tMove Up : by Up arrow key	\t\tMove Left : by Left arrow key								      \n");
    printf("\t\tMove Down : by Down arrow key	\t\tMove Right : by Right arrow key								  \n");
    printf("\t2. You can move number at empty position only													      \n");
    printf("\t3.For each valid move your total number of move will decreased by 1							      \n");
    printf("\t4.Wining situation number in a 4 x 4 matrix should be in order from 1 to 15	                      \n");
    ;
    printf("\t\twinning situation :																			      \n");
    printf("\t\t| 1  | 2  | 3  | 4  |																			  \n");
    printf("\t\t| 5  | 6  | 7  | 8  |																			  \n");
    printf("\t\t| 9  | 10 | 11 | 12 |																			  \n");
    printf("\t\t| 13 | 14 | 15 |    |    																		  \n");
    printf("\t5. You can exit the game at any time by pressing 'E' or 'e' So Try to win in minimum no of move     \n");
    printf("\t\tHappy gaming, Good Luck																		      \n");
    printf("\tPress any key to start.....");
    getch();
}

void win()
{

    if (solved)
        printf("\nCongratulations %s! You solved the puzzle.\n", name);
}

void gameOver()
{
    if (moves == 0)
    {
        printf("Oops! Looks like you ran out off all your moves.\n");
    }
    printf("Thanks for playing the game, %s. We hope that you had fun while playing.", name);
    getch();
}

void print(int matrix[4][4])
{

    system("cls");

    printf("\nHello, %s! \t\t|\t\tRemaing moves : %d\n", name, moves);

    for (int d = 0; d < 33; d++)
    {
        printf("%c", 196);
    }
    printf("\n");

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            if (matrix[a][b] == 16)
            {
                if (b == 3)
                {
                    printf("| \t|");
                }
                else
                    printf("| \t");
            }
            else
            {
                if (b == 3)
                    printf("|%d\t|", matrix[a][b]);
                else
                    printf("|%d\t", matrix[a][b]);
            }
        }
        printf("\n");
    }
    for (int d = 0; d < 33; d++)
    {
        printf("%c", 196);
    }
}

void update(int matrix[4][4])
{

    int a, b, r, c;

    input = _getch();

    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        {
            if (matrix[a][b] == 16)
            {
                r = a;
                c = b;
            }
        }
    }

    switch (input)
    {
    case KEY_UP:
        if (r > 0 && r < 4)
        {
            int temp = matrix[r - 1][c];
            matrix[r - 1][c] = matrix[r][c];
            matrix[r][c] = temp;
            moves--;
        }
        break;
    case KEY_DOWN:
        if (r < 3 && r < 4)
        {
            int temp = matrix[r + 1][c];
            matrix[r + 1][c] = matrix[r][c];
            matrix[r][c] = temp;
            moves--;
        }
        break;
    case KEY_LEFT:
        if (c > 0 && r < 4)
        {
            int temp = matrix[r][c - 1];
            matrix[r][c - 1] = matrix[r][c];
            matrix[r][c] = temp;
            moves--;
        }
        break;
    case KEY_RIGHT:
        if (c < 3 && r < 4)
        {
            int temp = matrix[r][c + 1];
            matrix[r][c + 1] = matrix[r][c];
            matrix[r][c] = temp;
            moves--;
        }
        break;
    }
}

int check(int matrix[4][4])
{

    int i = 1, j, k;

    if (moves == 0)
        return 0;

    if (input == 'e' || input == 'E')
        return 0;

    for (j = 0; j < 4; j++)
    {
        for (k = 0; k < 4; k++)
        {
            if (matrix[j][k] != i++)
            {
                return 1;
            }
        }
    }
    solved = 1;
    return 0;
}

void init(int size, bool flag[], int val[], int i, int x, int matrix[4][4])
{
    time_t t1;
    srand((unsigned)time(&t1));

    input = 0;
    moves = 1000;

    // Generate random numbers in 1D array

    while (i < 15)
    {
        x = rand() % 15 + 1;
        if (flag[x - 1] == 0)
        {
            flag[x - 1] = 1;
            val[i++] = x;
        }
    }

    i = 0;

    // store 1D array into 2D array

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            matrix[r][c] = val[i++];
        }
        matrix[3][3] = 16;
    }
    setName();
}

int main()
{
    const int size = 15;
    bool flag[15] = {0};
    int matrix[4][4], val[15], test;

    int x = 0, i = 0;

    intro();

    init(size, flag, val, i, x, matrix);

    while (check(matrix))
    {
        print(matrix);
        update(matrix);
    }

    win();

    gameOver();

    print(matrix);

    return 0;
}

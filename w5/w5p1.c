/*
    ==================================================
    Workshop #5 (Part-1):
    ==================================================
    Name   :Patel Ved Rajendrakumar
    ID     :149409203
    Email  :vrpatel33@myseneca.ca
    Section:IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_LENGTH 70
#define MIN_LENGTH 10
#define MAX_MOVES 26
#define MIN_MOVES 3

int main(void)
{
    int lives, length, Moves , i , j , c , k ;
    char name;

    
    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n");

    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &name);
    
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &lives);

        if (lives > MAX_LIVES || lives < MIN_LIVES)
        {
        printf("     Must be between 1 and 10!\n");
        }

    } while (lives<MIN_LIVES || lives>MAX_LIVES);
    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &length);


        if ((length <MIN_LENGTH || length>MAX_LENGTH) || (length % 5 != 0))
        {
        printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    } while ((length <MIN_LENGTH || length>MAX_LENGTH) || (length % 5 != 0));

    do {

        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Moves);

        if (Moves<MIN_MOVES || Moves>MAX_MOVES)
        {
        printf("    Value must be between 3 and 26\n");
        }

    } while (Moves<MIN_MOVES || Moves>MAX_MOVES);
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", length);

    int g[MAX_LENGTH];
    for (i = 0; i < length; i += 5)
    {
        printf("   Positions [%2d-%2d]:", i + 1, i + 5);
        for (k = i; k <i+5; k++)
        {
            
            scanf("%d",&g[k]);
            
        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", length);
    int f[MAX_LENGTH];
    for (c = 0; c < length; c += 5)
    {
        printf("   Positions [%2d-%2d]:", c + 1, c + 5);
        for (j = c; j < c+5; j++)
        {
            scanf("%d", &f[j] );
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", name);
    printf("   Lives      : %d\n", lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", length);
    printf("   Bombs      : ");
    for (i = 0; i < length ; i++)
    {
        printf("%d", g[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < length; i++)
    {

        printf("%d", f[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;

}
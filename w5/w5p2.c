/*
    ==================================================
    Workshop #5 (Part-2):
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
#define MAX_MOVES 15
#define MIN_MOVES 3
struct playerinfo
{
    int lives;
    char name;
    int nooftreasure;
    int history[MAX_LENGTH];
    int location[MAX_LENGTH];
};
struct gameinfo
{
    int length;
    int Moves;
    int nextmove;
    int remainmoves;
    int bombs[MAX_LENGTH];
    int treasure[MAX_LENGTH];
};

int main(void)
{
    int i = 0, j = 0, k = 0, c = 0;

    struct playerinfo pSetting;
    struct gameinfo gSetting;
    pSetting.nooftreasure = 0;

    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n");

    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &pSetting.name);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &pSetting.lives);

        if (pSetting.lives > MAX_LIVES || pSetting.lives < MIN_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }

    } while (pSetting.lives<MIN_LIVES || pSetting.lives>MAX_LIVES);
    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &gSetting.length);


        if ((gSetting.length <MIN_LENGTH || gSetting.length>MAX_LENGTH) || (gSetting.length % 5 != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }

    } while ((gSetting.length <MIN_LENGTH || gSetting.length>MAX_LENGTH) || (gSetting.length % 5 != 0));

    do {

        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gSetting.Moves);

        if (gSetting.Moves<MIN_MOVES || gSetting.Moves>MAX_MOVES)
        {
            printf("    Value must be between 3 and 15\n");
        }

    } while (gSetting.Moves<MIN_MOVES || gSetting.Moves>MAX_MOVES);
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gSetting.length);


    for (i = 0; i < gSetting.length; i += 5)
    {
        printf("   Positions [%2d-%2d]:", i + 1, i + 5);
        for (k = i; k < i + 5; k++)
        {

            scanf("%d", &gSetting.bombs[k]);//bomb

        }
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gSetting.length);

    for (c = 0; c < gSetting.length; c += 5)
    {
        printf("   Positions [%2d-%2d]:", c + 1, c + 5);
        for (j = c; j < c + 5; j++)
        {
            scanf("%d", &gSetting.treasure[j]);//treasure
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", pSetting.name);
    printf("   Lives      : %d\n", pSetting.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", gSetting.length);
    printf("   Bombs      : ");
    for (i = 0; i < gSetting.length; i++)
    {
        printf("%d", gSetting.bombs[i]);//bomb
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gSetting.length; i++)
    {

        printf("%d", gSetting.treasure[i]);//treasure
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    //printf("\n");

    for (i = 0; i < gSetting.length; i++)
    {
        pSetting.history[i] = '-';//history
    }
    for (i = 0; i < gSetting.length; i++)
    {
        pSetting.location[i] = ' ';//location
    }
    int firstlooptime = 0;
    while (gSetting.Moves != 0 && pSetting.lives != 0) {
        if (firstlooptime != 0) {
            printf("  ");
            for (i = 0; i < gSetting.length; i++)
            {
                printf("%c", pSetting.location[i]);//loation
            }
        }
        else {
           
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gSetting.length; i++)
        {
            printf("%c", pSetting.history[i]); //history
        }
        if (firstlooptime != 0) {
            for (i = 0; i < gSetting.length; i++) {
                pSetting.location[i] = ' ';//location
            }
        }
        printf("\n");
        printf("  |||||||||1|||||||||2\n");
        printf("  12345678901234567890\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", pSetting.lives, pSetting.nooftreasure, gSetting.Moves);
        printf("+---------------------------------------------------+\n");

        do {
            printf("Next Move [1-20]: ");
            scanf("%d", &gSetting.nextmove);
            if (gSetting.nextmove > 20 || gSetting.nextmove < 1)
            {
                printf("  Out of Range!!!\n");
            }

        } while (gSetting.nextmove > 20 || gSetting.nextmove < 1);
        printf("\n");
        if (gSetting.bombs[gSetting.nextmove - 1] == 1 && gSetting.treasure[gSetting.nextmove - 1] == 0 && pSetting.history[gSetting.nextmove - 1] == '-')
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            pSetting.history[gSetting.nextmove - 1] = '!';//history
            pSetting.lives--;
            gSetting.Moves--;
            pSetting.location[gSetting.nextmove - 1] = 'V';//location
        }
        else if (gSetting.bombs[gSetting.nextmove - 1] == 1 && gSetting.treasure[gSetting.nextmove - 1] == 1 && pSetting.history[gSetting.nextmove - 1] == '-') {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            pSetting.history[gSetting.nextmove - 1] = '&';//history
            pSetting.lives--;
            gSetting.Moves--;
            pSetting.nooftreasure++;
            pSetting.location[gSetting.nextmove - 1] = 'V';//location
            firstlooptime = 1;
        }
        else if (gSetting.treasure[gSetting.nextmove - 1] == 1 && gSetting.bombs[gSetting.nextmove - 1] == 0 && pSetting.history[gSetting.nextmove - 1] == '-')
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            pSetting.history[gSetting.nextmove - 1] = '$';//history
            pSetting.nooftreasure++;
            gSetting.Moves--;
            pSetting.location[gSetting.nextmove - 1] = 'V';//location
            firstlooptime = 1;
        }
        else if (gSetting.treasure[gSetting.nextmove - 1] == 0 && gSetting.bombs[gSetting.nextmove - 1] == 0 && pSetting.history[gSetting.nextmove - 1] == '-') {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            pSetting.history[gSetting.nextmove - 1] = '.';//history
            gSetting.Moves--;
            pSetting.location[gSetting.nextmove - 1] = 'V';//location
            firstlooptime = 1;
        }
        else if (pSetting.history[gSetting.nextmove - 1] != '-') {
            printf("===============> Dope! You've been here before!\n\n");
            
            pSetting.location[gSetting.nextmove - 1] = 'V';//location
            firstlooptime = 1;

        }

    }
    if (pSetting.lives == 0) {
        printf("No more LIVES remaining!\n\n");
        printf("  ");
        for (i = 0; i < gSetting.length; i++)
        {
            printf("%c", pSetting.location[i]);//location
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gSetting.length; i++)
        {
            printf("%c", pSetting.history[i]);//histrry
        }


        printf("\n");
        printf("  |||||||||1|||||||||2\n");
        printf("  12345678901234567890\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", pSetting.lives, pSetting.nooftreasure, gSetting.Moves);
        printf("+---------------------------------------------------+\n\n");
        printf("##################\n");
        printf("#   Game over!   #\n");
        printf("##################\n\n");
        printf("You should play again and try to beat your score!\n");
    }
    return 0;

}
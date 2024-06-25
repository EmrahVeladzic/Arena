#ifndef RENDERER
#define RENDERER

#include <stdio.h>
#include "Characters.h"
#include <windows.h>

void qClear()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );

    for (size_t i = 0; i < 10; i++)
    {
        printf("                           \n");
    }

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );

}


int Render(ent* Player, ent* AI) {

    qClear();
    

    printf("P1\tAI\n");
    printf("%d\t%d\n",(int)Player->HP, (int)AI->HP);
    printf("%d\t%d\n",(int)Player->Stamina,(int)AI->Stamina);
    printf("%d\t%d\n",(int)GET_POSITION(Player->Actions) ,(int)GET_POSITION(AI->Actions));
    if (GET_BLOCKING(AI->Actions) == 1) {
       printf("GUARDING\n");
    }
    if (GET_ATTACK(AI->Actions) == 1) {
        printf("PARRY\n");
    }

	return 0;
}

#endif // !RENDERER


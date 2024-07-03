#include <stdio.h>
#include <stdlib.h>
#include "row_summing.h"
#pragma warning (disable : 4996)

void sumuj_wiersze_w_macierzy(const char* nazwa_pliku, int** macierz, int wiersze, int elementy)
{
    FILE* wyniki = fopen(nazwa_pliku, "w");
    if (wyniki == NULL)
    {
        printf("Blad otwarcia pliku!");
        return;
    }

    for (int i = 0; i < wiersze; i++)
    {
        int suma_wiersza = 0;
        for (int j = 0; j < elementy; j++)
        {
            suma_wiersza += macierz[i][j];
            fprintf(wyniki, "%d ", macierz[i][j]);
        }
        fprintf(wyniki, "=> Suma wiersza %d: %d\n", i + 1, suma_wiersza);
        printf("Suma wiersza %d: %d\n", i + 1, suma_wiersza);
    }

    fclose(wyniki);
}
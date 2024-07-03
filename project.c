#include <stdio.h>
#include <stdlib.h>
#include "read_matrix.h"
#include "row_summing.h"
#pragma warning (disable : 4996)

int main()
{
    int** macierz = NULL;
    int wiersze, elementy;

    if (wczytaj_macierz_z_pliku("matrix.txt", &macierz, &wiersze, &elementy) == -1)
    {
        return 1;
    }

    printf("Macierz:\n");
    for (int i = 0; i < wiersze; i++)
    {
        for (int j = 0; j < elementy; j++)
        {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }

    sumuj_wiersze_w_macierzy("results.txt", macierz, wiersze, elementy);

    zwolnij_macierz(macierz, wiersze);

    return 0;
}
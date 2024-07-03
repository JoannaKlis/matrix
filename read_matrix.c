#include <stdio.h>
#include <stdlib.h>
#include "read_matrix.h"
#include "error.h"
#pragma warning (disable : 4996)

int wczytaj_macierz_z_pliku(const char* nazwa_pliku, int*** macierz, int* wiersze, int* elementy)
{
    FILE* plik = fopen(nazwa_pliku, "r");
    if (plik == NULL)
    {
        error(2, "Blad otwarcia pliku");
        return -1;
    }

    *wiersze = 0;
    *elementy = 0;

    *macierz = (int**)malloc(sizeof(int*));
    (*macierz)[*wiersze] = (int*)malloc(sizeof(int));

    while (fscanf(plik, "%d", &(*macierz)[*wiersze][*elementy]) == 1)
    {
        (*elementy)++;
        if (fgetc(plik) == '\n')
        {
            (*wiersze)++;
            *elementy = 0;
            *macierz = (int**)realloc(*macierz, sizeof(int*) * (*wiersze + 1));
            if (*macierz == NULL)
            {
                error(3, "Brak pamieci");
                fclose(plik);
                return -1;
            }
            (*macierz)[*wiersze] = (int*)malloc(sizeof(int));
            if ((*macierz)[*wiersze] == NULL)
            {
                error(3, "Brak pamieci");
                fclose(plik);
                return -1;
            }
        }
        else
        {
            (*macierz)[*wiersze] = (int*)realloc((*macierz)[*wiersze], sizeof(int) * (*elementy + 1));
            if ((*macierz)[*wiersze] == NULL)
            {
                error(3, "Brak pamieci");
                fclose(plik);
                return -1;
            }
        }
    }

    if (*elementy > 0)
    {
        (*wiersze)++;
    }
    if (fscanf(plik, "%*s") != EOF) 
    {
        error(1, "Niepoprawne wartosci macierzy");
        fclose(plik);
        return -1;
    }
    fclose(plik);
    return 0;
}

void zwolnij_macierz(int** macierz, int wiersze)
{
    for (int i = 0; i < wiersze; ++i)
    {
        free(macierz[i]);
    }
    free(macierz);
}
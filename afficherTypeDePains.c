#include <stdlib.h>
#include <stdio.h>
#include"defines.h"

void afficherTypeDePains()
{
    FILE *fichier = fopen("typePain.txt", "r");

    if (fichier == NULL)
    {
        printf("Le fichier typePain.txt n'a pas pu etre ouvert \nFermer le programme et recommencer \n");
    }
    else
    {
        char nomPain[TAILLE_MAX];

        int i = 0;
        while (fgets(nomPain, TAILLE_MAX, fichier))
        {
            i++;
            printf("%i) %s", i, nomPain);
        }

        printf("\n");

        fclose(fichier);
    }
}
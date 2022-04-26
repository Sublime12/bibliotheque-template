#include<stdio.h>
#include<string.h>

#include"defines.h"

int recupererTypeDePain(int ligne, char *typeDePain)
{
    FILE *fichier = fopen("typePain.txt", "r");

    if (fichier == NULL)
    {
        printf("Le fichier typePain.txt n'a pas pu etre ouvert \nPeut etre qu'elle n'existe pas ou elle est deja ouverte par une autre instance du programme \nReessayer plutard \n");
    }
    else 
    {
        char chaineARecuperer[TAILLE_MAX];

        ligne--;
        // printf("La ligne recherchee est : %i \n\n", ligne);

        int i = 0;
        while (fgets(chaineARecuperer, TAILLE_MAX, fichier) != NULL)
        {
            if (i == ligne)
            {
                for (int j = 0; j < strlen(chaineARecuperer); j++)
                {
                    if (chaineARecuperer[j] == '\n')
                    {
                        chaineARecuperer[j] = ' ';
                    }
                }

                strcpy(typeDePain, chaineARecuperer);
                return 1;
            }

            i++;
        }
    }
}
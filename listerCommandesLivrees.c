#include<stdio.h>
#include "defines.h"

void listerCommandesLivrees()
{
    FILE *fichier = fopen("commandes.txt", "r");

    if (fichier == NULL)
    {
        printf("Le fichier commandes.txt n'existe pas ou elle est utilisee par un autre programme \nAucune commande trouvee \n");
    }
    else
    {
        char ligneARecuperer[TAILLE_MAX];
        int estLivree = 0, i = 0;

        char nullTypeDePain[TAILLE_MAX];
        int nullVariable = 0;

        while (fgets(ligneARecuperer, TAILLE_MAX, fichier))
        {
            i++;
            sscanf(ligneARecuperer, "%s %i %i %i",
                   nullTypeDePain,
                   &nullVariable,
                   &nullVariable,
                   &estLivree);

            if (estLivree)
            {
                printf("%i) %s ", i, ligneARecuperer);
            }
        }

        fclose(fichier);
    }
}
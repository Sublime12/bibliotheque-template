#include<stdio.h>
#include <string.h>

#include "defines.h"

void listerToutesLesCommandes()
{
    FILE *fichier = fopen("commandes.txt", "r");
    char commande[TAILLE_MAX];

    if (fichier == NULL)
    {
        printf("Le fichier commandes.txt n'existe pas ou elle est deja utilisee par un autre programme \nAucune commande trouvee \n");
    }
    else 
    {

        printf("type-pain prix-unitaire-fc quantite \n");

        int i = 0;
        while (fgets(commande, TAILLE_MAX, fichier) != NULL)
        {
            i++;
            // int tailleChaine = strlen(commande);
            // commande[tailleChaine - 2] = ' ';
            // commande[tailleChaine - 3] = ' ';

            printf("%i) %s", i, commande);
        }
        fclose(fichier);
    }
}
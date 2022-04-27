#include<stdlib.h>
#include<stdio.h>

#include"constantes.h"

int main()
{

    int choixUtilisateur;

    printf("Bonjour ce programme est la pour vous aider a gerer les activites courantes d'une bibliotheque \n");

    do
    {

        printf("\nChoisir un element : \n\n1) lister toutes les commandes \n2) lister les commandes en attente \n3) lister les marchandises livrees \n4) Commander une marchandise \n5) Confirmer une livraison \n6) Ajouter un nouveau type \n0) Appuyer sur 0 pour quitter\n\nR) ");

        scanf("%i", &choixUtilisateur);

        if (choixUtilisateur == 1)
        {
            //
        }
        else if (choixUtilisateur == 2)
        {
            //
        }
        else if (choixUtilisateur == 3)
        {
            //
        }
        else if (choixUtilisateur == 4)
        {
            //
        }
        else if (choixUtilisateur == 5)
        {
            //
        } 
        else if (choixUtilisateur == 6)
        {
            //
        }
    } while (choixUtilisateur != 0);

    return 0;
}
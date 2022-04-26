#include<stdlib.h>
#include<stdio.h>
#include"afficherTypeDePains.h"
#include"recupererTypeDePain.h"
#include"enregistrerCommande.h"
#include"listerToutesLesCommandes.h"
#include"structures.c"
#include"mettreAJourCommande.h"
#include"listerCommandesEnAttente.h"
#include"listerCommandesLivrees.h"
#include"ajouterTypeDePain.h"

#include"defines.h"

int main()
{

    int choixUtilisateur;

    printf("Bonjour ce programme est la pour vous aider a gerer les activites courantes d'une boulangerie \n");

    do
    {

        printf("\nChoisir un element : \n\n1) lister toutes les commandes \n2) lister les commandes en attente \n3) lister les marchandises livrees \n4) Commander une marchandise \n5) Confirmer une livraison \n6) Ajouter un nouveau type \n0) Appuyer sur 0 pour quitter\n\nR) ");

        char typeDePain[TAILLE_MAX];

        scanf("%i", &choixUtilisateur);

        if (choixUtilisateur == 1)
        {
            listerToutesLesCommandes();
        }
        else if (choixUtilisateur == 2)
        {
            listerCommandesEnAttente();

            printf("Voici toutes les commandes listees ci-haut \n");
        }
        else if (choixUtilisateur == 3)
        {
            listerCommandesLivrees();
        }
        else if (choixUtilisateur == 4)
        {
            int quantite;

            struct Client client;

            printf("Voici les types de pains disponibles : \n");
            afficherTypeDePains();

            printf("Quel type de pain voulez-vous commander ? ");
            scanf("%i", &choixUtilisateur);

            printf("En quelle quantite ? ");
            scanf("%i", &quantite);

            printf("Entrer le sexe du client (0 pour homme 1 pour femme): ");
            scanf("%i", &client.sexe);

            printf("Entrer le nom du client : ");
            scanf("%s", client.nom);

            printf("Entrer le prenom du client : ");
            scanf("%s", client.prenom);

            printf("Entrer le numero de telephone du client : ");
            scanf("%s", client.numeroDeTelephone);

            printf("Entrer la commune du client : ");
            scanf("%s", client.adresse.commune);

            printf("Entrer le quartier du client : ");
            scanf("%s", client.adresse.quartier);

            printf("Entrer l'avenue du client : ");
            scanf("%s", client.adresse.avenue);

            printf("Entrer le numero de l'avenue du client : ");
            scanf("%i", &client.adresse.numero);

            enregistrerCommande(
                choixUtilisateur,
                quantite,
                client.nom,
                client.prenom,
                client.sexe,
                client.numeroDeTelephone,
                client.adresse.commune,
                client.adresse.quartier,
                client.adresse.avenue,
                client.adresse.numero);
            printf("Votre commande a ete enregistree \n");
        }
        else if (choixUtilisateur == 5)
        {
            printf("Entrer le numero de la livraison : ");
            scanf("%i", &choixUtilisateur);

            mettreAJourCommande(choixUtilisateur);

            // printf("Votre commande a ete mise a jour");
        } 
        else if (choixUtilisateur == 6)
        {
            int quantite = 0;
            char typeDePain[TAILLE_MAX];

            printf("Entrer le nom de pain : ");
            scanf("%s", typeDePain);

            printf("Entrer le prix de pain : ");
            scanf("%i", &quantite);

            ajouterTypeDePain(typeDePain, quantite);
        }
    } while (choixUtilisateur != 0);

    return 0;
}
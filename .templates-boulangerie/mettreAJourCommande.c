#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.c"

#include "defines.h"

void mettreAJourCommande(int identifiant)
{

    identifiant--;

    int i = 0, quantite = 0, estCeCommandeLivree = 0;
    long ligneDeCommande = 0;
    char ligneARecuperer[TAILLE_MAX] = "", ligneAEcrire[TAILLE_MAX] = "";
    FILE *fichier = fopen("commandes.txt", "r+");

    if (fichier == NULL)
    {
        printf("erreur : le fichier n'as pas pu etre ouvert");
        // exit(EXIT_FAILURE);
    }
    else
    {

        char typePain[TAILLE_MAX];

        struct Client client;

        struct Commande commande;

        while (fgets(ligneARecuperer, TAILLE_MAX, fichier))
        {
            if (i == identifiant)
            {
                int retourEnArriere = strlen(ligneARecuperer);

                printf("Commande trouvee \n");
                sscanf(ligneARecuperer, "%s %i %i %i %s %s %c %s %s %s %s %i ",
                       commande.nomDuPain,
                       &commande.prixDePain,
                       &commande.nombreDePain,
                       &estCeCommandeLivree,
                       client.nom,
                       client.prenom,
                       &client.sexe,
                       client.numeroDeTelephone,
                       client.adresse.commune,
                       client.adresse.quartier,
                       client.adresse.avenue,
                       &client.adresse.numero);

                if (!estCeCommandeLivree)
                {

                    fseek(fichier, -retourEnArriere - 1, SEEK_CUR);

                    // printf("ligne a ecrire est : %s \n", ligneAEcrire);

                    printf("Monsieur/Madame %s a commande %i %s(s)dont le prix unitaire est %i fc; \nLe prix total est : %i \n",
                           client.nom,
                           commande.nombreDePain,
                           commande.nomDuPain,
                           commande.prixDePain,
                           commande.nombreDePain * commande.prixDePain);

                    fprintf(fichier, "%s %i %i %i %s %s %c %s %s %s %s %i ",
                            commande.nomDuPain,
                            commande.prixDePain,
                            commande.nombreDePain,
                            1,
                            client.nom,
                            client.prenom,
                            client.sexe,
                            client.numeroDeTelephone,
                            client.adresse.commune,
                            client.adresse.quartier,
                            client.adresse.avenue,
                            client.adresse.numero);

                    fseek(fichier, 0, SEEK_CUR);

                    printf("Votre commande a ete mise a jour \n");
                }
                else
                {
                    printf("La commande du client a deja ete livree \nElle ne peut pas etre livree deux fois \n");
                }
            }
            i++;
        }

        fclose(fichier);
    }
}
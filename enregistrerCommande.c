#include<stdio.h>
#include"recupererTypeDePain.h"
#include"structures.c"

#include"defines.h"

void enregistrerCommande(
    int identifiantTypePain, 
    int quantite, 
    char *nom, 
    char *prenom, 
    char sexe, 
    char *numeroDeTelephone, 
    char *commune,
    char *quartier,
    char *avenue,
    int numero

)
{
    FILE *fichier = fopen("commandes.txt", "a");

    char nomPain[TAILLE_MAX];
    int prix = 0;

    char typePain[TAILLE_MAX];
    recupererTypeDePain(identifiantTypePain, typePain);

    sscanf(typePain, "%s %i", nomPain, &prix);

    fprintf(fichier, "%s %i %i %s %s %c %s %s %s %s %i \n", 
        typePain, 
        quantite, 
        0,
        nom,
        prenom,
        sexe == 0 ? 'H' : 'F',
        numeroDeTelephone,
        commune,
        quartier,
        avenue,
        numero
    );

    printf("Le client %s a commande %i %s de prix unitaire %i fc \nLe prix total fait : %i fc \n", 
        nom, 
        quantite, 
        nomPain, 
        prix,
        prix * quantite
    );
    fclose(fichier);
}
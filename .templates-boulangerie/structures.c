#include"defines.h"

struct Adresse
{
    char commune[TAILLE_MAX];
    char quartier[TAILLE_MAX];
    char avenue[TAILLE_MAX];
    int numero;
};

struct Client
{
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    char sexe;
    char numeroDeTelephone[12];
    struct Adresse adresse;
};

struct Commande
{
    char nomDuPain[TAILLE_MAX];
    // int typeDePain;
    int prixDePain;
    int nombreDePain;
    // double prixTotal;
};

// // double getPrixTotal(struct Demande demande) 
// // {
// //     return demande.prixDePain * demande.nombreDePain;
// // }
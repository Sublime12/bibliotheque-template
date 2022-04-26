#include<stdio.h>

void ajouterTypeDePain(char *nouveauTypePain, int prix)
{
    FILE *fichier = fopen("typePain.txt", "a");

    fprintf(fichier, "\n%s %i", nouveauTypePain, prix);

    fclose(fichier);
}
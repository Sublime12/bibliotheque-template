#include<stdlib.h>
#include<stdio.h>
#include "dependencies/mariadb-connector-c-3.2.6-src/include/mysql.h"
#include <mysql/mysql.h>

#include"constantes.h"

void hello();
void printHello();

int main()
{

    MY_SQL *conn;

    conn = mysql_init(conn);
    if (conn == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        exit(1);
    }

    if (!mysql_real_connect(
        conn,                   // Connection
        "localhost",            // Host
        "root",                 // User account
        NULL,                   // User password
        NULL,                   // Default database
        3306,                   // Port number
        NULL,                   // Path to socket file
        0                       // Additional options
    ))
    {
        // Report the failed-connection error & close the handle
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    mysql_query(conn, "CREATE DATABASE dbtest2");

    printHello();

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
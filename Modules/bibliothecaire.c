#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

void create_bibliothecaire(
    char* username,
    char* password,
    char* nom,
    char* postnom,
    char* sexe
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "INSERT INTO bibliothecaire (username, password, nom, postnom, sexe) VALUES (\"%s\", SHA2(\"%s\", 256), \"%s\", \"%s\", \"%s\")",
        username,
        password,
        nom,
        postnom,
        sexe
    );

    query_library(query);
}

void update_bibliothecaire(
    int id_to_update,
    char* username,
    char* password,
    char* nom,
    char* postnom,
    char* sexe
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "UPDATE bibliothecaire SET username = \"%s\", password = SHA2(\"%s\", 256), nom = \"%s\", postnom = \"%s\", sexe = \"%s\" WHERE id = %i",
        username,
        password,
        nom,
        postnom,
        sexe,
        id_to_update
    );

    query_library(query);
}

void delete_bibliothecaire(int id)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "DELETE FROM bibliothecaire WHERE id = %i",
        id
    );

    query_library(query);
}

void select_bibliothecaires()
{
    print_select_query(
        "SELECT id, username, nom, postnom, sexe, password FROM  bibliothecaire",
        "id\tusername\tnom\tpostnom\tsexe\tmot-de-passe\n\n"
    );
}

void select_bibliothecaire(int id)
{
    print_select_query_one_row("bibliothecaire", id);
}
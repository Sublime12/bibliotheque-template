#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

void create_membre(
    int bibliothecaire_id,
    char* nom,
    char* postnom,
    char* sexe
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "INSERT INTO membre (bibliothecaire_id, nom, postnom, sexe) VALUES (%i, \"%s\", \"%s\", \"%s\")",
        bibliothecaire_id,
        nom,
        postnom,
        sexe
    );

    // printf("La requete de creation est : %s", query);
    query_library(query);
}

void update_membre(
    int id_to_update,
    int bibliotheque_id,
    char* nom,
    char* postnom,
    char* sexe
)
{
    // MYSQL* conn = connection();

    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "UPDATE membre SET bibliothecaire_id = %i, nom = \"%s\", postnom = \"%s\", sexe = \"%s\" WHERE id = %i",
        bibliotheque_id,
        nom,
        postnom,
        sexe,
        id_to_update
    );

    query_library(query);

    // if (mysql_query(conn, query)) {
    //     show_mysql_error(conn);
    // }

    // mysql_close(conn);
}

void delete_membre(int membre_id)
{
    char query[TAILLE_QUERY];

    sprintf(
        query,
        "DELETE FROM membre where id = %i",
        membre_id

    );

    query_library(query);
}

void select_membres()
{
    print_select_query(
        "SELECT * FROM membre", // query
        "id\tbibliotheque_id\tnom\tpostnom\tsexe\n\n" // label
    );
}

void select_membre(int id)
{
    print_select_query_one_row("membre", id);
}
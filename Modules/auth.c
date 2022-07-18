#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

int isCredentialsCorrect(
    char* username, 
    char* password
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "SELECT * FROM bibliothecaire WHERE username = \"%s\" AND password = SHA2(\"%s\", 256)",
        username,
        password
    );

    MYSQL* conn = query_library(query);

    MYSQL_RES* result = mysql_store_result(conn);

    return mysql_fetch_row(result) == NULL ? 0 : 1;
}

update_credentials(
    int id_to_update,
    char *username,
    char *password,
    char *nom,
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
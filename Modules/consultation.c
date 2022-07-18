#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

void create_consultation(
    int membre_id,
    int document_id,
    char* matricule
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "INSERT INTO consultation (membre_id, document_id,matricule, date_emprunt) VALUES (%i, %i,\"%s\", NOW())",
        membre_id,
        document_id,
        matricule
    );

    query_library(query);
}

void update_consultation(
    int id_to_update,
    int membre_id,
    int  document_id,
    char* matricule
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "UPDATE consultation SET membre_id = %i, document_id = %i, matricule = \"%s\" WHERE id = %i",
        membre_id,
        document_id,
        matricule,
        id_to_update
    );

    query_library(query);
}

void select_consultations()
{
    print_select_query(
        "SELECT id, membre_id, document_id, matricule,date_emprunt FROM consultation",
        "id\tmembre_id\tdocument_id\tmatricule\tdate_emprunt\n\n"
    );
}

void select_consultation(int id)
{
    print_select_query_one_row("consultation", id);
}

void delete_consultation(int id)
{
    char query[TAILLE_QUERY] = "";
    sprintf(
        query,
        "DELETE FROM consultation WHERE id = %i",
        id
    );

    query_library(query);
}
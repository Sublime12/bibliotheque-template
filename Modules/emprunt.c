#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

void create_emprunt(
    int membre_id,
    int  document_id,
    char* matricule
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "INSERT INTO emprunt (membre_id, document_id,matricule, date_emprunt) VALUES (%i, %i,\"%s\", NOW())",
        membre_id,
        document_id,
        matricule
    );

    query_library(query);
}

void update_emprunt(
    int id_to_update,
    int membre_id,
    int  document_id,
    char* matricule,
    int isRestituted
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "UPDATE emprunt SET membre_id = %i, document_id = %i, matricule = \"%s\"%s WHERE id = %i",
        membre_id,
        document_id,
        matricule,
        isRestituted == 0 ? "" : " ,date_restitution = NOW()",
        id_to_update
    );

    query_library(query);
}

void select_emprunts()
{
    print_select_query(
        "SELECT id, membre_id, document_id, matricule,date_emprunt, date_restitution FROM emprunt",
        "id\tmembre_id\tdocument_id\tmatricule\tdate_emprunt\tdate_restitution\n\n"
    );
}

void select_emprunt(int id)
{
    print_select_query_one_row("emprunt", id);
}

void delete_emprunt(int id)
{
    char query[TAILLE_QUERY] = "";
    sprintf(
        query,
        "DELETE FROM emprunt WHERE id = %i",
        id
    );

    query_library(query);
}
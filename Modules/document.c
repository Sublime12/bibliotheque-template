#include <mysql/mysql.h>
#include "../Headers/Modules/Database/connection.h"
#include "../constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_document(
    int membre_id,
    int categorie_id,
    char* titre,
    char* libelle,
    char* description,
    char* auteur,
    char* domaine,
    int tiroir_id
) 
{

    MYSQL* conn = connection();
    char query[TAILLE_QUERY] = "";

    sprintf(
        query, 
        "INSERT INTO document (membre_id, categorie_id, libelle, titre, description, auteur, domaine) VALUES (%i, %i, '%s', '%s', '%s', '%s', '%s')",
        membre_id,
        categorie_id,
        libelle,
        titre,
        description,
        auteur,
        domaine
    );

    // printf("Your sql query for document table is : '%s' \n", query);

    if (mysql_query(conn, query)) {
        show_mysql_error(conn);
    }

    mysql_close(conn);
}

void update_document(
    int id_to_update,
    int membre_id,
    int categorie_id,
    char* titre,
    char* libelle,
    char* description,
    char* auteur,
    char* domaine,
    int tiroir_id
)
{
    MYSQL* conn = connection();

    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "UPDATE document SET membre_id = %i, categorie_id = %i, titre = '%s', libelle = '%s', description = '%s', auteur = '%s', domaine = '%s' WHERE id = %i",
        membre_id,
        categorie_id,
        titre,
        libelle,
        description,
        auteur,
        domaine,
        id_to_update
    );

    // printf("Your update query is : '%s' \n", query);

    if (mysql_query(conn, query)) {
        show_mysql_error(conn);
    } 

    mysql_close(conn);
}

void delete_document(int id)
{
    MYSQL* conn = connection();
    char query[TAILLE_QUERY] = "";
    sprintf(query, "DELETE FROM document WHERE id  = %d", id);

    if (mysql_query(conn, query))
    {
        show_mysql_error(conn);
    }

    printf("Your document was deleted");
}

void select_documents()
{
    MYSQL* conn = connection();

    if (mysql_query(conn, "SELECT id, titre, libelle, auteur, domaine FROM document")) {
        show_mysql_error(conn);
    }

    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row;

    int count = mysql_num_fields(result);
    int i = 0;

    printf("id\ttitre\tlibelle\tauteur\tdomaine\n\n");
    while (row =  mysql_fetch_row(result)) {
        for (i = 0; i < count; i++) {
            printf("[%s]\t", row[i]);
        }
        printf("\n\n");
    }

    mysql_free_result(result);

    mysql_close(conn);
}

void select_document(int id)
{
    MYSQL* conn = connection();
    char query[TAILLE_QUERY] = "";

    sprintf(query, "SELECT * FROM document where id = %i", id);

    if (mysql_query(conn, query)) {
        show_mysql_error(conn);
    }

    MYSQL_RES* result = mysql_store_result(conn);
    int count = mysql_num_fields(result);
    MYSQL_FIELD* field;
    MYSQL_ROW row;
    int i = 0;

    while (row = mysql_fetch_row(result)) {
        for (i = 0; i < count; i++) {
            field = mysql_fetch_field(result);
        
            printf("[%s]\n", field->name);
            printf("%s\n\n", row[i]);
        }
    }
    mysql_free_result(result);

    mysql_close(conn);
}
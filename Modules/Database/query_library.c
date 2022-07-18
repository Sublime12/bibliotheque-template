#include <mysql/mysql.h>
#include <stdio.h>

#include "../../constantes.h"

#include "../../Headers/Modules/Database/query_library.h"
#include "../../Headers/Modules/Database/connection.h"

MYSQL* query_library(char* query)
{
    MYSQL* conn = connection();

    if (mysql_query(conn, query)) {
        show_mysql_error(conn);
    }

    // mysql_close(conn);

    return conn;
}

void print_select_query(
    char* query,
    char* label
)
{
    MYSQL* conn = connection();

    if (mysql_query(conn, query)) {
        show_mysql_error(conn);
    }

    MYSQL_RES* result = mysql_store_result(conn);
    MYSQL_ROW row;

    int count = mysql_num_fields(result);
    int i = 0;

    printf(label);
    while (row =  mysql_fetch_row(result)) {
        for (i = 0; i < count; i++) {
            printf("[%s]\t", row[i]);
        }
        printf("\n\n");
    }

    mysql_free_result(result);

    mysql_close(conn);

}

void print_select_query_one_row(
    char* table,
    int id
)
{
    MYSQL* conn = connection();
    char query[TAILLE_QUERY] = "";

    sprintf(
        query, 
        "SELECT * FROM %s where id = %i", 
        table, 
        id
    );

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
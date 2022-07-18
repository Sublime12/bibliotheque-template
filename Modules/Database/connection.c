#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>


void show_mysql_error(MYSQL* connection)
{
    printf(
        "Error(%d) [%s] \"%s\"", 
        mysql_errno(connection),
        mysql_sqlstate(connection),
        mysql_error(connection)
    );

    // exit(EXIT_FAILURE);
}

void show_stmt_error(MYSQL_STMT* statement)
{
    printf(
        "Statement error(%d) [%s] \"%s\"", 
        mysql_stmt_errno(statement),
        mysql_stmt_sqlstate(statement),
        mysql_stmt_error(statement)
    );

    // exit(EXIT_FAILURE);
}

MYSQL *connection()
{

    MYSQL *conn;

    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "unable to initialize connection struct\n");
        exit(1);
    }

    if (!mysql_real_connect(
        conn,        // Connection
        "localhost", // Host
        "root",      // User account
        NULL,        // User password
        "library",        // Default database
        3306,        // Port number
        NULL,        // Path to socket file
        0            // Additional options
        ))
    {
        // Report the failed-connection error & close the handle
        printf("Le service mysql est arrete \nLancement de la commande : systemctl start mariadb.service\nVeuiller entrer votre mot de passe linux : \n");
        system("systemctl start mariadb.service");
        mysql_real_connect(
        conn,        // Connection
        "localhost", // Host
        "root",      // User account
        NULL,        // User password
        "library",        // Default database
        3306,        // Port number
        NULL,        // Path to socket file
        0            // Additional options
        );
        // fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        // mysql_close(conn);
        // exit(1);
    }

    return conn;
}

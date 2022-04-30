#include <mysql/mysql.h>

MYSQL *connection()
{

    MYSQL *conn;

    conn = mysql_init(conn);
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
        NULL,        // Default database
        3306,        // Port number
        NULL,        // Path to socket file
        0            // Additional options
        ))
    {
        // Report the failed-connection error & close the handle
        fprintf(stderr, "Error connecting to Server: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    return conn;
}
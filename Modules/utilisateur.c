#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include "../constantes.h"

char* get_user()
{
    return getenv("USER");
}

char* get_groups_for_current_user(char* list_of_groups)
{
    int ngroups;
    struct passwd *pw;
    struct group *gr;

    ngroups = 3;

    gid_t *groups = malloc(sizeof(*groups) * ngroups);

    if (groups == NULL) {
        perror("failure on call on malloc");
        exit(EXIT_FAILURE);
    }

    /** Fetch passwd structure (contains first group ID for user) */

    pw = getpwnam(get_user());
    if (pw == NULL) {
        perror("Failure on call to getpwnam");
        exit(EXIT_FAILURE);
    }

    /** retrieve group list */

    if (getgrouplist(get_user(), pw->pw_gid, groups, &ngroups)) {
        // fprintf(stderr, "getgrouplist()) returned -1; ngroups = %d\n", ngroups);
        // exit(EXIT_SUCCESS);
    }

    char groups_id[TAILLE_CHAINE]= "";
    char groups_id_copy[TAILLE_CHAINE]= "";
    int j = 0;
    for (j = 0; j < ngroups; j++) {
        sprintf(
            groups_id,
            "%s %d",
            groups_id_copy,
            groups[j]
        );
        memset(groups_id_copy, 0, sizeof(char) * TAILLE_CHAINE - 1);

        strcpy(groups_id_copy, groups_id);
    }


    strcpy(list_of_groups, groups_id);
 
    free(groups);
    return list_of_groups;
}

void create_utilisateur(
    char* groups_id,
    char* linux_user,
    int processus_id,
    int parent_processus_id
)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "INSERT INTO utilisateur (groups_id, linux_user, processus_id, parent_processus_id) VALUES(\"%s\", \"%s\", %i, %i)",
        groups_id,
        linux_user,
        processus_id,
        parent_processus_id
    );

    query_library(query);
}

void select_utilisateurs()
{
    print_select_query(
        "SELECT * FROM utilisateur",
        "id\tgroups_id\tuser\tprocessus\tparent_processus\n\n"
    );
}

void delete_utilisateur(int id)
{
    char query[TAILLE_QUERY] = "";

    sprintf(
        query,
        "DELETE FROM utilisateur WHERE id = %i",
        id
    );

    query_library(query);
}
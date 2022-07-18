char* get_user();

char* get_groups_for_current_user();

void create_utilisateur(
    char* groups_id,
    char* linux_user,
    int processus_id,
    int parent_processus_id
);

void select_utilisateurs();

void delete_utilisateur(int id);
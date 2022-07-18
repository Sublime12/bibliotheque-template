void create_bibliothecaire(
    char* username,
    char* password,
    char* nom,
    char* postnom,
    char* sexe
);

void update_bibliothecaire(
    int id_to_update,
    char* username,
    char* password,
    char* nom,
    char* postnom,
    char* sexe
);

void delete_bibliothecaire(int id);

void select_bibliothecaires();

void select_bibliothecaire(int id);
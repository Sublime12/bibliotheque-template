void create_membre(
    int bibliotheque_id,
    char* nom,
    char* postnom,
    char* sexe
);

void update_membre(
    int id_to_update,
    int bibliotheque_id,
    char* nom,
    char* postnom,
    char* sexe
);

void delete_membre(int membre_id);

void select_membres();

void select_membre(int id);
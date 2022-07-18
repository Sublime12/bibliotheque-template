void create_emprunt(
    int membre_id,
    int  document_id,
    char* matricule
);

void update_emprunt(
    int id_to_update,
    int membre_id,
    int  document_id,
    char* matricule,
    int isRestituted
);

void select_emprunts();

void select_emprunt(int id);

void delete_emprunt(int id);
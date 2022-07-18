void create_consultation(
    int membre_id,
    int document_id,
    char* matricule
);

void update_consultation(
    int id_to_update,
    int membre_id,
    int  document_id,
    char* matricule
);

void select_consultations();

void select_consultation(int id);

void delete_consultation(int id);
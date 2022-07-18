void create_document(
    int membre_id,
    int categorie_id,
    char* titre,
    char* libelle,
    char* description,
    char* auteur,
    char* domaine,
    int tiroir_id
);

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
);
void delete_document(int id);

void select_documents();

void select_document(int id);
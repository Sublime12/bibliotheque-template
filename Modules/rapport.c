#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>

#include "../Headers/Modules/Database/connection.h"
#include "../Headers/Modules/Database/query_library.h"

#include "../constantes.h"

void print_lists_empruntes()
{
    print_select_query(
        "SELECT consultation.id, consultation.matricule, document.titre  FROM consultation  INNER JOIN document ON consultation.document_id = document.id ORDER BY document.titre;",
        "id\tmatricule\tdocument_titre\n\n"
    );
}

void print_membres_en_ordre_alphabetique()
{
    print_select_query(
        "SELECT * FROM membre ORDER BY nom",
        "id\tbiblio_id\tnom\tpostnom\tsexe\n\n"
    );
}

void print_documents_a_remettre()
{
    print_select_query(
        "SELECT * FROM emprunt WHERE date_restitution is NULL",
        "id\tmembre_id\tmatricule\tdate_emprunt\tdate_restitution\tdocument_id\n\n"
    );
}

void print_dernier_document_consulte()
{
    print_select_query(
        "select consultation.*, document.titre as document_titre from consultation  inner join document on consultation.document_id = document.id order by consultation.id desc limit 0, 1;",
        "id\tmem_id\tdoc_id\tmatri\tdate_empr\tdate_res\ttitre_doc\n\n"
    );
}

void print_tiroir_with_most_books()
{
    print_select_query(
        "SELECT tiroir_id, COUNT(tiroir_id) as count_tiroir FROM document GROUP BY tiroir_id ORDER BY count_tiroir DESC LIMIT 0, 1",
        "Voici le tiroir qui a le plus de documents \n\n"
    );
}

void print_document_with_SE()
{
    print_select_query(
        "SELECT * FROM document WHERE domaine = 'systeme-d-exploitation'",
        "La liste des documents avec systeme-d-exploitation \n\n"
    );
}
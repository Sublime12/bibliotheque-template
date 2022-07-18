
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <mysql/mysql.h>
#include <unistd.h>

#include "Headers/Modules/Database/connection.h"
#include "Headers/Modules/Database/query_library.h"
#include "Headers/Modules/document.h"
#include "Headers/Modules/membre.h"
#include "Headers/Modules/auth.h"
#include "Headers/Modules/rapport.h"
#include "Headers/Modules/consultation.h"
#include "Headers/Modules/emprunt.h"
#include "Headers/Modules/utilisateur.h"
#include "Headers/Modules/bibliothecaire.h"


#include"constantes.h"

int main()
{


    // system("systemctl start mariadb.service");

    /** faisons la connection a ce niveau */
    int i = 0;
    char username[TAILLE_CHAINE] = "";
    char password[TAILLE_CHAINE] = "";
    char list_of_groups[TAILLE_CHAINE] = "";

    printf("Processus courant : %i\nProcessus pere : %i\n\n", getpid(), getppid());
    printf("User connecte : %s\n", get_user());
    printf("User appartient aux groups : %s \n\n", get_groups_for_current_user(list_of_groups));

    create_utilisateur(
        get_groups_for_current_user(list_of_groups),
        get_user(),
        getpid(),
        getppid()
    );

    for (i = 0; !isCredentialsCorrect(username, password); i++) 
    {
        if (i > 0)
        {
            printf("Mot de passe incorrect \n");
        }

        printf("Username : ");
        scanf("%s", &username);

        printf("mot de passe : ");
        scanf("%s", &password);

        if (i >= 2) 
        {
            printf("Trois tentatives incorrects de mot de passe \n\n");
            exit(EXIT_FAILURE);
        }
    }
    int choixUtilisateur;

    printf("Bonjour ce programme est la pour vous aider a gerer les activites courantes d'une bibliotheque \n");

    do
    {

        printf("\nChoisir un element concernant la gestion globale du programme : \n\n1) documents \n2) membres \n3) consultations \n4) emprunts \n5) rapports \n6) utilisateurs \n7) bibliothecaires \n0) Appuyer sur 0 pour quitter le programme\n\nR) ");

        scanf("%i", &choixUtilisateur);

        if (choixUtilisateur == 1) // documents
        {
            int choixUtilisateur;
            do
            {
                printf("\nChoisir un element parmis les suivants concernant la gestion des documents: \n\n1) ajouter un document \n2) modifier un document \n3) voir tous les documents \n4) voir un document en particulier \n5) supprimer un document \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    printf("Veuiller fournir les informations pour ajouter un nouveau document\n\n");

                    int membre_id = 0;
                    int categorie_id = 0;
                    int tiroir_id = 0;

                    char titre[TAILLE_CHAINE] = "";
                    char libelle[TAILLE_CHAINE] = "";
                    char description[TAILLE_CHAINE] = "";
                    char auteur[TAILLE_CHAINE] = "";
                    char domaine[TAILLE_CHAINE] = "";

                    printf("Entrer le titre du document : ");
                    scanf("%s", titre);

                    printf("Entrer le libelle du document : ");
                    scanf("%s", libelle);

                    printf("Entrer la description du document : ");
                    scanf("%s", description);

                    printf("Entrer l'auteur du document : ");
                    scanf("%s", auteur);

                    printf("Entrer le domaine du document : ");
                    scanf("%s", domaine);

                    printf("Entrer l'id du membre possedant le document : ");
                    scanf("%i", &membre_id);

                    printf("Entrer l'id de la categorie au quel appartient le document : ");
                    scanf("%i", &categorie_id);

                    printf("Entrer l'id du tiroir au quel vous voulez qu'on place le document : ");
                    scanf("%i", &tiroir_id);

                    create_document(
                        membre_id,
                        categorie_id,
                        titre,
                        libelle,
                        description,
                        auteur,
                        domaine,
                        tiroir_id
                    );
                }
                else if (choixUtilisateur == 2) // modifier le document
                {
                    printf("Veuiller fournir les informations pour modifier le document\n\n");

                    int membre_id = 0;
                    int categorie_id = 0;

                    int document_id = 0;

                    char titre[TAILLE_CHAINE] = "";
                    char libelle[TAILLE_CHAINE] = "";
                    char description[TAILLE_CHAINE] = "";
                    char auteur[TAILLE_CHAINE] = "";
                    char domaine[TAILLE_CHAINE] = "";

                    printf("Entrer l'id du document a modifier : ");
                    scanf("%i", &document_id);

                    printf("Entrer le titre du document : ");
                    scanf("%s", titre);

                    printf("Entrer le libelle du document : ");
                    scanf("%s", libelle);

                    printf("Entrer la description du document : ");
                    scanf("%s", description);

                    printf("Entrer l'auteur du document : ");
                    scanf("%s", auteur);

                    printf("Entrer le domaine du document : ");
                    scanf("%s", domaine);

                    printf("Entrer l'id du membre possedant le document : ");
                    scanf("%i", &membre_id);

                    printf("Entrer l'id de la categorie au quel appartient le document : ");
                    scanf("%i", &categorie_id);

                    update_document(
                        document_id,
                        membre_id,
                        categorie_id,
                        titre,
                        libelle,
                        description,
                        auteur,
                        domaine,
                        1
                    );

                }
                else if (choixUtilisateur == 3)
                {
                    select_documents();
                }
                else if (choixUtilisateur == 4)
                {
                    int document_id = 0;
                    printf("Entrer l'id du document : ");
                    scanf("%d", &document_id);

                    select_document(document_id);
                }
                else if (choixUtilisateur == 5) // supprimer un document
                {
                    int document_id = 0;

                    printf("Entrer l'id du document que vous voulez supprimer\nN.B : Le document supprime le sera pour toujours\n\nR) ");

                    scanf("%i", &document_id);

                    delete_document(document_id);
                }
            } while (choixUtilisateur != 0);

        }
        else if (choixUtilisateur == 2) // membres
        {
            int choixUtilisateur;
            do
            {
                printf("\nChoisir un element parmis les suivants concernant la gestion des membres: \n\n1) ajouter un membre \n2) modifier un membre \n3) voir tous les membres \n4) voir un membre en particulier \n5) supprimer un membre \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    printf("Veuiller fournir les informations pour ajouter un nouveau membre\n\n");

                    int bibliothecaire_id = 0;

                    char nom[TAILLE_CHAINE] = "";
                    char postnom[TAILLE_CHAINE] = "";
                    int sexe = 0;

                    printf("Entrer le nom du membre : ");
                    scanf("%s", nom);

                    printf("Entrer le postnom du membre : ");
                    scanf("%s", postnom);

                    printf("Entrer le sexe du membre (0 pour homme le reste pour femme): ");
                    scanf("%i", &sexe);

                    printf("Entrer l'id du bibliothecaire : ");
                    scanf("%i", &bibliothecaire_id);

                    create_membre(
                        bibliothecaire_id,
                        nom,
                        postnom,
                        sexe == 0 ? "H" : "F"
                    );
                }
                else if (choixUtilisateur == 2) // modifier le membre
                {
                    printf("Veuiller fournir les informations pour ajouter un nouveau membre\n\n");

                    int bibliothecaire_id = 0;
                    int id_to_update = 0;

                    char nom[TAILLE_CHAINE] = "";
                    char postnom[TAILLE_CHAINE] = "";
                    int sexe = 0;

                    printf("Entrer l'id du membre a modifier : ");
                    scanf("%i", &id_to_update);

                    printf("Entrer le nom du membre : ");
                    scanf("%s", nom);

                    printf("Entrer le postnom du membre : ");
                    scanf("%s", postnom);

                    printf("Entrer le sexe du membre (0 pour homme le reste pour femme): ");
                    scanf("%i", &sexe);

                    printf("Entrer l'id du bibliothecaire : ");
                    scanf("%i", &bibliothecaire_id);

                    update_membre(
                        id_to_update,
                        bibliothecaire_id,
                        nom,
                        postnom,
                        sexe == 0 ? "H" : "F"
                    );
                }
                else if (choixUtilisateur == 3)
                {
                    select_membres();
                }
                else if (choixUtilisateur == 4)
                {
                    int membre_id = 0;
                    printf("Entrer l'id du membre : ");
                    scanf("%d", &membre_id);

                    select_membre(membre_id);
                }
                else if (choixUtilisateur == 5) // supprimer un document
                {
                    int membre_id = 0;

                    printf("Entrer l'id du membre que vous voulez supprimer\nN.B : Le membre supprime le sera pour toujours\n\nR) ");

                    scanf("%i", &membre_id);

                    delete_membre(membre_id);
                }
            } while (choixUtilisateur != 0);

        }
        else if (choixUtilisateur == 3) // consultations
        {
            int choixUtilisateur;
            do
            {
                printf("\nChoisir un element parmis les suivants concernant la gestion des consultations des documents : \n\n1) ajouter une consultation \n2) modifier une consultation \n3) voir toutes les consultations \n4) voir une consultation en particulier \n5) supprimer une consultation \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    printf("Veuiller fournir les informations pour ajouter une nouvelle consultation\n\n");

                    int membre_id = 0;
                    int document_id = 0;

                    char matricule[TAILLE_CHAINE] = "";

                    printf("Entrer l'id du membre qui veut consulter le document: ");
                    scanf("%i", &membre_id);

                    printf("Entrer le matricule du document a consulter : ");
                    scanf("%s", matricule);

                    printf("Entrer l'id du document a consulter : ");
                    scanf("%i", &document_id);

                    create_consultation(
                        membre_id,
                        document_id,
                        matricule
                    );
                }
                else if (choixUtilisateur == 2) // modifier une consultation
                {
                    printf("Veuiller fournir les informations pour modifier un nouveau emprunt\n\n");

                    int membre_id = 0;
                    int document_id = 0;
                    int consultation_id = 0;

                    char matricule[TAILLE_CHAINE] = "";

                    printf("Entrer l'id de la consultation : ");
                    scanf("%i", &consultation_id);

                    printf("Entrer l'id du membre qui veut consulter le document: ");
                    scanf("%i", &membre_id);

                    printf("Entrer le matricule du document a consulter : ");
                    scanf("%s", matricule);

                    printf("Entrer l'id du document a consulter : ");
                    scanf("%i", &document_id);

                    update_consultation(
                        consultation_id,
                        membre_id,
                        document_id,
                        matricule
                    );

                }
                else if (choixUtilisateur == 3) // selectionner tous les consultations
                {
                    select_consultations();
                }
                else if (choixUtilisateur == 4)
                {
                    int consultation_id = 0;
                    printf("Entrer l'id de la consultation : ");
                    scanf("%d", &consultation_id);

                    select_consultation(consultation_id);
                }
                else if (choixUtilisateur == 5) // supprimer une consultation
                {
                    int consultation_id = 0;

                    printf("Entrer l'id de la consultation que vous voulez supprimer\nN.B : L'emprunt supprime le sera pour toujours\n\nR) ");

                    scanf("%i", &consultation_id);

                    delete_consultation(consultation_id);
                }
            } while (choixUtilisateur != 0);
        }
        else if (choixUtilisateur == 4) // emprunts
        {
            int choixUtilisateur;
            do
            {
                printf("\nChoisir un element parmis les suivants concernant la gestion des emprunts: \n\n1) ajouter un emprunt \n2) modifier un emprunt \n3) voir tous les enprunts \n4) voir un enprunt en particulier \n5) supprimer un emprunt \n6) Confirmer la remise du document \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    printf("Veuiller fournir les informations pour ajouter un nouveau emprunt\n\n");

                    int membre_id = 0;
                    int document_id = 0;

                    char matricule[TAILLE_CHAINE] = "";

                    printf("Entrer l'id du membre qui veut emprunter le document: ");
                    scanf("%i", &membre_id);

                    printf("Entrer le matricule du document a emprunter : ");
                    scanf("%s", matricule);

                    printf("Entrer l'id du document a emprunter : ");
                    scanf("%i", &document_id);

                    create_emprunt(
                        membre_id,
                        document_id,
                        matricule
                    );
                }
                else if (choixUtilisateur == 2) // modifier le enprunt
                {
                    printf("Veuiller fournir les informations pour modifier un nouveau emprunt\n\n");

                    int membre_id = 0;
                    int document_id = 0;
                    int emprunt_id = 0;

                    char matricule[TAILLE_CHAINE] = "";

                    printf("Entrer l'id de l'emprunt : ");
                    scanf("%i", &emprunt_id);

                    printf("Entrer l'id du membre qui veut emprunter le document: ");
                    scanf("%i", &membre_id);

                    printf("Entrer le matricule du document a emprunter : ");
                    scanf("%s", matricule);

                    printf("Entrer l'id du document a emprunter : ");
                    scanf("%i", &document_id);

                    update_emprunt(
                        emprunt_id,
                        membre_id,
                        document_id,
                        matricule,
                        0
                    );

                }
                else if (choixUtilisateur == 3) // selectionner tous les emprunts
                {
                    select_emprunts();
                }
                else if (choixUtilisateur == 4)
                {
                    int emprunt_id = 0;
                    printf("Entrer l'id de l'emprunt : ");
                    scanf("%d", &emprunt_id);

                    select_emprunt(emprunt_id);
                }
                else if (choixUtilisateur == 5) // supprimer un emprunts
                {
                    int membre_id = 0;

                    printf("Entrer l'id de l'emprunt que vous voulez supprimer\nN.B : L'emprunt supprime le sera pour toujours\n\nR) ");

                    scanf("%i", &membre_id);

                    delete_membre(membre_id);
                }
                else if (choixUtilisateur == 6) // remise emprunt document
                {
                    printf("Veuiller fournir les informations pour identifiier la remise d'un document\n\n");

                    int membre_id = 0;
                    int document_id = 0;
                    int emprunt_id = 0;

                    char matricule[TAILLE_CHAINE] = "";

                    printf("Entrer l'id de l'emprunt : ");
                    scanf("%i", &emprunt_id);

                    printf("Entrer l'id du membre qui a emprunte le document: ");
                    scanf("%i", &membre_id);

                    printf("Entrer le matricule du document qui a ete emprunte : ");
                    scanf("%s", matricule);

                    printf("Entrer l'id du document qui a ete emprunte : ");
                    scanf("%i", &document_id);

                    update_emprunt(
                        emprunt_id,
                        membre_id,
                        document_id,
                        matricule,
                        1
                    );

                }
            } while (choixUtilisateur != 0);

        }
        else if (choixUtilisateur == 5) // rapports
        {
            int choixUtilisateur;

            do
            {
                printf("\nChoisir un element parmis les suivants concernant les rapports : \n\n1) lister les livres empruntes en ordre alphabetique \n2) lister les membres en ordre alphabetique \n3) lister les livres a restituer \n4) l'id du tiroir qui a le plus de livres \n5) dernier livre consulte \n6) livre qui a comme domaine 'system-d-exploitation' \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    print_lists_empruntes();
                } 
                else if (choixUtilisateur == 2)
                {
                    print_membres_en_ordre_alphabetique();
                } 
                else if (choixUtilisateur == 3)
                {
                    print_documents_a_remettre();
                } 
                else if (choixUtilisateur == 4)
                {
                    // printf("Fonctionnalite pas encore etablie");

                    print_tiroir_with_most_books();
                } 
                else if (choixUtilisateur == 5)
                {
                    print_dernier_document_consulte();
                }
                else if (choixUtilisateur == 6)
                {
                    print_document_with_SE();
                }
            }while (choixUtilisateur != 0);
        } 
        else if (choixUtilisateur == 6) // utilisateurs
        {
            int choixUtilisateur;

            do
            {
                printf("\nChoisir un element parmis les suivants concernant les utilisateurs : \n\n1) voir les utilisateurs \n2) supprimer un utilisateur \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%d", &choixUtilisateur);
                if (choixUtilisateur == 1)
                {
                    select_utilisateurs();
                }
                else if (choixUtilisateur == 2)
                {   
                    int processus_id_to_delete = 0;

                    printf("Entrer l'id du processus a supprimer : ");
                    scanf("%i", &processus_id_to_delete);
                
                    delete_utilisateur(processus_id_to_delete);
                }

            }while (choixUtilisateur != 0);
        }
        else if (choixUtilisateur == 7) // biblioothecaires
        {
            int choixUtilisateur;

            do
            {

                printf("Bienvenu(e) dans la partie d'administration\nLes bibliothecaires que vous ajoutez ici peuvent acceder a votre appplication Veuiller faire attention a ce que vous ecrivez!!!!\nChoisir parmis les options suivantes : \n\n1) ajouter un bibliothecaire \n2) modifier un bibliothecaire \n3) voir tous les bibliothecaires \n4) voir un bibliothecaire en particulier \n5) supprimer un bibliothecaire \n0) Appuyer sur 0 pour quitter\n\nR) ");
            
                scanf("%i", &choixUtilisateur);

                if (choixUtilisateur == 1)
                {
                    char username[TAILLE_CHAINE] = "";
                    char password[TAILLE_CHAINE] = "";
                    char nom[TAILLE_CHAINE] = "";
                    char postnom[TAILLE_CHAINE] = "";
                    int sexe = 0;

                    printf("Veuiller entrer les informations pour ajouter un nouveau bibliothecaire\n");

                    printf("Entrer le nom d'utilisateur(username) : ");
                    scanf("%s", username);

                    printf("Entrer le mot de passe : ");
                    scanf("%s", password);

                    printf("Entrer votre  nom : ");
                    scanf("%s", nom);

                    printf("Entrer le postnom : ");
                    scanf("%s", postnom);

                    printf("Entrer votre sexe(0 pour homme le reste pour femme) : ");
                    scanf("%s", &sexe);
                    
                    create_bibliothecaire(
                        username,
                        password,
                        nom,
                        postnom,
                        sexe == 0 ? "F" : "H"
                    );
                }
                else if (choixUtilisateur == 2)
                {
                    int bibliothecaire_id = 0;
                    char username[TAILLE_CHAINE] = "";
                    char password[TAILLE_CHAINE] = "";
                    char nom[TAILLE_CHAINE] = "";
                    char postnom[TAILLE_CHAINE] = "";
                    int sexe = 0;

                    printf("Veuiller entrer les informations pour modifier un bibliothecaire\n");

                    printf("Entrer l'id du bibliothecaire a modifier : ");
                    scanf("%i", &bibliothecaire_id);

                    printf("Entrer le nom d'utilisateur(username) : ");
                    scanf("%s", username);

                    printf("Entrer le mot de passe : ");
                    scanf("%s", password);

                    printf("Entrer votre  nom : ");
                    scanf("%s", nom);

                    printf("Entrer le postnom : ");
                    scanf("%s", postnom);

                    printf("Entrer votre sexe(0 pour homme le reste pour femme) : ");
                    scanf("%i", &sexe);
                    
                    update_bibliothecaire(
                        bibliothecaire_id,
                        username,
                        password,
                        nom,
                        postnom,
                        sexe == 0 ? "F" : "H"
                    );
                } 
                else if (choixUtilisateur == 3)
                {
                    select_bibliothecaires();
                }
                else if (choixUtilisateur == 4)
                {
                    int bibliothecaire_id = 0;

                    printf("Entrer l'id du bibliothecaire a afficher : ");
                    scanf("%i", &bibliothecaire_id);

                    select_bibliothecaire(bibliothecaire_id);
                }
                else if (choixUtilisateur == 5)
                {
                    int id_to_delete = 0;

                    printf("Attention !!!Le bibliothecaire suprimmee le sera pour toujours\n");

                    printf("Entrer l'id du bibliothecaire a modifier : ");
                    scanf("%i", &id_to_delete);

                    delete_bibliothecaire(id_to_delete);
                }
            }while(choixUtilisateur != 0);
        }
    } while (choixUtilisateur != 0);

    return 0;
}
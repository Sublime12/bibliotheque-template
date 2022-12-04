Pour compiler et executer vous devez etre sur Centos 8 et installer les librairies de mysql pour C.
En plus vous devez creer une base de données qui correspond au ficher `Dump Copy.sql`


Ce programme permet de gerer une bibliotheque en console 
Dans les modules il y a plusieurs fichiers sous modules correspondant a leurs responsabilites 

Se connecter ou de s'inscrire au debut

* document : (
    * enregister
    * modifier
    * suprimmer
    * afficher des documents
)
* membre : (
    * enregister
    * modifier
    * suprimmer
    * afficher des membres
)
* consultation : (
    * enregister : (
        prendre  l'id document et id membre 
    )
    * modifier // faire idem
    * suprimmer // faire idem
    * afficher des membres 
)

* emprunt : (
    * enregister : (
        prendre  l'id document et id membre 
    )
    * modifier // faire idem
    * suprimmer // faire idem
    * afficher des membres 
)
* rapport : (
    * La liste des livres empruntés en ordre alphabétique 
    * La liste des membres en ordre alphabétique
    * Liste des livres qu’on doit restituer 
    * L’ID du tiroir qui contient beaucoup des livres
    * Dernier document consulté
    * Le nom des auteurs dans le domaine de système d’exploitation et base de 
donnée
)
* utilisateur : (
    * enregister ( id utilisateur id group  processus-pere-id )
    * modifier 
    * suprimmer
    * afficher des utilisateur
)

-- CREATE DATABASE IF NOT EXISTS library;

-- USE library;

-- DROP TABLE IF EXISTS CarteAcces;
-- CREATE TABLE CarteAcces (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   bibliothecaire_id int(11) NOT NULL,
--   membre_id int(11) DEFAULT NULL,
--   nom varchar(255) DEFAULT NULL,
--   postnom varchar(255) DEFAULT NULL,
--   matricule varchar(255) DEFAULT NULL,
--   sexe varchar(4) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS bibliothecaire;
-- CREATE TABLE bibliothecaire (
--   nom varchar(255) DEFAULT NULL,
--   postnom varchar(255) DEFAULT NULL,
--   sexe varchar(4) DEFAULT NULL,
--   password varchar(255) NOT NULL,
--   username varchar(255) NOT NULL,
--   id int(11) NOT NULL AUTO_INCREMENT,
--   PRIMARY KEY (id),
--   UNIQUE KEY username (username)
-- );

-- DROP TABLE IF EXISTS categorie;
-- CREATE TABLE categorie (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   libelle varchar(255) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS consultation;
-- CREATE TABLE consultation (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   membre_id int(11) DEFAULT NULL,
--   document_id int(11) DEFAULT NULL,
--   matricule varchar(255) DEFAULT NULL,
--   date_emprunt date DEFAULT NULL,
--   date_restitution date DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS document;
-- CREATE TABLE document (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   membre_id int(11) DEFAULT NULL,
--   categorie_id int(11) DEFAULT NULL,
--   libelle varchar(255) DEFAULT NULL,
--   titre varchar(255) DEFAULT NULL,
--   description text DEFAULT NULL,
--   auteur varchar(255) DEFAULT NULL,
--   domaine varchar(255) DEFAULT NULL,
--   tiroir_id int(11) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS emprunt;
-- CREATE TABLE emprunt (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   membre_id int(11) DEFAULT NULL,
--   matricule varchar(255) DEFAULT NULL,
--   date_emprunt date DEFAULT NULL,
--   date_restitution date DEFAULT NULL,
--   document_id int(11) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS fiche;
--   id int(11) NOT NULL AUTO_INCREMENT,
--   categorie_id int(11) DEFAULT NULL,
--   bibliothecaire_id int(11) DEFAULT NULL,
--   membre_id int(11) DEFAULT NULL,
--   tiroir_id int(11) DEFAULT NULL,
--   nom_auteur varchar(255) DEFAULT NULL,
--   titre varchar(255) DEFAULT NULL,
--   date_obtention date DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS membre;
-- CREATE TABLE membre (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   bibliothecaire_id int(11) DEFAULT NULL,
--   nom varchar(255) DEFAULT NULL,
--   postnom varchar(255) DEFAULT NULL,
--   sexe varchar(4) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS tiroir;
-- CREATE TABLE tiroir (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   libelle varchar(255) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- DROP TABLE IF EXISTS utilisateur;
-- CREATE TABLE utilisateur (
--   id int(11) NOT NULL AUTO_INCREMENT,
--   groups_id varchar(45) DEFAULT NULL,
--   linux_user varchar(100) DEFAULT NULL,
--   processus_id int(11) DEFAULT NULL,
--   parent_processus_id int(11) DEFAULT NULL,
--   PRIMARY KEY (id)
-- );

-- ALTER TABLE CarteAcces ADD FOREIGN KEY (bibliothecaire_id) REFERENCES bibliothecaire(id);

-- ALTER TABLE consultation ADD FOREIGN KEY (membre_id) REFERENCES membre(id);
-- ALTER TABLE consultation ADD FOREIGN KEY (document_id) REFERENCES document(id);

-- ALTER TABLE document ADD FOREIGN KEY (membre_id) REFERENCES membre(id);
-- ALTER TABLE document ADD FOREIGN KEY (categorie_id) REFERENCES categorie(id);

-- ALTER TABLE emprunt ADD FOREIGN KEY (membre_id) REFERENCES membre(id);
-- ALTER TABLE emprunt ADD FOREIGN KEY (document_id) REFERENCES document(id);

ALTER TABLE fiche ADD FOREIGN KEY (categorie_id) REFERENCES categorie(id);
ALTER TABLE fiche ADD FOREIGN KEY (bibliothecaire_id) REFERENCES bibliothecaire(id);
ALTER TABLE fiche ADD FOREIGN KEY (membre_id) REFERENCES membre(id);

ALTER TABLE membre ADD FOREIGN KEY (bibliothecaire_id) REFERENCES bibliothecaire(id);

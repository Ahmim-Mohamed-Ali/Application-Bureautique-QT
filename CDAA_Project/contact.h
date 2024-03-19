
/**
 * @file contact.h
 * @brief Définition de la classe contact.
 */
#ifndef CONTACT_H
#define CONTACT_H
#include "sdateauto.h"
#include <ostream>
#include <QtSql>
#include <QJsonObject>
#include <QtDebug>
#include<QFile>
#include <iostream>
#include <string>
#include "interaction.h"
using namespace std;

/**
 * @class Contact
 * @brief Classe représentant un contact.
 */

class Contact
{
private:
     struct sdateAuto date;
    int id_c;///< ID du contact
    string nom;///< Nom du contact
    string prenom;///< Prénom du contact
    string entreprise;///< Entreprise du contact
    string mail;///< Adresse e-mail du contact
    string telephone;///< Numéro de téléphone du contact
    string urlPhoto;///< URL de la photo du contact
    string  dateCreation;///< Date de création du contat
    string dateEdition;///< Date d'édition du contact
    vector<Interaction> liste_inter;///< Liste des interactions associées au contact



public:
    /**
         * @brief Constructeur par défaut de la classe Contact.
         */
    Contact();
    void convertirDateEnString();
    /**
         * @brief Constructeur de la classe Contact.
         * @param nom Nom du contact.
         * @param prenom Prénom du contact.
         * @param entreprise Entreprise du contact.
         * @param mail Adresse e-mail du contact.
         * @param telephone Numéro de téléphone du contact.
         * @param photo URL de la photo du contact.
         * @param dateCreation Date de création du contact.
         */
    Contact(string nom,string prenom,string entreprise,string mail,string telephone,string photo);
    /**
         * @brief Surcharge de l'opérateur de sortie pour l'affichage d'un contact.
         * @param os Flux de sortie.
         * @param c Contact à afficher.
         */

   string getNom() const;

   string getPrenom() const;

   string getEntreprise() const;

   string getMail() const;

   string getTelephone() const;

   string getDateCreation() const;

   string getUrlPhoto() const;

   int getId_C();

   void setNom(const string &newNom);
   void convertDate();

   void setPrenom(const string &newPrenom);

   void setEntreprise(const string &newEntreprise);

   void setTelephone(const string &newTelephone);

   void setMail(const string &newMail);

   void setDateCreation(const string &newDateCreation);

   void setUrlPhoto(const string &newUriPhoto);

   void setId_c(int newId_c);
   /**
        * @brief Modifie un attribut du contact.
        * @param modif Nouvelle valeur de l'attribut.
        * @param attribut Nom de l'attribut à modifier.
        */


   /**
        * @brief Obtient une interaction du contact.
        * @param id_i ID de l'interaction à obtenir.
        * @return L'interaction correspondant à l'ID spécifié.
        */

   Interaction* getInteraction(int id_i);


   /**
        * @brief Affiche toutes les interactions du contact.
        */
   void AfficherInteractions();

   /**
      * @brief Obtient un pointeur vers une interaction du contact.
      * @param id_i ID de l'interaction à obtenir.
      * @return Pointeur vers l'interaction correspondant à l'ID spécifié.
      */
   Interaction* getPointerInteraction(int id_i);
   /**
    * @brief Obtient la liste des interactions associées au contact.
    * @return Pointeur vers le vecteur d'interactions.
    */
   vector<Interaction>* getListe_inter() ;

   string getDateEdition() const;
   void setDateEdition( string newDateEdition);

};

#endif // CONTACT_H

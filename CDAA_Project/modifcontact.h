/**
 * @file modifcontact.h
 * @brief Définition de la classe modifcontact.
 */
#ifndef MODIFCONTACT_H
#define MODIFCONTACT_H
#include "sdateauto.h"
#include "contact.h"
#include <string>

/**
 * @class ModifContact
 * @brief Classe permettant de gérer les modifications sur un objet Contact.
 */

class ModifContact
{
public:
    /**
         * @brief Constructeur de la classe ModifContact.
         * @param id ID de la modification.
         * @param type Type de la modification (par exemple : entreprise, mail, nom, prénom, téléphone).
         */
    ModifContact(int id,string type);
    /**
        * @brief Modifie l'entreprise d'un contact.
        * @param valeur Nouvelle valeur de l'entreprise.
        * @param c Pointeur vers l'objet Contact à modifier.
        */
    void ModifierEntreprise(string valeur,Contact* c);
    /**
         * @brief Modifie l'adresse e-mail d'un contact.
         * @param valeur Nouvelle valeur de l'adresse e-mail.
         * @param c Pointeur vers l'objet Contact à modifier.
         */
    void ModifierMail(string valeur,Contact* c);
    /**
        * @brief Modifie le nom d'un contact.
        * @param valeur Nouvelle valeur du nom.
        * @param c Pointeur vers l'objet Contact à modifier.
        */
    void ModifierNom(string valeur,Contact* c);
    /**
       * @brief Modifie le prénom d'un contact.
       * @param valeur Nouvelle valeur du prénom.
       * @param c Pointeur vers l'objet Contact à modifier.
       */
    void ModifierPrenom(string valeur,Contact* c);
    /**
         * @brief Modifie le numéro de téléphone d'un contact.
         * @param valeur Nouvelle valeur du numéro de téléphone.
         * @param c Pointeur vers l'objet Contact à modifier.
         */
    void ModifierTelephone(string valeur,Contact* c);
    /**
        * @brief Affiche les détails de la modification, y compris le type et la date.
        */
    void toString();

private:
    string type;///< Type de la modification.
     struct sdateAuto date;///< Date de la modification.
     int contact;///< ID du contact à modifier.

};

#endif // MODIFCONTACT_H


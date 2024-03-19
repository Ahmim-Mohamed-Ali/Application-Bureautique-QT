/**
 * @file gestioncontact.h
 * @brief Définition de la classe gestioncontact.
 */
#ifndef GESTIONCONTACTS_H
#define GESTIONCONTACTS_H
#include "contact.h"
#include <vector>
#include "modifcontact.h"
#include "gestionbd.h"

class GestionContacts
{
public:

    GestionContacts();
    static GestionContacts* getInstance();
    void AddContact(Contact c);
    int Get_Last_Id();
    void RemoveContact(Contact* c);
    int NombreContact();
    void GetAllOfContact();
    void Get_Contact_By_Name(std::string name);
    void Get_Contact_By_Entreprise(std::string entreprise);
    vector<Contact> getListe_Contacts() const;
    void TrierContactAlphabetique();
     void TrierContactCreation();
    void TrierContactIntervalle(std::string date_debut,std::string date_fin);
    void setListe_Contacts(std::vector<Contact> newListe_Contacts);
    Contact* Get_Contact_By_ID(int id);
    void ModifyContact(Contact c,Contact c2);

private:
  static GestionContacts* instance;
    std::vector<Contact> liste_Contacts;
};

#endif // GESTIONCONTACTS_H

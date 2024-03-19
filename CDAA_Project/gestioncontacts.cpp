#include "gestioncontacts.h"

GestionContacts::GestionContacts()
{

}




GestionContacts* GestionContacts::instance = nullptr;

GestionContacts* GestionContacts::getInstance() {
    if (!instance) {
        instance = new GestionContacts();
        qDebug()<<"Je vais encore ecup et creer cest pas bien !";
        instance->GetAllOfContact();
        // Initialisez la connexion à la base de données ici
    }
    return instance;
}



void GestionContacts::Get_Contact_By_Name(std::string nom){
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->GetContactByName(&liste_Contacts,nom);

}

void GestionContacts::Get_Contact_By_Entreprise(std::string entreprise){
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->GetContactByEntreprise(&liste_Contacts,entreprise);

}



void GestionContacts::AddContact(Contact c){
    liste_Contacts.push_back(c);
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->Insert_Contact_Into_BD(c);
}

void GestionContacts::RemoveContact(Contact* c){
     qDebug()<<"Nom et id et prenom du contact recue"<<c->getNom()<<c->getId_C()<<c->getPrenom();
    for (auto it = liste_Contacts.begin(); it != liste_Contacts.end(); ++it) {
        qDebug()<<"Nom et id et prenom"<<it->getNom()<<it->getId_C()<<it->getPrenom();
        if (it->getId_C() == c->getId_C()) {
            it = liste_Contacts.erase(it);
            qDebug()<<"cest le bon contact avec lid numero"<<c->getId_C()<<"Il a ete supprimer du modele et va etre supprimer d ela bd";
            break;  // Sortir de la boucle une fois que l'élément est supprimé
        }
    }
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->Delete_Contact_Into_BD(*(c));
}

void GestionContacts::GetAllOfContact(){
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->getAllPersonnes(&liste_Contacts);


}

void  GestionContacts::ModifyContact(Contact c,Contact c2){
    for(int i=0;i<static_cast<int>(liste_Contacts.size());i++){
        if(liste_Contacts.at(i).getId_C()==c.getId_C()) liste_Contacts.at(i)=c2;
    }
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->bddUpdate(c,c2);
}
int GestionContacts::NombreContact()
{
    return liste_Contacts.size();
    qDebug()<<"Taille de la liste actuelle"<<liste_Contacts.size();
}


int GestionContacts::Get_Last_Id(){
    if(GestionContacts::getInstance()->getListe_Contacts().size()!=0){
        return  GestionContacts::getInstance()->getListe_Contacts().back().getId_C();
    }
    else return 0;

}

void GestionContacts::TrierContactAlphabetique(){
    GestionBD* gestionBd = GestionBD::getInstance();
   gestionBd->getAllPersonnesBy_Ascending(&liste_Contacts);

}


void GestionContacts::TrierContactCreation(){
    GestionBD* gestionBd = GestionBD::getInstance();
   gestionBd->getAllPersonnesBy_Date_Ascending(&liste_Contacts);
}

vector<Contact> GestionContacts::getListe_Contacts() const
{
    return liste_Contacts;
}

void GestionContacts::setListe_Contacts( std::vector<Contact> newListe_Contacts)
{
    liste_Contacts = newListe_Contacts;
}


Contact* GestionContacts::Get_Contact_By_ID(int id){
    for(int i=0;i<static_cast<int>(liste_Contacts.size());i++){
        if(liste_Contacts.at(i).getId_C()==id) return &(liste_Contacts.at(i));
    }
    return nullptr;
}

void GestionContacts::TrierContactIntervalle(std::string date_debut,std::string date_fin){
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->getAllPersonnesBy_Date_Intervalle(&liste_Contacts,date_debut,date_fin);
}

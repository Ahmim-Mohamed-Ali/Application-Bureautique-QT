#include "controllercontact.h"

ControllerContact::ControllerContact(QObject *parent)
    : QObject{parent}
{

}


// ControllerContact.cpp
void ControllerContact::ajouterNouveauContact(const QString& nom, const QString& prenom, const QString& entreprise, const QString& mail, const QString& tel, const QString& photo) {
    // Créez une instance de Contact avec les informations fournies


    Contact nouveauContact;
    qDebug()<<nouveauContact.getId_C();
    nouveauContact.setNom(nom.toStdString());
    nouveauContact.setEntreprise(entreprise.toStdString());
    nouveauContact.setPrenom(prenom.toStdString());
    nouveauContact.setMail(mail.toStdString());
    nouveauContact.setTelephone(tel.toStdString());
    nouveauContact.setUrlPhoto(photo.toStdString());
    int last_id=GestionContacts::getInstance()->Get_Last_Id();
    nouveauContact.setId_c(last_id+1);
    GestionContacts::getInstance()->AddContact(nouveauContact);

    // Émettez un signal pour informer que la liste des contacts a changé
    emit signalListeContactsMiseAJour();
}


void ControllerContact::RechercherParNom(std::string nom){
    GestionContacts::getInstance()->Get_Contact_By_Name(nom);
    emit signalUpdateContacts();

}

void ControllerContact::RechercherParEntreprise(std::string entreprise){
    GestionContacts::getInstance()->Get_Contact_By_Entreprise(entreprise);
    qDebug()<<GestionContacts::getInstance()->getListe_Contacts().size();
    emit signalUpdateContacts();

}

void ControllerContact::TrierContactsAlphabetique(){
    GestionContacts::getInstance()->TrierContactAlphabetique();
    emit signalUpdateContacts();
}

void ControllerContact::TrierContactsCreation(){
    GestionContacts::getInstance()->TrierContactCreation();
    emit signalUpdateContacts();
}

void ControllerContact::TrierContactIntervalle(std::string debut,std::string fin){
    GestionContacts::getInstance()->TrierContactIntervalle(debut,fin);

    emit signalUpdateContacts();
}
void ControllerContact::OuvrirPageContact(int id) {
    // Récupérez le contact à partir du modèle
    Contact* contact = GestionContacts::getInstance()->Get_Contact_By_ID(id);
    // Émettez un signal pour indiquer l'ouverture de la page de contact avec le contact récupéré
    emit signalOuvrirPageContact(*(contact));
}


void ControllerContact::DeleteFiche(int id){
     Contact* contact = GestionContacts::getInstance()->Get_Contact_By_ID(id);
    GestionContacts::getInstance()->RemoveContact(contact);
    emit signalListeContactsMiseAJour();
}


void ControllerContact::AfficheInfoContact(int id) {
    // Récupérez le contact à partir du modèle
    Contact* contact = GestionContacts::getInstance()->Get_Contact_By_ID(id);
    // Émettez un signal pour indiquer l'ouverture de la page de contact avec le contact récupéré
    emit signalInfoContact(*(contact));
}

void ControllerContact::ModifierContact(Contact c1,Contact c2){
    GestionContacts::getInstance()->ModifyContact(c1,c2);
    emit ContactUpdate(c2);
}

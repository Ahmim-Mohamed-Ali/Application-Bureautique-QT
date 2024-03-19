#ifndef CONTROLLERCONTACT_H
#define CONTROLLERCONTACT_H
#include "contact.h"
#include "gestionbd.h"
#include <QObject>
#include "gestioncontacts.h"
class ControllerContact : public QObject
{
    Q_OBJECT
public:
    explicit ControllerContact(QObject *parent = nullptr);
     void ajouterNouveauContact(const QString& nom, const QString& prenom, const QString& entreprise, const QString& mail, const QString& tel, const QString& photo);
    void  RechercherParNom(std::string nom);
     void RechercherParEntreprise(std::string entreprise);
     void OuvrirPageContact(int id);
     void DeleteFiche(int id);
     void AfficheInfoContact(int id);
     void ModifierContact(Contact c ,Contact c2);
     void TrierContactIntervalle(std::string debut,std::string fin);
public slots:
    void TrierContactsAlphabetique();
    void TrierContactsCreation();
signals:
void signalListeContactsMiseAJour();
void signalUpdateContacts();
void signalOuvrirPageContact(Contact c);
void signalInfoContact(Contact c);
void ContactUpdate(Contact c);
};

#endif // CONTROLLERCONTACT_H

#include "widgetlistecontacts.h"
#include "ui_widgetlistecontacts.h"

WidgetListeContacts::WidgetListeContacts(ControllerContact* controllerContact,QWidget *parent) :
    cc(controllerContact),QWidget(parent),
    ui(new Ui::WidgetListeContacts)
{
    ui->setupUi(this);

    mettreAJourListeContacts();
    connect(cc, SIGNAL(signalListeContactsMiseAJour()) ,this, SLOT(mettreAJourListeContacts()));
    connect(cc, SIGNAL(ContactUpdate(Contact)) ,this, SLOT(mettreAJourListeContacts()));
    connect(ui->Search,SIGNAL(clicked(bool)),this,SLOT(RechercheContact()));
    connect(cc,SIGNAL(signalUpdateContacts()) ,this, SLOT(mettreAJourListeContacts()));
    connect(ui->Alphabetique,SIGNAL(clicked(bool)),cc,SLOT(TrierContactsAlphabetique()));
    connect(ui->Contact_Results, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(AfficherPageContact(int ,int)));
}

WidgetListeContacts::~WidgetListeContacts()
{
    delete ui;
}

void WidgetListeContacts::mettreAJourListeContacts(){

    int taille= GestionContacts::getInstance()->NombreContact();
    ui->ContactNumber->display(double(taille));
    ui->Contact_Results->verticalHeader()->setVisible(false);
    ui->Contact_Results->clearContents();  // Effacer le contenu des cellules
    ui->Contact_Results->setRowCount(0);  // Réinitialiser le nombre de lignes à zéro
    ui->Contact_Results->setColumnCount(3);
    ui->Contact_Results->setHorizontalHeaderLabels({"ID","Nom", "Prénom"});

        for (int i = 0; i<taille; i++) {
         Contact contact = GestionContacts::getInstance()->getListe_Contacts().at(i);
        // Ajouter une nouvelle ligne à la tableWidget
        int row = ui->Contact_Results->rowCount();
        ui->Contact_Results->insertRow(row);

        // Ajouter le nom et le prénom dans les cellules de la nouvelle ligne
        QString identifiant = QString::number(contact.getId_C());
        QTableWidgetItem *itemId = new QTableWidgetItem(identifiant);
        itemId->setData(Qt::UserRole, QVariant(identifiant));
        QString nom = QString::fromStdString(contact.getNom());
        QTableWidgetItem *itemNom = new QTableWidgetItem(nom);
        QString prenom = QString::fromStdString(contact.getPrenom());
        QTableWidgetItem *itemPrenom = new QTableWidgetItem(prenom);

        ui->Contact_Results->setItem(row, 0, itemId);
        ui->Contact_Results->setItem(row, 1, itemNom);     // Colonne 0 pour le nom
        ui->Contact_Results->setItem(row, 2, itemPrenom);  // Colonne 1 pour le prénom
    }
}


void WidgetListeContacts::RechercheContact(){
    if(!ui->Nom->text().isEmpty()){
        QString name=ui->Nom->text();
        std::string nom = name.toStdString();
        cc->RechercherParNom(nom);
    }
    else if(!ui->Entreprise->text().isEmpty()){
        QString entreprise=ui->Entreprise->text();
        cc->RechercherParEntreprise(entreprise.toStdString());

    }
    else    qDebug()<<"Rien na ete selectionne";
}



void WidgetListeContacts::AfficherPageContact(int row, int col){
 int idContact = ui->Contact_Results->item(row, col)->data(Qt::UserRole).toInt();
    pcc= new PageContact(cc);
     cc->OuvrirPageContact(idContact);
    pcc->show();
}

#include "widgetlistescontacts.h"
#include "ui_widgetlistescontacts.h"

WidgetListesContacts::WidgetListesContacts(ControllerContact* controllerContact,QWidget *parent) :
    QMainWindow(parent),cc(controllerContact),
    ui(new Ui::WidgetListesContacts)
{
    ui->setupUi(this);
    mettreAJourListeContacts();
    connect(ui->Search_Date,SIGNAL(clicked(bool)),this,SLOT(RechercheParIntervalles()));
    connect(cc, SIGNAL(signalListeContactsMiseAJour()) ,this, SLOT(mettreAJourListeContacts()));
    connect(cc, SIGNAL(ContactUpdate(Contact)) ,this, SLOT(mettreAJourListeContacts()));
    connect(ui->Search,SIGNAL(clicked(bool)),this,SLOT(RechercheContact()));
    connect(cc,SIGNAL(signalUpdateContacts()) ,this, SLOT(mettreAJourListeContacts()));
    connect(ui->Contact_Results, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(AfficherPageContact(int ,int)));
}

WidgetListesContacts::~WidgetListesContacts()
{
    delete ui;
}


void WidgetListesContacts::mettreAJourListeContacts(){

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



void WidgetListesContacts::RechercheContact(){
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


void WidgetListesContacts::AfficherPageContact(int row, int col){
    int idContact;
    if(col==1 || col==2){
        idContact = ui->Contact_Results->item(row, 0)->data(Qt::UserRole).toInt();
    }

    else{

        idContact = ui->Contact_Results->item(row, col)->data(Qt::UserRole).toInt();
    }
    pcc= new PageContact(cc);
    cc->OuvrirPageContact(idContact);
    pcc->setWindowModality(Qt::ApplicationModal);
    pcc->show();
}

void WidgetListesContacts::on_actionTrier_Par_Ordre_Alphabetique_triggered()
{
    cc->TrierContactsAlphabetique();
}


void WidgetListesContacts::on_actionTrier_Par_Date_De_Creation_triggered()
{
    cc->TrierContactsCreation();
}

void WidgetListesContacts::RechercheParIntervalles(){
    QDate dateDebut = ui->dateDebut->date();
    QDate dateFin = ui->dateFin->date();
    std::string date_debut = dateDebut.toString("dd/MM/yyyy").toStdString();
    std::string date_fin = dateFin.toString("dd/MM/yyyy").toStdString();
    qDebug()<<date_debut;
    qDebug()<<date_fin;

    cc->TrierContactIntervalle(date_debut,date_fin);

}

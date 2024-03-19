#include "pagecontact.h"
#include "ui_pagecontact.h"

PageContact::PageContact(ControllerContact* cc,QWidget *parent) :
    QMainWindow(parent),cc{cc},
    ui(new Ui::PageContact)
{
    ui->setupUi(this);
    ci = new ControllerInteraction(this);
    connect(cc,SIGNAL(signalOuvrirPageContact(Contact)),this,SLOT(OuvrirPageContact(Contact)));
    connect(cc,SIGNAL(ContactUpdate(Contact)),this,SLOT(OuvrirPageContact(Contact)));
    connect(ci,SIGNAL(AjoutInteraction()),this,SLOT(UpdateInteractions()));
    connect(ui->Result_Interaction, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(AfficherPageInteraction(int ,int)));
}

PageContact::~PageContact()
{
    delete ui;
}


void PageContact::OuvrirPageContact(Contact c){
    QString nom=QString::fromStdString(c.getNom());
    QString id=QString::number(c.getId_C());
    QString prenom=QString::fromStdString(c.getPrenom());
    QString entreprise=QString::fromStdString(c.getEntreprise());
    QString mail=QString::fromStdString(c.getMail());
    QString telephone=QString::fromStdString(c.getTelephone());
    qDebug()<<c.getMail();
    qDebug()<<c.getDateCreation();
    QString dateCreation=QString::fromStdString(c.getDateCreation());
    qDebug()<<"sdfsdf\n";
    qDebug()<<c.getDateCreation();
    QString dateEdition=QString::fromStdString(c.getDateEdition());
    ui->Nom->setText(nom);
    ui->id->setText(id);
    ui->Prenom->setText(prenom);
    ui->Entreprise->setText(entreprise);
    ui->Mail->setText(mail);
    ui->Telephone->setText(telephone);
    ui->Date_Creation->setText(dateCreation);
    ui->Modification->setText(dateEdition);
    ui->Nom->setReadOnly(true);
    ui->Prenom->setReadOnly(true);
    ui->Entreprise->setReadOnly(true);
    ui->Mail->setReadOnly(true);
    ui->Telephone->setReadOnly(true);
    ui->Date_Creation->setReadOnly(true);
    ui->Modification->setReadOnly(true);
    qDebug()<<c.getUrlPhoto();
    QPixmap image(c.getUrlPhoto().c_str());
    if (!image.isNull()) {
        // Redimensionner l'image pour s'adapter à la taille de votre QLabel si nécessaire
        image = image.scaled(ui->Photo->size(), Qt::KeepAspectRatio);

        // Afficher l'image dans le QLabel
        ui->Photo->setPixmap(image);
        ui->Photo->setScaledContents(true);  // Optionnel : ajuster la taille de QLabel à l'image
    } else {
        // L'image n'a pas pu être chargée, vous pouvez afficher un avertissement ou une image par défaut.
        ui->Photo->setText("L'utilisateur n'a Pas de Photo");
    }
    id_contact=ui->id->text().toInt();
    ci->setC((GestionContacts::getInstance()->Get_Contact_By_ID(id_contact)));
}


void PageContact::on_actionLister_Les_Interactions_triggered()
{
    ListerInteractions();
}



void PageContact::ListerInteractions(){
    Contact* contact= GestionContacts::getInstance()->Get_Contact_By_ID(id_contact);
    qDebug() << "Taille de la liste avant getAllInteractions : " << contact->getListe_inter()->size();

    GestionnaireInteraction::getInstance()->GetAllOfInteractions(id_contact);
     qDebug() << "Taille de la liste apres getAllInteractions : " << contact->getListe_inter()->size();
    ui->Result_Interaction->verticalHeader()->setVisible(false);
    ui->Result_Interaction->clearContents();  // Effacer le contenu des cellules
    ui->Result_Interaction->setRowCount(0);  // Réinitialiser le nombre de lignes à zéro
    ui->Result_Interaction->setColumnCount(2);
    ui->Result_Interaction->setHorizontalHeaderLabels({"Contenu","Date"});

    for (int i = 0; i<static_cast<int>(contact->getListe_inter()->size()); i++) {
        Interaction interact = contact->getListe_inter()->at(i);
        // Ajouter une nouvelle ligne à la tableWidget
        int row = ui->Result_Interaction->rowCount();
        ui->Result_Interaction->insertRow(row);

        // Ajouter le nom et le prénom dans les cellules de la nouvelle ligne
        QString contenue = QString::fromStdString(interact.getContenu());
        QTableWidgetItem *itemContenue = new QTableWidgetItem(contenue);
        itemContenue->setData(Qt::UserRole, QVariant(contenue));
        QString date = QString::fromStdString(interact.getDateEdition());
        QTableWidgetItem *itemDate = new QTableWidgetItem(date);
        itemDate->setData(Qt::UserRole, QVariant(date));

        ui->Result_Interaction->setItem(row, 0, itemContenue);
        ui->Result_Interaction->setItem(row, 1, itemDate);     // Colonne 0 pour le nom

    }
}



void PageContact::UpdateInteractions(){
    //int id_contact=ui->id->text().toInt();
    Contact* contact= GestionContacts::getInstance()->Get_Contact_By_ID(id_contact);
    ui->Result_Interaction->verticalHeader()->setVisible(false);
    ui->Result_Interaction->clearContents();  // Effacer le contenu des cellules
    ui->Result_Interaction->setRowCount(0);  // Réinitialiser le nombre de lignes à zéro
    ui->Result_Interaction->setColumnCount(2);
    ui->Result_Interaction->setHorizontalHeaderLabels({"Contenu","Date"});

    for (int i = 0; i<static_cast<int>(contact->getListe_inter()->size()); i++) {
        Interaction interact = contact->getListe_inter()->at(i);
        // Ajouter une nouvelle ligne à la tableWidget
        int row = ui->Result_Interaction->rowCount();
        ui->Result_Interaction->insertRow(row);


        // Ajouter le nom et le prénom dans les cellules de la nouvelle ligne
        QString contenue = QString::fromStdString(interact.getContenu());
        QTableWidgetItem *itemContenue = new QTableWidgetItem(contenue);
        itemContenue->setData(Qt::UserRole, QVariant(contenue));
        QString date = QString::fromStdString(interact.getDateEdition());
        QTableWidgetItem *itemDate = new QTableWidgetItem(date);
        itemDate->setData(Qt::UserRole, QVariant(date));

        ui->Result_Interaction->setItem(row, 0, itemContenue);
        ui->Result_Interaction->setItem(row, 1, itemDate);     // Colonne 0 pour le nom


    }
}


void PageContact::AfficherPageInteraction(int row ,int col){
    std::string contenu, date;
    if(col==0)
    {
        contenu = ui->Result_Interaction->item(row, col)->data(Qt::UserRole).toString().toStdString();
        date = ui->Result_Interaction->item(row, 1)->data(Qt::UserRole).toString().toStdString();
    }
    else{

        contenu = ui->Result_Interaction->item(row, 0)->data(Qt::UserRole).toString().toStdString();
        date = ui->Result_Interaction->item(row, col)->data(Qt::UserRole).toString().toStdString();

    }
    pi=new WidgetInteractionPage(ci);
    ci->OuvrirPageInteraction(contenu,date);
    pi->setWindowModality(Qt::ApplicationModal);
    pi->show();


}

void PageContact::on_actionSupprimer_La_Fiche_triggered()
{
    DeletePageContact();
}

void PageContact::DeletePageContact(){
    int entier =ui->id->text().toInt();
    cc->DeleteFiche(entier);

    QMessageBox::information(nullptr, "Succès", "Le contact a été Supprimmer avec succès.");
    this->close();
}

void PageContact::on_actionModifier_La_Fiche_triggered()
{
    ModifyContact();
}

void PageContact::ModifyContact(){
    //int entier =ui->id->text().toInt();
    mc= new WidgetModifyContact(cc);
    cc->AfficheInfoContact(id_contact);
    mc->setWindowModality(Qt::ApplicationModal);
    mc->show();
}



void PageContact::LancerWidgetAddInteraction(){
    // int id_contact=ui->id->text().toInt();
    //ci->setC(*(GestionContacts::getInstance()->Get_Contact_By_ID(id_contact)));
    ai=new WidgetAddInteraction(ci);
      ai->setWindowModality(Qt::ApplicationModal);
    ai->show();

}


void PageContact::on_actionAjouter_Une_Interaction_triggered()
{
    LancerWidgetAddInteraction();
}




void PageContact::on_actionRecherche_Interaction_triggered()
{

}


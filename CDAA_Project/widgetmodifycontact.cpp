#include "widgetmodifycontact.h"
#include "ui_widgetmodifycontact.h"

WidgetModifyContact::WidgetModifyContact(ControllerContact* controllerContact,QWidget *parent) :
    QWidget(parent),cc(controllerContact),
    ui(new Ui::WidgetModifyContact)
{
    ui->setupUi(this);
    connect(cc,SIGNAL(signalInfoContact(Contact)),this,SLOT(AfficheInfoContact(Contact)));
    connect(ui->Modifier,SIGNAL(clicked(bool)),this,SLOT(ModifierContact()));
     connect(ui->Photo,SIGNAL(clicked(bool)),this,SLOT(ModifyPhoto()));
}

WidgetModifyContact::~WidgetModifyContact()
{
    delete ui;
}
void WidgetModifyContact::AfficheInfoContact(Contact c){

    QString nom=QString::fromStdString(c.getNom());
    QString id=QString::number(c.getId_C());
    QString prenom=QString::fromStdString(c.getPrenom());
    QString entreprise=QString::fromStdString(c.getEntreprise());
    QString mail=QString::fromStdString(c.getMail());
    QString telephone=QString::fromStdString(c.getTelephone());
    ui->Nom->setText(nom);
    ui->id->setText(id);
    ui->id->setReadOnly(true);
    ui->Prenom->setText(prenom);
    ui->Entreprise->setText(entreprise);
    ui->Mail->setText(mail);
    ui->Telephone->setText(telephone);
}


void WidgetModifyContact::ModifierContact(){
    Contact c2;
    int entier =ui->id->text().toInt();
    Contact* c=GestionContacts::getInstance()->Get_Contact_By_ID(entier);
    c2.setDateCreation(c->getDateCreation());
    if(ui->checkName->isChecked()){
        c2.setNom(ui->Nom->text().toStdString());

    }
    else{
        c2.setNom(c->getNom());
    }
    if(ui->checkPrenom->isChecked()){
        c2.setPrenom(ui->Prenom->text().toStdString());
    }
    else{
        c2.setPrenom(c->getPrenom());
    }
    if(ui->checkMail->isChecked()){
        c2.setMail(ui->Mail->text().toStdString());
    }
    else{
        c2.setMail(c->getMail());
    }
    if(ui->CheckEntreprise->isChecked()){
        c2.setEntreprise(ui->Entreprise->text().toStdString());
    }
    else{
        c2.setEntreprise(c->getEntreprise());
    }
    if(ui->checkPhone->isChecked()){
        c2.setTelephone(ui->Telephone->text().toStdString());
    }
    else{
        c2.setTelephone(c->getTelephone());
    }
    if(ui->checkPhoto->isChecked()){
        c2.setUrlPhoto(ui->Photo->text().toStdString());
    }
    else{
        c2.setUrlPhoto(c->getUrlPhoto());
    }
    c2.setId_c(c->getId_C());
    cc->ModifierContact(*(c),c2);
    qDebug()<<"Date du contact cree 2"<<c2.getDateCreation();
    QMessageBox::information(nullptr, "Succès", "Le contact a été Modifié avec succès.");
    this->close();

}


void WidgetModifyContact::ModifyPhoto(){
    QString cheminPhoto = QFileDialog::getOpenFileName(this, tr("Choisir une photo"), "", tr("Images (*.png *.jpg)"));
    if (!cheminPhoto.isNull()) {
        // Le chemin du fichier a été sélectionné, faites ce que vous devez avec->
        ui->Photo->setText(cheminPhoto);
    }
    else {
        // L'utilisateur a annulé la sélection, vous pouvez gérer cela selon vos besoins
        qDebug()<<"Vous n'avez rien choissi";
    }
}

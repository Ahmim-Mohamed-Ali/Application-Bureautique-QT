#include "creercontact.h"
#include "ui_creercontact.h"

CreerContact::CreerContact(ControllerContact* controllerContact, QWidget* parent)
    :  QWidget(parent),cc(controllerContact), ui(new Ui::CreerContact) {
    ui->setupUi(this);
    // Créez et configurez les widgets nécessaires (LineEdit, boutons, etc.)

    // Connectez le bouton de création à la méthode du contrôleur
    connect(ui->Create, SIGNAL(clicked(bool)), this, SLOT(VerifierContact()));
    connect(ui->Photo,SIGNAL(clicked(bool)),this,SLOT(VerifPhoto()));
}

void CreerContact::VerifPhoto(){
    QString cheminPhoto = QFileDialog::getOpenFileName(this, tr("Choisir une photo"), "", tr("Images (*.png *.jpg)"));
    if (!cheminPhoto.isNull()) {
        // Le chemin du fichier a été sélectionné, faites ce que vous devez avec.
        ui->Photo->setText(cheminPhoto);
    }
    else {
        // L'utilisateur a annulé la sélection, vous pouvez gérer cela selon vos besoins
        qDebug()<<"Vous n'avez rien choissi";
    }
}


CreerContact::CreerContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreerContact)
{
    ui->setupUi(this);
}

CreerContact::~CreerContact()
{
    delete ui;
}


void CreerContact::VerifierContact() {
    qDebug()<<"je verifie les info du contact";
    QString nom = ui->Nom->text();
    QString prenom = ui->Prenom->text();
    QString entreprise = ui->Entreprise->text();
    QString mail = ui->Mail->text();
    QString telephone = ui->Telephone->text();
    try {

        // Vérifiez la longueur du numéro de téléphone
        if (telephone.length() > 10) {
            throw std::out_of_range("Le numéro de téléphone ne doit pas dépasser 10 caractères.");
        }

        QString urlPhoto = ui->Photo->text();
        //QString date_crea = ui->Date->text();
        // Appelez la méthode du contrôleur pour ajouter le contac
        cc->ajouterNouveauContact(nom,prenom, entreprise,mail,telephone,urlPhoto);
        // Fermez le widget de création de contact ou effectuez d'autres actions nécessaires
        this->close();

    } catch (const std::out_of_range& e) {
        // Capturez l'exception et gérez l'erreur ici
        qDebug() << "Erreur : " << e.what();
         this->close();
        // Ajoutez ici le code pour gérer l'erreur, par exemple, affichez un message d'erreur à l'utilisateur.
    }

}

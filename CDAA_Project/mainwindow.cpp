#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    ui->setupUi(this);
     controllerTodo = new ControllerTodo(this);
    connect(ui->Collect,SIGNAL(clicked(bool)),this,SLOT(CollectAllTodo()));
    connect(ui->Collect_Todo,SIGNAL(clicked(bool)),this,SLOT(CollectAllInteraction()));
    connect(controllerTodo,SIGNAL(signalUpdateAllTodo()),this,SLOT(UpdateTodoList()));
     controllerContact = new ControllerContact(this);
    GestionContacts::getInstance();
     for(int i=0;i<GestionContacts::getInstance()->getListe_Contacts().size();i++){
     ui->IdContact_Box->addItem(QString::number(GestionContacts::getInstance()->getListe_Contacts().at(i).getId_C()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::CollectAllTodo(){
    QDate dateDebut = ui->Date1->date();
    QDate dateFin = ui->Date2->date();

    std::string date_debut = dateDebut.toString("dd/MM/yyyy").toStdString();
    std::string date_fin = dateFin.toString("dd/MM/yyyy").toStdString();
    qDebug()<<date_debut;
    qDebug()<<date_fin;
    ControllerInteraction* ci = new ControllerInteraction(this);
    ci->GetAllInteraction_Date(date_debut,date_fin);
    ui->Results_Interaction->verticalHeader()->setVisible(false);
    ui->Results_Interaction->clearContents();  // Effacer le contenu des cellules
    ui->Results_Interaction->setRowCount(0);  // Réinitialiser le nombre de lignes à zéro
    ui->Results_Interaction->setColumnCount(3);
    ui->Results_Interaction->setHorizontalHeaderLabels({"Contenu","Date","Id Contact"});
    qDebug()<<"Taille de la liste apres methode"<<GestionnaireInteraction::getInstance()->getListe_Interactions().size();
    for (int i = 0; i<static_cast<int>(GestionnaireInteraction::getInstance()->getListe_Interactions().size()); i++) {
        Interaction interact = GestionnaireInteraction::getInstance()->getListe_Interactions().at(i);
        // Ajouter une nouvelle ligne à la tableWidget
        int row = ui->Results_Interaction->rowCount();
        ui->Results_Interaction->insertRow(row);

        // Ajouter le nom et le prénom dans les cellules de la nouvelle ligne
        QString contenue = QString::fromStdString(interact.getContenu());
        QTableWidgetItem *itemContenue = new QTableWidgetItem(contenue);
        itemContenue->setData(Qt::UserRole, QVariant(contenue));
        QString date = QString::fromStdString(interact.getDateEdition());
        QTableWidgetItem *itemDate = new QTableWidgetItem(date);
        itemDate->setData(Qt::UserRole, QVariant(date));
        QString idContact =  QString::number(interact.getId_c());
        QTableWidgetItem *itemContact = new QTableWidgetItem(idContact);
        itemContact->setData(Qt::UserRole, QVariant(idContact));

        ui->Results_Interaction->setItem(row, 0, itemContenue);
        ui->Results_Interaction->setItem(row, 1, itemDate);
        ui->Results_Interaction->setItem(row, 2, itemContact);

    }
}




void MainWindow::on_actionAjouter_Un_Contact_2_triggered()
{
    // Créez et affichez le widget WidgetCreationContact en lui passant le contrôleur
    cc = new CreerContact(controllerContact);
    cc->setWindowModality(Qt::ApplicationModal);
    cc->show();
}


void MainWindow::on_actionLister_Les_Contacts_2_triggered()
{
    // Créez et affichez le widget WidgetCreationContact en lui passant le contrôleur
    lc = new WidgetListesContacts(controllerContact);
    lc->setWindowModality(Qt::ApplicationModal);
    lc->show();
}


void MainWindow::CollectAllInteraction(){
    QDate dateDebut = ui->Date1_Todo->date();
    QDate dateFin = ui->Date2_Todo->date();

    std::string date_debut = dateDebut.toString("dd/MM/yyyy").toStdString();
    std::string date_fin = dateFin.toString("dd/MM/yyyy").toStdString();
    qDebug()<<date_debut;
    qDebug()<<date_fin;
    if(ui->checkContact->isChecked()){
        int id_Contact=ui->IdContact_Box->currentText().toInt();
        qDebug()<<"Id du contact choisi"<<id_Contact;
        controllerTodo->GetAllOfTodo_ByIntervalle_Contact(date_debut,date_fin,id_Contact);
    }
    else{
            controllerTodo->GetAllOfTodo_ByIntervalle(date_debut,date_fin);
    }

}

void MainWindow::UpdateTodoList(){
    ui->Results_Interaction->verticalHeader()->setVisible(false);
    ui->Results_Interaction->clearContents();  // Effacer le contenu des cellules
    ui->Results_Interaction->setRowCount(0);  // Réinitialiser le nombre de lignes à zéro
    ui->Results_Interaction->setColumnCount(3);
    ui->Results_Interaction->setHorizontalHeaderLabels({"Contenu","Date","Id Contact"});
    qDebug()<<"Taille de la liste apres methode"<<GestionTodo::getInstance()->getListe_todos().size();
    for (int i = 0; i<static_cast<int>(GestionTodo::getInstance()->getListe_todos().size()); i++) {
        Todo todo = GestionTodo::getInstance()->getListe_todos().at(i);
        // Ajouter une nouvelle ligne à la tableWidget
        int row = ui->Results_Interaction->rowCount();
        ui->Results_Interaction->insertRow(row);

        // Ajouter le nom et le prénom dans les cellules de la nouvelle ligne
        QString contenue = QString::fromStdString(todo.getTask());
        QTableWidgetItem *itemContenue = new QTableWidgetItem(contenue);
        itemContenue->setData(Qt::UserRole, QVariant(contenue));
        QString date = QString::fromStdString(todo.getDatePrevu());
        QTableWidgetItem *itemDate = new QTableWidgetItem(date);
        itemDate->setData(Qt::UserRole, QVariant(date));
        QString idContact = QString::number(todo.getNum_contact());
        QTableWidgetItem *itemContact = new QTableWidgetItem(idContact);
        itemContact->setData(Qt::UserRole, QVariant(idContact));

        ui->Results_Interaction->setItem(row, 0, itemContenue);
        ui->Results_Interaction->setItem(row, 1, itemDate);
        ui->Results_Interaction->setItem(row, 2, itemContact);
    }
}

void MainWindow::on_actionExport_Json_triggered()
{
    qDebug()<<"le menu a ete clique";
    GestionBD::getInstance()->exportJson();

}


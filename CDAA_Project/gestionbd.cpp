#include "gestionbd.h"
#include "gestioncontacts.h"
GestionBD::GestionBD(QObject *parent)
    : QObject{parent}
{
    dbouverture=false;
    connectDB();

}

 GestionBD::~GestionBD() {
    delete instance;
}

GestionBD* GestionBD::instance = nullptr;

GestionBD* GestionBD::getInstance() {
    if (!instance) {
        instance = new GestionBD();
        // Initialisez la connexion à la base de données ici
    }
    return instance;
}



bool GestionBD::connectDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString localeUri="C:/Users/moham/OneDrive/Bureau/Final_Project/BD/database.sqlite";
    db.setDatabaseName( localeUri );
    if(!db.open())
    {
        qDebug() << "Pas de connexion àla BDD !";
            dbouverture=false;
    }
    else
    {
        qDebug() << "Connexion réussie àla BDD !";
        dbouverture=true;
    }

    return dbouverture;
}



void GestionBD::closeDB()
{
    if (dbouverture==true)
        db.close();
}

QString GestionBD::convertirFormatDate( QString dateEntree) {
    QDate date = QDate::fromString(dateEntree, "dd/MM/yyyy");
    return date.toString("yyyy-MM-dd");

}


void GestionBD::Insert_Contact_Into_BD(Contact c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO contact (nom, prenom, entreprise,mail,telephone,urlPhoto,dateCreation,dateEdition) VALUES (:n, :p, :e,:m,:t,:u,:d,:de)");
    query.bindValue(":n", QString::fromStdString(c.getNom()));
    query.bindValue(":p", QString::fromStdString(c.getPrenom()));
    query.bindValue(":e", QString::fromStdString(c.getEntreprise()));
    query.bindValue(":m", QString::fromStdString(c.getMail()));
    query.bindValue(":t", QString::fromStdString(c.getTelephone()));
    query.bindValue(":u", QString::fromStdString(c.getUrlPhoto()));
    query.bindValue(":d", QDate::fromString(QString::fromStdString(c.getDateCreation()), "dd/MM/yyyy"));
    query.bindValue(":de", QString::fromStdString(c.getDateCreation()));
    if(!query.exec())
    {
                  qDebug() << "Impossible d’exécuter la requête :" << query.lastError().text();
    }
    else
    {

         qDebug()<<"Je Suis ici au niveau du GestionBD";
    }
}



void GestionBD::getAllPersonnes(std::vector<Contact>* lc)
{
    lc->clear();
    if (dbouverture==true)
    {
         QSqlQuery query("SELECT id, nom, prenom, entreprise, mail, telephone, urlPhoto, dateCreation, dateEdition FROM contact");
        if(!query.exec())
        {
             qDebug() << "Impossible d’exécuter la requête :" << query.lastError().text();
            qDebug() << "Impossible d’exécuter la requête !";
        }
        else
        {
            qDebug() << "Requête réussie !";

            while(query.next())
            {
                Contact c;
                int id = query.value(0).toInt();
                c.setId_c(id);
                QString r = query.value(1).toString();
                c.setNom(r.toStdString());
                r = query.value(2).toString();
                c.setPrenom(r.toStdString());
                r=query.value(3).toString();
                c.setEntreprise(r.toStdString());
                r=query.value(4).toString();
                c.setMail(r.toStdString());
                r=query.value(5).toString();
                c.setTelephone(r.toStdString());
                r=query.value(6).toString();
                c.setUrlPhoto(r.toStdString());
                c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
                r=query.value(8).toString();
                c.setDateEdition(r.toStdString());
                lc->push_back(c);
            }
        }
    }
}


void GestionBD::getAllInteractions(std::vector<Interaction> *li, int id_contact){
    li->clear();
    QSqlQuery query;
    query.prepare("SELECT interaction.* FROM Interaction "
                  "JOIN contact ON interaction.idContact = contact.id "
                  "WHERE contact.id = :idContact;");
    query.bindValue(":idContact", id_contact);
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête pour recupere les interactions de ce contact!";
    }
    else
    {
        qDebug() << "Requête bien réussie !";
        while(query.next())
        {
            Interaction i;
            int id = query.value(1).toInt();
            i.setId_i(id);
            QString r = query.value(2).toString();
            i.setContenu(r.toStdString());
            i.setDateEdition(query.value(3).toDate().toString("dd/MM/yyyy").toStdString());
            qDebug()<<"Numero de l'interaction recupere"<<i.getId_i();
            qDebug()<<"Contenu de l'interaction recupere"<<i.getContenu();
            qDebug()<<"Date format de l'interaction recupere"<<i.getDateEdition();
            li->push_back(i);
        }
    }



}

void GestionBD::getAllTodo(std::vector<Todo> *lt, int id_interaction){
    lt->clear();
    QSqlQuery query;
    query.prepare("SELECT todo.* FROM Todo "
                  "JOIN TodoInteractionAssociation ON todo.id = TodoInteractionAssociation.idTodo "
                  "WHERE TodoInteractionAssociation.idInteraction = :idInteraction;");
    query.bindValue(":idInteraction", id_interaction);
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête pour recupere les todos de cette interaction !";
    }
    else
    {
        qDebug() << "Requête bien réussie pour recupere les todos de cette interaction!";
        while(query.next())
        {
            Todo d;
            QString r = query.value(1).toString();
            d.setTask(r.toStdString());
            qDebug()<<"Contenu de Todo"<< d.getTask();
            d.setDate(query.value(2).toDate().toString("dd/MM/yyyy").toStdString());
            qDebug()<< "Date du Todo"<<d.getDatePrevu();
            lt->push_back(d);
        }

    }



}



void GestionBD::GetContactByName(std::vector<Contact>* lc,std::string nom){

    lc->clear();
    QSqlQuery query;
    if (dbouverture==true)
    {

        query.prepare("SELECT * FROM contact WHERE nom=:n;");
        query.bindValue(":n", QString::fromStdString(nom));

    }
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête !";
    }
    else
    {
        qDebug() << "Requête réussie !";
         while(query.next())
        {
           Contact c;
            int id = query.value(0).toInt();
            c.setId_c(id);
            QString r = query.value(1).toString();
            c.setNom(r.toStdString());
            r = query.value(2).toString();
            c.setPrenom(r.toStdString());
            r=query.value(3).toString();
            c.setEntreprise(r.toStdString());
            r=query.value(4).toString();
            c.setMail(r.toStdString());
            r=query.value(5).toString();
            c.setTelephone(r.toStdString());
            r=query.value(6).toString();
            c.setUrlPhoto(r.toStdString());
             c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
            r=query.value(8).toString();
            c.setDateEdition(r.toStdString());
            lc->push_back(c);
        }
    }

}




bool GestionBD::bddUpdate(Contact c,Contact c2){
    qDebug()<<"Contact De Base";
    qDebug()<<c.getNom();
    qDebug()<<c.getPrenom();
    qDebug()<<c.getDateCreation();
       qDebug()<<"Contact Modifie";
    qDebug()<<c2.getNom();
    qDebug()<<c2.getPrenom();
    qDebug()<<c2.getMail();
    qDebug()<<c2.getEntreprise();
    qDebug()<<c2.getTelephone();
    qDebug()<<c2.getUrlPhoto();
    qDebug()<<c2.getDateCreation();
    qDebug()<<c2.getDateEdition();
    if (dbouverture==true)
    {
        QSqlQuery query;
        //avec une préparation de la requête et des champs pré−conçus
        query.prepare("UPDATE contact SET nom=:newn, prenom=:newp ,entreprise=:newe,mail=:newm ,telephone=:newt,urlPhoto=:newu,dateCreation=:newd,dateEdition=:newde WHERE nom=:n and prenom=:p;");
        query.bindValue(":n", QString::fromStdString(c.getNom()));
        query.bindValue(":p", QString::fromStdString(c.getPrenom()));
        query.bindValue(":newn", QString::fromStdString(c2.getNom()));
        query.bindValue(":newp", QString::fromStdString(c2.getPrenom()));
        query.bindValue(":newm", QString::fromStdString(c2.getMail()));
        query.bindValue(":newe", QString::fromStdString(c2.getEntreprise()));
        query.bindValue(":newt", QString::fromStdString(c2.getTelephone()));
        query.bindValue(":newu", QString::fromStdString(c2.getUrlPhoto()));
        query.bindValue(":newd", QDate::fromString(QString::fromStdString(c.getDateCreation()), "dd/MM/yyyy"));
        query.bindValue(":newde", QString::fromStdString(c2.getDateEdition()));

        if (!query.exec())
        {
            qDebug() << "Erreur à la mise àjour";
            return false;
        }
        else{
            qDebug() << "Contact mise àjour";return true;
        }
    }
    return true;

}

void GestionBD::GetContactByEntreprise(std::vector<Contact>* lc,std::string entreprise){

    lc->clear();
    QSqlQuery query;
    if (dbouverture==true)
    {

        query.prepare("SELECT * FROM contact WHERE Entreprise=:n;");
        query.bindValue(":n", QString::fromStdString(entreprise));

    }
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête !";
    }
    else
    {
        qDebug() << "Requête réussie !";
        Contact c;
        while(query.next())
        {
            int id = query.value(0).toInt();
            c.setId_c(id);
            QString r = query.value(1).toString();
            c.setNom(r.toStdString());
            r = query.value(2).toString();
            c.setPrenom(r.toStdString());
            r=query.value(3).toString();
            c.setEntreprise(r.toStdString());
            r=query.value(4).toString();
            c.setMail(r.toStdString());
            r=query.value(5).toString();
            c.setTelephone(r.toStdString());
            r=query.value(6).toString();
            c.setUrlPhoto(r.toStdString());
           c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
            r=query.value(8).toString();
            c.setDateEdition(r.toStdString());
            lc->push_back(c);
        }
    }
}


void GestionBD::Delete_Contact_Into_BD(Contact c){
    qDebug()<<"id Recupere "<<c.getId_C();
    if (dbouverture==true)
    {
        QSqlQuery query;

        query.prepare("DELETE FROM contact WHERE nom=:n and prenom=:p;");
        query.bindValue(":n", QString::fromStdString(c.getNom()));
        query.bindValue(":p", QString::fromStdString(c.getPrenom()));
        if (!query.exec())
        {
            qDebug() << "Erreur à la suppression";
                // emit Informer_Supression(supprimer);
        }
        else{
            qDebug() << "Le contact num"<<c.getId_C()<< "avec le nom"<< c.getNom()<<"a ete supp de la bd";
        }

    }
}


void GestionBD::Insert_Interaction_Into_BD(int id_c,Interaction i){
    QSqlQuery query;
    query.prepare("INSERT INTO Interaction (idContact, contenu,DateCreation) VALUES (:idc, :c, :de)");
    query.bindValue(":c", QString::fromStdString(i.getContenu()));
    query.bindValue(":idc",QString::number(id_c));
    qDebug()<<"Date de creation "<<i.getDateEdition();
     query.bindValue(":de", QDate::fromString(QString::fromStdString(i.getDateEdition()), "dd/MM/yyyy"));
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête !";
    }
    else
    {
        qDebug() << "Requête réussie !";
        int id_interact = query.lastInsertId().toInt();
        i.setId_i(id_interact);
        qDebug() <<"Id de linteraction insere"<< id_interact;
        Contact* c=GestionContacts::getInstance()->Get_Contact_By_ID(id_c);
        c->getListe_inter()->push_back(i);

    }
}


void GestionBD::Insert_Todo_Into_BD(Todo d,int id_interaction){
    qDebug()<<"Id recue depuis le gestionnaire de todo"<<id_interaction;
    QSqlQuery query;
    query.prepare("INSERT INTO Todo (contenu,DatePrevue) VALUES (:c, :dp)");
    query.bindValue(":c", QString::fromStdString(d.getTask()));
    query.bindValue(":dp",QDate::fromString(QString::fromStdString(d.getDatePrevu()), "dd/MM/yyyy"));
    if(!query.exec())
    {
        qDebug() << "Impossible d’exécuter la requête pour inserer le todo a cette interaction";
    }
    else
    {
        qDebug() << "Requête réussie pour inserer le todo a cette interaction !";
        int id_todo = query.lastInsertId().toInt();
        qDebug() << "Id de linteraction qui va etre insere"<<id_interaction;
        qDebug() <<"Id deu Todo qui va etre insere"<< id_todo;
        QSqlQuery query2;
        query2.prepare("INSERT INTO TodoInteractionAssociation (idTodo,idInteraction) VALUES (:idt,:idi)");
        query2.bindValue(":idi", QString::number(id_interaction));
          query2.bindValue(":idt",QString::number(id_todo));
        if(!query2.exec())
        {
            qDebug() << "Impossible d’exécuter la requête !";
        }
        else
        {
            qDebug() << "Requête réussie !";

        }


    }
}


void GestionBD::getAllPersonnesBy_Ascending(std::vector<Contact>* lc){
    lc->clear();
    if (dbouverture==true)
    {
        QSqlQuery query("SELECT id,nom, prenom,entreprise,mail,telephone,urlPhoto,dateCreation,dateEdition from contact ORDER BY prenom ASC");
        if(!query.exec())
        {
            qDebug() << "Impossible d’exécuter la requête !";
        }
        else
        {
            qDebug() << "Requête réussie !";
            while(query.next())
            {            Contact c;
                int id = query.value(0).toInt();
                c.setId_c(id);
                QString r = query.value(1).toString();
                c.setNom(r.toStdString());
                r = query.value(2).toString();
                c.setPrenom(r.toStdString());
                r=query.value(3).toString();
                c.setEntreprise(r.toStdString());
                r=query.value(4).toString();
                c.setMail(r.toStdString());
                r=query.value(5).toString();
                c.setTelephone(r.toStdString());
                r=query.value(6).toString();
                c.setUrlPhoto(r.toStdString());
                c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
                r=query.value(8).toString();
                c.setDateEdition(r.toStdString());
                lc->push_back(c);
            }
        }
    }




}



void GestionBD::getAllPersonnesBy_Date_Ascending(std::vector<Contact>*lc){

    lc->clear();
    if (dbouverture==true)
    {
        QSqlQuery query("SELECT id, nom, prenom, entreprise, mail, telephone, urlPhoto, dateCreation, dateEdition FROM contact ORDER BY substr(dateCreation, 7, 4) || '-' || substr(dateCreation, 4, 2) || '-' || substr(dateCreation, 1, 2) DESC");
            if(!query.exec())
        {
            qDebug() << "Impossible d’exécuter la requête !";
        }
        else
        {
            qDebug() << "Requête réussie !";
            while(query.next())
            {            Contact c;
                int id = query.value(0).toInt();
                c.setId_c(id);
                QString r = query.value(1).toString();
                c.setNom(r.toStdString());
                r = query.value(2).toString();
                c.setPrenom(r.toStdString());
                r=query.value(3).toString();
                c.setEntreprise(r.toStdString());
                r=query.value(4).toString();
                c.setMail(r.toStdString());
                r=query.value(5).toString();
                c.setTelephone(r.toStdString());
                r=query.value(6).toString();
                c.setUrlPhoto(r.toStdString());
                c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
                r=query.value(8).toString();
                c.setDateEdition(r.toStdString());
                lc->push_back(c);
            }
        }
    }


}



void GestionBD::getAllPersonnesBy_Date_Intervalle(std::vector<Contact>* lc, std::string date_debut, std::string date_fin) {
    lc->clear();
    QString date_start=convertirFormatDate(QString::fromStdString(date_debut));
    QString date_end=convertirFormatDate(QString::fromStdString(date_fin));
    QSqlQuery query;
    if (dbouverture==true)
    {

        query.prepare("SELECT * FROM contact WHERE dateCreation BETWEEN :date_deb AND :date_fin;");
        query.bindValue(":date_deb", date_start);
        query.bindValue(":date_fin",date_end);

    }


    if (!query.exec()) {
        qDebug() << "Impossible d’exécuter la requête : " << query.lastError().text();
    } else {
        qDebug() << "Requête réussie POUR Recuperer les contacts dans ces intervalles de dates!";
        while (query.next()) {
             qDebug() << "Requête réussie POUR Recuperer CE CONTACT";
            Contact c;
            // Remplir les données du contact à partir des résultats de la requête
            c.setId_c(query.value(0).toInt());
            c.setNom(query.value(1).toString().toStdString());
            c.setPrenom(query.value(2).toString().toStdString());
            c.setEntreprise(query.value(3).toString().toStdString());
            c.setMail(query.value(4).toString().toStdString());
            c.setTelephone(query.value(5).toString().toStdString());
            c.setUrlPhoto(query.value(6).toString().toStdString());
            c.setDateCreation(query.value(7).toDate().toString("dd/MM/yyyy").toStdString());
            c.setDateEdition(query.value(8).toString().toStdString());
            qDebug() << "Contact recupere avec la date"<<c.getDateCreation();
            lc->push_back(c);
        }
    }
}

void GestionBD::getAllInteractionsBy_Date_Intervalle(std::vector<Interaction>* li,std::string date_debut,std::string date_fin){
    qDebug()<<"J'ai recu cette date de debut"<<date_debut;
    qDebug()<<"J'ai recu cette date de debut"<<date_fin;
    qDebug()<<"JE FAIS SA ici ou je recupere les id";
    QString date_start=convertirFormatDate(QString::fromStdString(date_debut));
    QString date_end=convertirFormatDate(QString::fromStdString(date_fin));
    qDebug()<<"J'ai converti cette date"<<date_start;
    qDebug()<<"J'ai converti cette date"<<date_end;
    QSqlQuery query;
    if (dbouverture==true)
    {

        query.prepare("SELECT * FROM Interaction WHERE dateCreation BETWEEN :date_deb AND :date_fin;");
        query.bindValue(":date_deb", date_start);
        query.bindValue(":date_fin",date_end);

    }


    if (!query.exec()) {
        qDebug() << "Impossible d’exécuter la requête : " << query.lastError().text();
    } else
    {
        qDebug() << "Requête réussie POUR Recuperer les Interactions dans ces intervalles de dates!";
        while (query.next())
        {
            qDebug() << "Requête réussie POUR Recuperer CETTE Interaction";
            Interaction i;
            // Remplir les données du contact à partir des résultats de la requête
            i.setId_c(query.value(0).toInt());
            i.setId_i(query.value(1).toInt());
            i.setContenu(query.value(2).toString().toStdString());
            try {
                i.setDateEdition(query.value(3).toDate().toString("dd/MM/yyyy").toStdString());
            } catch (const std::exception &e) {
                qDebug() << "Erreur lors de la conversion de date : " << e.what();
            }
            qDebug()<<i.getContenu();
            qDebug()<<i.getDateEdition();
            li->push_back(i);
        }
        qDebug()<<"Taille des Interactions recuperes"<<li->size();
    }

}


void GestionBD::getAllTodoBy_Date_Intervalle(std::vector<Todo>* lt, std::string date_debut, std::string date_fin) {
    lt->clear();
    qDebug()<<"Date recup dans BD actu"<<date_debut;
    qDebug()<<"Date Fin recup dans BD actu"<<date_fin;
    QSqlQuery query;
    if (dbouverture) {
        // Convertir les dates de début et de fin au format attendu par SQLite
        QString date_start=convertirFormatDate(QString::fromStdString(date_debut));
        QString date_end=convertirFormatDate(QString::fromStdString(date_fin));

        query.prepare("SELECT td.contenu, td.DatePrevue, i.idContact FROM Todo td "
                      "JOIN TodoInteractionAssociation ti ON td.id = ti.idTodo "
                      "JOIN Interaction i ON i.idInteraction = ti.idInteraction "
                      "WHERE DatePrevue BETWEEN :date_deb AND :date_fin;");
        query.bindValue(":date_deb", date_start);
        query.bindValue(":date_fin", date_end);
    }


    if (!query.exec()) {
        qDebug() << "Impossible d’exécuter la requête : " << query.lastError().text();
    } else {
        qDebug() << "Requête réussie POUR Recuperer les Todos dans ces intervalles de dates!";
        while (query.next()) {
            Todo d;
            // Remplir les données du contact à partir des résultats de la requête

            d.setTask(query.value(0).toString().toStdString());
            d.setDate(query.value(1).toDate().toString("dd/MM/yyyy").toStdString());
            d.setNum_contact(query.value(2).toInt());
            lt->push_back(d);
        }
    }
}


void GestionBD::GetAllOfTodo_Intervalle_Contact(std::vector<Todo>* lt,std::string date_debut,std::string date_fin, int id_contact){

    lt->clear();
    qDebug()<<"Date recup dans BD actu"<<date_debut;
    qDebug()<<"Date Fin recup dans BD actu"<<date_fin;
    qDebug()<<"Id recup"<<id_contact;
    QSqlQuery query;
    if (dbouverture) {
        // Convertir les dates de début et de fin au format attendu par SQLite
        QString date_start=convertirFormatDate(QString::fromStdString(date_debut));
        QString date_end=convertirFormatDate(QString::fromStdString(date_fin));
        qDebug()<<date_start;
        qDebug()<<date_end;

        query.prepare("SELECT td.contenu, td.DatePrevue, i.idContact FROM Todo td "
                      "JOIN TodoInteractionAssociation ti ON td.id = ti.idTodo "
                      "JOIN Interaction i ON i.idInteraction = ti.idInteraction "
                      "WHERE DatePrevue BETWEEN :date_deb AND :date_fin "
                      "AND i.idContact = :idContact;"
                      );
        query.bindValue(":date_deb", date_start);
        query.bindValue(":date_fin", date_end);
        query.bindValue(":idContact", id_contact);
    }


    if (!query.exec()) {
        qDebug() << "Impossible d’exécuter la requête : " << query.lastError().text();
    } else {
        qDebug() << "Requête réussie POUR Recuperer les Todos dans ces intervalles de dates!";
        while (query.next()) {
            Todo d;
            // Remplir les données du contact à partir des résultats de la requête

            d.setTask(query.value(0).toString().toStdString());
            d.setDate(query.value(1).toDate().toString("dd/MM/yyyy").toStdString());
            d.setNum_contact(query.value(2).toInt());
            lt->push_back(d);
        }
        qDebug() << "Taille des Todo recup de c contact"<<lt->size();
    }


}

void GestionBD::exportJson(){

    QSqlQuery query1,query2,query3,query4;
    query1.prepare("SELECT * FROM contact");
    if(!query1.exec()){
        qDebug("Sa ne marche pas");
    }

    else {
        qDebug("Sa Marche je fais lexport en Json des Contacts");
        QJsonArray qj;

        while(query1.next()){
            QJsonObject oj;
            oj["ID"]=query1.value(0).toString();
            oj["nom"]=query1.value(1).toString();
            oj["prenom"]=query1.value(2).toString();
            oj["entreprise"]=query1.value(3).toString();
            oj["mail"]=query1.value(4).toString();
            oj["telephone"]=query1.value(5).toString();
            oj["urlPhoto"]=query1.value(6).toString();
            oj["dateCreation"]=query1.value(7).toString();
            oj["dateEdition"]=query1.value(8).toString();

            qj.append(oj);
        }

        QJsonDocument jDocument(qj);
        QFile fichier ("C:/Users/moham/OneDrive/Bureau/Final_Project/BD/contact.json");
        if(fichier.open(QIODevice::WriteOnly)){
            fichier.write(jDocument.toJson());
            qDebug()<<"Export en json reussi dans le fichier ouvert";
            fichier.close();
        }
    }


    query2.prepare("SELECT * FROM Interaction");
    if(!query2.exec()){
        qDebug("Sa ne marche pas");
    }

    else {
        qDebug("Sa Marche je fais lexport en Json des Interactions");
        QJsonArray qinteraction;

        while(query2.next()){
            QJsonObject oj;
            oj["ID Contact"]=query2.value(0).toString();
            oj["Id Interaction"]=query2.value(1).toString();
            oj["Contenu"]=query2.value(2).toString();
            oj["Date Creation"]=query2.value(3).toString();
            qinteraction.append(oj);
        }

        QJsonDocument jDocumentInteraction(qinteraction);
        QFile fichier ("C:/Users/moham/OneDrive/Bureau/Final_Project/BD/interaction.json");
        if(fichier.open(QIODevice::WriteOnly)){
            fichier.write(jDocumentInteraction.toJson());
            qDebug()<<"Export en json reussi dans le fichier ouvert";
            fichier.close();
        }
    }

    query3.prepare("SELECT * FROM Todo");
    if(!query3.exec()){
        qDebug("Sa ne marche pas");
    }

    else {
        qDebug("Sa Marche je fais lexport en Json des Todos");
        QJsonArray qTodo;

        while(query3.next()){
            QJsonObject oj;
            oj["ID Todo"]=query3.value(0).toString();
            oj["Contenu"]=query3.value(1).toString();
            oj["Date Prevue"]=query3.value(2).toString();
            qTodo.append(oj);
        }

        QJsonDocument jDocumentTodo(qTodo);
        QFile fichier ("C:/Users/moham/OneDrive/Bureau/Final_Project/BD/todo.json");
        if(fichier.open(QIODevice::WriteOnly)){
            fichier.write(jDocumentTodo.toJson());
            qDebug()<<"Export en json reussi dans le fichier ouvert";
            fichier.close();
        }
    }


    query4.prepare("SELECT * FROM TodoInteractionAssociation");
    if(!query4.exec()){
        qDebug("Sa ne marche pas");
    }

    else {
        qDebug("Sa Marche je fais lexport en Json des TodoInteractionAssociation");
        QJsonArray qTodoInteractionAssociation;

        while(query4.next()){
            QJsonObject oj;
            oj["ID TodoInteractionAssociation"]=query4.value(0).toString();
            oj["Id Todo"]=query4.value(1).toString();
            oj["Id Interaction"]=query4.value(2).toString();
            qTodoInteractionAssociation.append(oj);
        }

        QJsonDocument jDocumentTodoInteraction(qTodoInteractionAssociation);
        QFile fichier ("C:/Users/moham/OneDrive/Bureau/Final_Project/BD/todoinetarctionassociations.json");
        if(fichier.open(QIODevice::WriteOnly)){
            fichier.write(jDocumentTodoInteraction.toJson());
            qDebug()<<"Export en json reussi dans le fichier ouvert";
            fichier.close();
        }
    }



}

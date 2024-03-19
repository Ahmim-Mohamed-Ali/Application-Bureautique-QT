#ifndef GESTIONBD_H
#define GESTIONBD_H
#include "contact.h"
#include <QObject>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <list>
#include "interaction.h"
#include <vector>
#include "todo.h"
#include <QDate>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class GestionBD : public QObject
{
    Q_OBJECT
private:
    bool dbouverture;
    QSqlDatabase db;
    static GestionBD* instance;

public:

    ~GestionBD();
     static GestionBD* getInstance();
    bool connectDB();
    void closeDB();
    explicit GestionBD(QObject *parent = nullptr);
    void Insert_Interaction_Into_BD(int id_c,Interaction i);
    bool bddUpdate(Contact c,Contact c2);
    void Insert_Contact_Into_BD(Contact c);
    void GetContactByEntreprise(std::vector<Contact>* lc,std::string entreprise);
    void GetContactByName(std::vector<Contact>* lc,std::string nom);
    void getAllPersonnes(std::vector<Contact>* lc) ;
    void Delete_Contact_Into_BD(Contact c);
    void getAllInteractions(std::vector<Interaction>* li,int id) ;
    void Insert_Todo_Into_BD(Todo d,int id_contact);
    void getAllPersonnesBy_Ascending(std::vector<Contact>*lc);
    void getAllPersonnesBy_Date_Ascending(std::vector<Contact>*lc);
    void getAllTodo(std::vector<Todo> *lt, int id_interaction);
    void getAllPersonnesBy_Date_Intervalle(std::vector<Contact>* lc,std::string date_debut,std::string date_fin);
    void getAllTodoBy_Date_Intervalle(std::vector<Todo>* lt,std::string date_debut,std::string date_fin);
    void GetAllOfTodo_Intervalle_Contact(std::vector<Todo>* lt,std::string date_debut,std::string date_fin, int id_contact);
    QString convertirFormatDate( QString dateEntree);
     void getAllInteractionsBy_Date_Intervalle(std::vector<Interaction>* li,std::string date_debut,std::string date_fin);
    void exportJson();

signals:

};

#endif // GESTIONBD_H

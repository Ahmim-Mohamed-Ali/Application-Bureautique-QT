#include "controllertodo.h"

ControllerTodo::ControllerTodo(QObject *parent)
    : QObject{parent}
{

}



void ControllerTodo::AjouterTodo(QString contenue,QString date){
    int id_interaction=getI()->getId_i();
    std::string contenu=contenue.toStdString();
    std::string date_creation=date.toStdString();
    qDebug()<<"Id Interaction dans le controllertodo"<<id_interaction;
            qDebug()<<"Contenu Todo dans le controllertodo"<<contenu;
    Todo td (contenu,date_creation);
    GestionTodo::getInstance()->Addtodo(td,getC(),id_interaction);
    emit AjoutTodo();
}

void ControllerTodo::AjouterTodo_Date(QString contenue){
    int id_interaction=getI()->getId_i();
    qDebug()<<"Id Interaction recue depuis laa page interaction"<<id_interaction;
    std::string contenu=contenue.toStdString();
        qDebug()<<"Contenu Todo"<<contenu;
    qDebug()<<"Id du Contact recue depuis le controllerTodo par le biais du controllerContact "<<getC()->getId_C();
        qDebug()<<"Taille Recup de liste interactions recue depuis le contact"<<getC()->getListe_inter()->size();
     Todo td (contenu);
        qDebug()<<"!!!!!!!!Date Du Todo cree"<<td.getDatePrevu();
    GestionTodo::getInstance()->Addtodo(td,getC(),id_interaction);
    emit AjoutTodo();
}

Interaction *ControllerTodo::getI() const
{
    return i;
}

void ControllerTodo::setI(Interaction *newI)
{
    i = newI;
}

Contact *ControllerTodo::getC() const
{
    return c;
}

void ControllerTodo::setC(Contact *newC)
{
    c = newC;
}


void ControllerTodo::GetAllOfTodo_ByIntervalle(std::string dateDebut,std::string dateFin){
     qDebug("Je suis la et je vais en direction de la gestionTodo avec intervalle ");
    GestionTodo::getInstance()->GetAllOfTodo_Intervalle(dateDebut,dateFin);
    emit signalUpdateAllTodo();
}


void ControllerTodo::GetAllOfTodo_ByIntervalle_Contact(std::string dateDebut,std::string dateFin,int idContact){
    qDebug("Je suis la et je vais en direction de la gestionTodo avec intervalle et id");
    GestionTodo::getInstance()->GetAllOfTodo_Intervalle_Contact(dateDebut,dateFin,idContact);
    emit signalUpdateAllTodo();
}

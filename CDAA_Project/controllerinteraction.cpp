#include "controllerinteraction.h"

ControllerInteraction::ControllerInteraction(QObject *parent)
    : QObject{parent}
{

}


void ControllerInteraction::AjouterInteraction(QString contenue){
    int id_contact=getC()->getId_C();
    std::string contenu=contenue.toStdString();
    Interaction i;
    i.setContenu(contenu);
    GestionnaireInteraction::getInstance()->addInteraction(id_contact,i);
    emit AjoutInteraction();
}




void ControllerInteraction::OuvrirPageInteraction(std::string contenu,std::string date) {
    Contact* contact=GestionContacts::getInstance()->Get_Contact_By_ID(c->getId_C());
      Interaction* interact = GestionnaireInteraction::getInstance()->getInteraction(contact,contenu,date);
    qDebug()<<"Contenue de la page interaction dans methode ouvrir"<<interact->getContenu();
     emit signalOuvrirPageInteraction(interact);
}

Contact *ControllerInteraction::getC() const
{
     return c;
}

void ControllerInteraction::setC(Contact *newC)
{
     c = newC;
}



void ControllerInteraction::GetAllInteraction_Date(std::string date_deb,std::string date_fin){
     GestionnaireInteraction::getInstance()->TrierInteractionIntervalle(date_deb,date_fin);
     qDebug()<<"Je suis la au niveau du controller d'interaction";
     //emit signalUpdateContacts();
}

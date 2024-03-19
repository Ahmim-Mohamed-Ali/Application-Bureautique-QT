#include "gestionnaireinteraction.h"

GestionnaireInteraction::GestionnaireInteraction()
{

}



GestionnaireInteraction* GestionnaireInteraction::instance = nullptr;

void GestionnaireInteraction::NombreInteractions(Contact* c){
    std::cout<<"Le contact ";
    std::cout<<c->getNom()<<" "<<c->getPrenom();
    std::cout<<" numero ";
    std::cout<<c->getId_C();
    std::cout<<" possede ";
    std::cout<<c->getListe_inter()->size();
    std::cout<<" interactions :"<<std::endl;
}


GestionnaireInteraction* GestionnaireInteraction::getInstance() {
if (!instance) {
    instance = new GestionnaireInteraction();
    // Initialisez la connexion à la base de données ici
}
return instance;
}

void GestionnaireInteraction::addInteraction(int id_c,Interaction interact){

 GestionBD::getInstance()->Insert_Interaction_Into_BD(id_c,interact);

}

std::vector<Interaction>* GestionnaireInteraction:: GetListeOfInteraction(Contact c){
 return c.getListe_inter();
}

void GestionnaireInteraction::GetAllOfInteractions(int id_c){
 Contact* c=GestionContacts::getInstance()->Get_Contact_By_ID(id_c);
 c->getListe_inter()->clear();
if(c->getListe_inter()->size()==0){qDebug()<<"ListeVide";}
for(int i=0;i<static_cast<int>(c->getListe_inter()->size());i++){qDebug()<<"Pas de bd"<<c->getListe_inter()->at(i).getContenu();}
 qDebug()<<"Taille Avant BD"<<c->getListe_inter()->size();
 GestionBD::getInstance()->getAllInteractions(c->getListe_inter(),id_c);
 for(int i=0;i<static_cast<int>(c->getListe_inter()->size());i++){qDebug()<<"Apres la bd"<<c->getListe_inter()->at(i).getContenu();}

}


Interaction* GestionnaireInteraction::getInteraction(Contact* c,std::string contenu,std::string date){

 for(int i=0;i<static_cast<int>(c->getListe_inter()->size());i++){
    Interaction* interact=&(c->getListe_inter()->at(i));
    if(interact->getContenu()==contenu && interact->getDateEdition()==date){
               return interact;
            }
        }
 return nullptr;
}


void GestionnaireInteraction::TrierInteractionIntervalle(std::string date_debut,std::string date_fin){
 GestionBD* gestionBd = GestionBD::getInstance();
 gestionBd->getAllInteractionsBy_Date_Intervalle(&liste_Interactions,date_debut,date_fin);
 qDebug()<<"Taille de liste recupe dans le gestionnaire"<<liste_Interactions.size();

}

std::vector<Interaction> GestionnaireInteraction::getListe_Interactions() const
{
 return liste_Interactions;
}

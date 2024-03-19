#include "gestiontodo.h"

GestionTodo* GestionTodo::instance = nullptr;
GestionTodo::GestionTodo()
{

}

void GestionTodo::GetAllOfTodo(Interaction* interaction){
    qDebug()<<"Je vais recup tout les todo de cette interaction qui a lid"<<interaction->getId_i();
    int id_i=interaction->getId_i();
       interaction->getLesTodos()->clear();
     qDebug()<<"Voici le texte de l'interaction en question avant le GetAll dans la BD"<<interaction->getContenu();
    GestionBD::getInstance()->getAllTodo(interaction->getLesTodos(),id_i);
    interaction->setContenu(interaction->getContenu()+"\n");
    for (int i = 0; i < static_cast<int>(interaction->getLesTodos()->size()); i++) {
        Todo todo = interaction->getLesTodos()->at(i);
        std::string contenuTodo = todo.getTask();
        std::string contenuDate = todo.getDatePrevu();
        std::string contenu =  " @todo " + contenuTodo + " @date " + contenuDate + "\n";
        interaction->setContenu(interaction->getContenu()+ contenu);
        contenu="";
    }
    qDebug()<<"Voici le texte de l'interaction en question apres le GetAll dans la BD"<<interaction->getContenu();
}

void GestionTodo::Addtodo(Todo d,Contact* c,int id_i){
    qDebug()<<"Contact recue depuis le controllertodo"<<c->getId_C();
    qDebug()<<"Id recue de l'interaction depuis le controllertodo"<<id_i;
    qDebug()<<"Interaction recupere  contenue"<<c->getInteraction(id_i)->getContenu();
    c->getInteraction(id_i)->AddTodo(d);
    GestionBD::getInstance()->Insert_Todo_Into_BD(d,id_i);
}

GestionTodo* GestionTodo::getInstance() {
    if (!instance) {
        instance = new GestionTodo();
        // Initialisez la connexion à la base de données ici
    }
    return instance;
}




void  GestionTodo::Affichetodo(Contact* c,int id_i){
    std::cout<< "Todo affecte a l'interaction "<<id_i<<" du contact "<<c->getNom()<<" "<<c->getPrenom()<<":"<<std::endl;
    c->getPointerInteraction(id_i)->AfficherTodo();
}


void GestionTodo::GetAllOfTodo_Intervalle(std::string date_debut,std::string date_fin){
         qDebug("Je suis la et je vais en direction de la bd pour un intervalle simple ");
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->getAllTodoBy_Date_Intervalle(&liste_todos,date_debut,date_fin);


}

void GestionTodo::GetAllOfTodo_Intervalle_Contact(std::string date_debut,std::string date_fin, int id_contact){
        qDebug("Je suis la et je vais en direction de la bd ");
    GestionBD* gestionBd = GestionBD::getInstance();
    gestionBd->GetAllOfTodo_Intervalle_Contact(&liste_todos,date_debut,date_fin,id_contact);

}


std::vector<Todo> GestionTodo::getListe_todos() const
{
    return liste_todos;
}


/**
 * @file gestiontodo.h
 * @brief Définition de la classe gestiontodo.
 */
#ifndef GESTIONTODO_H
#define GESTIONTODO_H
#include "todo.h"
#include "contact.h"
#include <vector>
#include "gestionbd.h"
#include "interaction.h"
class GestionTodo
{
public:
    static GestionTodo* getInstance();
    GestionTodo();

    void Addtodo(Todo d,Contact* c,int id_i);
    void GetAllOfTodo(Interaction* interaction);
    void  Affichetodo(Contact* c,int id_i);
    void GetAllOfTodo_Intervalle(std::string date_debut,std::string date_fin);
    void GetAllOfTodo_Intervalle_Contact(std::string date_debut,std::string date_fin, int id_contact);

    std::vector<Todo> getListe_todos() const;

private:
    static GestionTodo* instance;
        std::vector<Todo> liste_todos;
};

#endif // GESTIONTODO_H

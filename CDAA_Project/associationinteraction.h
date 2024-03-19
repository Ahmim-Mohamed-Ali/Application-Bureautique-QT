/**
 * @file associationinteractiontodo.h
 * @brief Définition de la classe associationinteractiontodo.
 */
 #ifndef ASSOCIATIONINTERACTIONTODO_H
#define ASSOCIATIONINTERACTIONTODO_H
#include "interaction.h"
#include "todo.h"
#include <unordered_map>//22-oct 19:40
using namespace std;

/**
 * @class AssociationInteractionTodo
 * @brief Classe pour représenter une association entre une interaction et un todo.
 */
class AssociationInteractionTodo
{
public:
    /**
         * @brief Constructeur de la classe AssociationInteractionTodo.
         *
         * @param i Pointeur vers l'interaction à associer.
         * @param d Pointeur vers le todo à associer.
         */
    AssociationInteractionTodo(Interaction *i, Todo *d);
    /**
         * @brief Affiche l'association entre l'interaction et le todo.
         */
    void Afficher();
    /**
        * @brief Obtient un pointeur vers l'interaction associée.
        *
        * @return Un pointeur vers l'interaction associée.
        */
    Interaction* getI();
    /**
         * @brief Obtient le todo associé.
         *
         * @return Le todo associé.
         */
    Todo getD();

private:
    Interaction *i;///< Pointeur vers l'interaction associée.
    Todo *d; ///< Pointeur vers le todo associé.
};

#endif // ASSOCIATIONINTERACTIONTODO_H


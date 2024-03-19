#include "associationinteraction.h"

/**
 * @brief Constructeur de la classe AssociationInteractionTodo.
 * @param i Un pointeur vers l'objet Interaction associé.
 * @param d Un pointeur vers l'objet Todo associé.
 */
AssociationInteractionTodo::AssociationInteractionTodo(Interaction *i,Todo *d)
{
    this->i=i;
    this->d=d;

}
/**
 * @brief Affiche l'association entre une Interaction et un Todo.
 */
void AssociationInteractionTodo::Afficher()
{
   std::cout << "Le Todo associée à l'intercation "<<(*i).getContenu()<<" est : " << (*d) << std::endl;
}

/**
 * @brief Récupère l'objet Interaction associé.
 * @return Un pointeur vers l'objet Interaction associé.
 */
Interaction* AssociationInteractionTodo::getI()
{
    return i;
}
/**
 * @brief Récupère l'objet Todo associé.
 * @return L'objet Todo associé.
 */
Todo AssociationInteractionTodo::getD()
{
    return *(d);
}

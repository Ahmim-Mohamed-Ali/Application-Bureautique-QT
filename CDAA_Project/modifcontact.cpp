
#include "modifcontact.h"
#include <iostream>

/**
 * @brief Constructeur de la classe ModifContact.
 *
 * Initialise une instance de ModifContact avec l'identifiant du contact et le type de modification.
 *
 * @param id L'identifiant du contact.
 * @param type Le type de modification à effectuer.
 */
ModifContact::ModifContact(int id,string type)
{
    day_point dp = floor<days>(system_clock::now());
    auto amj = year_month_day{dp};
    this->date.jour = amj.day();
    this->date.mois = amj.month();
    this->date.annee = amj.year();
    this->type=type;
    this->contact=id;
}
/**
 * @brief Affiche un message de modification.
 *
 * Affiche un message indiquant la modification effectuée sur un contact, y compris la date.
 */

void ModifContact::toString(){
    std::cout<<"Le contact numero: "<<this->contact<< " a ete " << this->type <<" le "<<this->date.jour<<"/"<<this->date.mois<<"/"<<this->date.annee<<std::endl;

}
/**
 * @brief Modifie l'entreprise d'un contact.
 *
 * Modifie l'entreprise d'un contact en utilisant la nouvelle valeur spécifiée.
 *
 * @param valeur La nouvelle valeur de l'entreprise.
 * @param c Le contact à modifier.
 */

void ModifContact::ModifierEntreprise(string valeur,Contact* c){
    c->setEntreprise(valeur);
}
/**
 * @brief Modifie le nom d'un contact.
 *
 * Modifie le nom d'un contact en utilisant la nouvelle valeur spécifiée.
 *
 * @param valeur La nouvelle valeur du nom.
 * @param c Le contact à modifier.
 */
void ModifContact::ModifierNom(string valeur,Contact* c){
    c->setNom(valeur);
}
/**
 * @brief Modifie le prénom d'un contact.
 *
 * Modifie le prénom d'un contact en utilisant la nouvelle valeur spécifiée.
 *
 * @param valeur La nouvelle valeur du prénom.
 * @param c Le contact à modifier.
 */
void ModifContact::ModifierPrenom(string valeur,Contact* c){
    c->setPrenom(valeur);
}
/**
 * @brief Modifie l'adresse e-mail d'un contact.
 *
 * Modifie l'adresse e-mail d'un contact en utilisant la nouvelle valeur spécifiée.
 *
 * @param valeur La nouvelle valeur de l'adresse e-mail.
 * @param c Le contact à modifier.
 */

void ModifContact::ModifierMail(string valeur,Contact* c){
    c->setMail(valeur);
}
/**
 * @brief Modifie le numéro de téléphone d'un contact.
 *
 * Modifie le numéro de téléphone d'un contact en utilisant la nouvelle valeur spécifiée.
 *
 * @param valeur La nouvelle valeur du numéro de téléphone.
 * @param c Le contact à modifier.
 */
void ModifContact::ModifierTelephone(string valeur,Contact* c){
    c->setTelephone(valeur);
}


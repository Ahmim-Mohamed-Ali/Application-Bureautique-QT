/**
 * @file gestionnaireinteraction.h
 * @brief Définition de la classe gestionnaireinteraction.
 */
#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H
#include "interaction.h"
#include "contact.h"
#include <vector>
#include "gestioncontacts.h"
/**
 * @class GestionnaireInteraction
 * @brief Classe pour gérer les interactions associées aux contacts.
 */
class GestionnaireInteraction
{
public:
    static GestionnaireInteraction* getInstance();
    GestionnaireInteraction();
    void addInteraction(int id_c,Interaction interact);
    void NombreInteractions(Contact* c);
    Interaction* getInteraction(Contact* c, std::string contenu,std::string date);
    std::vector<Interaction>* GetListeOfInteraction(Contact c);
    void GetAllOfInteractions(int id_c);
    void TrierInteractionIntervalle(std::string date_deb,std::string date_fin);
    std::vector<Interaction> getListe_Interactions() const;

signals:
private:
      static GestionnaireInteraction* instance;
     std::vector<Interaction> liste_Interactions;
};

#endif // GESTIONNAIREINTERACTION_H

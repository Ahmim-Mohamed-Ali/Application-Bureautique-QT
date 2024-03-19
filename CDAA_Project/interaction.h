
/**
 * @file interaction.h
 * @brief Définition de la classe interaction.
 */
#ifndef INTERACTION_H
#define INTERACTION_H
#include <string>
#include <ostream>
#include "sdateauto.h"
#include "todo.h"
#include <vector>
#include <iomanip>
#include <chrono>  // pour std::put_time
#include <ctime>
using namespace std;

/**
 * @class Interaction
 * @brief Classe représentant une interaction.
 */

class Interaction
{
private:
    int id_i;///< ID de l'interaction.
    int id_c;
    struct sdateAuto date;///< La date de l'interaction.
    string dateEdition;
    string contenu;///< Le contenu de l'interaction.
    vector <Todo> lesTodos;///< Liste des todos associés à l'interaction.

public:
    void convertirDateEnString();
    /**
         * @brief Constructeur par défaut de la classe Interaction.
         * Par défaut, le contenu est vide, mais la date est la date courante.
         */
    Interaction();
    /**
         * @brief Constructeur de la classe Interaction avec contenu initial.
         * @param initialContenu Contenu initial de l'interaction.
         */
    Interaction(const std::string &);

    /**
     * @brief Destructeur de la classe Interaction.
     */
    ~Interaction();
    /**
         * @brief Obtient la date de l'interaction.
         * @return La date de l'interaction.
         */
    struct sdateAuto getDate() const;
    /**
         * @brief Obtient le jour de la date de l'interaction.
         * @return Le jour de la date.
         */
    day getJour() const;
    /**
         * @brief Obtient le mois de la date de l'interaction.
         * @return Le mois de la date.
         */
    month getMois() const;
    /**
        * @brief Obtient l'année de la date de l'interaction.
        * @return L'année de la date.
        */
    year getAnnee() const;
    /**
       * @brief Obtient le contenu de l'interaction.
       * @return Le contenu de l'interaction.
       */
    string getContenu() const;
    /**
        * @brief Définit la date de l'interaction.
        * @param newDate La nouvelle date de l'interaction.
        */
    void setDate(const struct sdateAuto &);
    /**
        * @brief Définit le contenu de l'interaction.
        * @param newContenu Le nouveau contenu de l'interaction.
        */
    void setContenu(const string &);
    /**
         * @brief Ajoute un todo à l'interaction.
         * @param d Le todo à ajouter.
         */
    void AddTodo(Todo d);
    /**
        * @brief Surcharge de l'opérateur de sortie pour afficher une interaction.
        * @param os Le flux de sortie.
        * @param i L'interaction à afficher.
        * @return Le flux de sortie modifié.
        */
    friend std::ostream& operator<<(ostream &, const Interaction );
    /**
         * @brief Obtient l'ID de l'interaction.
         * @return L'ID de l'interaction.
         */
    int getId_i() const;
    /**
         * @brief Obtient un pointeur vers la liste des todos associés à l'interaction.
         * @return Pointeur vers la liste des todos.
         */
    vector<Todo>* getLesTodos();
    /**
         * @brief Affiche la liste des todos associés à l'interaction.
         */
    void AfficherTodo();
    /**
        * @brief Définit l'ID de l'interaction.
        * @param newId_i Le nouvel ID de l'interaction.
        */
    void setId_i(int newId_i);
    string getDateEdition() const;
    void setDateEdition( string newDateEdition);
    void convertDate();
    int getId_c() const;
    void setId_c(int newId_c);
};

#endif // INTERACTION_H

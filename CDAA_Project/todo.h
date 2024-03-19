/**
 * @file todo.h
 * @brief Définition de la classe Todo pour gérer les tâches à faire.
 */
#ifndef TODO_H
#define TODO_H
#include <string>
#include "sdateauto.h"
#include <iomanip>
using namespace std;

/**
 * @class Todo
 * @brief Classe représentant une tâche à faire (todo).
 */
class Todo
{
public:
    Todo();
    /**
         * @brief Constructeur de la classe Todo avec une tâche et une date.
         * @param task La tâche à faire.
         * @param date La date prévue pour la tâche.
         */
    Todo(string task,string date);
    /**
        * @brief Obtient la description de la tâche.
        * @return La description de la tâche.
        */
    string getTask() const ;
    /**
         * @brief Obtient la date courante de la tâche.
         * @return Une référence à la date courante de la tâche.
         */
     sdateAuto& getDateCourante() ;
     /**
         * @brief Obtient la date prévue pour la tâche.
         * @return La date prévue pour la tâche.
         */
     string getDatePrevu();
     /**
         * @brief Surcharge de l'opérateur de sortie pour afficher une tâche (todo).
         * @param os Le flux de sortie.
         * @param t La tâche à afficher.
         * @return Le flux de sortie modifié.
         */
    friend std::ostream& operator<<(ostream &,Todo &);
    /**
         * @brief Constructeur de la classe Todo avec une description de tâche.
         * La date courante est automatiquement définie.
         * @param task La description de la tâche.
         */
     Todo(const string& task);
     /**
          * @brief Définit la date prévue pour la tâche.
          * @param DatePrevue La date prévue au format "jj/mm/aaaa".
          */
     void setDate(string datePrevue);
     /**
      * @brief Extrait une date au format "jj/mm/aaaa" à partir d'une chaîne de caractères.
      *
      * Cette fonction tente d'extraire une date valide au format "jj/mm/aaaa" à partir d'une chaîne de caractères.
      *
      * @param dateStr La chaîne de caractères contenant la date au format "jj/mm/aaaa".
      * @return True si la date a pu être extraite avec succès, sinon False.
      */
     bool extraireDate(const string &dateStr);
     /**
          * @brief Convertit la tâche en une chaîne de caractères.
          * @return La tâche convertie en une chaîne de caractères au format Doxygen.
          */
     string toString();

     /**
      * @brief Convertit la date courante en une chaîne de caractères.
      * @return La date courante convertie en une chaîne de caractères au format "jj/mm/aaaa".
      */
     string toStringDateCourante();
     void convertirDateEnString();

     void setTask( string newTask);

     int getNum_contact() const;
     void setNum_contact(int newNum_contact);

     int getNum_interaction() const;
     void setNum_interaction(int newNum_interaction);
     void convertDate();

 private:
    string task;///< Description de la tâche.
    sdateAuto dateCourante;///< Date courante de la tâche.
    string datePrevu;///< Date prévue pour la tâche.
    int num_contact;
    int num_interaction;
};

#endif // TODO_H

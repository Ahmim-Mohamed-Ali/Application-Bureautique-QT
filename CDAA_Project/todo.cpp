#include "todo.h"
#include <string>
#include <sdateauto.h>
#include <ostream>
#include <iostream>




Todo::Todo(const string &Task)
{
    day_point dp = floor<days>(system_clock::now());
    auto amj = year_month_day{dp};
    this->dateCourante.jour = amj.day();
    this->dateCourante.mois = amj.month();
    this->dateCourante.annee = amj.year();
    this->task=Task;
    convertirDateEnString();
        convertDate();
}

Todo::Todo(std::string task,string datePrevue)
{
    this->task=task;
    setDate(datePrevue);
}
Todo::Todo(){}

void Todo::convertirDateEnString() {
    // Convertissez les composants de la date en une chaîne de caractères
    std::stringstream dateStr;
    dateStr << std::setw(2) << dateCourante.jour << "/"
            << std::setw(2) << std::setfill('0') << dateCourante.mois << "/"
            << dateCourante.annee;

    // Obtenez la chaîne de caractères résultante
    datePrevu = dateStr.str();

}

void Todo::setTask( string newTask)
{
    task = newTask;
}

int Todo::getNum_contact() const
{
    return num_contact;
}

void Todo::setNum_contact(int newNum_contact)
{
    num_contact = newNum_contact;
}

int Todo::getNum_interaction() const
{
    return num_interaction;
}

void Todo::setNum_interaction(int newNum_interaction)
{
    num_interaction = newNum_interaction;
}
string Todo::getTask() const{
    return task;
}

string Todo::getDatePrevu(){
    return datePrevu;
}

sdateAuto& Todo::getDateCourante(){
    return dateCourante;
}

void Todo::setDate(std::string DatePrevue){


      this->datePrevu=DatePrevue;


}

std::ostream& operator<<(std::ostream & os,Todo & i)
{

    if(i.datePrevu.empty()){
        os << "@Todo "<< i.getTask() << " @date " << i.toStringDateCourante();
    }
    else{
        os << "@Todo "<< i.getTask()<<" @date "<<i.getDatePrevu();
    }

return os;
}


bool Todo::extraireDate(const std::string &dateStr) {
    if (dateStr.length() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
        return false; // Le format n'est pas "jj/mm/aaaa"
    }

    try {
        int jour = std::stoi(dateStr.substr(0, 2));
        int mois = std::stoi(dateStr.substr(3, 2));
        int annee = std::stoi(dateStr.substr(6, 4));

        // Vérifiez si le jour, le mois et l'année sont valides
        if (jour >= 1 && jour <= 31 &&
            mois >= 1 && mois <= 12 &&
            annee >= 2000 && annee <= 2099) {
            return true; // La date est valide
        }
    } catch (const std::exception &e) {
        // Erreur de conversion
    }

    return false; // La date n'est pas valide
}

string Todo::toStringDateCourante()
{
    return std::to_string(static_cast<unsigned int>(this->dateCourante.jour)) + "/" +
            std::to_string(static_cast<unsigned int>(this->dateCourante.mois)) + "/" +
            std::to_string(static_cast<int>(this->dateCourante.annee));
}

string Todo::toString(){
    string contenu;
    if(this->datePrevu.empty()){
        contenu="@Todo "+this->getTask()+" @date "+this->toStringDateCourante();
    }
    else{
        contenu= "@Todo "+ this->getTask()+" @date "+this->getDatePrevu();
    }
    return contenu;
}



void Todo::convertDate(){
    const std::string moisNoms[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    // Extraction du jour, du mois et de l'année
    std::string jourStr = datePrevu.substr(0, 2);
    std::string moisStr = datePrevu.substr(4, 3); // Extraction des 3 caractères du mois
    std::string anneeStr = datePrevu.substr(8, 4);

    // Conversion du mois en format numérique
    int moisNum = -1;
    for (int i = 0; i < 12; ++i) {
        if (moisStr == moisNoms[i]) {
            moisNum = i + 1; // Les mois commencent à 1
            break;
        }
    }

    // Vérification de la validité du mois
    if (moisNum != -1) {
        // Construction de la nouvelle date au format "08/12/2022"
        std::string nouvelleDate = jourStr + "/" + std::to_string(moisNum) + "/" + anneeStr;
        setDate(nouvelleDate);
    } else {
        // Gestion de l'erreur si le mois n'est pas valide
        // (par exemple, affichage d'un message d'erreur)
    }
}

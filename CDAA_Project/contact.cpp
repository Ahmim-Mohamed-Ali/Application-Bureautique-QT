#include "contact.h"
#include <list>
#include <iostream>


std::string Contact::getNom() const
{
    return nom;
}


void Contact::convertirDateEnString() {
    // Convertissez les composants de la date en une chaîne de caractères
    std::stringstream dateStr;
    dateStr << std::setw(2) << date.jour << "/"
            << std::setw(2) << std::setfill('0') << date.mois << "/"
            << date.annee;

    // Obtenez la chaîne de caractères résultante
    dateEdition = dateStr.str();
    dateCreation=dateStr.str();
}
void Contact::setNom(const std::string &newNom)
{
    nom = newNom;
}

std::string Contact::getPrenom() const
{
    return prenom;
}

void Contact::setPrenom(const std::string &newPrenom)
{
    prenom = newPrenom;
}

std::string Contact::getEntreprise() const
{
    return entreprise;
}

void Contact::setEntreprise(const std::string &newEntreprise)
{
    entreprise = newEntreprise;
}

std::string Contact::getMail() const
{
    return mail;
}

void Contact::setMail(const std::string &newMail)
{
    mail = newMail;
}

std::string Contact::getTelephone() const
{
    return telephone;
}

void Contact::setTelephone(const std::string &newTelephone)
{
    telephone = newTelephone;
}

std::string Contact::getUrlPhoto() const
{
    return urlPhoto;
}

void Contact::setUrlPhoto(const std::string &newUriPhoto)
{
    urlPhoto = newUriPhoto;
}

string Contact::getDateCreation() const
{
    return dateCreation;
}

void Contact::setDateCreation(const string &newDateCreation)
{
    dateCreation = newDateCreation;
}



vector<Interaction>* Contact::getListe_inter()
{
    return &liste_inter;
}

void Contact::setId_c(int newId_c)
{
    id_c = newId_c;
}

string Contact::getDateEdition() const
{
    return dateEdition;
}

void Contact::setDateEdition( string newDateEdition)
{
    dateEdition = newDateEdition;
}

Contact::Contact(){
    this->mail="";
    this->nom="";
    this->urlPhoto="";
    this->telephone="";
    this->entreprise="";
    this->prenom="";
    this->dateCreation="";
    day_point dp = floor<days>(system_clock::now());
    auto amj = year_month_day{dp};
    this->date.jour = amj.day();

    this->date.mois = amj.month();
    this->date.annee = amj.year();
    convertirDateEnString();
    convertDate();

}

Contact::Contact( std::string nom,  std::string prenom,  std::string entreprise,  std::string mail,  std::string telephone,  std::string photo)
{
    this->mail=mail;
    this->nom=nom;
    this->urlPhoto=photo;
    this->telephone=telephone;
    this->entreprise=entreprise;
    this->prenom=prenom;
    this->liste_inter=std::vector<Interaction>();
    convertirDateEnString();
    convertDate();
}



int Contact::getId_C(){
    return this->id_c;
}




/**
 * @brief Obtient une interaction du contact.
 * @param id_i ID de l'interaction à obtenir.
 * @return L'interaction correspondant à l'ID spécifié.
 */
Interaction* Contact::getInteraction(int id_i){
    for(int i=0;i<static_cast<int>(this->liste_inter.size());i++){
        if(liste_inter.at(i).getId_i()==id_i){
            return (&liste_inter.at(i));
        }

    }
    return nullptr;

}
/**
 * @brief Obtient un pointeur vers une interaction du contact.
 * @param id_i ID de l'interaction à obtenir.
 * @return Pointeur vers l'interaction correspondant à l'ID spécifié.
 */
Interaction* Contact::getPointerInteraction(int id_i){
    for(int i=0;i<static_cast<int>(this->liste_inter.size());i++){
        if(liste_inter.at(i).getId_i()==id_i){
            return &(liste_inter.at(i));
        }
    }
    return nullptr;
}

/**
 * @brief Affiche la liste des interactions du contact.
 */
void Contact::AfficherInteractions(){
    for(int i=0;i<static_cast<int>(this->liste_inter.size());i++){
        std::cout<<liste_inter.at(i)<<std::endl;
    }

}


void Contact::convertDate(){
    const std::string moisNoms[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    // Extraction du jour, du mois et de l'année
    std::string jourStr = dateEdition.substr(0, 2);
    std::string moisStr = dateEdition.substr(4, 3); // Extraction des 3 caractères du mois
    std::string anneeStr = dateEdition.substr(8, 4);

    qDebug()<<"date recup"<<jourStr<<moisStr<<anneeStr;
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
        setDateCreation(nouvelleDate);
        setDateEdition(nouvelleDate);
    } else {
        // Gestion de l'erreur si le mois n'est pas valide
        // (par exemple, affichage d'un message d'erreur)
    }
}







#include "interaction.h"
#include <ctime>
#include "sdateauto.h"
#include <QDebug>

int Interaction::getId_i() const
{
    return id_i;
}
/**
 * @brief Obtient un pointeur vers la liste des todos associés à l'interaction.
 * @return Pointeur vers la liste des todos.
 */
vector<Todo>* Interaction::getLesTodos()
{
    return &lesTodos;
}
/**
 * @brief Définit l'ID de l'interaction.
 * @param newId_i Le nouvel ID de l'interaction.
 */
void Interaction::setId_i(int newId_i)
{
    id_i = newId_i;
}
/**
 * @brief Constructeur par défaut de la classe Interaction.
 * Par défaut, la date est définie à la date courante et le contenu est "NULL".
 */
string Interaction::getDateEdition() const
{
    return dateEdition;
}

Interaction::Interaction()
{
    // Obtient la date courante
    day_point dp = floor<days>(system_clock::now());
    auto amj = year_month_day{dp};
    this->date.jour = amj.day();
    this->date.mois = amj.month();
    this->date.annee = amj.year();
    this->setContenu("NULL");
        convertirDateEnString();
    convertDate();
     this->lesTodos = vector<Todo>();
}

/**
 * @brief Constructeur de la classe Interaction avec contenu initial.
 * @param c Contenu initial de l'interaction.
 */
Interaction::Interaction(const std::string & c)
{
    this->setContenu(c);
    // Obtient la date courante
    day_point dp = floor<days>(system_clock::now());
    auto amj = year_month_day{dp};
    this->date.jour = amj.day();
    this->date.mois = amj.month();
    this->date.annee = amj.year();

    convertirDateEnString();
    convertDate();
    this->lesTodos = vector<Todo>();
}
/**
 * @brief Destructeur de la classe Interaction.
 */
Interaction::~Interaction()
{
}

struct sdateAuto Interaction::getDate() const
{
    return date;
}


day Interaction::getJour() const
{
    return date.jour;
}


month Interaction::getMois() const
{
    return date.mois;
}

year Interaction::getAnnee() const
{
    return date.annee;
}


std::string Interaction::getContenu() const
{
    return contenu;
}

void Interaction::setDate(const struct sdateAuto & d)
{
    date.jour = d.jour;
    date.mois = d.mois;
    date.annee = d.annee;
}

void Interaction::setContenu(const std::string & c)
{
    contenu = c;
}

std::ostream& operator<<(std::ostream & os, const Interaction  i)
{
    os << "Interaction numero " << i.getId_i()<<" "<<i.getContenu();
    return os;
}

void Interaction::AddTodo(Todo d){
     this->setContenu(this->getContenu() + "\n" + "@todo "+d.getTask()+"@date "+d.getDatePrevu()+"\n");
    this->getLesTodos()->push_back(d);
}


void Interaction::AfficherTodo(){
    for(int i=0;i<static_cast<int>(this->lesTodos.size());i++){
        std::cout<<lesTodos.at(i)<<std::endl;
    }

}


void Interaction::setDateEdition( string newDateEdition)
{
    dateEdition = newDateEdition;
}

int Interaction::getId_c() const
{
    return id_c;
}

void Interaction::setId_c(int newId_c)
{
    id_c = newId_c;
}

void Interaction::convertirDateEnString() {
    // Convertissez les composants de la date en une chaîne de caractères
    std::stringstream dateStr;
    dateStr << std::setw(2)<<date.jour<<"/"<<std::setw(2)<<std::setfill('0')<<date.mois<<"/"<<date.annee;

    // Obtenez la chaîne de caractères résultante
    dateEdition = dateStr.str();

}

void Interaction::convertDate(){
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
        setDateEdition(nouvelleDate);
    } else {
        // Gestion de l'erreur si le mois n'est pas valide
        // (par exemple, affichage d'un message d'erreur)
    }
}



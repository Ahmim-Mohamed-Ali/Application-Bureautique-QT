#include "contact.h"
#include <QApplication>
#include <list>
#include <vector>
#include "interaction.h"
#include "gestionnaireinteraction.h"
#include "todo.h"
#include "associationinteraction.h"
#include <string>
#include "gestioncontacts.h"
#include "gestiontodo.h"
#include "gestionbd.h"
#include "mainwindow.h"
using namespace std;

/**
 * @brief Fonction principale du programme.
 * @param argc Nombre d'arguments en ligne de commande.
 * @param argv Tableau des arguments en ligne de commande.
 * @return Code de sortie de l'application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
 w.show();


    return a.exec();
}

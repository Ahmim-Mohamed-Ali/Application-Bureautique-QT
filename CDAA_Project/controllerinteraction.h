#ifndef CONTROLLERINTERACTION_H
#define CONTROLLERINTERACTION_H
#include "contact.h"
#include <QObject>
#include <QString>
#include "gestionnaireinteraction.h"
class ControllerInteraction : public QObject
{
    Q_OBJECT
public:
    explicit ControllerInteraction(QObject *parent = nullptr);
    void AjouterInteraction(QString contenue);
    void OuvrirPageInteraction(std::string contenue,std::string date);
    void GetAllInteraction_Date(std::string date_deb,std::string date_fin);

    Contact *getC() const;
    void setC(Contact *newC);

signals:
    void AjoutInteraction();
    void signalOuvrirPageInteraction(Interaction* interact);

private:
    Contact* c;
};

#endif // CONTROLLERINTERACTION_H

#ifndef CONTROLLERTODO_H
#define CONTROLLERTODO_H
#include "interaction.h"
#include "todo.h"
#include <QObject>
#include "gestiontodo.h"
class ControllerTodo : public QObject
{
    Q_OBJECT
public:
    explicit ControllerTodo(QObject *parent = nullptr);
    void AjouterTodo(QString contenue,QString date);
    void AjouterTodo_Date(QString contenue);
    Interaction *getI() const;
    void setI(Interaction *newI);
    Contact *getC() const;
    void setC(Contact *newC);
    void GetAllOfTodo_ByIntervalle(std::string dateDebut,std::string dateFin);
    void GetAllOfTodo_ByIntervalle_Contact(std::string dateDebut,std::string dateFin,int idContact);

signals:
    void AjoutTodo();
    void signalUpdateAllTodo();

private:
    Interaction* i;
    Contact* c;
};

#endif // CONTROLLERTODO_H

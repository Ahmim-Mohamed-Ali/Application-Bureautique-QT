#ifndef PAGECONTACT_H
#define PAGECONTACT_H
#include <QMainWindow>
#include "controllercontact.h"
#include <QWidget>
#include <QObject>
#include <QPixmap>
#include <QMessageBox>
#include "widgetmodifycontact.h"
#include "widgetaddinteraction.h"
#include "controllerinteraction.h"
#include "widgetinteractionpage.h"
namespace Ui {
class PageContact;
}

class PageContact : public QMainWindow
{
    Q_OBJECT

public:
    explicit PageContact(ControllerContact* cc,QWidget *parent = nullptr);
    ~PageContact();


public slots:
    void OuvrirPageContact(Contact c);
    void DeletePageContact();
    void ModifyContact();
    void ListerInteractions();
    void LancerWidgetAddInteraction();
    void UpdateInteractions();
    void AfficherPageInteraction(int row ,int col);

private slots:
    void on_actionSupprimer_La_Fiche_triggered();

    void on_actionModifier_La_Fiche_triggered();

    void on_actionAjouter_Une_Interaction_triggered();

    void on_actionLister_Les_Interactions_triggered();

    void on_actionRecherche_Interaction_triggered();

private:
    Ui::PageContact *ui;
    ControllerContact* cc;
    WidgetModifyContact* mc;
    WidgetAddInteraction* ai;
    ControllerInteraction* ci;
    WidgetInteractionPage* pi;
    int id_contact;
};

#endif // PAGECONTACT_H

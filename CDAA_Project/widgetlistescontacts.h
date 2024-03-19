#ifndef WIDGETLISTESCONTACTS_H
#define WIDGETLISTESCONTACTS_H
#include "controllercontact.h"
#include "gestioncontacts.h"
#include <QWidget>
#include <QDebug>
#include "pagecontact.h"
#include <QMainWindow>

namespace Ui {
class WidgetListesContacts;
}

class WidgetListesContacts : public QMainWindow
{
    Q_OBJECT

public:
    explicit WidgetListesContacts(ControllerContact* cc,QWidget *parent = nullptr);
    ~WidgetListesContacts();

public slots:
    void mettreAJourListeContacts();
    void RechercheContact();
    void AfficherPageContact(int row,int col);
    void RechercheParIntervalles();

private slots:
    void on_actionTrier_Par_Ordre_Alphabetique_triggered();

    void on_actionTrier_Par_Date_De_Creation_triggered();

private:
    Ui::WidgetListesContacts *ui;
    ControllerContact* cc;
    PageContact* pcc;
};

#endif // WIDGETLISTESCONTACTS_H

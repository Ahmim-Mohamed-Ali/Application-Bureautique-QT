#ifndef WIDGETLISTECONTACTS_H
#define WIDGETLISTECONTACTS_H
#include "controllercontact.h"
#include "gestioncontacts.h"
#include <QWidget>
#include <QDebug>

#include "pagecontact.h"
namespace Ui {
class WidgetListeContacts;
}

class WidgetListeContacts : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetListeContacts(ControllerContact* cc,QWidget *parent = nullptr);
    ~WidgetListeContacts();

public slots:
    void mettreAJourListeContacts();
    void RechercheContact();
    void AfficherPageContact(int row,int col);
private:
    Ui::WidgetListeContacts *ui;
    ControllerContact* cc;
    PageContact* pcc;
};

#endif // WIDGETLISTECONTACTS_H

#ifndef WIDGETMODIFYCONTACT_H
#define WIDGETMODIFYCONTACT_H
#include "controllercontact.h"
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
class WidgetModifyContact;
}

class WidgetModifyContact : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetModifyContact(ControllerContact* cc,QWidget *parent = nullptr);
    ~WidgetModifyContact();
public slots:
    void AfficheInfoContact(Contact c);
    void ModifierContact();
    void ModifyPhoto();
private:
    Ui::WidgetModifyContact *ui;
    ControllerContact* cc;
};

#endif // WIDGETMODIFYCONTACT_H

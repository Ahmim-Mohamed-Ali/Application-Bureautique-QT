#ifndef CREERCONTACT_H
#define CREERCONTACT_H
#include "controllercontact.h"
#include <QWidget>
#include <QFileDialog>
namespace Ui {
class CreerContact;
}

class CreerContact : public QWidget
{
    Q_OBJECT

public:
    explicit CreerContact(QWidget *parent = nullptr);
    ~CreerContact();
    CreerContact(ControllerContact* controllerContact, QWidget* parent=nullptr);
public slots:
    void VerifierContact();
    void VerifPhoto();

private:
    ControllerContact* cc;
        Ui::CreerContact *ui;
};

#endif // CREERCONTACT_H

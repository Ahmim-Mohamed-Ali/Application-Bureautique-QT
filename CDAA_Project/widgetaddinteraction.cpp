#include "widgetaddinteraction.h"
#include "ui_widgetaddinteraction.h"

WidgetAddInteraction::WidgetAddInteraction(ControllerInteraction* controllerInteract,QWidget *parent) :
    QWidget(parent),ci(controllerInteract),
    ui(new Ui::WidgetAddInteraction)
{   ui->setupUi(this);
    connect(ui->Add,SIGNAL(clicked(bool)),this,SLOT(AddInteraction()));

}

WidgetAddInteraction::~WidgetAddInteraction()
{
    delete ui;
}


void WidgetAddInteraction::AddInteraction(){
    QString contenue = ui->Contenu->toPlainText();
    ci->AjouterInteraction(contenue);
    this->close();
}

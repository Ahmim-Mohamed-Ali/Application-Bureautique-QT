#include "widgetaddtodo.h"
#include "ui_widgetaddtodo.h"

WidgetAddTodo::WidgetAddTodo(ControllerTodo* ct,QWidget *parent) :
    QWidget(parent),td{ct},
    ui(new Ui::WidgetAddTodo)
{
    ui->setupUi(this);
     connect(ui->Add, SIGNAL(clicked()), this, SLOT(entreeTexte()));
}

WidgetAddTodo::~WidgetAddTodo()
{
    delete ui;
}

void WidgetAddTodo::entreeTexte(){
    QTextDocument * qdoc = ui->Contenu->document();
    QTextCursor c=ui->Contenu->textCursor();
    c.setPosition(0);
    ui->Contenu->setTextCursor(c);


    c = qdoc->find("@todo", c.position());

    if (!c.isNull() && !c.atEnd()) {
        // Affichez la position du curseur

        c.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);

        // Déplacez le curseur vers la droite pour sélectionner le texte après "@todo"
        c.movePosition(QTextCursor::WordRight, QTextCursor::KeepAnchor);
        QString texteApresCurseur = c.selectedText().trimmed();
        texteApresCurseur.remove("@todo");

        int positionDate = texteApresCurseur.indexOf("@date");

        if (positionDate != -1) {
            // S'il y a une date, récupérez le contenu et la date
            QString contenuTodo = texteApresCurseur.left(positionDate).trimmed();
            QString dateTodo = texteApresCurseur.mid(positionDate + 5).trimmed(); // 5 est la longueur de "@date"
           td->AjouterTodo(contenuTodo,dateTodo);
             QMessageBox::warning(this, "Todo Crée", "Un Todo à été crée Avec La Date");
            this->close();
        }
        else {
        // Le texte n'a pas été trouvé
             QString contenuTodo = texteApresCurseur.trimmed();
            td->AjouterTodo_Date(contenuTodo);
        QMessageBox::warning(this, "Aucune Date Trouvé", "Un Todo à été crée Avec La Date Du Jour");
            this->close();
        }
    }
    else{
        QMessageBox::warning(this, "Aucun @Todo Trouvé", "Vous N'avez pas créer de todo");
        this->close();
    }
    c.setPosition(0);
    ui->Contenu->setTextCursor(c);
}

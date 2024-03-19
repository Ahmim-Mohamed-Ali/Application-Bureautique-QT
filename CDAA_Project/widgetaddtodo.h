#ifndef WIDGETADDTODO_H
#define WIDGETADDTODO_H
#include <QMessageBox>
#include <QWidget>
#include "todo.h"
#include "controllertodo.h"
namespace Ui {
class WidgetAddTodo;
}

class WidgetAddTodo : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAddTodo(ControllerTodo* ct,QWidget *parent = nullptr);
    ~WidgetAddTodo();
public slots:
    void entreeTexte();
private:
    Ui::WidgetAddTodo *ui;
    ControllerTodo* td;

};

#endif // WIDGETADDTODO_H

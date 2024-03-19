#ifndef WIDGETINTERACTIONPAGE_H
#define WIDGETINTERACTIONPAGE_H
#include "controllerinteraction.h"
#include <QMainWindow>
#include "widgetaddtodo.h"
namespace Ui {
class WidgetInteractionPage;
}

class WidgetInteractionPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WidgetInteractionPage(ControllerInteraction* controllerInteraction,QWidget *parent = nullptr);
    ~WidgetInteractionPage();

public slots:
    void OuvrirPageInteraction(Interaction* interact);

private slots:
    void on_actionAjouter_Todo_triggered();
    void RefreshInteraction();
private:
    Ui::WidgetInteractionPage *ui;
    ControllerInteraction* ci;   ControllerTodo* ct;
    WidgetAddTodo* ad;
};

#endif // WIDGETINTERACTIONPAGE_H

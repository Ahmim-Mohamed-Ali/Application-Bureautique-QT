#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "controllercontact.h"
#include <QMainWindow>
#include "creercontact.h"
#include "widgetlistescontacts.h"
#include "controllertodo.h"
#include "controllerinteraction.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_actionAjouter_Un_Contact_2_triggered();
    void CollectAllTodo();
    void on_actionLister_Les_Contacts_2_triggered();
    void CollectAllInteraction();
    void UpdateTodoList();

    void on_actionExport_Json_triggered();

private:
    Ui::MainWindow *ui;
    CreerContact* cc;
    ControllerContact* controllerContact;
     ControllerTodo* controllerTodo;
    WidgetListesContacts* lc ;
};

#endif // MAINWINDOW_H

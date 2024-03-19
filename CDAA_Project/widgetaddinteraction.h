#ifndef WIDGETADDINTERACTION_H
#define WIDGETADDINTERACTION_H
#include "controllerinteraction.h"
#include <QWidget>

namespace Ui {
class WidgetAddInteraction;
}

class WidgetAddInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAddInteraction(ControllerInteraction* ci,QWidget *parent = nullptr);
    ~WidgetAddInteraction();
public slots:
    void AddInteraction();
private:
    Ui::WidgetAddInteraction *ui;
    ControllerInteraction* ci;
};

#endif // WIDGETADDINTERACTION_H

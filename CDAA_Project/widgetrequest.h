#ifndef WIDGETREQUEST_H
#define WIDGETREQUEST_H

#include <QWidget>

namespace Ui {
class WidgetRequest;
}

class WidgetRequest : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRequest(QWidget *parent = nullptr);
    ~WidgetRequest();

private:
    Ui::WidgetRequest *ui;
};

#endif // WIDGETREQUEST_H

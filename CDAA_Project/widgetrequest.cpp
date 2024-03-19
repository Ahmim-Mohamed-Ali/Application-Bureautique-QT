#include "widgetrequest.h"
#include "ui_widgetrequest.h"

WidgetRequest::WidgetRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRequest)
{
    ui->setupUi(this);
}

WidgetRequest::~WidgetRequest()
{
    delete ui;
}

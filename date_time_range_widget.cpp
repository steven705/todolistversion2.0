#include "date_time_range_widget.h"
#include "ui_date_time_range_widget.h"

DateTimeRangeWidget::DateTimeRangeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateTimeRangeWidget)
{
    ui->setupUi(this);
    initPage();
}

DateTimeRangeWidget::~DateTimeRangeWidget()
{
    delete ui;
}

void DateTimeRangeWidget::initPage()
{
    connect(ui->btnYes, &QPushButton::clicked, this, [this] {

        QString start = ui->wdgStart->datetime();
        //QString end = ui->wdgEnd->datetime();

        //emit signal_dateTime(QString("%1 - %2").arg(start).arg(end));
        emit signal_dateTime(QString("%1").arg(start));
    });

    connect(ui->btnCancel, &QPushButton::clicked, this, [this] {
        emit signal_cancel();
    });

    QDateTime date = QDateTime::currentDateTime();
    //ui->wdgStart->setDateTime(date.toString("yyyy-MM-dd hh:mm:ss"));
    ui->wdgStart->setDateTime("开始时间：");
}

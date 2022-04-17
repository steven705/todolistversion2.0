/********************************************************************************
** Form generated from reading UI file 'date_time.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_TIME_H
#define UI_DATE_TIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTime
{
public:
    QVBoxLayout *verticalLayout_6;
    QWidget *WidgetMain;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetDate;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QDateEdit *dateEdit;
    QCalendarWidget *calendarWidget;
    QWidget *widgetTime;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetHour;
    QWidget *widgetMin;

    void setupUi(QWidget *DateTime)
    {
        if (DateTime->objectName().isEmpty())
            DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->resize(244, 470);
        verticalLayout_6 = new QVBoxLayout(DateTime);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        WidgetMain = new QWidget(DateTime);
        WidgetMain->setObjectName(QString::fromUtf8("WidgetMain"));
        WidgetMain->setStyleSheet(QString::fromUtf8("QWidget#WidgetMain{\n"
"background:#FFFFFF;\n"
"}\n"
"QWidget#widgetDate,#widgetTime{\n"
"border-bottom:1px solid #A7B7CE;\n"
"}\n"
"\n"
"QTimeEdit,QDateEdit{\n"
"border:1px solid #B9D2E2;\n"
"color:#43464B;\n"
"font-size:12pt;\n"
"}\n"
"\n"
"QPushButton#btnYes{\n"
"border:0px;\n"
"color:#0092FF;\n"
"font-size:11pt;\n"
"background: transparent;\n"
"}\n"
"QPushButton#btnCancel{\n"
"border:0px;\n"
"color:#34445B;\n"
"font-size:11pt;\n"
"background: transparent;\n"
"}\n"
"\n"
"/**\344\270\212\345\261\202\345\271\264\346\234\210\345\257\274\350\210\252\346\240\217**/\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar{ \n"
"background-color: #FFFFFF;\n"
"height:30px;\n"
"}\n"
"\n"
"/**\345\271\264\346\234\210\351\200\211\346\213\251\346\214\211\351\222\256**/\n"
"QToolButton#qt_calendar_monthbutton,#qt_calendar_yearbutton{\n"
"color:#43464B;\n"
"font-size:11pt;\n"
"border:0px;\n"
"background-color: #FFFFFF;\n"
"}\n"
"QToolButton#qt_calendar_monthbutton:hover,#qt_calendar_yearbutton:hover{\n"
"color:#43464B;\n"
""
                        "font-size:11pt;\n"
"height:15px;\n"
"background-color: #FFFFFF;\n"
"}\n"
"/**\350\256\276\347\275\256\346\234\210\344\273\275\351\200\211\346\213\251\344\270\213\346\213\211\346\214\211\351\222\256\345\261\205\344\270\255**/\n"
"QToolButton#qt_calendar_monthbutton::menu-indicator{\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: center right;\n"
"right: 3px;\n"
"width: 10px;\n"
"}\n"
"/**\346\234\210\344\273\275\345\211\215 \345\220\216\346\214\211\351\222\256**/\n"
"QToolButton#qt_calendar_prevmonth{\n"
"icon-size:20px 20px;\n"
"border:0px;\n"
"qproperty-icon:url(:/month-earlier.png);\n"
"background: transparent;\n"
"}\n"
"QToolButton#qt_calendar_nextmonth{\n"
"icon-size:20px 20px;\n"
"border:0px;\n"
"qproperty-icon:url(:/month-later.png);\n"
"background: transparent;\n"
"}\n"
"\n"
"QCalendarWidget QMenu{\n"
"width:100px;\n"
"color:#43464B;\n"
"left:10px;\n"
"font-size:10pt;\n"
"background-color:#FFFFFF;\n"
"border:1px solid #EFF4F8;\n"
"}\n"
"\n"
"QCalendarWidget QMenu QAction{\n"
"width: 100px;\n"
""
                        "color: #43464B;\n"
"font-size: 12pt;\n"
"background-color: #FFFFFF;\n"
"}\n"
"QCalendarWidget QMenu QAction:hover{\n"
"color:#FFFFFF;\n"
"background-color: #0092FF;\n"
"}\n"
"QCalendarWidget QWidget{ \n"
"alternate-background-color: #FFFFFF;\n"
"border-bottom:1px solid #EFF4F8;\n"
"}\n"
"QHeaderView#qt_scrollarea_vcontainer{\n"
"background-color: #FF1111;\n"
"}\n"
"QCalendarWidget QAbstractItemView:enabled \n"
"{\n"
"font-size:14px; \n"
"color: #34445B; \n"
"selection-background-color: #0092FF; \n"
"selection-color: #FFFFFF;\n"
"}\n"
"/* days in other months */\n"
"QCalendarWidget QAbstractItemView:disabled { \n"
"color:#C7C7C7; \n"
"}\n"
""));
        horizontalLayout_4 = new QHBoxLayout(WidgetMain);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widgetDate = new QWidget(WidgetMain);
        widgetDate->setObjectName(QString::fromUtf8("widgetDate"));
        verticalLayout_2 = new QVBoxLayout(widgetDate);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateEdit = new QDateEdit(widgetDate);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(0, 32));
        dateEdit->setMaximumSize(QSize(10000, 16777215));
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout->addWidget(dateEdit);

        calendarWidget = new QCalendarWidget(widgetDate);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(240, 230));
        calendarWidget->setSizeIncrement(QSize(240, 230));
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addWidget(widgetDate);

        widgetTime = new QWidget(WidgetMain);
        widgetTime->setObjectName(QString::fromUtf8("widgetTime"));
        verticalLayout_4 = new QVBoxLayout(widgetTime);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        timeEdit = new QTimeEdit(widgetTime);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setMinimumSize(QSize(240, 32));
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_3->addWidget(timeEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        widgetHour = new QWidget(widgetTime);
        widgetHour->setObjectName(QString::fromUtf8("widgetHour"));
        widgetHour->setMinimumSize(QSize(40, 140));
        widgetHour->setMaximumSize(QSize(40, 16777215));
        widgetHour->setSizeIncrement(QSize(40, 140));

        horizontalLayout->addWidget(widgetHour);

        widgetMin = new QWidget(widgetTime);
        widgetMin->setObjectName(QString::fromUtf8("widgetMin"));
        widgetMin->setMinimumSize(QSize(40, 140));
        widgetMin->setMaximumSize(QSize(40, 16777215));
        widgetMin->setSizeIncrement(QSize(40, 140));

        horizontalLayout->addWidget(widgetMin);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addWidget(widgetTime);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_6->addWidget(WidgetMain);


        retranslateUi(DateTime);
        QObject::connect(calendarWidget, SIGNAL(clicked(QDate)), dateEdit, SLOT(setDate(QDate)));
        QObject::connect(calendarWidget, SIGNAL(activated(QDate)), dateEdit, SLOT(setDate(QDate)));

        QMetaObject::connectSlotsByName(DateTime);
    } // setupUi

    void retranslateUi(QWidget *DateTime)
    {
        DateTime->setWindowTitle(QCoreApplication::translate("DateTime", "DateTime", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("DateTime", "H:mm:ss", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTime: public Ui_DateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_TIME_H

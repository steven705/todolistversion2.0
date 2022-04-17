/********************************************************************************
** Form generated from reading UI file 'date_time_range_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATE_TIME_RANGE_WIDGET_H
#define UI_DATE_TIME_RANGE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "date_time.h"

QT_BEGIN_NAMESPACE

class Ui_DateTimeRangeWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *wdgMain;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    DateTime *wdgStart;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCancel;
    QPushButton *btnYes;

    void setupUi(QWidget *DateTimeRangeWidget)
    {
        if (DateTimeRangeWidget->objectName().isEmpty())
            DateTimeRangeWidget->setObjectName(QString::fromUtf8("DateTimeRangeWidget"));
        DateTimeRangeWidget->resize(350, 500);
        DateTimeRangeWidget->setMinimumSize(QSize(250, 500));
        horizontalLayout_5 = new QHBoxLayout(DateTimeRangeWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        wdgMain = new QWidget(DateTimeRangeWidget);
        wdgMain->setObjectName(QString::fromUtf8("wdgMain"));
        horizontalLayout_4 = new QHBoxLayout(wdgMain);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wdgStart = new DateTime(wdgMain);
        wdgStart->setObjectName(QString::fromUtf8("wdgStart"));
        wdgStart->setMinimumSize(QSize(100, 470));

        horizontalLayout->addWidget(wdgStart);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnCancel = new QPushButton(wdgMain);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setEnabled(true);
        btnCancel->setMinimumSize(QSize(50, 32));
        btnCancel->setMaximumSize(QSize(32, 16777215));
        btnCancel->setBaseSize(QSize(32, 32));

        horizontalLayout_2->addWidget(btnCancel);

        btnYes = new QPushButton(wdgMain);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));
        btnYes->setMinimumSize(QSize(50, 32));
        btnYes->setMaximumSize(QSize(32, 16777215));

        horizontalLayout_2->addWidget(btnYes);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_5->addWidget(wdgMain);


        retranslateUi(DateTimeRangeWidget);

        QMetaObject::connectSlotsByName(DateTimeRangeWidget);
    } // setupUi

    void retranslateUi(QWidget *DateTimeRangeWidget)
    {
        DateTimeRangeWidget->setWindowTitle(QCoreApplication::translate("DateTimeRangeWidget", "Form", nullptr));
        btnCancel->setText(QCoreApplication::translate("DateTimeRangeWidget", "\345\217\226\346\266\210", nullptr));
        btnYes->setText(QCoreApplication::translate("DateTimeRangeWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTimeRangeWidget: public Ui_DateTimeRangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATE_TIME_RANGE_WIDGET_H

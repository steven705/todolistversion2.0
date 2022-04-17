/********************************************************************************
** Form generated from reading UI file 'thingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THINGSWIDGET_H
#define UI_THINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thingsWidget
{
public:
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *thingsWidget)
    {
        if (thingsWidget->objectName().isEmpty())
            thingsWidget->setObjectName(QString::fromUtf8("thingsWidget"));
        thingsWidget->resize(409, 687);
        graphicsView = new QGraphicsView(thingsWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 100, 391, 581));
        lineEdit = new QLineEdit(thingsWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 101, 51));
        dateEdit = new QDateEdit(thingsWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(110, 50, 291, 51));
        textEdit = new QTextEdit(thingsWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 391, 41));
        pushButton = new QPushButton(thingsWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 580, 91, 71));

        retranslateUi(thingsWidget);

        QMetaObject::connectSlotsByName(thingsWidget);
    } // setupUi

    void retranslateUi(QWidget *thingsWidget)
    {
        thingsWidget->setWindowTitle(QCoreApplication::translate("thingsWidget", "Widget", nullptr));
        lineEdit->setText(QCoreApplication::translate("thingsWidget", "\346\227\245\346\234\237\357\274\232", nullptr));
        textEdit->setHtml(QCoreApplication::translate("thingsWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:14pt;\">\344\273\212\346\227\245\344\272\213\351\241\271</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("thingsWidget", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thingsWidget: public Ui_thingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THINGSWIDGET_H

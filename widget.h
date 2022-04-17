#pragma once
#pragma execution_character_set("utf-8")
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"tdlcalendar.h"
#include"mysqlconnect.h"
#include"dbType.h"
#include"login.h"
#include"logon.h"
#include"showinf.h"
#include"thingswidget.h"
#include<QDate>
#include"dialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //登录部分
    void userLogin();

    //展示部分
    void userShowInf(QString name, QString password,int myCase);

    //注册部分
    void userLogon();

    //初始化函数
    void init();


private:
    Ui::Widget *ui;

    //辅助用于日期转换
    QDate changeFromStr(QString str);

    //日历界面
    Window * myCalwidget;

    //显示界面
    thingsWidget* myTodoWidget;

    //今天的查询结果
    QVector<todolist_ui_inf> nowEvent;


    mySqlConnect* myDb;
    logon* mylogon;//注册
    login* mylogin;//登录窗口
    ShowInf* showUserInf;//显示用户信息窗口


    Dialog* myShowEventDlg;//显示事件全部信息

    //用来登录的按钮
    QPushButton* mybtn;

    //0表示未登录 1表示登录了
    int nowCase;

    //当前的用户的信息
    tabel_userInf NowUser;


   
};
#endif // WIDGET_H

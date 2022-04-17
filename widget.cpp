#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1000,700);
    init();


    //获取当前日期进行显示
    QDateTime dt;
    QDate date;
    dt.setDate(date.currentDate());
    QString currentDate = dt.toString("yyyy-MM-dd");
    date = changeFromStr(currentDate);
    myTodoWidget->DateChanged(date);

    NowUser.userName = "";

    //初始化
    nowEvent = myDb->searchNowDayData(NowUser.userName, currentDate);
    //显示到界面上

    myTodoWidget->SetBtnText(nowEvent);


    //点击登录
    connect(mybtn, &QPushButton::clicked, [=]() {
        if (NowUser.userName == "")
        {
            userLogin();
        }
        else
        {
            userShowInf(NowUser.userName, NowUser.password,1);
        }

        });

    //接收日期
    connect(myCalwidget, &Window::sendDayToMain, [&](QString str) {
        //数据库查询
        QDate date = changeFromStr(str);
        myTodoWidget->DateChanged(date);
        

        //查询今天的事件
        

        //返回的是所有信息的结构体
        nowEvent= myDb->searchNowDayData(NowUser.userName, str);
        myTodoWidget->SetBtnText(nowEvent);

        //用户选择日期
        

        });


    //监视来自todolist窗口的信号
    connect(myTodoWidget, &thingsWidget::send, [&](int id) {

        myShowEventDlg = new Dialog;
        if (id == -1)
        {
            //添加信息
        }
        else
        {
            //myShowEventDlg->set(nowEvent[id]);
        }
        myShowEventDlg->show();
        //监控来自其信号 修改或者添加

        myShowEventDlg->exec();
        });

    //监视来自 显示日程信息的窗口
    //修改或者添加
    

}

//将str转换为Qdate
QDate Widget::changeFromStr(QString str)
{
    QStringList list = str.split("-");//QString字符串分割函数
    int year = list[0].toInt();
    int month = list[1].toInt();
    int day = list[2].toInt();
    QDate date(year, month, day);
    return date;
}
void Widget::init()
{
      myCalwidget=new Window(this);
      myTodoWidget =new thingsWidget(this);
      myTodoWidget->move(530,0);

      myDb=new mySqlConnect(this);
      if(myDb->connect())
      {
           QMessageBox::information(this, "infor", "success");
      }
      else
      {
             QMessageBox::information(this, "infor", "fail");
             //qDebug()<<"error open database because"<<db.lastError().text();
      }
      mybtn=new QPushButton(this);
      mybtn->move(930, 0);
     
}

//登录部分
void Widget::userLogin()
{
    mylogin = new login;
    mylogin->show();

    //显示信息
    connect(mylogin, &login::send, [&](QString name, QString password)
        {
            userShowInf(name, password,0);

        });

    //注册新用户
    connect(mylogin, &login::sendlogon, this, &Widget::userLogon);

}

//展示部分
void Widget::userShowInf(QString name, QString password,int myCase)
{
    //用数据库做一下验证
    //获得一下用户信息
    tabel_userInf myUser;
    bool isOk;
    //登录
    if (myCase == 0)
    {
        myUser.userName = name;
        myUser.password = password;
        isOk = myDb->login(myUser);
        //保存副本
        NowUser = myUser;
    }
    //显示
    else
    {
        myUser = NowUser;
        isOk = 1;
    }
    if (isOk)
    {
        

        mylogin->close();
        //调出新的窗口显示
        showUserInf = new ShowInf();
        QByteArray tmp = myUser.byteArray;
        showUserInf->set(myUser.userPetName, myUser.birthday, myUser.sex, myUser.note, myUser.suffix, tmp);
        //修改头像
        connect(showUserInf, &ShowInf::changedPic, [&](tabel_userInf tmpmyUser)
            {
                myUser.path = tmpmyUser.path;
                myUser.suffix = tmpmyUser.suffix;

                bool isOk = myDb->changeUserInf(myUser, 0);

               

            });
        //修改用户
        connect(showUserInf, &ShowInf::goingChangeUser, [=]()
            {
                showUserInf->close();
                mybtn->clicked(true);
            });
        //修改资料
        connect(showUserInf, &ShowInf::goingChangeInf, [=]()
            {
                mylogon = new logon;
                mylogon->set(myUser);
                mylogon->show();
                connect(mylogon, &logon::changedInf, [&](tabel_userInf tmpmyUser)
                    {
                        bool isOk = myDb->changeUserInf(tmpmyUser, 1);
                        if (isOk)
                        {
                            mylogon->close();
                            showUserInf->set(tmpmyUser.userPetName, tmpmyUser.birthday, tmpmyUser.sex, tmpmyUser.note, myUser.suffix, myUser.byteArray);
                        }
                        else
                        {
                            QMessageBox::information(NULL, "infor", "fail");
                        }
                    });
            });
        showUserInf->show();

    }
    else
    {
        //提示其重新输入
        mylogin->errorPrompt();
    }
}

//注册部分
void Widget::userLogon()
{
    mylogon = new logon;
    mylogon->show();
    mylogin->close();
    connect(mylogon, &logon::sendlogonInf, [&](tabel_userInf userInfToLogon)
        {
            bool st = myDb->logon(userInfToLogon);
            if (st)
            {
                mylogon->close();
                mybtn->clicked(true);
            }
            else
            {
                QMessageBox::information(this, "提示", "账户重命名");
            }
        });

}


Widget::~Widget()
{
    delete ui;
}


#include "thingswidget.h"
#include "ui_thingswidget.h"

const int EventMaxNum = 20;

thingsWidget::thingsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thingsWidget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    // 将部件添加到布局管理器中
    layout = new QGraphicsLinearLayout;
    layout->setOrientation(Qt::Vertical);

    for (int i = 0; i < EventMaxNum; i++) {
        MyPushButton* btn = new MyPushButton;
        // 设置大小
        btn->setFixedSize(this->width() - 70, this->height() / 10);
        QGraphicsProxyWidget* pushButtonProxy = scene->addWidget(btn);//添加到场景中
        layout->addItem((QGraphicsWidget*)pushButtonProxy);//添加到布局当中
        vec_btn.push_back(btn);// 添加到vec_btn中，管理
        btn->setText(QString::number(i + 1));
        btn->setmyID(i);
        connect(btn, &MyPushButton::clicked, this, &thingsWidget::sendClickedToMain);
    }
   
    // 创建图形部件，设置其为一个顶层窗口，然后在其上应用布局
    form = new QGraphicsWidget;
    form->setLayout(layout);
    //将部件添加到场景中
    scene->addItem(form);
    //显示视图窗口
    ui->graphicsView->show();
    connect(ui->pushButton, &QPushButton::clicked,
        this, &thingsWidget::on_pushButton_clicked);
}

void thingsWidget::SetBtnText(const QVector<todolist_ui_inf>& SerchEvent) {
    int TupleNum = SerchEvent.size();
    for (int i = 0; i < EventMaxNum; i++)
    {
        vec_btn[i]->hide();
    }
    for (int i = 0; i < TupleNum; i++) 
    {
        vec_btn[i]->setText(SerchEvent[i].EventTitle);
        vec_btn[i]->show();
    }
}


thingsWidget::~thingsWidget()
{
    delete ui;
}

/// <summary>
/// 点击加号出现添加信息窗口
/// </summary>
void thingsWidget::on_pushButton_clicked()
{

    emit send(-1);
}

/// <summary>
/// 设置标头日期
/// </summary>
/// <param name="date"> 传入的日期</param>
void thingsWidget::DateChanged(const QDate& date)
{
    ui->dateEdit->setDate(date);
}

//将点击信号传递至主窗口
void thingsWidget::sendClickedToMain() {
    MyPushButton* tmp = (MyPushButton*)sender();
    emit send(tmp->getmyID());
}

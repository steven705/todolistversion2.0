#include "mysqlconnect.h"
#include <QMessageBox>

mySqlConnect::mySqlConnect(QObject *parent) : QObject(parent)
{

}
//连接数据库
bool mySqlConnect::connect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("47.98.181.12");
    db.setPort(3306);
    db.setDatabaseName("todolist");
    db.setUserName("user_todolist");
    db.setPassword("15377619612Lzx@");
    if (db.open())
    {
        query=QSqlQuery(db);
        return true;
    }
    else
    {
        return false;
    }
}
 //用户验证
bool mySqlConnect::login(tabel_userInf& myUser)
{
	QString str = QString("select * from userInf where userName='%1' and userPassword= '%2'")
		.arg(myUser.userName).arg(myUser.password);
	query.exec(str);
	//只要有结果就查询成功了
	//同时将信息复制过来
	while (query.next())
	{
		//将信息复制过来
		myUser.userPetName= query.value(2).toString();
		myUser.birthday = query.value(3).toString();
		myUser.sex = query.value(4).toString();
		myUser.note = query.value(5).toString();
		myUser.suffix= query.value(6).toString();
		myUser.byteArray = query.value(7).toByteArray();
		return true;
	}
	return false;
}
//用户注册
bool mySqlConnect::logon(tabel_userInf myUser)
{
    //先看一下这个用户名是不是存在的
	//存在的话
	QString str = QString("select * from userInf where userName='%1'").arg(myUser.userName);
	query.exec(str);
	//只要有结果说明用户名被用了
	while (query.next())
	{
        return false;
	}

	//将照片以二进制流的方式存到数据库
	QByteArray data;
	QString path =myUser.path;
	QFile* file = new QFile(path); //fileName为二进制数据文件名  
	file->open(QIODevice::ReadOnly);
	data = file->readAll();
	file->close();
	QVariant var(data);
	

	QString strQSL = QString("insert into  userInf values('%1','%2','%3','%4','%5','%6','%7',?)")
        .arg(myUser.userName).arg(myUser.password).arg(myUser.userPetName).
		arg(myUser.birthday).arg(myUser.sex).arg(myUser.note).arg(myUser.suffix);
	query.prepare(strQSL);
	query.addBindValue(var);
	return query.exec();
}
//修改用户信息
//修改用户信息
bool mySqlConnect::changeUserInf(tabel_userInf& myUser, int i)
{
	bool st6 = true, st7 = true;
	//表示修改头像
	if (i == 0)
	{
		//将照片以二进制流的方式存到数据库
		QByteArray data;
		QString path = myUser.path;
		QFile* file = new QFile(path); //fileName为二进制数据文件名  
		file->open(QIODevice::ReadOnly);
		data = file->readAll();
		myUser.byteArray.clear();
		myUser.byteArray.squeeze();
		int t = data.size();
		myUser.byteArray.resize(t + 1000);
		myUser.byteArray = data;
		file->close();
		QVariant var(data);
		QString strQSL = QString("update userInf set userPicture= ? where userName='%1'").arg(myUser.userName);
		query.prepare(strQSL);
		query.addBindValue(var);
		st7 = query.exec();


		QString strQSL6 = QString("update userInf set suffix='%2' where userName='%1'").arg(myUser.userName).arg(myUser.suffix);
		st6 = query.exec(strQSL6);
	}





	//分别修改 这里是一个bug
	QString strQSL2 = QString("update userInf set userPetName='%2' where userName='%1'").arg(myUser.userName).arg(myUser.userPetName);
	bool st2 = query.exec(strQSL2);
	QString strQSL3 = QString("update userInf set userBirthday='%2' where userName='%1'").arg(myUser.userName).arg(myUser.birthday);
	bool st3 = query.exec(strQSL3);
	QString strQSL4 = QString("update userInf set userSex='%2' where userName='%1'").arg(myUser.userName).arg(myUser.sex);
	bool st4 = query.exec(strQSL4);
	QString strQSL5 = QString("update userInf set userNote='%2' where userName='%1'").arg(myUser.userName).arg(myUser.note);
	bool st5 = query.exec(strQSL5);



	return st2 && st3 && st4 && st5 && st6 && st7;

}

//添加新数据
bool mySqlConnect::addNewData(todolist_ui_inf myuiInf)
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("hh:mm:ss");

	QString strQSL = QString("insert into infTodo2 values('%1','%2','%3','%4','%5','%6','%7','%8','%9')")
		.arg(myuiInf.userName).arg(current_date).arg(myuiInf.BeginDT).arg(myuiInf.EndDT).
		arg(myuiInf.BeginT).arg(myuiInf.EndT).
		arg(myuiInf.EventTitle).arg(myuiInf.EventType).arg(myuiInf.Note);
	return query.exec(strQSL);
}

//
todolist_ui_inf mySqlConnect::searchEventData(QString nowUser, QString event, QString nowDay, int EventType)
{
	todolist_ui_inf ret;
	return ret;
}
//3
//根据传入的信息将数据从数据库删除  infToDoList 
//todolist_ui_inf& myuiInf 是ui界面传入的(显示详细信息的部分)
void mySqlConnect::deleteData(todolist_ui_inf& myuiInf)
{
	return;
}
//4
//根据传入的信息将数据从数据库修改  infToDoList 
//todolist_ui_inf& myuiInf 是ui界面传入的(显示详细信息的部分)
bool mySqlConnect::alterData(todolist_ui_inf& myuiInf)
{
	QString strQSL = QString("update infTodo2 set BeginDT ='%1',EndDT='%2',BeginT ='%3',EndT='%4',EventTitle='%5',EventType='%6',Note='%7'where userName='%8' and addTime='%9'")
		.arg(myuiInf.BeginDT).arg(myuiInf.EndDT).
		arg(myuiInf.BeginT).arg(myuiInf.EndT).
		arg(myuiInf.EventTitle).arg(myuiInf.EventType).arg(myuiInf.Note).
		arg(myuiInf.userName).arg(myuiInf.addTime);
	return query.exec(strQSL);
}

//查询当日事项的所有信息返回
QVector<todolist_ui_inf> mySqlConnect::searchNowDayData(QString nowUser,QString Nowday)
{
	QString str = QString("select * from infTodo2 where userName='%1' and '%2'>= BeginDT and '%2'<= EndDT").arg(nowUser).arg(Nowday);
	query.exec(str);
	
	QVector<todolist_ui_inf> ret;
	while (query.next())
	{
		todolist_ui_inf tmp;
		tmp.userName = query.value(0).toString();
		tmp.addTime = query.value(1).toString();
		tmp.BeginDT = query.value(2).toString();
		tmp.EndDT = query.value(3).toString();
		tmp.BeginT = query.value(4).toString();
		tmp.EndT = query.value(5).toString();
		tmp.EventTitle = query.value(6).toString();
		tmp.EventType = query.value(7).toInt();
		tmp.Note = query.value(8).toString();
		ret.push_back(tmp);
	}
	return ret;
}


//关闭数据库连接
void mySqlConnect::closeConnect()
{
    db.close();
}

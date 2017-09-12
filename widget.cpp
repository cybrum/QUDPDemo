#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),m_pUIInstance(new Ui::Widget)
{
    m_pUIInstance->setupUi(this);

    connect(m_pUIInstance->lineEdit,SIGNAL(returnPressed()),this, SLOT(writeMessage()));
    connect(m_pUIInstance->sendButton,SIGNAL(clicked()),this, SLOT(writeMessage()));
    connect(m_pUIInstance->listenButton,SIGNAL(clicked()),this, SLOT(listenMessage()));
    connect(m_pUIInstance->clearButton,SIGNAL(clicked()),this, SLOT(clearLog()));
    connect(m_pUIInstance->exportBtn,SIGNAL(clicked()),this, SLOT(exportLog()));
    connect(&m_Client,SIGNAL(dataReceived()),this, SLOT(newMessage()));
    writeMessage();
}

void Widget::newMessage()
{
    m_pUIInstance->textBrowser->setText(m_pUIInstance->textBrowser->toPlainText()+"\n"+m_Client.readData());
}

Widget::~Widget()
{
    delete m_pUIInstance;
}

void Widget::writeMessage()
{
    if(m_pUIInstance->lineEdit->text().isEmpty())
    {
        m_Client.sendMessage("******* Connection Established! ******");
    }
    else
    {
        m_Client.sendMessage(m_pUIInstance->lineEdit->text());
    }
    listenMessage();
}

void Widget::listenMessage()
{
    m_pUIInstance->lnEdtIPAdd->setText(m_Client.senderIPAddress());
    m_pUIInstance->lnEdtPortNo->setText(m_Client.senderPort());
    m_pUIInstance->textBrowser->setText(m_pUIInstance->textBrowser->toPlainText()+"\n"+m_Client.readData());
}

void Widget::clearLog()
{
    m_pUIInstance->textBrowser->setText("");
}

void Widget::exportLog()
{
    QString location =    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QFile file(location+"/log.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::ReadWrite|QIODevice::Append))
    {
         qDebug() << "FAIL TO CREATE FILE / FILE NOT EXIST!";
    }
    //qDebug()<<QDateTime::currentDateTime().toString()<<location;
    QTextStream out(&file);
    out<<endl<< QDateTime::currentDateTime().toString();
    out << m_pUIInstance->textBrowser->toPlainText();
    file.close();
    QMessageBox msgBox;
    msgBox.setText("Log saved succesfully in log.txt at "+ location+".");
    msgBox.exec();
}

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),m_pUIInstance(new Ui::Widget)
{
    m_pUIInstance->setupUi(this);

    connect(m_pUIInstance->lineEdit,SIGNAL(returnPressed()),this, SLOT(writeMessage()));
    connect(m_pUIInstance->sendButton,SIGNAL(clicked()),this, SLOT(writeMessage()));
    connect(m_pUIInstance->listenButton,SIGNAL(clicked()),this, SLOT(listenMessage()));
    connect(m_pUIInstance->clearButton,SIGNAL(clicked()),this, SLOT(clearLog()));
    writeMessage();
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

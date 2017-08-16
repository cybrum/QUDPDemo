#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),m_pUIInstance(new Ui::Widget)
{
    m_pUIInstance->setupUi(this);

    connect(m_pUIInstance->lineEdit,SIGNAL(returnPressed()),this, SLOT(writeMessage()));
    connect(m_pUIInstance->pushButton,SIGNAL(clicked()),this, SLOT(writeMessage()));
}

Widget::~Widget()
{
    delete m_pUIInstance;
}
void Widget::writeMessage()
{
    if(m_pUIInstance->lineEdit->text().isEmpty())
    {
        m_Client.sendMessage("******* Hello World! ******\n");
    }
    else
    {
        m_Client.sendMessage(m_pUIInstance->lineEdit->text());
    }
    m_pUIInstance->textBrowser->setText(m_pUIInstance->textBrowser->toPlainText()+"\n"+m_Client.readData());
}

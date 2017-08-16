#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myudp.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void writeMessage();

private:
    Ui::Widget *m_pUIInstance = nullptr;
    MyUDP m_Client;
};

#endif // WIDGET_H

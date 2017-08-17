#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "udphelper.h"

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
    void listenMessage();
    void clearLog();
    void exportLog();

private:
    Ui::Widget *m_pUIInstance = nullptr;
    UDPHelper m_Client;
};

#endif // WIDGET_H

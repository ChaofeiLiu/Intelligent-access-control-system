#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
public:
    QTcpSocket *sk;

public slots:
    void connect_msg();
    void recv_msg();
    void send_msg();
private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_clear_clicked();
};

#endif // WIDGET_H

#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->sk = new QTcpSocket();
    sk->connectToHost("127.0.0.1", 8888);

    connect(sk, SIGNAL(connected()), this, SLOT(connect_msg()));
    connect(sk, SIGNAL(readyRead()), this, SLOT(recv_msg()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connect_msg()
{
    qDebug() << "connect success.";
}

void Widget::recv_msg()
{
    QByteArray msg;
    msg = sk->readAll();

    QString myrecvmsg = msg.toStdString().c_str();
    ui->textEdit->append(myrecvmsg);
}

void Widget::send_msg()
{
    QString msg = ui->lineEdit->text();
    QByteArray sendmsg = msg.toLatin1();

    sk->write(sendmsg);
    ui->textEdit->append(msg);
}

void Widget::on_pushButton_send_clicked()
{
    send_msg();
}

void Widget::on_pushButton_clear_clicked()
{
    ui->lineEdit->clear();
}

#include <QFile>
#include <QString>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_accept_clicked()
{
    // Open file for server setting
    QFile config_file("config.txt");
    config_file.open(QIODevice::WriteOnly | QIODevice::Text);


    QString config_string;

    config_string = ui->lineEdit_ip->text() + ':';
    config_string += ui->lineEdit_port->text() + ':';
    config_string += ui->lineEdit_users->text();

    ui->label_info->setText("Settings updated");

    config_file.write(config_string.toStdString().c_str());
    config_file.close();
}

void MainWindow::on_pushButton_default_clicked()
{

    // Open file for server setting
    QFile config_file("config.txt");
    config_file.open(QIODevice::WriteOnly | QIODevice::Text);

    QString config_string = "127.0.0.1:7500:10";

    ui->label_info->setText("Default setting 127.0.0.1:7500:10");

}


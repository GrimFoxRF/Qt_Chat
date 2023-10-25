#include "bannwindow.h"
#include "ui_bannwindow.h"

BannWindow::BannWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BannWindow)
{
    ui->setupUi(this);
}

BannWindow::~BannWindow()
{
    delete ui;
}

void BannWindow::on_bannCurrentUserButton_clicked()
{

}


void BannWindow::on_unbannCurrentUserButton_clicked()
{

}


void BannWindow::on_closeBunnWindowButton_clicked()
{
    close();
}


#include "mainwindow.h"
#include "showmessageswindow.h"
#include "bannwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    debugWindowBrowser = ui->debugWindowBrowser;
    network = new Network(this);

    connect(network, &Network::infoMessage, this, &MainWindow::displayMessage);
    //connect(network, &DatabaseManager::infoMessageDB, this, &MainWindow::displayMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete network;
    qApp->exit(0);
}


void MainWindow::on_startServerButton_clicked()
{
    network->startServer();
}


void MainWindow::on_stopServerButton_clicked()
{
    network->closeServer();
}


void MainWindow::on_showMessagesButton_clicked()
{
    class showMessagesWindow *showMessages = new class showMessagesWindow;
    showMessages->show();

}


void MainWindow::on_bannUserButton_clicked()
{
    BannWindow *bannWindow = new BannWindow(this);
    bannWindow->show();
}


void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::displayMessage(const QString &message)
{
    debugWindowBrowser->append(message);
}


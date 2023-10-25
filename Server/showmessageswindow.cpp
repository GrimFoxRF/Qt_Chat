#include "showmessageswindow.h"
#include "ui_showmessageswindow.h"

showMessagesWindow::showMessagesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showMessagesWindow),
    databaseManager(databaseManager)
{
    ui->setupUi(this);
}

showMessagesWindow::~showMessagesWindow()
{
    delete ui;
}

void showMessagesWindow::on_closeUsersMessagesButton_clicked()
{
    close();
}


void showMessagesWindow::on_showAllMessagesButton_clicked()
{
    QString query = "SELECT message, timestamp FROM chat_history";
    QSqlQuery result = databaseManager->executeQueryResult(query);

    // Теперь вы можете обрабатывать результаты запроса и выводить их в окно.
    while (result.next()) {
        QString message = result.value(0).toString();
        QString timestamp = result.value(1).toString();
        // Ваш код для вывода сообщений в окно usersMessagesBrowser
    }
}


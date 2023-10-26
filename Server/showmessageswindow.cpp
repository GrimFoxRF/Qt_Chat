#include "showmessageswindow.h"
#include "ui_showmessageswindow.h"

showMessagesWindow::showMessagesWindow(DatabaseManager* dbManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showMessagesWindow),
    databaseManager(dbManager)
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
    DatabaseManager databaseManager;

    // Вызовите метод showAllUsersMessages для получения сообщений
    QVector<QString> messages = databaseManager.showAllUsersMessages();

    if (messages.isEmpty()) {
        // Если сообщений нет, выведите соответствующее сообщение.
        ui->usersMessagesBrowser->setText("Сообщений нет");
    } else {
        // Если есть сообщения, выведите их в окно usersMessagesBrowser.
        QString allMessages;
        for (const QString& message : messages) {
            allMessages += message + "\n";
        }
        ui->usersMessagesBrowser->setText(allMessages);
    }
}

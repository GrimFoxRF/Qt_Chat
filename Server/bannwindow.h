#ifndef BANNWINDOW_H
#define BANNWINDOW_H

#include <QDialog>

namespace Ui {
class BannWindow;
}

class BannWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BannWindow(QWidget *parent = nullptr);
    ~BannWindow();

private slots:
    void on_bannCurrentUserButton_clicked();

    void on_unbannCurrentUserButton_clicked();

    void on_closeBunnWindowButton_clicked();

private:
    Ui::BannWindow *ui;
};

#endif // BANNWINDOW_H

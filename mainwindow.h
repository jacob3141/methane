#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuickWidgets/QQuickWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_urlComboBox_activated(QString value);
    void on_backPushButton_clicked();
    void on_forwardPushButton_clicked();
    void on_reloadPushButton_clicked();

    void linkClicked(QUrl url);

private:
    Ui::MainWindow *ui;
    QQuickWidget _quickWidget;
};

#endif // MAINWINDOW_H

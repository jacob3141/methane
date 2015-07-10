#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->webView, SIGNAL(linkClicked(QUrl)), this, SLOT(linkClicked(QUrl)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_urlComboBox_activated(QString value) {
    if(!value.startsWith("http://") &&
       !value.startsWith("https://") &&
       !value.startsWith("file://")) {
        value.prepend("http://");
    }

    linkClicked(QUrl(value));
}

void MainWindow::on_backPushButton_clicked() {
    ui->webView->back();
}

void MainWindow::on_forwardPushButton_clicked() {
    ui->webView->forward();
}

void MainWindow::on_reloadPushButton_clicked() {
    ui->webView->reload();
}

void MainWindow::linkClicked(QUrl url) {
    if(url.toString().endsWith(".qml")) {
        ui->stackedWidget->setCurrentWidget(ui->qmlPage);
        ui->quickWidget->setSource(url);
    } else {
        ui->stackedWidget->setCurrentWidget(ui->webPage);
        ui->webView->load(url);
    }
    ui->urlComboBox->setCurrentText(url.toString());
}

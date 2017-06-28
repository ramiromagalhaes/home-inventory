#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventfilter.h"
#include <QShortcut>
#include <iostream>
#include <services.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->productBarcodeText->installEventFilter(new EnterKeyPressHandler(&isTake, &amount, ui->productBarcodeText, ui->statusBar));

    setTakeState();
    setAmount(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAmount(const int amount) {
    this->amount = amount;
}

void MainWindow::setTakeState() {
    isTake = true;
}

void MainWindow::setStoreState() {
    isTake = false;
}

void MainWindow::on_productBarcodeText_textChanged()
{
    Product p;

    if ( Services::getInstance().getProduct(ui->productBarcodeText->toPlainText().toStdString(), p) ) {
        ui->productNameLabel->setText( QString::fromStdString(p.name) );
    } else {
        ui->productNameLabel->setText( QString::fromStdString("-") );
    }
}

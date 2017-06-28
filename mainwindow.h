#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>

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
    void setAmount(const int amount);

    void setTakeState();

    void setStoreState();

private slots:
    void on_productBarcodeText_textChanged();

private:
    Ui::MainWindow *ui;

    bool isTake; //if false then it is store
    int amount;
    std::string productId;
};

#endif // MAINWINDOW_H

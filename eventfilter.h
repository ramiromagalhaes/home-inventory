#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QPlainTextEdit>
#include <QString>
#include <QStatusBar>
#include <sstream>
#include <iostream>
#include "services.h"


class EnterKeyPressHandler : public QObject {
    Q_OBJECT

    bool * take;
    int * amount;
    QPlainTextEdit *productBarcodeText;
    QStatusBar* statusBar;


public:
    EnterKeyPressHandler(bool* t, int* amount, QPlainTextEdit* productId, QStatusBar* statusBar) {
        this->take = t;
        this->amount = amount;
        this->productBarcodeText = productId;
        this->statusBar = statusBar;
    }

protected:
    bool eventFilter(QObject *obj, QEvent *event) {
        if (event->type() != QEvent::KeyPress) {
            return QObject::eventFilter(obj, event);
        }

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if ( keyEvent->key() == Qt::Key_Return ) {
            //Aqui devo fazer algo util!
            const std::string s = productBarcodeText->toPlainText().toStdString();

            if ( *take ) {
                Services::getInstance().take(s);
            } else {
                Services::getInstance().place(s);
            }

            Product p;
            if ( Services::getInstance().getProduct(s, p) ) {
                std::stringstream ss;
                ss << p.name << ". Em estoque: " << p.qtd;
                statusBar->showMessage(QString::fromStdString(ss.str()), 10000);
            }

            productBarcodeText->clear();
            productBarcodeText->setFocus();
        } else {
            return QObject::eventFilter(obj, event);
        }

        return true;
    }
};

#endif // EVENTFILTER_H

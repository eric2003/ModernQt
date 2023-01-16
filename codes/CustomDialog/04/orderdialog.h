#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>
#include <QList>

namespace Ui {
class OrderDialog;
}

class OrderDialog : public QDialog
{
    Q_OBJECT

public:
    using OrderItemType = QPair<QString, int>;
    explicit OrderDialog(QWidget *parent = nullptr);
    ~OrderDialog();
public:
    QString senderName() const;
    QString senderAddress() const;
    bool sendOffers();
    QList< OrderItemType > orderItems() const;
private:
    void setupOrderItems();
private:
    Ui::OrderDialog *ui;
};


#endif // ORDERDIALOG_H

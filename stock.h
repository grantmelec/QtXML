#ifndef STOCK_H
#define STOCK_H

#include <stdio.h>
#include <QString>
#include <QObject>

using namespace std;

class Stock: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString item READ getItem WRITE setItem)
    Q_PROPERTY(int quantity READ getQuantity WRITE setQuantity)

protected:
    QString item;
    int quantity;


public:
    //Constructors
    Stock();
    Stock(QString i, int q);
    ~Stock();

    //Getters
    QString getItem();
    int getQuantity();

    //Setters
    void setItem(QString i);
    void setQuantity(int q);

    virtual QString toString();
};

#endif // STOCK_H

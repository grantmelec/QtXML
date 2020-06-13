#include "stock.h"


//Constructors
Stock::Stock(){}
Stock::Stock(QString i, int q){item = i;quantity = q;}
Stock::~Stock(){}                                           //Destructor

//Getters
QString Stock::getItem(){return item;}
int Stock::getQuantity(){return quantity;}

//Setters
void Stock::setItem(QString i){item = i;}
void Stock::setQuantity(int q){quantity = q;}

QString Stock::toString()
{
    QString DataText =  QString("%1.%2").arg(item,QString::number(quantity));
    return(DataText);
}

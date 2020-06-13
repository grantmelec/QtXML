#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H
#include <confectionery.h>
#include <readingmaterial.h>


class StockFactory
{
private:

    ReadingMaterial * RM;
    Confectionery * CON;
public:
    StockFactory();
    ~StockFactory();
    Stock * createStock(QString ClassName,QString Name,int quantity ,QString var);          //Confectionary

};

#endif // STOCKFACTORY_H

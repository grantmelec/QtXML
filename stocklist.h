#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QObjectList>
#include<QList>
#include <readingmaterial.h>
#include <confectionery.h>
#include <stock.h>
#include<QObject>

class StockList
{
private:
        QList<Stock*> RM;                                 //QObject list for Reading Material
        QList<Stock*> CON;                                //QObject list for Confectionary
        static StockList* getInstance();                    // singleton accessor function; it is static so that it can be called without an instance of MyTableModel having to be created first
        static StockList *onlyInstance;                     // this is the only instance that will be created; it is static as it is called in a static function
    
public:
    ~StockList();
    QList<Stock*> getList(QString ListType);
    void AddList(Stock *p);
    
};

#endif // STOCKLIST_H

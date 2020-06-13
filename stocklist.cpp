#include "stocklist.h"
#include<QDebug>

//Meta Property libraries
#include <QMetaObject>
#include <QMetaProperty>

// Singleton
StockList *StockList::onlyInstance = NULL; //initialise the static data member
StockList* StockList::getInstance()
{
    if (onlyInstance == NULL)               // check if the onlyInstance exists yet
        onlyInstance = new StockList();     // if not, allocate memory

    return onlyInstance;
}


StockList::~StockList(){}
QList<Stock *> StockList::getList(QString ListType)
{
    if(QString::compare(ListType,"Confectionery")==0)
    {
        return  CON;
    }
        return RM;
}


void StockList::AddList(Stock *p)
{
    //get and print metadata
     const QMetaObject *metadata = p->metaObject();
     QMetaProperty metaproperty = metadata->property(3);            //the first

     if(QString::compare("weight",metaproperty.name()) == 0)        //Confectionary has a weight property
     {
         //qDebug()<<"\nAdding QObject to Confectionary QList";
         CON.append(p);
     }else if(QString::compare("frequency",metaproperty.name()) == 0)
     {
          //qDebug()<<"\nAdding QObject to Reading Material QList";
          RM.append(p);
     }
}



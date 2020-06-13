#include "stockfactory.h"
#define STR_EQUAL 0

#include <QDebug>



//Constructors
StockFactory::StockFactory(){}
StockFactory::~StockFactory(){}





//Method for determining which instance to create
Stock * StockFactory::createStock(QString ClassName,QString Name,int quantity ,QString var)        //Confectionary
{
       if (QString::compare("Confectionery",ClassName) == STR_EQUAL)
       {
           CON = new Confectionery(Name,quantity,var.toInt());
           return CON;

       }else //if(QString::compare("ReadingMaterial",ClassName) == STR_EQUAL)
       {
           RM = new ReadingMaterial(Name,quantity,var);
           return RM;
       }

}


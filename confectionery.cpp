#include "confectionery.h"
#include <QString>
using namespace std;

Confectionery::Confectionery(){}                                                //Constructors
Confectionery::Confectionery(QString i,int q,int w):Stock(i,q){weight = w;}     //Constructors
Confectionery::~Confectionery(){}                                               //Destructor
int Confectionery::getWeight(){return weight;}                                  //Getters
void  Confectionery::setWeight(int w){weight = w;}                              //Setters
QString Confectionery::toString ()
{
     QString DataText =  QString("%1.%2.%3").arg(item,QString::number(quantity),QString::number(weight));
     return(DataText);
}

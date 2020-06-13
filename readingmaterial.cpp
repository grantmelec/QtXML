#include "readingmaterial.h"
#include <QString>

ReadingMaterial::ReadingMaterial(){}
ReadingMaterial::ReadingMaterial(QString i,int q,QString f):Stock(i,q){frequency = f;}
ReadingMaterial::~ReadingMaterial(){}
QString ReadingMaterial::getFrequency(){return frequency;}
void ReadingMaterial::setFrequency(QString f){frequency = f;}

QString ReadingMaterial::toString()
{
    QString DataText =  QString("%1.%2.%3").arg(item,QString::number(quantity),frequency);
    return DataText;
}

#ifndef READINGMATERIAL_H
#define READINGMATERIAL_H
#include <stock.h>

class ReadingMaterial:public Stock
{
        Q_OBJECT
        Q_PROPERTY(QString frequency READ getFrequency WRITE setFrequency)
private:
    QString frequency;
public:
    ReadingMaterial();
    ReadingMaterial(QString i,int q,QString f);
    ~ReadingMaterial();
    QString getFrequency();
    void setFrequency(QString f);
    QString toString();

};

#endif // READINGMATERIAL_H

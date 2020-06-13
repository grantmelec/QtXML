#ifndef CONFECTIONERY_H
#define CONFECTIONERY_H
#include <stock.h>

class Confectionery:public Stock
{
    Q_OBJECT
    Q_PROPERTY(int weight READ getWeight WRITE setWeight)

private:
    int weight;
public:


    Confectionery();                        //Constructors
    Confectionery(QString i,int q,int w);   //Constructors
    ~Confectionery();
    int getWeight();                        //Getters
    void  setWeight(int w);                 //Setters
    QString toString ();


};

#endif // CONFECTIONERY_H

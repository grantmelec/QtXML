#include <QCoreApplication>
#include <stockfactory.h>
#include <stock.h>
#include <stocklist.h>
#include <QDebug>

#include <QStandardPaths>
#include <QXmlStreamWriter>
#include <QFile>



void saveToFile(QString filename);
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    StockFactory sf;
    Stock* i1 = sf.createStock("Confectionery", "Kit Kat", 12, "65");    
    Stock* i2 = sf.createStock("ReadingMaterial", "The Star", 10, "Daily");
    Stock* i3 = sf.createStock("Confectionery", "Bar One", 36, "85");
    Stock* i4 = sf.createStock("ReadingMaterial", "The Rock", 50, "Weekly");
    Stock* i5 = sf.createStock("Confectionery", "Gums", 10, "20");
    Stock* i6 = sf.createStock("ReadingMaterial", "Rapport", 10, "Monthly");
    //qDebug()<<"\n------------------------";

    //Add QObject to List
    StockList stocklist;
    stocklist.AddList(i1);
    stocklist.AddList(i2);
    stocklist.AddList(i3);
    stocklist.AddList(i4);
    stocklist.AddList(i5);
    stocklist.AddList(i6);


 QString myPath = QString("%1/StockInv.xml").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
 QFile file(myPath);
 // file.open(QIODevice::WriteOnly);

         if (!file.open(QIODevice::WriteOnly)){
             qDebug()<<"Device is read only";
         } else {
             QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
             xmlWriter->setDevice(&file);
             xmlWriter->setAutoFormatting(true);
             xmlWriter->writeStartDocument();

             xmlWriter->writeComment("XML List: Confectionary and Reading Material");
             xmlWriter->writeStartElement("stockList");                                   //start stocklist



             QList<Stock*> CONlist =stocklist.getList("Confectionery");
             QList<Stock*> RMlist =stocklist.getList("ReadingMaterial");

                       //--------------------------------
                       //        Confectionary List
                       //--------------------------------
                       int count = 0;
                       xmlWriter->writeStartElement("stockitem");
                       xmlWriter->writeAttribute("type","Confectionery");

                       foreach(Stock *k,CONlist)
                       {
                           QStringList text = k->toString().split(".");

                            QString j = QString("%1").arg(count);
                           xmlWriter->writeStartElement("Entry");
                           xmlWriter->writeAttribute("No",j);

                           xmlWriter->writeTextElement("item",text[0]);
                           xmlWriter->writeTextElement("quantity",text[1]);
                           xmlWriter->writeTextElement("weight",text[2]);

                           xmlWriter->writeEndElement();
                            count++;
                       }
                      xmlWriter->writeEndElement();   //End Confectionary List
                      qDebug()<<"Done writing XML Confectionary list";


                      //--------------------------------
                      //        Reading Material List
                      //--------------------------------
                      count = 0;
                      xmlWriter->writeStartElement("stockitem");
                      xmlWriter->writeAttribute("type","Reading Material");

                      foreach(Stock *d,RMlist)
                      {
                          QStringList text = d->toString().split(".");

                           QString j = QString("%1").arg(count);
                          xmlWriter->writeStartElement("Entry");
                          xmlWriter->writeAttribute("No",j);

                          xmlWriter->writeTextElement("item",text[0]);
                          xmlWriter->writeTextElement("quantity",text[1]);
                          xmlWriter->writeTextElement("frequency",text[2]);

                          xmlWriter->writeEndElement();
                           count++;
                      }
                     xmlWriter->writeEndElement();   //End Confectionary List
                      qDebug()<<"Done writing XML Reading Material list";

             xmlWriter->writeEndElement();
             xmlWriter->writeEndDocument();
         }

         file.close();



    qDebug()<<"Write XML file complete";

    return a.exec();
}


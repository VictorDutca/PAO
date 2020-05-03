#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <QFile>
#include <QJsonDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XMLHandler
{
public:
    XMLHandler();
private:
    QXmlStreamReader XMLRead;
    QXmlStreamWriter XMLWrite;
};

#endif // XMLHANDLER_H

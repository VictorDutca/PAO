#ifndef XMLHANDLER_H
#define XMLHANDLER_H
#include <QFile>
#include <QJsonDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "lista.h"
#include "workout.h"
#include "nuoto.h"
#include "corsa.h"
#include "ciclismo.h"
#include "triathlon.h"

class XMLHandler {

private:
    QXmlStreamReader XMLRead;
    QXmlStreamWriter XMLWrite;

public:
    XMLHandler();
    void FileReader(QString);
    Workout* WorkoutExplode(QString);
    void FileWriter();

};

#endif // XMLHANDLER_H

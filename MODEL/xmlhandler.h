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
    Dlista<Workout*>& wrk;
    QXmlStreamReader XMLRead;
    QXmlStreamWriter XMLWrite;
public:
    XMLHandler(Dlista<Workout*>&);
    void FileReader(QString);
    Workout* WorkoutExplode(QString);
    void FileExport(QIODevice&);
    void FileWriter();

};

#endif // XMLHANDLER_H

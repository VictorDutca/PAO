#include "xmlhandler.h"
#include <QFile>
#include <QJsonDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <iostream>

XMLHandler::XMLHandler(Dlista<Workout*>& worki) : wrk(worki) {}

void XMLHandler::FileReader(QString work) {
    QFile FileWorkout(work);
    if(FileWorkout.open(QIODevice::ReadOnly | QIODevice::Text)){
        //try{
            XMLRead.setDevice(&FileWorkout);
            XMLRead.readNext();
            while(!XMLRead.atEnd() && !XMLRead.hasError()){
                XMLRead.readNext();
                if(XMLRead.isStartDocument())
                    continue;
                if(XMLRead.isStartElement()){
                    if(XMLRead.name() == "workout")
                        continue;
                    QString work1 = XMLRead.name().toString();
                    Workout* w = WorkoutExplode(work1);
                    wrk.pushT(w);                }
            }
        }
    else{
        QFile FileWorkoutDefault (":/Files/QFitWorkout.xml");
        if(FileWorkoutDefault.open(QIODevice::ReadOnly | QIODevice::Text)){
            XMLRead.setDevice(&FileWorkoutDefault);
            XMLRead.readNext();
            while(!XMLRead.atEnd() && !XMLRead.hasError()){
                XMLRead.readNext();
                if(XMLRead.isStartDocument())
                    continue;
                if(XMLRead.isStartElement()){
                    if(XMLRead.name() == "workout")
                        continue;
                    QString work1 = XMLRead.name().toString();
                    Workout* w = WorkoutExplode(work1);
                    wrk.pushT(w);                }
            }
        }
    }
    FileWorkout.close();
    }

Workout* XMLHandler::WorkoutExplode(QString work){
    Workout* w = nullptr;
    XMLRead.readNextStartElement();
    if(XMLRead.isStartElement()){
        if(work == "swimming"){
            int freestyle, frog, backstroke, length;
           // XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            backstroke = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            frog = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            freestyle = XMLRead.readElementText().toInt();
            w = new Nuoto(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(frog),
                          static_cast<unsigned int>(backstroke),
                          static_cast<unsigned int>(freestyle));
        }
        else if(work == "running"){
            int length, plain,downhill,uphill,distance;
            //XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plain = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distance = XMLRead.readElementText().toInt();
            w = new Corsa(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(distance),
                          static_cast<unsigned int>(plain),
                          static_cast<unsigned int>(uphill),
                          static_cast<unsigned int>(downhill));
        }
        else if(work == "cycling"){
            int length, plain,downhill,uphill,distance;
            //XMLRead.readNextStartElement();
            length = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plain = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphill = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distance = XMLRead.readElementText().toInt();
            w = new Ciclismo(static_cast<unsigned int>(length),
                          static_cast<unsigned int>(distance),
                          static_cast<unsigned int>(plain),
                          static_cast<unsigned int>(uphill),
                          static_cast<unsigned int>(downhill));
        }
        else if(work == "triathlon"){
            int plainCo,downhillCo,uphillCo,distanceCo,lengthCo,plainCi,downhillCi,uphillCi,distanceCi,lengthCi,freestyle, frog, backstroke, lengthN;
            //XMLRead.readNextStartElement();
            lengthN = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            backstroke = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            frog = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            freestyle = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            lengthCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plainCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhillCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphillCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distanceCo = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            lengthCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            plainCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            downhillCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            uphillCi = XMLRead.readElementText().toInt();
            XMLRead.readNextStartElement();
            distanceCi = XMLRead.readElementText().toInt();
            w = new Triathlon(static_cast<unsigned int>(lengthCo),
                          static_cast<unsigned int>(distanceCo),
                          static_cast<unsigned int>(plainCo),
                          static_cast<unsigned int>(uphillCo),
                          static_cast<unsigned int>(downhillCo),
                          static_cast<unsigned int>(lengthCi),
                          static_cast<unsigned int>(distanceCi),
                          static_cast<unsigned int>(plainCi),
                          static_cast<unsigned int>(uphillCi),
                          static_cast<unsigned int>(downhillCi),
                          static_cast<unsigned int>(lengthN),
                          static_cast<unsigned int>(frog),
                          static_cast<unsigned int>(backstroke),
                          static_cast<unsigned int>(freestyle));
        }
        XMLRead.readNext();
    }
    return w;
}

//file writer

void XMLHandler::FileWriter(){
    QFile file("QFitWorkout.xml");
    //file.close(); //messo per sicurezza


    if (file.open(QIODevice::WriteOnly)) {
        XMLWrite.setDevice(&file);
        XMLWrite.setAutoFormatting(true);
        XMLWrite.writeStartDocument();

        XMLWrite.writeStartElement("workout");
        Dlista<Workout*>::iterator it = wrk.begin();
        for (;it != wrk.end(); ++it) {
            //std::string tipo = (*it)->tipo();
            if(dynamic_cast<Triathlon*>(*it)) {
                Triathlon* p = dynamic_cast<Triathlon*>(*it);
                XMLWrite.writeStartElement("triathlon");
                XMLWrite.writeTextElement("lengthswimming", QString::fromStdString(std::to_string(( p->Nuoto::get_durata()/3 ))));
                XMLWrite.writeTextElement("backstroke", QString::fromStdString(std::to_string(( p->Nuoto::getVascheDorso() ))));
                XMLWrite.writeTextElement("frog", QString::fromStdString(std::to_string(( p->Nuoto::getVascheRana() ))));
                XMLWrite.writeTextElement("freestyle", QString::fromStdString(std::to_string(( p->Nuoto::getVascheLibero() ))));

                XMLWrite.writeTextElement("lengthrunning", QString::fromStdString(std::to_string(( p->Corsa::get_durata()/3 ))));
                XMLWrite.writeTextElement("plainrunning", QString::fromStdString(std::to_string(( p->Corsa::get_pianura() ))));
                XMLWrite.writeTextElement("downhillrunning", QString::fromStdString(std::to_string(( p->Corsa::get_discesa() ))));
                XMLWrite.writeTextElement("uphillrunning", QString::fromStdString(std::to_string(( p->Corsa::get_salita() ))));
                XMLWrite.writeTextElement("distancerunning", QString::fromStdString(std::to_string(( p->Corsa::get_distanza() ))));

                XMLWrite.writeTextElement("lengthcycling", QString::fromStdString(std::to_string(( p->Ciclismo::get_durata()/3 ))));
                XMLWrite.writeTextElement("plaincycling", QString::fromStdString(std::to_string(( p->Ciclismo::get_pianura() ))));
                XMLWrite.writeTextElement("downhillcycling", QString::fromStdString(std::to_string(( p->Ciclismo::get_discesa() ))));
                XMLWrite.writeTextElement("uphillcycling", QString::fromStdString(std::to_string(( p->Ciclismo::get_salita() ))));
                XMLWrite.writeTextElement("distancecycling", QString::fromStdString(std::to_string(( p->Ciclismo::get_distanza() ))));

                XMLWrite.writeEndElement();

            } else if(dynamic_cast<Ciclismo*>(*it)) {
                Ciclismo* p = dynamic_cast<Ciclismo*>(*it);
                XMLWrite.writeStartElement("cycling");
                XMLWrite.writeTextElement("length", QString::fromStdString(std::to_string(((*it)->get_durata()))));
                XMLWrite.writeTextElement("plain", QString::fromStdString(std::to_string((p->get_pianura()))));
                XMLWrite.writeTextElement("downhill", QString::fromStdString(std::to_string((p->get_discesa()))));
                XMLWrite.writeTextElement("uphill", QString::fromStdString(std::to_string((p->get_salita()))));
                XMLWrite.writeTextElement("distance", QString::fromStdString(std::to_string((p->get_distanza()))));

                XMLWrite.writeEndElement();
            } else if(dynamic_cast<Corsa*>(*it)) {
                Corsa* p = dynamic_cast<Corsa*>(*it);
                XMLWrite.writeStartElement("running");
                XMLWrite.writeTextElement("length", QString::fromStdString(std::to_string(((*it)->get_durata()))));
                XMLWrite.writeTextElement("plain", QString::fromStdString(std::to_string((p->get_pianura()))));
                XMLWrite.writeTextElement("downhill", QString::fromStdString(std::to_string((p->get_discesa()))));
                XMLWrite.writeTextElement("uphill", QString::fromStdString(std::to_string((p->get_salita()))));
                XMLWrite.writeTextElement("distance", QString::fromStdString(std::to_string((p->get_distanza()))));
                XMLWrite.writeEndElement();
            } else if (dynamic_cast<Nuoto*>(*it)) {
                Nuoto* p = dynamic_cast<Nuoto*>(*it);
                 XMLWrite.writeStartElement("swimming");
                 XMLWrite.writeTextElement("length", QString::fromStdString(std::to_string(((*it)->get_durata()))));
                 XMLWrite.writeTextElement("backstroke", QString::fromStdString(std::to_string((p->getVascheDorso()))));
                 XMLWrite.writeTextElement("frog", QString::fromStdString(std::to_string((p->getVascheRana()))));
                 XMLWrite.writeTextElement("freestyle", QString::fromStdString(std::to_string((p->getVascheLibero()))));

                 XMLWrite.writeEndElement();
            }
        }
        XMLWrite.writeEndElement(); // allenamenti

        XMLWrite.writeEndDocument();
    }
    file.close();
}



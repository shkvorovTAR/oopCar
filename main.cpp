#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QString>
//#include "ncar.h"

//Class Car
class Car
{
    float engineVolume= 1.0 ; // liters
    int   doorsCount  = 4;    // units
    float tankMax = 50.0;   // liters
    float gasVolume = 0.0;  // liters
    float odometer = 0.0;   // km
    float gasConsumption = 14.6; // km per liter

public:
    QString qsRegNumber = "      ";

    //Maximum capacity of car's tank to fuel
    Car(float vol, float tank) {
        qDebug() << "Car(float vol) 27";
        if (tank > 0) {
            tankMax = tank;
            qDebug() << "tankMax is now " << tankMax;
        }
        engineVolume = vol;
        setCons();
    }

    Car() {
        qDebug() << "defaule cons() 18";
        setCons();
    }

    Car(float vol) {
        qDebug() << "Car(float vol) 23";
        engineVolume = vol;
        setCons();
    }

    Car(QString reg) {
        qDebug() << "Car(QString reg) 29";
        qsRegNumber = reg;
        setCons();
    }

    Car(float vol, QString reg) {
        qDebug() << "Car(float vol, QString reg) 35";
        engineVolume = vol;
        qsRegNumber = reg;
    }
    // End of constructions

    void setDoorsCount(int newCount) {
        if ((newCount >1) && (newCount < 10)) {
            doorsCount = newCount;
        }
    }

    void setCons(){
        if (engineVolume > 0.0) {
            gasConsumption = engineVolume*14.6;

            qDebug().noquote() << "gasConsumption now = " << gasConsumption ;
        }
    }

    QString toPrint() {
        QString qsTemp = "Reg Number is %1; engine vol is %2; doors count %3";
        return qsTemp.arg(qsRegNumber).arg( (double)engineVolume, 2 , 'f', 3).arg(doorsCount);
    }

    QString shortPrint() {
        QString qsTemp = "Reg Number is %1; gas volume %2; odomentr %3";
        return qsTemp.arg(qsRegNumber).arg( (double)gasVolume).arg((double) odometer, 2 , 'f', 3);
    }

    float fill(float volume){
        gasVolume = volume > tankMax ? tankMax : gasVolume+volume;
        return gasVolume;
    }

    float drive (float km) {
        float litersSpend = km/gasConsumption;
        float kmResult = 0;
        if (litersSpend > gasVolume) {
            odometer += gasConsumption * gasVolume;
            kmResult = gasConsumption * gasVolume;
            gasVolume = 0;
        } else {
            odometer += km;
            gasVolume -= litersSpend;
            kmResult = km;
        }
        return kmResult;
    }
};

/*
QDebug operator<<(QDebug dbg, NCar &c){
    QDebugStateSaver saver(dbg);
    dbg.noquote() << c.toPrint();
    return dbg;
}
*/

void showInput(Car car);
int main()
{
    qDebug () << "Homework: oopCAR";
    qDebug () << " ";
    Car car1(1.4, 60);
    car1.qsRegNumber = "777BMW";
    showInput(car1);

    Car car2(1.5, 25);
    car2.qsRegNumber = "123ABC";
    showInput(car2);

    Car car3(2.8, 12);
    car3.qsRegNumber = "000XXX";
    showInput(car3);

    Car car4(0.4, 6);
    car4.qsRegNumber = "717BJK";
    showInput(car4);

    Car car5(2.2, 3);
    car5.qsRegNumber = "EKG222";
    showInput(car5);
    return (0);
}

void showInput(Car car) {
    for (int i=0; i<10; i++) {
        car.drive(231);
        if(i==2 || i==5 || i==8) car.fill(7);
        qDebug() << car.shortPrint();
    }
    qDebug().noquote() << "\n";
}

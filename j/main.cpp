#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QLocale>
#include <QTranslator>
#include "getdatafilters.h"
#include "datahtmlwebsitefilter.h"
#include <fstream>
#include <string>
#include <exception>






bool operator>(DataHTMLWebsiteFilter data, DataHTMLWebsiteFilter data2) {
    std::string ResultMasjidTimeJumua1minData1; for (int i = 0 ; i<2 ; i++) { ResultMasjidTimeJumua1minData1 += data.getResultMasjidTimeJumua1()[i]; }
    std::string ResultMasjidTimeJumua1hourData1; for (int i = 3; i<5 ; i++) { ResultMasjidTimeJumua1hourData1 += data.getResultMasjidTimeJumua1()[i]; }

    std::string ResultMasjidTimeJumua1minData2; for (int i = 0 ; i<2 ; i++) { ResultMasjidTimeJumua1minData2 += data2.getResultMasjidTimeJumua1()[i]; }
    std::string ResultMasjidTimeJumua1hourData2; for (int i = 3; i<5 ; i++) { ResultMasjidTimeJumua1hourData2 += data2.getResultMasjidTimeJumua1()[i]; }


    std::cout << " ResultMasjidTimeJumua1minData1: " << ResultMasjidTimeJumua1minData1;
    std::cout << " ResultMasjidTimeJumua1hourData1: " << ResultMasjidTimeJumua1hourData1;
    std::cout << " ResultMasjidTimeJumua1hourData2: " << ResultMasjidTimeJumua1hourData2;
    std::cout << " ResultMasjidTimeJumua1minData2: " << ResultMasjidTimeJumua1minData2;
    std::cout << std::endl;

    float ResultMasjidTimeJumua1minData1float = std::stof(ResultMasjidTimeJumua1minData1);
    float ResultMasjidTimeJumua1hourData1float = std::stof(ResultMasjidTimeJumua1hourData1);
    float ResultMasjidTimeJumua1minData2float = std::stof(ResultMasjidTimeJumua1minData2);
    float ResultMasjidTimeJumua1hourData2float = std::stof(ResultMasjidTimeJumua1hourData2);

    if (ResultMasjidTimeJumua1hourData1float > ResultMasjidTimeJumua1hourData2float)  {  return true;   }
    else if (ResultMasjidTimeJumua1hourData1float == ResultMasjidTimeJumua1hourData2float) {
        if (ResultMasjidTimeJumua1minData1float > ResultMasjidTimeJumua1minData2float) { return true;  }
        else if (ResultMasjidTimeJumua1minData1float == ResultMasjidTimeJumua1minData2float) {return true;}
        else                                                                           { return false; }
    }
    else {return false;}


}
bool operator==(DataHTMLWebsiteFilter data, DataHTMLWebsiteFilter data2) {
    std::string ResultMasjidTimeJumua1minData1; for (int i = 0 ; i<2 ; i++) { ResultMasjidTimeJumua1minData1 += data.getResultMasjidTimeJumua1()[i]; }
    std::string ResultMasjidTimeJumua1hourData1; for (int i = 3; i<5 ; i++) { ResultMasjidTimeJumua1hourData1 += data.getResultMasjidTimeJumua1()[i]; }

    std::string ResultMasjidTimeJumua1minData2; for (int i = 0 ; i<2 ; i++) { ResultMasjidTimeJumua1minData2 += data2.getResultMasjidTimeJumua1()[i]; }
    std::string ResultMasjidTimeJumua1hourData2; for (int i = 3; i<5 ; i++) { ResultMasjidTimeJumua1hourData2 += data2.getResultMasjidTimeJumua1()[i]; }

    std::cout << " ResultMasjidTimeJumua1minData1: " << ResultMasjidTimeJumua1minData1;
    std::cout << " ResultMasjidTimeJumua1hourData1: " << ResultMasjidTimeJumua1hourData1;
    std::cout << " ResultMasjidTimeJumua1hourData2: " << ResultMasjidTimeJumua1hourData2;
    std::cout << " ResultMasjidTimeJumua1minData2: " << ResultMasjidTimeJumua1minData2;
    std::cout << std::endl;


    float ResultMasjidTimeJumua1minData1float = std::stof(ResultMasjidTimeJumua1minData1);
    float ResultMasjidTimeJumua1hourData1float = std::stof(ResultMasjidTimeJumua1hourData1);
    float ResultMasjidTimeJumua1minData2float = std::stof(ResultMasjidTimeJumua1minData2);
    float ResultMasjidTimeJumua1hourData2float = std::stof(ResultMasjidTimeJumua1hourData2);

    if (ResultMasjidTimeJumua1hourData1float == ResultMasjidTimeJumua1hourData2float && ResultMasjidTimeJumua1minData1float == ResultMasjidTimeJumua1minData2float) {
        return true;
    }
    else {
        return false;
    }
}


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv); 
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "JumuaTimesTracker_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    GetDataFilters filtersTest;



    // test
    DataHTMLWebsiteFilter dataWebsite1, dataWebsite2, dataWebsite3;
    dataWebsite3.GetDohrTimeMasjid(std::string(filtersTest.getDataHTMLWebsite("https://mawaqit.net/fr/asmc78-la-celle-saint-cloud")));

    dataWebsite1.GetJumuaTimesMasjid(std::string(filtersTest.getDataHTMLWebsite("https://mawaqit.net/fr/institut-ibn-badis-nanterre")));
    dataWebsite2.GetJumuaTimesMasjid(std::string(filtersTest.getDataHTMLWebsite("https://mawaqit.net/fr/asmc78-la-celle-saint-cloud")));
    if (dataWebsite1 > dataWebsite2) { std::cout << "LE JUMUA A LA MOSQU TARD" <<  "  : jumuaMosque1 : " << dataWebsite1.getResultMasjidTimeJumua1() << " : jumua mosque 2 : "  << dataWebsite2.getResultMasjidTimeJumua1()<< std::endl; }   //
    else { std::cout << "LE JUMUA A LA MOSQUE1 est plus tot " <<  "  : jumuaMosque1 : " << dataWebsite1.getResultMasjidTimeJumua1() << " : jumua mosque 2 : "  << dataWebsite2.getResultMasjidTimeJumua1()<< std::endl; }
    if (dataWebsite1 == dataWebsite2) {std::cout << " LES 2 MOSQUEE PRIENT A LA MEME HEURE" << std::endl;}
    std::ofstream fileTest("C:/testMawaqit/test2.txt");
    fileTest << filtersTest.getDataHTMLWebsite("https://mawaqit.net/fr/asmc78-la-celle-saint-cloud");
    std::cout << " RRRRRRRRRRRRRRR2 " << dataWebsite3.getResultMasjidTimeDohr() << std::endl;

    if (dataWebsite1.getResultMasjidTimeJumua1() > dataWebsite3.getResultMasjidTimeDohr()) {std::cout << " JUMUAAA APRES DOHR " << std::endl;}
    else {std::cout << " JUMUAAA AVANT DOHR " << std::endl;}
    return app.exec();





}

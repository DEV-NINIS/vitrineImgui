#ifndef GETDATAFILTERS_H
#define GETDATAFILTERS_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <vector>

class GetDataFilters: public QObject
{



public:
    GetDataFilters();
    virtual ~GetDataFilters();

    // website data html/css/js
    std::string getDataHTMLWebsite(const char* hyperlink);
    static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);

    void getFiltersUsers(float distMax, std::string time_begin, std::string time_end);

private:

// variables of the filter user

float distanceMax;

    float timeBeginHours;
    float timeBeginMin;
    float timeEndHours;
    float timeEndMin;



// position 
float Lattitude; float Longitude;


};

#endif // GETDATAFILTERS_H

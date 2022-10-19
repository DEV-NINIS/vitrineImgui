#ifndef DATAHTMLWEBSITEFILTER_H
#define DATAHTMLWEBSITEFILTER_H


#include <iostream>
#include <string>
#include <vector>

class DataHTMLWebsiteFilter
{

public:
    DataHTMLWebsiteFilter();
    virtual ~DataHTMLWebsiteFilter();
    void GetJumuaTimesMasjid(std::string HTMLWebsiteCode); // this fonction filters the html data until it finds the jumua schedule info and reviews this info
    void GetDohrTimeMasjid(std::string HTMLWebsiteCode);
    char filterVariableData(char value[]);
    std::string convertToString(char value[]);
    // compare value class for operator

    std::string getResultMasjidTimeJumua1() const;
    std::string getResultMasjidTimeDohr() const;
    float getResultMasjidTimeJumua2() const;

private:
// result of the time of pray

    std::string resultMasjidTimeJumua1;
    std::string resultMasjidTimeJumua2;
    std::string resultMasjidTimeDohr;


};

#endif // DATAHTMLWEBSITEFILTER_H

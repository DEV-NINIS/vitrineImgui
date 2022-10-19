#include "datahtmlwebsitefilter.h"
#include <string>
#include <vector>

#define NOT_SECOND_JUMUA 0
#define SIZE_CHAR (6 * sizeof(char)/sizeof(char))

static int numberCaracterOfTypeData = 8;
static int numberCaracterOfTypeDataDohr = 17;


DataHTMLWebsiteFilter::DataHTMLWebsiteFilter()
{
    resultMasjidTimeJumua1 = "";
    resultMasjidTimeJumua2 = "";
    resultMasjidTimeDohr = "";
}
DataHTMLWebsiteFilter::~DataHTMLWebsiteFilter(){}



void DataHTMLWebsiteFilter::GetJumuaTimesMasjid(std::string HTMLWebsiteCode) { // get the time of the jumua  1, 2 in a masjid

   char TempResultMasjidTimeJumua1[6];
   char TempResultMasjidTimeJumua2[6]; // is a list of 6 char because \"13h40\" for exanple have 6 characters





    int numberCaracterStringTimeJumua1 = HTMLWebsiteCode.find("\"jumua\":");
    std::cout << " NUMBER CHARACTER IS :" << numberCaracterStringTimeJumua1 << std::endl;
    int numberCaracterStringTimeJumua2 = HTMLWebsiteCode.find("\"jumua2\":");
    std::cout << " NUMBER CHARACTER IS :" << numberCaracterStringTimeJumua2 << std::endl;

    for (int i = 0; i< 7; i++) { TempResultMasjidTimeJumua1[i] = HTMLWebsiteCode[numberCaracterStringTimeJumua1 + numberCaracterOfTypeData + i]; }
    for (int i = 0; i< 7; i++) { TempResultMasjidTimeJumua2[i] = HTMLWebsiteCode[numberCaracterStringTimeJumua2 + numberCaracterOfTypeData + i]; }

    // filterVariableData


    resultMasjidTimeJumua1 = this->convertToString(TempResultMasjidTimeJumua1);
    resultMasjidTimeJumua2 = this->convertToString(TempResultMasjidTimeJumua2);

   std::cout << " horaires 1 : " << resultMasjidTimeJumua1 << std::endl;
   std::cout << " horaires 2 : " << resultMasjidTimeJumua2 << std::endl;

}
void DataHTMLWebsiteFilter::GetDohrTimeMasjid(std::string HTMLWebsiteCode) {

    char TempResultMasjidTimeDohr[6];

    int numberCaracterStringTimeDohr = HTMLWebsiteCode.find("\"times\":");
    std::cout << "numberCaracterStringTimeDohr is :" << numberCaracterStringTimeDohr << " fin " << std::endl;

    for (int i = 0; i<  7; i++) { TempResultMasjidTimeDohr[i] = HTMLWebsiteCode[numberCaracterStringTimeDohr + numberCaracterOfTypeDataDohr + i]; }

    resultMasjidTimeDohr = this->convertToString(TempResultMasjidTimeDohr);

    std::cout << " HORAIRES DOHR ADJ = " << resultMasjidTimeDohr << " fin" << std::endl;


}
std::string DataHTMLWebsiteFilter::convertToString(char value[]) {
    const char* tempValue = value;
    return std::string(tempValue);
}




std::string DataHTMLWebsiteFilter::getResultMasjidTimeJumua1() const {
    std::string tempResultTimeJumua1hours; for (int i = 1; i<3; i++) { tempResultTimeJumua1hours += resultMasjidTimeJumua1[i]; }
    std::string tempResultTimeJumua1min;   for (int i = 4; i<6; i++) { tempResultTimeJumua1min += resultMasjidTimeJumua1[i]; }

    return std::string(tempResultTimeJumua1hours + "." + tempResultTimeJumua1min);
}

std::string DataHTMLWebsiteFilter::getResultMasjidTimeDohr() const  {
    std::string tempResultTimeDohrhours; for (int i = 1; i<3; i++) { tempResultTimeDohrhours += resultMasjidTimeDohr[i]; }
    std::string tempResultTimeDohrmin;   for (int i = 4; i<6; i++) { tempResultTimeDohrmin += resultMasjidTimeDohr[i]; }

    return std::string(tempResultTimeDohrhours + "." + tempResultTimeDohrmin);
}


// // //
float DataHTMLWebsiteFilter::getResultMasjidTimeJumua2() const {

}

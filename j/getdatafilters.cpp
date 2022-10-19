#include "getdatafilters.h"
#include <vector>
#include <string>

#include <curl/curl.h>

GetDataFilters::GetDataFilters()
{


    timeBeginHours = 0;
    timeBeginMin = 0;
    timeEndHours = 0;
    timeEndMin = 0;
    distanceMax = 0;
}


GetDataFilters::~GetDataFilters() {}


// fonctions

void GetDataFilters::getFiltersUsers(float distMax, std::string time_begin, std::string time_end) {
    distanceMax = distMax;
    // filter string charachter and convert to 100 ratio

        std::string temp_time_begin_hour;  // the fonction of this variable is to ass the all caracters of time begin to convert in float
        std::string temp_time_begin_min;




            temp_time_begin_hour = temp_time_begin_hour + time_begin[0];
            temp_time_begin_hour = temp_time_begin_hour + time_begin[1];



            temp_time_begin_min = temp_time_begin_min + time_begin[3];
            temp_time_begin_min = temp_time_begin_min + time_begin[4];





        std::string temp_time_end_hour;  // the fonction of this variable is to ass the all caracters of time begin to convert in float
        std::string temp_time_end_min;


            temp_time_end_hour = temp_time_end_hour + time_end[0];
            temp_time_end_hour = temp_time_end_hour + time_end[1];



           temp_time_end_min = temp_time_end_min + time_end[3];
           temp_time_end_min = temp_time_end_min + time_end[4];


// convert all in a float

           timeBeginHours = std::stof(temp_time_begin_hour);
           timeBeginMin = std::stof(temp_time_begin_min);

           timeEndHours = std::stof(temp_time_end_hour);
           timeEndMin = std::stof(temp_time_end_min);



std::cout << timeEndHours << " h " << timeEndMin;
}



// data website
size_t GetDataFilters::my_write(void *buffer, size_t size, size_t nmemb, void *param) {
    std::string& text = *static_cast<std::string*>(param);
     size_t totalsize = size * nmemb;
     text.append(static_cast<char*>(buffer), totalsize);
     return totalsize;

}


std::string GetDataFilters::getDataHTMLWebsite(const char* hyperlink) {
    std::string result;
     CURL* curl;
     CURLcode res;
     curl_global_init(CURL_GLOBAL_DEFAULT);
     curl = curl_easy_init();
     if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, hyperlink);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->my_write);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
      if (CURLE_OK != res) {
       std::cerr << "CURL error: " << res << '\n';
      }
     }
     curl_global_cleanup();
     return result;
}

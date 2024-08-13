
#include "utils.hpp"
#include <sstream>

bool isLeapYear(int year) {
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string &date) {
   if (date.size() != 10) return false;

   int year, month, day;
   std::stringstream dateStream(date.substr(0, 4));
   dateStream >> year;
   dateStream.clear();
   dateStream.str(date.substr(5, 2));
   dateStream >> month;
   dateStream.clear();
   dateStream.str(date.substr(8, 2));
   dateStream >> day;
   if (dateStream.fail() || dateStream.rdbuf()->in_avail() != 0) return false;
   if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;
   if (month == 2) {
      if (day > (isLeapYear(year) ? 29 : 28)) return false;
   } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30) return false;
   }
   return true;
}

time_t convertDateToTimeT(const std::string &date) {
   struct tm tm;
   strptime(date.c_str(), "%Y-%m-%d", &tm);
   return mktime(&tm);
}
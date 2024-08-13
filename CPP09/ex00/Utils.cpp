
#include "utils.hpp"
#include <algorithm>
#include <cctype>
#include <locale>

bool isLeapYear(int year) {
   return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string &date) {
   if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
      return false;
   }

   int year, month, day;
   std::stringstream ss;

   // Extraire et convertir l'année
   ss.str(date.substr(0, 4));
   ss >> year;
   if (ss.fail() || !ss.eof()) return false;
   ss.clear();

   // Extraire et convertir le mois
   ss.str(date.substr(5, 2));
   ss >> month;
   if (ss.fail() || !ss.eof()) return false;
   ss.clear();

   // Extraire et convertir le jour
   ss.str(date.substr(8, 2));
   ss >> day;
   if (ss.fail() || !ss.eof()) return false;
   ss.clear();

   // Vérifier les valeurs de l'année, du mois et du jour
   if (year < 0 || month < 1 || month > 12 || day < 1) {
      return false;
   }

   // Vérifier les jours par mois
   if (month == 2) {
      if (day > (isLeapYear(year) ? 29 : 28)) return false;
   } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30) return false;
   } else {
      if (day > 31) return false;
   }

   return true;
}

time_t convertDateToTimeT(const std::string &date) {
   struct tm tm = {};
   strptime(date.c_str(), "%Y-%m-%d", &tm);
   return mktime(&tm);
}

void trim(std::string &str) {
   std::string::iterator start = str.begin();
   while (start != str.end() && std::isspace(*start)) {
      ++start;
   }
   std::string::iterator end = str.end();
   while (end != start && std::isspace(*(end - 1))) {
      --end;
   }
   str.assign(start, end);
}
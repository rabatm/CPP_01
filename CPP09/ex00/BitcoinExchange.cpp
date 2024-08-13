#include "BitcoinExchange.hpp"
#include <cmath>
#include <ctime>
#include "Utils.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
   *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
   if (this != &other) {
      items = other.items;  // Assigne directement la map
   }
   return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadItemsfromCsv(const std::string &filename) {
   if (filename.empty()) {
      std::cerr << "😿 Error: filename is empty" << std::endl;
      return false;
   }
   std::ifstream file(filename.c_str());
   if (!file.is_open()) {
      std::cerr << "😿 Error: Cannot open file " << filename << std::endl;
      return false;
   }

   std::string line;
   std::getline(file, line);  // Ignore header line
   while (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string date;
      double price;
      if (std::getline(ss, date, ',') && ss >> price) {
         // Trim whitespace
         date.erase(date.find_last_not_of(" \n\r\t") + 1);
         if (!isValidDate(date)) {
            std::cerr << "😿 Error: Invalid date format" << std::endl;
            continue;
         }
         if (price < 0) {
            std::cerr << "😿 Error: Invalid price" << std::endl;
            continue;
         }
         items[date] = price;  // Insère ou met à jour l'élément dans la map
      } else {
         std::cerr << "😿 Error: Invalid line format => " << line << std::endl;
      }
   }
   file.close();
   return true;
}

// Fonction pour trouver la date la plus proche
std::string BitcoinExchange::getCloseDate(const std::string &date) const {
   if (items.empty()) {
      std::cerr << "😿 Error: No items loaded" << std::endl;
      return "";
   }
   if (!isValidDate(date)) {
      std::cerr << "😿 Error: Invalid date format" << std::endl;
      return "";
   }

   time_t t = convertDateToTimeT(date);
   std::map<std::string, double>::const_iterator lower =
       items.lower_bound(date);
   if (lower == items.end()) {
      if (items.empty()) {
         return "";
      }
      --lower;
   }

   std::string closest_date = lower->first;
   time_t closest_t = convertDateToTimeT(closest_date);
   double min_diff = std::fabs(difftime(t, closest_t));

   if (lower != items.begin()) {
      --lower;
      time_t prev_t = convertDateToTimeT(lower->first);
      double prev_diff = std::fabs(difftime(t, prev_t));
      if (prev_diff < min_diff) {
         closest_date = lower->first;
      }
   }

   return closest_date;
}

// Fonction pour obtenir le prix à une date donnée
double BitcoinExchange::getPrice(const std::string &date) const {
   std::string closest_date = getCloseDate(date);
   if (closest_date.empty()) {
      return 0;
   }
   return items.at(closest_date);
}

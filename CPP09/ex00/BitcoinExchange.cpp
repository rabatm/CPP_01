#include "BitcoinExchange.hpp"
#include <cmath>

BitcoinExchange::BitcoinExchange() {
   std::cout << "BitcoinExchange constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
   std::cout << "BitcoinExchange copy constructor" << std::endl;
   *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
   std::cout << "BitcoinExchange assignment operator" << std::endl;
   (void)other;
   return *this;
}

BitcoinExchange::~BitcoinExchange() {
   std::cout << "BitcoinExchange destructor" << std::endl;
}

bool BitcoinExchange::loadItemsfromCsv(const std::string &filename) {
   if (filename.empty() || filename == "") {
      std::cerr << "Error: filename is empty" << std::endl;
      return false;
   }
   std::ifstream file(filename.c_str());
   if (!file.is_open()) {
      std::cerr << "Error: Cannot open file " << filename << std::endl;
      return false;
   }
   std::string line;
   while (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string date;
      double price;
      if (std::getline(ss, date, ',') && ss >> price) {
         if (!isValidDate(date)) {
            std::cerr << "Error: Invalid date format" << std::endl;
            return false;
         }
         if (price < 0) {
            std::cerr << "Error: Invalid price" << std::endl;
            return false;
         }
         bts_item *item = new bts_item;
         item->date = date;
         item->price = price;
         items.push_back(item);
      }
   }
   file.close();
   return true;
}

std::string BitcoinExchange::getCloseDate(std::string date) {
   if (items.empty()) {
      std::cerr << "Error: No items loaded" << std::endl;
      return "";
   }
   if (!isValidDate(date)) {
      std::cerr << "Error: Invalid date format" << std::endl;
      return "";
   }
   time_t t = convertDateToTimeT(date);
   std::string closest_date = items[0]->date;
   time_t closest_t = convertDateToTimeT(closest_date);
   double min_diff = std::fabs(t - closest_t);
   for (size_t i = 1; i < items.size(); i++) {
      time_t current_t = convertDateToTimeT(items[i]->date);
      double current_diff = std::fabs(t - current_t);
      if (current_diff < min_diff) {
         min_diff = current_diff;
         closest_date = items[i]->date;
      }
   }
   return closest_date;
}

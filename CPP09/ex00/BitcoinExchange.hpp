#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
  private:
   std::map<std::string, double> items;

  public:
   BitcoinExchange();
   BitcoinExchange(const BitcoinExchange &other);
   BitcoinExchange &operator=(const BitcoinExchange &other);
   ~BitcoinExchange();

   bool loadItemsfromCsv(const std::string &filename);
   std::string getCloseDate(const std::string &date) const;
   double getPrice(const std::string &date) const;
};

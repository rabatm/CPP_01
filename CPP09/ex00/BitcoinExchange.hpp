#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "utils.hpp"

typedef struct {
   std::string date;
   double price;
} bts_item;

class BitcoinExchange {

  private:
   std::vector<bts_item *> items;

  public:
   BitcoinExchange();
   BitcoinExchange(const BitcoinExchange &other);
   BitcoinExchange &operator=(const BitcoinExchange &other);
   ~BitcoinExchange();
   bool loadItemsfromCsv(const std::string &filename);
   std::string getCloseDate(std::string date);
};
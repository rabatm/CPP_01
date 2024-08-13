#include "BitcoinExchange.hpp"

std::string intputDate(std::string &date) {
   std::cout
       << "📆 saissir la date : sous la forme YYYY-MM-DD or kisskiss for exit"
       << std::endl;
   std::cin >> date;
   return date;
}

int main() {
   BitcoinExchange exchange;
   exchange.loadItemsfromCsv("data.csv");
   std::string date;
   intputDate(date);
   while (date != "kisskiss" && isValidDate(date)) {
      std::cout << "Close date: " << exchange.getCloseDate(date) << std::endl;
      intputDate(date);
   }
   return 0;
}
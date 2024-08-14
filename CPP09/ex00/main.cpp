#include <iostream>
#include "BitcoinExchange.hpp"
#include "Utils.hpp"

int main(int argc, char *argv[]) {
   if (argc != 2) {
      std::cerr << "😿 Error: missing file name." << std::endl;
      std::cerr << "🧑‍💻 Usage: " << argv[0] << " filename.csv"
                << std::endl;
      return 1;
   }

   BitcoinExchange exchange;
   if (!exchange.loadItemsfromCsv("data.csv")) {
      return 1;
   }

   std::ifstream input(argv[1]);
   if (!input.is_open()) {
      std::cerr << "😿 Error: could not open file." << std::endl;
      return 1;
   }
   std::string line;

   // Vérifier l'en-tête du fichier
   if (std::getline(input, line)) {
      std::stringstream ss(line);
      std::string headerDate, headerValue;

      std::getline(ss, headerDate, '|');
      std::getline(ss, headerValue);

      trim(headerDate);
      trim(headerValue);

      if (headerDate != "date" || headerValue != "value") {
         std::cerr << headerDate << std::endl;
         std::cerr << headerValue << std::endl;
         std::cerr << "😿 Error: invalid header. Expected 'date | value'"
                   << std::endl;
         return 1;
      }
   } else {
      std::cerr << "😿 Error: unable to read header" << std::endl;
      return 1;
   }

   while (std::getline(input, line)) {
      std::string date;
      std::string valueStr;
      std::stringstream ss(line);

      std::getline(ss, date, '|');
      std::getline(ss, valueStr);

      trim(date);
      trim(valueStr);

      if (!isValidDate(date)) {
         std::cerr << "😿 Error: bad input => " << line << std::endl;
         continue;
      }

      double value;
      std::stringstream valueStream(valueStr);
      valueStream >> value;
      if (valueStream.fail() || !valueStream.eof()) {
         std::cerr << "😿 Error: not a positive number." << std::endl;
         continue;
      }
      if (value < 0 || value > 1000) {
         std::cerr << "😿 Error: too large a number." << std::endl;
         continue;
      }

      double price = exchange.getPrice(date);
      if (price == 0) {
         std::cerr << "😿 Error: date not found in database." << std::endl;
      } else {
         std::cout << date << " => " << value << " = " << value * price
                   << std::endl;
      }
   }

   input.close();
   return 0;
}

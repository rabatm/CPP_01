#pragma once
#include <fstream>
#include <sstream>
#include <string>

bool isLeapYear(int year);
bool isValidDate(const std::string &date);
time_t convertDateToTimeT(const std::string &date);
void trim(std::string &s);

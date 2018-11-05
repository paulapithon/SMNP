//
// Created by calazans on 04/11/18.
//

#ifndef CLIENT_STRINGUTILS_H
#define CLIENT_STRINGUTILS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& pString, const char delimiter);
std::string hexToString(int value);
void addInteger(std::string& pstring, const unsigned int value);
std::string addLeadingZeros(const std::string& pstring);
std::string toHex(const std::string& pString);

template <typename T>
std::string addLeadingZeros(T pValue);

template <typename T>
std::string addLeadingZeros(T pValue) {
    char addValue[20];
    sprintf(addValue,"%.2x",pValue);
    return std::string(addValue);
}
#endif //CLIENT_STRINGUTILS_H

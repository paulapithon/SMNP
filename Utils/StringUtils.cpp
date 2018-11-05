//
// Created by calazans on 04/11/18.
//

#include <cstring>
#include "StringUtils.h"
//OPTIMIZE
std::vector<std::string> split(const std::string& pString, const char delimiter ){
    std::vector<std::string> rValue;
    std::string temp;
    std::string test = pString;
    size_t pos = test.find(delimiter);
    while(pos == 0){
        test = test.substr(1);
        pos = test.find(delimiter);
    }
    while(pos > 0 && pos < test.size()){
        rValue.push_back(test.substr(0,pos));
        test = test.substr(pos+1);
        pos = test.find(delimiter);
    }
    rValue.push_back(test);
    return rValue;
}

std::string hexToString(int value){
    char info[15];
    sprintf(info,"%x",value);
    return std::string(info);
}


void addInteger(std::string& pstring, const unsigned int value) {
    char addValue[20];
    sprintf(addValue,"%.2x",value);
    pstring.append(addValue);
}

std::string addLeadingZeros(const std::string& pstring) {
    return addLeadingZeros(atoi(pstring.c_str()));
}

std::string toHex(const std::string& pString){
    std::string rValue;
    char value[50];
    for (int i = 0; i < pString.size(); ++i) {
        sprintf(value,"%.2x",(int)pString[i]);
        rValue.append(value);
    }
    return rValue;
}
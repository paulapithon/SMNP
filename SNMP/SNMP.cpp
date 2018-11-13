//
// Created by calazans on 04/11/18.
//

#include "SNMP.h"
#include <string>
#include <cmath>
#include <cstring>
#include "../Utils/StringUtils.h"
#include <thread>
#include <mutex>
#include <ctime>
#include <regex>

#define OID_VALUE "2b"
#define VAR_BIND_TYPE "30"
#define VALUE_FIELD "0500"
#define VAR_BIND_LIST_TYPE "30"
#define OID_TYPE "06"
#define ERROR_INDEX "020100"
#define ERROR "020100"
#define REQUEST_ID "020101"

std::mutex DataSocketMutex;

std::string getStringComplexOIDPart(const unsigned int pValue) {
    std::string result;

    unsigned int count = 0;
    unsigned int value = pValue;
    unsigned int integerPart;

    while (value >= 128) {
        value = value >> 7;
        count++;
    }

    unsigned int rest = pValue;

    for (int j = count - 1; j > 0; j--) {
        integerPart = (rest >> 7);
        rest -= integerPart << 7, j;
        addInteger(result,integerPart + 128);
    }

    addInteger(result,rest);

    return result;
}

void SNMP::addElem(const std::string& message){
    std::string in(message.c_str());
    this->snmpAnswerHistory.push_back(in);
}
std::string SNMP::decode(const SNMPMessageName::SNMPMessage& snmpMessage) const {
    std::string result = "";
    size_t oidLength;
    std::string oidType;
    char oidTotal[300];
    char varBindTotal[300];
    char varBindListTotal[300];
    char PDU[300];
    char community[300];
    char message[300];

    // OID
    std::vector<std::string> oidParts = split(snmpMessage.objectId,'.');

    std::string pubOrPri = snmpMessage.community;
    std::string oidValue = OID_VALUE;
    int oidPartValue;

    for (int i = 2; i < oidParts.size(); i++) {
        oidPartValue = atoi(oidParts[i].c_str());
        if (oidPartValue > 127) {
            oidValue += getStringComplexOIDPart(oidPartValue);
        } else {
             oidValue += addLeadingZeros(oidParts[i]);
        }
    }

    oidLength = oidValue.length() / 2;

    sprintf(oidTotal,"%s%s%s",OID_TYPE,addLeadingZeros(oidLength).c_str(),oidValue.c_str());

    // VarBind
    sprintf(varBindTotal,"%s%s%s%s", VAR_BIND_TYPE , addLeadingZeros((oidLength + 2 + 2)).c_str(),oidTotal,VALUE_FIELD);

    // VarBindList
    sprintf(varBindListTotal,"%s%s%s", VAR_BIND_LIST_TYPE , addLeadingZeros((strlen(varBindTotal) / 2)).c_str(),varBindTotal);


    // PDU
    sprintf(PDU,"%.2x%s%s%s%s%s",0xa0,addLeadingZeros((9 + ((strlen(varBindListTotal)/2)))).c_str(),REQUEST_ID, ERROR,ERROR_INDEX, varBindListTotal);
	std::string hexPubOrPri = toHex(pubOrPri);
    // Community
    sprintf(community,"%.2x%s%s",0x04,addLeadingZeros(pubOrPri.length()).c_str(), hexPubOrPri.c_str());

    // Version
    const char* version = "020100";

     // Message
    sprintf(message, "%.2x%s%s%s%s",0x30,addLeadingZeros( 3 + (strlen(community) / 2) + (strlen(PDU) / 2) ).c_str(),version,community, PDU);
    std::string rValue(message);
    return rValue;
}
std::string SNMP::encode(const std::string& snmpMessage) const {
    std::string rValue;
    int number;
    int value;
    for (int i = 0; i < snmpMessage.size(); i+=2) {
        value = 0;
        number = snmpMessage[i];
        if(number >= '0' && number <=  '9'){
            number -= '0';
        }
		else
		{				
			number -= 'a';
			number += 10;
        }
		value = number * 16;
        number = snmpMessage[i+1];
        if(number >= '0' && number <=  '9'){
            number -= '0';
        }
		else{
            number -= 'a';
			number += 10;
        }
        value += number;
		rValue += ((char)value);
    }
    return rValue;
}
std::string wait(DatagramSocket* ds, SNMP* thisObj){
    DataSocketMutex.lock();
    DatagramSocket* acutalSocket = ds;
    DataSocketMutex.unlock();
	std::string tempVar = acutalSocket->getMessage();
    thisObj->addElem(tempVar);
    delete acutalSocket;
	return tempVar;
}


std::string SNMP::sendAndWait(const std::string& ip, int port, const std::string& message){
    DataSocketMutex.lock();
    this->ds = new DatagramSocket(ip, port);
    DataSocketMutex.unlock();
    this->ds->sendMessage(message.c_str(), message.size());
    std::string rValue = wait(this->ds,this);
	delete this->ds;
	return rValue;
}


int main(){
	int count = 0;
    int value = 128 * 128;
    SNMP s;
    SNMPMessageName::SNMPMessage mes;
    mes.community = "public";
    mes.targetIp = "192.168.15.5";
    mes.targetPort = "161";
	mes.objectId = ".1.3.6.1.2.1.1.1.0";

	std::string messfae = s.decode(mes);
    // printf("%s\n",messfae.c_str());
    //printf("%s\n",s.encode(messfae).c_str());
    std::string test = s.sendAndWait(mes.targetIp, 161, s.encode(messfae));
	
    std::regex reg("[^\\w\\d\\s!-/\\:;]+");
    test = regex_replace(test, reg, "");
	printf("%s\n",test.c_str());
	return 0;
}
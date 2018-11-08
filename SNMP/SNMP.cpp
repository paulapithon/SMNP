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

    for (int i = 1; i < oidParts.size(); i++) {
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
    sprintf(varBindTotal,"%s%s%s%s", VAR_BIND_TYPE , addLeadingZeros((oidLength + 4)).c_str(),oidTotal,VALUE_FIELD);

    // VarBindList
    sprintf(varBindListTotal,"%s%s%s", VAR_BIND_LIST_TYPE , addLeadingZeros((strlen(varBindTotal) / 2)).c_str(),varBindTotal);


    // PDU
    sprintf(PDU,"a0%s%s%s%s%s",addLeadingZeros((9 + (strlen(varBindListTotal)))).c_str(),REQUEST_ID, ERROR,ERROR_INDEX, varBindListTotal);

    // Community
    sprintf(community,"04%s%s",addLeadingZeros(toHex(pubOrPri).length() / 2).c_str(), toHex(pubOrPri).c_str());

    // Version
    const char* version = "020100";

     // Message
    sprintf(message, "30%s%s%s%s",addLeadingZeros( 3 + (strlen(community) / 2) + (strlen(PDU) / 2) ).c_str(),
            version,community, PDU);
    std::string teste(message);
    return teste;
}
void wait(DatagramSocket* ds, SNMP* thisObj){
    printf("Hey");
    DataSocketMutex.lock();
    DatagramSocket* acutalSocket = ds;
    DataSocketMutex.unlock();
    thisObj->addElem(acutalSocket->getMessage());
    delete acutalSocket;
}


void SNMP::sendAndWait(const std::string& ip, int port, const std::string& message){
    DataSocketMutex.lock();
    this->ds = new DatagramSocket(ip, port);
    DataSocketMutex.unlock();

    this->ds->sendMessage(message);
//    std::thread waiting(wait,this->ds,this);
//    waiting.join();

    DataSocketMutex.lock();
    DatagramSocket* acutalSocket = ds;
    DataSocketMutex.unlock();
    this->addElem(acutalSocket->getMessage());
    delete acutalSocket;
}



int main(){
	const char* teste[] = {"1.3.6.1.4.1.12619.1.1.1",
						   "1.3.6.1.4.1.12619.1.1.2",
						   "1.3.6.1.4.1.12619.1.1.3",
						   "1.3.6.1.4.1.12619.1.2.1",
						   "1.3.6.1.4.1.12619.1.2.2",
						   "1.3.6.1.4.1.12619.1.2.2.1",
						   "1.3.6.1.4.1.12619.1.2.2.1.1",
						   "1.3.6.1.4.1.12619.1.2.2.1.2",
						   "1.3.6.1.4.1.12619.1.2.2.1.3",
						   "1.3.6.1.4.1.12619.1.2.2.1.4",
						   "1.3.6.1.4.1.12619.1.3.1",
						   "1.3.6.1.4.1.12619.1.3.2",
						   "1.3.6.1.4.1.12619.1.3.3",
						   "1.3.6.1.4.1.12619.1.3.4",
						   "1.3.6.1.4.1.12619.1.3.5",
						   "1.3.6.1.4.1.12619.1.3.6",
						   "1.3.6.1.4.1.12619.1.4.1"}; 
    int count = 0;
    int value = 128 * 128;
    SNMP s;
    SNMPMessageName::SNMPMessage mes;
    mes.community = "public";
    mes.targetIp = "192.168.15.7";
    mes.targetPort = "9002";
	for(int i = 0; i < 17;i++)
	{
		mes.objectId = teste[i];//".1.3.6.1.2.1.2.2.1.1.1";

		std::string messfae = s.decode(mes);
		printf("%s\n",messfae.c_str());
        s.sendAndWait(mes.targetIp, 9002, messfae);
	}
}
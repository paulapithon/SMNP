//
// Created by calazans on 04/11/18.
//

#include "SNMP.h"
#include <string>
#include <cmath>
#include <cstring>
#include "../Utils/StringUtils.h"

#define OID_VALUE "2b"
#define VAR_BIND_TYPE "30"
#define VALUE_FIELD "0500"
#define VAR_BIND_LIST_TYPE "30"
#define OID_TYPE "06"
#define ERROR_INDEX "020100"
#define ERROR "020100"
#define REQUEST_ID "020101"

std::string getStringComplexOIDPart(const unsigned int pValue) {
    std::string result;

    unsigned int count = 0;
    unsigned int value = pValue;
    unsigned int integerPart;

    while (value >= 128) {
        value = value >> 7;
        count++;
    }
    printf("%d\n",value);

    unsigned int rest = pValue;

    for (int j = count - 1; j > 0; j--) {
        integerPart = (rest >> 128);
        rest -= integerPart << 128, j;
        addInteger(result,integerPart + 128);
    }

    addInteger(result,rest);

    return result;
}

void SNMP::decode(SNMPMessageName::SNMPMessage snmpMessage){
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
    printf("302902010004067075626c6963a02f0201010201000201003011300f060b2b030601020102020101010500 \n%s , %d ",message,teste.compare("302902010004067075626c6963a02f0201010201000201003011300f060b2b030601020102020101010500"));
}
int main(){
    int count = 0;
    int value = 128 * 128;
    SNMP s;
    SNMPMessageName::SNMPMessage mes;
    mes.objectId = ".1.3.6.1.2.1.2.2.1.1.1";
    mes.community = "public";
    mes.targetIp = "127.0.0.1";
    mes.targetPort = "8080";

    s.decode(mes);
}
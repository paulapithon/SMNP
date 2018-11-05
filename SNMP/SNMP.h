//
// Created by calazans on 04/11/18.
//

#ifndef SERVER_SNMP_H
#define SERVER_SNMP_H


#include <vector>
#include "SMNPMessage.h"

class SNMP {
private:
    std::vector<SNMPMessageName::SNMPMessage> snmpMessageHistroy;
public:
    void decode(SNMPMessageName::SNMPMessage snmpMessage);
};


#endif //SERVER_SNMP_H

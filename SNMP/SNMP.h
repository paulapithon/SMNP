//
// Created by calazans on 04/11/18.
//

#ifndef SERVER_SNMP_H
#define SERVER_SNMP_H


#include <vector>
#include <string>
#include "SMNPMessage.h"
#include "../Socket/DatagramSocket.h"

class SNMP {
private:
    DatagramSocket* ds;
    std::vector<SNMPMessageName::SNMPMessage> snmpMessageHistory;
    std::vector<std::string> snmpAnswerHistory;
public:
    std::string decode(const SNMPMessageName::SNMPMessage& snmpMessage) const;
    void sendAndWait(const std::string& ip, int port, const std::string& message);
    void addElem(const std::string& message);
};


#endif //SERVER_SNMP_H

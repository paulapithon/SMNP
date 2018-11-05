#ifndef SNMPSESSION_H
#define SNMPSESSION_H

#include <string>
#include <sys/socket.h>

class SNMPSession{
private:
    int udpSocket;
    QHostAddress *agentAddress;
    qint16 agentPort;
    qint16 socketPort;

    int getValueFromGetResponse(QString &receivedValue, QByteArray &receivedDatagram,
                                const int &errorIndex, const int &valueTypeIndex,
                                const int &valueIndex, const int &valueLenghtIndex);
    QByteArray convertIntAccordingToBER(int valueToConvert);
    void convertOIDAccordingToBER(QByteArray &oid);
    void convertOIDAccordingToBER(QByteArray &oid);


public:
    SNMPSession();
    SNMPSession(const std::string &agentAddress, int agentPort, int socketPort);
    ~SNMPSession();

// SNMP message methods
    int sendSetRequest(const QString &communityStringParameter,
                       const QString oidParameter, int value);
    int sendSetRequest(const QString &communityStringParameter,
                       const QString oidParameter, const QString &valueParameter);
    int sendGetRequest(QString &receivedValue,
                       const QString &communityStringParameter, const QString &oidParameter);

// additional public methods
};

#endif // SNMPSESSION_H
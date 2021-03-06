#include "snmpsession.h"

//----[ Constructors/Destructors ]-----------------------------------------------------

SNMPSession::SNMPSession()
{
}

/**
*   The constructor will initialize the SNMPSession object with the given values,
*   and will also bind the UDP socket to the specified socketPort.
*   This allows the socket to emit the readyRead signal on datagram arrival.
*/
SNMPSession::SNMPSession(const std::string &agentAddress, int agentPort, int  socketPort)
{
    this->agentAddress = agentAddress;
    this->agentPort = agentPort;
    this->socketPort = socketPort;
    udpSocket.bind(socketPort);
}

SNMPSession::~SNMPSession()
{
    delete agentAddress;
}


//----[ SNMP set-request/get-request methods ]-------------------------------------------------


/**
*   This method will send a SNMP set-request with the specified community string,
*   OID and integer value.
*   Returns 0 on success or one of the following error codes on failture :
*   1 -- Response message too large to transport
*   2 -- The name of the requested object was not found
*   3 -- A data type in the request did not match the data type in the SNMP agent
*   4 -- The SNMP manager attempted to set a read-only parameter
*   5 -- General Error (some error other than the ones listed above)
*   6 -- Timeout, no response from agent (5 seconds)
*/
int SNMPSession::sendSetRequest(const QString &communityStringParameter, const QString oidParameter, int value)
{
    QByteArray communityString = communityStringParameter.toAscii();
    QByteArray oid = oidParameter.toAscii();

    QByteArray datagram; // the datagram to send
    QByteArray receivedDatagram; // the received value
    const int errorIndex = 14 + communityString.size();

// include Value field
    int currentLength = 0;
    if(value > 256)
    {
        unsigned char secondByte = value;
        int firstByte = value >> 8;
        datagram.push_back(firstByte);
        datagram.push_back(secondByte);
        datagram.push_front(0x02);
        datagram.push_front(0x02);
        currentLength += 4;
    } else
    {
        datagram.push_front(value);
        datagram.push_front(0x01);
        datagram.push_front(0x02);
        currentLength += 3;
    }

    convertOIDAccordingToBER(oid);

// include Object Identifier field
    datagram.push_front(oid);
    datagram.push_front(oid.size());
    datagram.push_front(0x6);
    currentLength += oid.size();
    currentLength += 2;

// include Varbind field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Varbind List field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Error Index field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include Error field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include Request ID
    datagram.push_front((rand() % 100 + 1));
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include PDU field
    datagram.push_front(currentLength);
    datagram.push_front(0xA3);
    currentLength += 2;

// include Community string
    datagram.push_front(communityString);
    datagram.push_front(communityString.size());
    datagram.push_front(0x04);
    currentLength += communityString.size();
    currentLength += 2;

// include SNMP version
    datagram.push_front((char)0x0);
    datagram.push_front(0x01);
    datagram.push_front(0x02);
    currentLength += 3;

// finish the construction with the SNMP Message lenght and type code
    datagram.push_front(currentLength);
    datagram.push_front(0x30);

// sending
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);

// Receive if there is an answer. Timeout after 5 seconds
    int timeoutTimer = 0;
    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending second try
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending third try
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 500)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }
        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    return 6;
}


/**
*   This method will send a SNMP set-request with the specified community string,
*   OID and string value.
*   Returns 0 on success or one of the following error codes on failture :
*   1 -- Response message too large to transport
*   2 -- The name of the requested object was not found
*   3 -- A data type in the request did not match the data type in the SNMP agent
*   4 -- The SNMP manager attempted to set a read-only parameter
*   5 -- General Error (some error other than the ones listed above)
*   6 -- Timeout, no response from agent (5 seconds)
*/
int SNMPSession::sendSetRequest(const QString &communityStringParameter,
                                const QString oidParameter, const QString &valueParameter)
{
    QByteArray communityString = communityStringParameter.toAscii();
    QByteArray oid = oidParameter.toAscii();
    QByteArray value = valueParameter.toAscii();

    QByteArray datagram; // the datagram to send
    QByteArray receivedDatagram; // the received value
    const int errorIndex = 14 + communityString.size();

    // check if the string is  Address
    bool isIPAddress = false;
    int dots = 0;

    for(int i=0;i<value.length();i++)
    {
        if(value.at(i) == '.')
            dots++;
    }

    if(dots == 3)
    {
        isIPAddress = true;
    }

// include Value field
    int currentLength = 0;
    if(isIPAddress)
    {
        QList<QByteArray> octets = value.split('.');
        for(int i=0;i<4;i++)
            datagram.push_back(octets[i].toInt());
        currentLength = 4;
        datagram.push_front(currentLength);
        datagram.push_front(0x40);
        currentLength += 2;
    } else
    {
        for(int i=0;i<value.size();i++)
        {
            datagram.push_back(value.at(i));
            currentLength++;
        }

        datagram.push_front(currentLength);
        datagram.push_front(0x04);
        currentLength += 2;
    }

    convertOIDAccordingToBER(oid);

// include Object Identifier field
    datagram.push_front(oid);
    currentLength += oid.size();
    datagram.push_front(oid.size());
    datagram.push_front(0x6);
    currentLength += 2;

// include Varbind field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Varbind List field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Error Index field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include Error field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include Request ID
    datagram.push_front((rand() % 100 + 1));
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include PDU field
    datagram.push_front(currentLength);
    datagram.push_front(0xA3);
    currentLength += 2;

// include Community string
    datagram.push_front(communityString);
    datagram.push_front(communityString.size());
    datagram.push_front(0x04);
    currentLength += communityString.size();
    currentLength += 2;

// include SNMP version
    datagram.push_front((char)0x0);
    datagram.push_front(0x01);
    datagram.push_front(0x02);
    currentLength += 3;

// finish the construction with the SNMP Message lenght and type code
    datagram.push_front(currentLength);
    datagram.push_front(0x30);

// sending
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    int timeoutTimer = 0;

    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending second attempt
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending third attempt
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 500)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            receivedDatagram.resize(udpSocket.pendingDatagramSize());
            udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());
            return receivedDatagram.at(errorIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    return 6;
}

/**
*   This method will send a SNMP get-request with the specified community string and OID
*   and then place the received get-response value in the receivedValue variable.
*   Returns 0 on success or one of the following error codes on failture :
*   1 -- Response message too large to transport
*   2 -- The name of the requested object was not found
*   3 -- A data type in the request did not match the data type in the SNMP agent
*   4 -- The SNMP manager attempted to set a read-only parameter
*   5 -- General Error (some error other than the ones listed above)
*   6 -- Timeout, no response from agent (5 seconds)
*/
int SNMPSession::sendGetRequest(QString &receivedValue,
                                const QString &communityStringParameter, const QString &oidParameter)
{
    QByteArray communityString = communityStringParameter.toAscii();
    QByteArray oid = oidParameter.toAscii();

    QByteArray datagram; // the datagram to send
    QByteArray receivedDatagram; // the received datagram

    const int errorIndex = 14 + communityString.size();
    const int valueTypeIndex = 24 + oid.split('.').size() + communityString.size() + 1;
    const int valueLenghtIndex = 24 + oid.split('.').size() + communityString.size() + 2;
    const int valueIndex = 24 + oid.split('.').size() + communityString.size() + 3;

// include Value field
    int currentLength = 2;
    datagram.push_front((char)0x0);
    datagram.push_front(0x05);

    convertOIDAccordingToBER(oid);

// include Object Identifier field
    datagram.push_front(oid);
    currentLength += oid.size();
    datagram.push_front(oid.size());
    datagram.push_front(0x6);
    currentLength += 2;

// include Varbind field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Varbind List field
    datagram.push_front(currentLength);
    datagram.push_front(0x30);
    currentLength += 2;

// include Error Index field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;
// include Error field
    datagram.push_front((char)0x0);
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include Request ID
    datagram.push_front((rand() % 100 + 1));
    datagram.push_front(0x1);
    datagram.push_front(0x2);
    currentLength += 3;

// include PDU field
    datagram.push_front(currentLength);
    datagram.push_front(0xA0);
    currentLength += 2;

// include Community string
    datagram.push_front(communityString);
    datagram.push_front(communityString.size());
    datagram.push_front(0x04);
    currentLength += communityString.size();
    currentLength += 2;

// include SNMP version
    datagram.push_front((char)0x0);
    datagram.push_front(0x01);
    datagram.push_front(0x02);
    currentLength += 3;

// finish the construction with the SNMP Message lenght and type code
    datagram.push_front(currentLength);
    datagram.push_front(0x30);

// SEND IT !!!
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);

// Receive it
    int result = 0;

    int timeoutTimer = 0;
    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            return result = getValueFromGetResponse(receivedValue, receivedDatagram, errorIndex,
                                                    valueTypeIndex, valueIndex, valueLenghtIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending second attempt
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 3000)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            return result = getValueFromGetResponse(receivedValue, receivedDatagram, errorIndex,
                                                    valueTypeIndex, valueIndex, valueLenghtIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    // sending third attempt
    udpSocket.writeDatagram(datagram, datagram.size(), *agentAddress, agentPort);
    timeoutTimer = 0;

    while(timeoutTimer <= 500)
    {
        if(udpSocket.hasPendingDatagrams())
        {
            return result = getValueFromGetResponse(receivedValue, receivedDatagram, errorIndex,
                                                    valueTypeIndex, valueIndex, valueLenghtIndex);
        }

        ManagerThread::sendSleep(1);
        timeoutTimer++;
    }

    return 6;
}


//----[ Additional public methods ]-------------------------------------------------



//----[ Other private methods ]-----------------------------------------------------

/**
*   This method will extract the value from the specified GetResponse datagram.
*   Returns 0 on success or one of the following error codes on failture :
*   1 -- Response message too large to transport
*   2 -- The name of the requested object was not found
*   3 -- A data type in the request did not match the data type in the SNMP agent
*   4 -- The SNMP manager attempted to set a read-only parameter
*   5 -- General Error (some error other than the ones listed above)
*   6 -- Timeout, no response from agent (5 seconds)
*/
int SNMPSession::getValueFromGetResponse(QString &receivedValue, QByteArray &receivedDatagram,
                                         const int &errorIndex, const int &valueTypeIndex,
                                         const int &valueIndex, const int &valueLenghtIndex)
{
    receivedDatagram.resize(udpSocket.pendingDatagramSize());
    udpSocket.readDatagram(receivedDatagram.data(), receivedDatagram.size());

    // if there is a problem, return the error code
    if(receivedDatagram.at(errorIndex) != 0)
    {
        return receivedDatagram.at(21);
    }

    // if it's integer
    if(receivedDatagram.at(valueTypeIndex) == 0x02)
    {
        if(valueIndex == receivedDatagram.size()-1) // if value is one byte
        {
            receivedValue = QString::number((unsigned char)receivedDatagram.at(valueIndex), 10);

            return 0;
        } else if(receivedDatagram.at(valueIndex) == 0) // if it's two bytes, but the first is 0, it's a bug
        {
            receivedValue = QString::number((unsigned char)receivedDatagram.at(valueIndex + 1), 10);

            return 0;
        } else // else, the value is two bytes and therefore conversion is needed
        {
            int firstHex = (unsigned char)receivedDatagram.at(valueIndex);
            int secondHex = (unsigned char)receivedDatagram.at(valueIndex+1);
            int resultValue = (firstHex * 256) + secondHex;

            receivedValue = QString::number(resultValue);
            return 0;
        }
    }

    // if it's an  IP address
    if(receivedDatagram.at(valueTypeIndex) == 0x40)
    {
        QString octet;
        for(int i = 0;i < receivedDatagram.at(valueLenghtIndex);i++){
            octet = QString::number((unsigned char)receivedDatagram.at(valueIndex+i), 10);
            receivedValue.push_back(octet);
            receivedValue.push_back(".");
        }

        receivedValue.truncate(receivedValue.size()-1);

        return 0;
    }

    // if it's an octet string
    if(receivedDatagram.at(valueTypeIndex) == 0x04)
    {
        for(int i = 0;i < receivedDatagram.at(valueLenghtIndex);i++){
            if(receivedDatagram.at(valueIndex+i) == 0x0)
                continue;
            receivedValue.push_back(receivedDatagram.at(valueIndex+i));
        }

        return 0;
    }

    return 6;
}


/**
*   This method will return the bytes of an integer bigger than 127,
*   according to the Basic Encoding Rules (BER).
*/
QByteArray SNMPSession::convertIntAccordingToBER(int valueToConvert)
{
    QByteArray convertedValue;
    QString binValue = QString::number(valueToConvert, 2);

    if(binValue.size()>14)
    {
        QString firstByte;
        QString secondByte;
        QString thirdByte;

        thirdByte = binValue.right(7);
        binValue.truncate(binValue.size()-7);
        secondByte = binValue.right(7);
        secondByte.push_front("1");
        binValue.truncate(binValue.size()-7);
        firstByte = binValue;

        while(firstByte.size()<7)
        {
            firstByte.push_front("0");
        }
        firstByte.push_front("1");

        convertedValue.push_front(thirdByte.toInt(NULL, 2));
        convertedValue.push_front(secondByte.toInt(NULL, 2));
        convertedValue.push_front(firstByte.toInt(NULL, 2));
    } else
    {
        QString secondByte;
        QString firstByte;
        secondByte = binValue.right(7);
        binValue.truncate(binValue.size()-7);
        firstByte = binValue;
        while(firstByte.size()<7)
        {
            firstByte.push_front("0");
        }

        firstByte.push_front("1");

        convertedValue.push_front(secondByte.toInt(NULL, 2));
        convertedValue.push_front(firstByte.toInt(NULL, 2));
    }

    return convertedValue;
}

/**
*   This method will convert a given OID according to the Basic Encoding Rules (BER).
*   It uses SNMPSession::convertIntAccordingToBER.
*/
void SNMPSession::convertOIDAccordingToBER(QByteArray &oid)
{
    QList<QByteArray> oidPartsList = oid.split('.');
    int currentValue = 0;
    int addedNumbers = 0;
    oidPartsList.removeFirst();
    oid[0] = 0x2B;

    for(int i = 1;i < oidPartsList.size();i++)
    {
        if((oidPartsList[i].size())>1)
        {
            QString tempValue;
            for(int j = 0;j<oidPartsList[i].size();j++)
            {
                tempValue.push_back(oidPartsList[i].at(j));
            }
            currentValue = tempValue.toInt(NULL, 10);
        } else
        {
            QString tempValue;
            tempValue = oidPartsList[i].at(0);
            currentValue = tempValue.toInt(NULL, 10);
        }
        if(currentValue<=127)
        {
            oid[i+addedNumbers] = currentValue;
        } else
        {
            QByteArray convertedValue = convertIntAccordingToBER(currentValue);

            if(convertedValue.size() == 2)
            {
                oid[i+addedNumbers] = convertedValue[0];
                oid[i+1+addedNumbers] = convertedValue[1];
                addedNumbers++;
            } else
            {
                oid[i+addedNumbers] = convertedValue[0];
                oid[i+1+addedNumbers] = convertedValue[1];
                oid[i+2+addedNumbers] = convertedValue[2];
                addedNumbers =+ 2;
            }

        }
    }

    oid.resize(oidPartsList.size()+addedNumbers);
}
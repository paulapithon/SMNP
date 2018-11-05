//
// Created by calazans on 04/11/18.
//

#ifndef SERVER_SMNPMESSAGE_H
#define SERVER_SMNPMESSAGE_H
namespace SNMPMessageName{
    typedef struct SNMPMessageStruct{
        const char* community;
        const char* objectId;
        const char* targetIp;
        const char* targetPort;
    } SNMPMessage;
}

#endif //SERVER_SMNPMESSAGE_H

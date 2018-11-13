//
// Created by Pichau on 13/11/2018.
//

#include "SNMPMessager.h"
#include <regex>
#include <string>
#include "../SNMP/SNMP.h"
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jstring JNICALL Java_br_com_poli_redes_jni_SNMPMessager_SendMenssage
            (JNIEnv *env, jobject, jstring ip, jstring port, jstring oid){
        const char *ipNativeString = (env)->GetStringUTFChars( ip, 0);
        const char *portNativeString = (env)->GetStringUTFChars( port, 0);
        const char *oidNativeString = (env)->GetStringUTFChars( oid, 0);

        int count = 0;
        int value = 128 * 128;
        SNMP s;
        SNMPMessageName::SNMPMessage mes;
        mes.community = "public";
        mes.targetIp = *ipNativeString;
        mes.targetPort = *portNativeString;
        mes.objectId = *oidNativeString;

        std::string messfae = s.decode(mes);
        std::string test = s.sendAndWait(mes.targetIp, atoi(portNativeString), s.encode(messfae));

        std::regex reg("[^\\w\\d\\s!-/\\:;]+");
        test = regex_replace(test, reg, "");
        jstring result = env->NewStringUTF(test.c_str());

        (env)->ReleaseStringUTFChars( oid, portNativeString);

        (env)->ReleaseStringUTFChars(port, portNativeString);

        (env)->ReleaseStringUTFChars(ip, ipNativeString);
    return  result;
}



#ifdef __cplusplus
}
#endif
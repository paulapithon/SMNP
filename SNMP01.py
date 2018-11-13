#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket
import pysnmp
import struct

c = pysnmp.version
print c
#Comm = raw_input('Digite a community desejada (default = public): ')
#if not Comm:
Comm = 'public'
lenComm = len(Comm)

#OID = raw_input('Digite o OID desejado: ')
OID = ".1.3.6.1.2.1.1.1.0"
OID = OID.replace(".", "")
OID = OID[2:]
oid = chr(0x2b)
for i in OID:
    oid = oid + chr(int(i))
lenOID = len(oid)

endIP = raw_input('Digite o endereco do alvo: ')

Port = int(raw_input('Digite a porta do alvo (161 ou ): '))

#prepara socket e conecta a interface - sem o 3o. argumento (protocol)
#nao ha filtragem do tipo de protocolo na recepcao
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.settimeout(10)
s.bind(('', 0))

#Monta mensagem SNMP de trás para frente
#Value Field
SVal = chr(05) + chr(00)

#Objeto Field
TypeOid = chr(0x06)
SOid = TypeOid + chr(lenOID) + oid

#Sequence / Varbind Type Field
TypeVarbind = chr(0x30) # tipo varbind
SVarbind = TypeVarbind + chr(lenOID + 2 + 2) + SOid + SVal

#Sequence / Varbind List Field
TypeVarbindList = chr(0x30) # tipo varbind list
SVarbindList = TypeVarbindList + chr(len(SVarbind)) + SVarbind

#campos Request ID, Error, ErrorIndex
RqID = chr(2) + chr(1) + chr(1)
Err = chr(2) + chr(1) + chr(0)
ErrIndex = chr(2) + chr(1) + chr(0)
print len(SVarbindList)
SPDU = chr(0xa0) + chr(3 + 3 + 3 + len(SVarbindList)) + RqID + Err + ErrIndex + SVarbindList

#Community
SComm = chr(4) + chr(lenComm) + Comm

#Versao
SVersao = chr(2) + chr(1) + chr(0)

#SNMP MESSAGE
MsgType = chr(0x30)
SSnmp = MsgType + chr(3 + 2 + lenComm + len(SPDU)) + SVersao + SComm + SPDU
print '\n', list(SSnmp)

#envia frame
s.sendto(SSnmp, (endIP, Port))
print 'Quadro enviado ...'
#print 'VERIFIQUE A RESPOSTA DO ALVO COM O WIRESHARK'

#recebe resposta snmp
while True:
	#print 'Aguardando resposta ...'
	try:
		Rxbuf = s.recv(2000)
		print 'Resposta Recebida!\n', list(Rxbuf)
	except socket.timeout:
		print 'TIME OUT!!!'
		exit()
	S = Rxbuf[0]
	break
#
s.close()

print 'Fim da Operacao. Socket fechado.'

# http://www.net-snmp.org/docs/mibs/
# http://oid-info.com/get/1.3.6.1.2.1.2.2.1.1
'''
interface
.1.3.6.1.2.1.2.1.0 = INTEGER: 3
.1.3.6.1.2.1.2.2.1.1.1 = INTEGER: 1
.1.3.6.1.2.1.2.2.1.1.2 = INTEGER: 2
.1.3.6.1.2.1.2.2.1.1.3 = INTEGER: 3
.1.3.6.1.2.1.2.2.1.2.1 = STRING: lo
.1.3.6.1.2.1.2.2.1.2.2 = STRING: Realtek Semiconductor Co., Ltd. RTL8101/2/6E PCI Express Fast/Gigabit Ethernet controller
.1.3.6.1.2.1.2.2.1.2.3 = STRING: Qualcomm Atheros QCA9565 / AR9565 Wireless Network Adapter
.1.3.6.1.2.1.2.2.1.3.1 = INTEGER: softwareLoopback(24)
.1.3.6.1.2.1.2.2.1.3.2 = INTEGER: ethernetCsmacd(6)
.1.3.6.1.2.1.2.2.1.3.3 = INTEGER: ethernetCsmacd(6)
.1.3.6.1.2.1.2.2.1.4.1 = INTEGER: 65536
.1.3.6.1.2.1.2.2.1.4.2 = INTEGER: 1500
.1.3.6.1.2.1.2.2.1.4.3 = INTEGER: 1500
.1.3.6.1.2.1.2.2.1.5.1 = Gauge32: 10000000
.1.3.6.1.2.1.2.2.1.5.2 = Gauge32: 10000000
'''
'''
system
.1.3.6.1.2.1.1.1.0 = STRING: Linux edison-Inspiron-3442 4.4.0-47-generic #68-Ubuntu SMP Wed Oct 26 19:39:52 UTC 2016 x86_64
.1.3.6.1.2.1.1.2.0 = OID: .1.3.6.1.4.1.8072.3.2.10
.1.3.6.1.2.1.1.3.0 = Timeticks: (701525) 1:56:55.25
.1.3.6.1.2.1.1.4.0 = STRING: Me <me@example.org>
.1.3.6.1.2.1.1.5.0 = STRING: edison-Inspiron-3442
.1.3.6.1.2.1.1.6.0 = STRING: Sitting on the Dock of the Bay
'''

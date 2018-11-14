# Protocolo SMNP
O protocolo SMNP (Simple Management Network Protocol) foi criado para facilitar o monitoramento e gerenciamento de redes permitindo que uma ferramenta de gerenciamento possa trabalhar com produtos e serviços de diversos fabricantes.

O ítem a ser monitorado ou gerenciado é um agente. Quem consulta (GET) ou solicita modificações (SET) é um gerente. O agente tambem tem a função de gerar alertas (TRAP). O agente SNMP, instalado no item a ser gerenciado, contempla uma tabela de informações que pode ser consultada ou modificada pelo sistema gerente. Para que esta consulta possa ser feita, o gerente tem que conhecer as informações que podem ser obtidas do agente SNMP.

![Esquema SMNP](https://image.ibb.co/etQb0L/Screen-Shot-2018-11-14-at-09-50-36.png)

O formato de mensagem SNMP especifica quais campos incluir na mensagem e em qual ordem.  Na camada mais externa, a mensagem SNMP é um campo único, do tipo Sequence. A mensagem inteira é uma sequência de três campos menores: a versão SNMP (Integer), a string de comunidade SNMP e a PDU SNMP (GetRequest ou SetRequest).

![Mensagens SMNP](https://www.rane.com/png/n161fig4.png)

_Esse projeto foi desenvolvido para a cadeira de **Gerência de Redes** 2018.2 da Universidade Politécnica de Pernambuco._

# Tutorial de teste RMI

## Passos para testar a aplicação Servidora com Objetos RMI:

1. Compile o código-fonte do servidor junto ao arquivo da Interface: `javac IMessage.java Server.java`
2. Execute a aplicação em um Console/Terminal: `java Server`

OBS: a aplicação servidora está configurada para subir na porta 8080

## Passos para testar a aplicação Cliente que acessa os Objetos RMI remotamente - precisa estar no mesmo domínio de rede - ex. rede Local (LAN) ou mesmo host (localhost):

1. Compile o código-fonte do servidor junto ao arquivo da Interface: `javac IMessage.java Client.java`
2. Execute a aplicação em um Console/Terminal: `java Client "<hostname>" <port>`

OBS: a aplicação cliente espera 2 argumentos, o primeiro é uma string com a indicação do hostname do servidor (ex. localhost, 192.168.0.12, 200.169.0.3, etc) e o segundo é um número de porta (use a 8080)
Exemplo de invocação do cliente:
`java Client "127.0.0.1" 8080`

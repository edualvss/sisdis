/**
 * Servidor
 * 1. Criar o socket (socket)
 * 2. Vincular a porta (bind)
 * 3. Ficar na escuta (listening)
 * 4. Aceitar conexões de entrada (accept)
 * 5. Enviar/receber
 * 
 * 6. Fechar socket
 */


// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
	char *hello = "Mensagem do SERVIDOR";
	
	// 1. Criar socket
	printf("Criando socket...\n");
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Socket criado!\n");
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	
	// 2. Vincular a porta (bind)
	if (bind(server_fd, (struct sockaddr *)&address,
								sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	printf("Vinculado na porta: %d\n", PORT);

	// 3. Ficar na escuta (listening)
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	// 4. Aceitar conexões de entrada (accept)
	printf("Listening...\n");
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
					(socklen_t*)&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	// 5. Enviar e receber mensagens
	printf("Connection accepted!\n");
	valread = read( new_socket , buffer, BUFFER_SIZE);
	printf("Mensagem recebida: %s\n",buffer );
	send(new_socket , hello , strlen(hello) , 0 );
	printf("Server message sent\n");


	// 6. Fechar conexões
	close(new_socket); // Fecha a conexão com o cliente
	close(server_fd); // Fecha o socket do servidor

	return 0;
}


/*
 * This program is a data-gram socket client file. It is based on the simple DGRAM socket client illustrated by Professor Dave Ogle, and further implemented and modifed by YuChen Gu on 1/18/2022.
 */
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
int Send(char *buffer, int newSocket, struct sockaddr_in serverAddress);

int main(int argc, char *argv[])
{
    int newSocket;
    struct sockaddr_in serverAddress;
    int portNum;
    char serverIP[29];
    char buffer[100];
    if (argc < 3){
        printf("usage is: client <remote IP Address> <remote port number>");
        exit(1);
    }

    newSocket = socket(AF_INET, SOCK_DGRAM, 0);

    portNum = atol(argv[2],NULL,10);
    strcpy(serverIP,argv[1]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNum);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);

    memset (buffer,'\0',100)
    sprintf(buffer, )
}
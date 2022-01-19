/*
 * This program is a data-gram socket server file. It is based on the simple DGRAM socket server illustrated by Professor Dave Ogle, and further implemented and modifed by YuChen Gu on 1/18/2022.
 */

#include <string.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h> 
#include <stdlib.h> 
 
 
int main(int argc, char *argv[]) { 
    int newSocket;
    int returnCode;
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
    char buffer[100];
    int flag = 0;
    int portNum;
    socklen_t clientLength = sizeof(struct sockaddr);

    if (argc < 2){
        printf("usage is: server <portNumber>\n");
        exit(1);
    }

    portNum = atoi(argv[1]);

    newSocket = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNum);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    returnCode = bind(newSocket,buffer, (struct sockaddr *) & serverAddress,sizeof(serverAddress));

    if (rc<0){
        perror ("bind");
        exit(1)
    }
    for(;;;){
        memset(buffer,'\0',100);
        returnCode = recvfrom(newSocket,buffer,sizeof(buffer),flag,(struct sockaddr *) &clientAddress, &clientLength ));
        if(rc<=0){
            printf("error on receive, quitting...");
            break;
        }
        printf("Reveived %d bytes\n",returnCode);
    }
    return 0;
}
 
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
    int newSocket;/*socket describer*/
    int returnCode;/*return code*/
    struct sockaddr_in serverAddress;/*server address*/
    struct sockaddr_in clientAddress;/*client address*/
    char buffer[100];/*buffer*/
    int flag = 0;/*socket call flags*/
    int portNum;/*local port*/
    socklen_t clientLength = sizeof(struct sockaddr);/*client socket length*/

    if (argc < 2){/*check cmd line syntax*/
        printf("usage is: server <portNumber>\n");
        exit(1);
    }

    portNum = atoi(argv[1]);

    /*create socket*/
    newSocket = socket(AF_INET, SOCK_DGRAM, 0);
    /*fill server address*/
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNum);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    /*bind socket with address*/
    returnCode = bind(newSocket, (struct sockaddr *) & serverAddress,sizeof(serverAddress));

    if (returnCode<0){/*check return code for binding process*/
        perror ("bind");
        exit(1);    
    }
    for(;;){
        memset(buffer,'\0',100);/*reset buffer*/
        /*receive data*/
        returnCode = recvfrom(newSocket,buffer,sizeof(buffer),flag,(struct sockaddr *) &clientAddress, &clientLength);
        if(returnCode<=0){/*check receive return code*/
            printf("error on receive, quitting...");
            break;
        }
        printf("Reveived %d bytes: %s\n",returnCode, buffer);
    }
    return 0;
}
 
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
int sendMsg(char *buffer, int newSocket, struct sockaddr_in serverAddress);

int main(int argc, char *argv[])
{
    int newSocket;/*new socket, socket descriptor*/
    struct sockaddr_in serverAddress;/*remote server address*/
    int portNum;/*remote server port*/
    char serverIP[29];/*server IP*/
    char msg[100]; /*message to send*/
    char buffer[100];/*data buffer*/

    if (argc < 3){/*run only if correct syntax on cmd line*/
        printf("usage is: client <remote IP Address> <remote port number>");
        exit(1);
    }

    /*socket creation*/
    newSocket = socket(AF_INET, SOCK_DGRAM, 0);

    /*fetch remote IP info from cmd line*/
    portNum = strtol(argv[2],NULL,10);
    strcpy(serverIP,argv[1]);

    /*setup server address*/
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNum);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);

    /*set message*/
    
    for(;;){
        memset (buffer,'\0',100);
        printf("Enter your message: ");
        scanf ("%[^\n]%*c", msg);
        if(strcmp(msg, "STOP")!=0){
            sprintf(buffer, "%s", msg);
            printf("Sending \"%s\" of %lu bytes\n", buffer, strlen(buffer));

            /*call helper to send message*/
            sendMsg(buffer, newSocket, serverAddress);
        }else{
            printf("\nShutting down client...");
            close (newSocket);
            return (0);
        }
    }
    

}

/*this function handles the actual send process*/
int sendMsg(char *buffer, int newSocket, struct sockaddr_in serverAddress){
    /*setup return code*/
    int returnCode = 0;
    /*send msg*/
    printf ("%s",buffer);
    returnCode = sendto(newSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    printf("sending %d bytes", returnCode);
    
    return (0);
}
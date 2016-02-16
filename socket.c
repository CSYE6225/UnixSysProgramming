#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
/* AF_INET indicates this is IPv4 */
/* SOCK_STREAM indicates connection oriented TCP protocol */
/* SOCK_DGRAM indicates UDP protocol */
/* Protocol -0 indicates IP protocol */
int main(int argc , char *argv[]){
    int socket_desc,port;
    char *message,server_reply[2000];
    struct sockaddr_in server;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
    }
    printf("Connecting to IP %s\n",argv[1]);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    port=atoi(argv[2]);
    server.sin_port=htons(port);
    printf("Connecting to port %s\n",argv[2]);

    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server))<0){
	puts("connect error");
	return 1;
    }
    puts("Connected");
    
    message = "GET /index1.html HTTP\r\n\r\n";
    if(send(socket_desc, message, strlen(message),0)<0){
      puts("Send failed");
      return 1;
    }

    puts("Data Sent\n");
    
    if(recv(socket_desc,server_reply,2000,0)<0){
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
    return 0;
}

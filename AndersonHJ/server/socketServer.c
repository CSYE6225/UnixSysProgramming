#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h> //used for strcpy
#include<netdb.h> //used for hostent

/* AF_INET indicates this is IPv4 */
/* SOCK_STREAM indicates connection oriented TCP protocol */
/* SOCK_DGRAM indicates UDP protocol */
/* Protocol -0 indicates IP protocol */
int main(int argc , char *argv[]){
    int socket_desc,new_socket,port,i,c;
    char *message,server_reply[2000],*hostname,ip[100];
    struct hostent *he;;
    struct sockaddr_in server,client;
    struct in_addr **addr_list;
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket\n");
    }
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;

    if (argv[1] == NULL){
        printf("Enter port number\n");
        return 1;
    }
    port=atoi(argv[1]);
    server.sin_port=htons(port);
    printf("After sin_port\n");
    printf("i=%d\n",i);
    if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0){
        puts("bind failed");
    }
    puts("bind done");
    while(1){
        listen(socket_desc,3);
        puts("Waiting for incoming conncetions...");
        c=sizeof(struct sockaddr_in);
        new_socket=accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&c);
        if (new_socket<0){
            perror("accpet failed");
        }
        puts("Connection accepted");
    }
    return 0;
}

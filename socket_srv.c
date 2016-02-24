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
    listen(socket_desc,3);
    puts("Waiting for incoming conncetions...");
    c=sizeof(struct sockaddr_in);
    new_socket=accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&c);
    if (new_socket<0){
        perror("accpet failed");
    }
    puts("Connection accepted");
    return 0;
    printf("Resolving the hostname %s\n",argv[1]);
    if ((he=gethostbyname(argv[1]))==NULL){
 	printf("gethostname Error");
	herror("gethostbyname");
 	return 1;
    }
    addr_list=(struct in_addr **) he->h_addr_list;
    for(i=0;addr_list[i]!=NULL;i++){
    	strcpy(ip,inet_ntoa(*addr_list[i]));
    }
    printf("%s resolved to : %s\n",argv[1],ip);
    printf("Connecting to hostname %s on IP %s\n",argv[1],ip);
    server.sin_addr.s_addr = inet_addr(ip);
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

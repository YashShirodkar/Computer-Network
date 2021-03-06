#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<sys/socket.h>
#define PORT 5000

int main(int argc, const char * argv[])
{
        struct sockaddr_in c_addr;
        int valueread, sock=0;
        struct sockaddr_in s_addr;
        char filename[20]= {0};
        char buffer[1024]= {0};
        
        if((sock= socket(AF_INET, SOCK_STREAM, 0))<0)
        {
                printf("\nSocket not created");
                return -1;
        }
        
        memset(&s_addr, '0', sizeof(s_addr));
        
        s_addr.sin_family= AF_INET;
        s_addr.sin_port= htons(PORT);
        
        if(inet_pton(AF_INET, "127.0.0.1", &s_addr.sin_addr)<=0)
        {
                printf("\nInvalid address");
                return -1; 
        }
        
        if((connect(sock, (struct sockaddr* ) &s_addr, sizeof(s_addr)))<0)
        {
                printf("\nConnection failed");
                return -1;
                
        }

        //send(sock, hello, strlen(hello), 0);
        //printf("Hello message sent\n");
        char data[200]= {0};
        FILE *fp;
        printf("Enter filename");
        scanf("%s", &filename);
        fp= fopen(filename, "r");
        while(fgets(buffer,200,fp)!=NULL)
        {
        	strcat(data,buffer);
        }
        write(sock, buffer,100);
        return 0;
}

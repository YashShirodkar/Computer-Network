// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<stdlib.h>
#include<string.h>
#define PORT 5000
void error(char *msg)
{
perror(msg);
exit(1);
}

int main(int argc, char *argv[])
{

int sockfd, newsockfd;
char buffer[256];
struct sockaddr_in serv_addr, cli_addr;
int n;
int clilen=sizeof(cli_addr);
char left[256];
char right[256];
char oper;
int i,j,k;
int op1,op2,result;

sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd < 0)
{
error("ERROR opening socket");
}


serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port =htons(PORT);

if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
{
error("ERROR on binding");
}

listen(sockfd,3);


newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,(socklen_t*)&clilen);

if (newsockfd < 0)
{
error("ERROR on accept");
}

bzero(buffer,256);

n = read(newsockfd,buffer,sizeof(buffer));

if (n < 0)
{
error("ERROR reading from socket");
}
for(i=0;i<strlen(buffer);i++)
{
    
   if(buffer[i]=='+'||buffer[i]=='-'||buffer[i]=='*'||buffer[i]=='/')
   {
       j=i;
       break;
       
   }
   else
   {
       left[i]=buffer[i];
    
   }
}

   oper=buffer[j];

k=0;
for(i=j+1;i<strlen(buffer);i++)
{
    right[k]=buffer[i];
    k++;
}

op1=atoi(left);
op2=atoi(right);
printf("Operand 1 %s",left);
printf("\nOperand 2 %s",right);
printf("\nOperator %c",oper);
if(oper=='+')
result=op1+op2;
else if(oper=='-')
result=op1-op2;
else if(oper=='*')
result=op1*op2;
else if(oper=='/')
result=op1/op2;


sprintf(buffer,"%d",result);
//printf("The result is %s",buffer);
 
write(newsockfd,buffer,sizeof(buffer));

return 0;
}

// Server side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define PORT 5000
#define PI 3.14159265
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
char trig[256];
char operand[256];
int i,j,k;
double op,value;
double result;

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
    
   if(buffer[i]==' ')
   {
       j=i;
       break;
       
   }
   else
   {
       trig[i]=buffer[i];
    
   }
}
k=0;
for(i=j+1;i<strlen(buffer);i++)
{
operand[k]=buffer[i];
k++;
}

printf("Operator %s",trig);
printf("\n");
printf("Operand %s",operand);
op=(double)atoi(operand);


value=PI/180;


if(strcmp(trig,"sin")==0)
result=sin(op*value);
else if(strcmp(trig,"cos")==0)
result=cos(op*value);
else if(strcmp(trig,"tan")==0)
result=tan(op*value);
else if(strcmp(trig,"cosec")==0)
result=(1/sin(op*value));
else if(strcmp(trig,"sec")==0)
result=(1/cos(op*value));
else if(strcmp(trig,"cot")==0)
result=(1/tan(op*value));


sprintf(buffer,"%lf",result);
//printf("The result is %s",buffer);
 
write(newsockfd,buffer,sizeof(buffer));

return 0;
}

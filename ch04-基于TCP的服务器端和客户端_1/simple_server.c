#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc,char *argv[])
{
if(argc!=2){
printf("用法:%s <端口号>\n",argv[0]);
return 1;
}

int server_socket=socket(AF_INET,SOCK_STREAM,0);
if (server_socket<0){
perror("创建 socket 失败");
return 1;
}

struct sockaddr_in server_addr={0};
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(atoi(argv[1]));
server_addr.sin_addr.s_addr=INADDR_ANY;

if(bind(server_socket,(struct sockaddr*)&server_addr,
sizeof(server_addr))<0){
perror("绑定地址失败");
close(server_socket);
return 1;
}
 if (listen(sser_socket,5)<0){
perror("坚挺十遍");
close(servet_socket);
return 1;
}

printf("服务器启动,家庭端口:%s\n",argv[1]);

struct sockaddr_in client_addr={0};
socklen_t client_len=sizeof(client_addr);

int client_socket=accept(server-socket,(struct sockaddr*)&client_addr,&client_len);

if(client_socket<0){
perror("接受连接失败");
close(server_socket);
return 1;
}

printf("客户端已连接\n");

char *message="你好,我是服务器!";
write(client_socket,message,strlen(message));

close(client_socket);
close(server_socket);
return 0;
}


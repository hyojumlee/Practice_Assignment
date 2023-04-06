#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

#define BUF_SIZE 100

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int serv_sock, clnt_sock;
    char message[BUF_SIZE];
    int str_len, fd;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;

    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    //프로토콜 체계를 설정하는 부분은 PF_INET을 사용하고,
    //주소 체계를 설정하는 부분은 AF_INET을 사용하는 것이 좋다는 것 같다.

    //프로토콜 체계 IPv4 설정
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    if (serv_sock == -1) {
        error_handling("socket() error");
    }

    //serv_adr을 0으로 memset
    memset(&serv_adr, 0, sizeof(serv_adr));
    //프로토콜 정의. AF_INET = IPv4
    serv_adr.sin_family = AF_INET;
    //server IP 주소를 자동으로 찾아서 대입해주는 옵션
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    //실행 파일 인자로 전달된 port를 server port로 설정
    serv_adr.sin_port = htons(atoi(argv[1]));

    //해당 소켓이 비정상 종료 되었을 때, bind로 할당된 소켓 자원은 프로세스가 재사용 할 수 없다.
    //아래의 SO_REUSEADDR로 bind된 소켓 자원을 재사용할 수 있도록 설정해주면 bind error은 발생하지 않는다.
    int optValue = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &optValue, sizeof(optValue));

    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
        error_handling("bind() error");
    }

    if (listen(serv_sock, 5) == -1) {
        error_handling("listen() error");
    }

    clnt_adr_sz = sizeof(clnt_adr);

    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    if (-1 == clnt_sock) {
        error_handling("accept() error");
    }

    str_len = read(clnt_sock, message, BUF_SIZE);
    
    if (-1 == str_len) {
        error_handling("read() error");
    }

    printf("message from client : %s \n", message);

    fd = open(message, O_RDONLY);

    if (-1 == fd) {
        error_handling("open() error");
    }
    
    while(1) {
        str_len = read(fd, message, BUF_SIZE);
        printf("server read : %d \n", str_len);

        if (str_len > 0) {
            write(clnt_sock, message, str_len);
        } else {
            break;
        }
    }

    close(fd);
    close(clnt_sock);
    close(serv_sock);

    return 0;
}

void error_handling(char* error_msg) {
    fputs(error_msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
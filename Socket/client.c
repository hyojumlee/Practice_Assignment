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
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len;
    int fd;

    if (argc != 5) {
        printf("Usage : %s <IP> <port> <file path> <local file path>", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    printf("message is %s \n", argv[3]);

    str_len = write(sock, argv[3], BUF_SIZE);
    
    if (-1 == str_len) {
        error_handling("write() error");
    }

    str_len = read(sock, message, BUF_SIZE);

    if (str_len == -1) {
        error_handling("read() error");
    }

    fd = open(argv[4], O_WRONLY | O_CREAT, 00664);

    if (-1 == fd) {
        error_handling("open() error");
    }

    while(1) {
        str_len = read(sock, message, BUF_SIZE);
        printf("read : %d \n", str_len);

        if (0 < str_len) {
            write(fd, message, str_len);
        } else {
            break;
        }
    }

    close(fd);
    close(sock);
    return 0;
}

void error_handling(char* message) {
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(1);
}
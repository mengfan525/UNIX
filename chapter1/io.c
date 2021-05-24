//不带缓冲的的I/O,将标准输入复制到标准输出
#include "apue.h"
#define BUFFSIZE   4096  //3.9节将详细说明BUFFSIZE常量不同值将如何影响程序的效率

int main(void){
    int n;
    char buf[BUFFSIZE];
     //STDIN_FILENO、STDOUT_FILENO包含在头文件<unistd.h>中（apue.h包含了此头文件）（下一章有详细说明）
    while((n = read(STDIN_FILENO,buf,BUFFSIZE) > 0)){
        if (write(STDOUT_FILENO,buf,n) != n){
            err_sys("write error");
        }
    }
    if (n < 0){
        err_sys("read error");
    }
    exit(0);
}
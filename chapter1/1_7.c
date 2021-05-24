//从标准输入读取命令并执行
#include "apue.h"
#include <sys/wait.h>

int main(void){
    char buf[MAXLINE];       //来自apue.h
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf , MAXLINE, stdin) != NULL){    //linux中Ctrl + D一般作为默认的文件结束符，fgets返回值为NULL
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;           //将每行字符串末尾的换行符换成NULL（ASCLL值为0），因为execlp函数以NUll结束，而不是换行符结束
    
        if((pid = fork()) < 0 ){             //fork子进程对父进程返回一个非负整数
         err_sys("fork error");
        }
        else if(pid == 0){
            execlp(buf ,buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
        if((pid = waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}
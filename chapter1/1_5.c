//用标准I/O将标准输入复制到标准输出
#include "apue.h"

int main(void){
    int c;
    while((c = getc(stdin)) != EOF){
        if (putc(c,stdout) == EOF){
            err_sys("output error");
        }
    }
    if (ferror(stdin)){
        err_sys("input error");
    }
    exit(0);
}
//程序运行不出错，但无结果，需要了解 stdout、stdin用法
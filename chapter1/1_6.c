//打印进程ID
#include "apue.h"

//getpid()得到其进程ID（pid_t数据类型），强制转换成long型
int main(void){
    printf("hello world from process ID %ld\n",(long)getpid());
    exit(0);
}
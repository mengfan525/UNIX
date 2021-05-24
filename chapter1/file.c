#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    //判断是否输入路径
    if(argc != 2)
        err_quit("ussge: ls directory_name");
    //判断路径是否为空，或者是否无权限打开
    if((dp = opendir(argv[1])) == NULL){
        err_sys("can't open %s",argv[1]);
    }
    //循环读取路径下的文件名
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n",dirp->d_name);
    
    closedir(dp);
    exit(0);

}
/*************************************************************************
	> File Name: my_ls.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 9 14:32:44 2020
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void do_ls(char[]);

int main(int argc, char *argv[]){
    if(argc == 1) {
        do_ls(".");
    }else{
        while(--argc){
            printf("%s:\n", *++argv);
            do_ls(*argv);
        }
    }
    return 0;
}

void do_ls(char dirname[]){
    DIR *dirp;
    struct dirent *direntp;

    if((dirp = opendir(dirname)) == NULL){
        perror("opendir");
        return;
    }

    while((direntp = readdir(dirp)) != NULL){
        printf("%s ", direntp->d_name);
    }
    closedir(dirp);
    printf("\n");
}

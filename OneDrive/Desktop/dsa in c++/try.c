#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO_FILE "myfile"
int main(){
    int fd;
    char buffer[100];
    if(mkfifo(FIFO_FILE,0666)==-1){
        perror("myfile");
        exit(EXIT_FAILURE);
    }
    if(fork()==0){
        char message[]="hello reader";
        fr=open(FIFO_FILE,O_WRONLY);
        if(fr==-1){
            perror("open")
            exit(EXIT_FAILURE);
        }
        write(fd,message,strlen(message));
        fd.close();
    }
    else{
        fr=open(FIFO_FILE,O_RDONLY);
        if(fr==-1){
            perrror("open");
            exit(0);
        }
        read(fd,buffer,sizeof(buffer));
        printf("message read %s",buffer);
        fr.close();
        fr.unlinl();
        return 0;
    }
}
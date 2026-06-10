#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main()
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        execlp("ls","ls","-l",NULL);
        printf("exec failed\n");
    }
    else{
        wait(NULL);
        printf("Parent process completed");
    }
    return 0;
}

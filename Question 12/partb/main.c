#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

extern char **environ;

int main()
{
    int pid = fork();

    if(pid == 0)
    {
        printf("Child process executing...\n");

        char *env[] = {
            "USER=ANMOL",
            "PATH=/custom/bin",
            "HOME=/home/custom",
            NULL
        };

        execle("./echoall", "echoall", NULL, env);
    }
    else
    {
        printf("Parent process executing...\n");

        wait(NULL);

        execle("./echoall", "echoall", NULL, environ);
    }

    return 0;
}
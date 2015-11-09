//
// Created by lmussio on 08/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if(pid == 0) {
        printf("%d: Brains!!!\n", getpid());
        exit(0);
    }

    pause();

    wait(&status);
    return 0;
}
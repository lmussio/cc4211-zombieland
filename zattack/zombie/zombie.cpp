//
// Created by lmussio on 08/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
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

    pid = wait(&status);
    if (WIFEXITED(status))
        fprintf(stderr, "\n\t[%d]\tProcess %d exited with status %d.\n",
                (int) getpid(), pid, WEXITSTATUS(status));

    return 0;
}
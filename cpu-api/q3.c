#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main( int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buff[] = "goodbye";
    char rbuff[50];
    //makes the pipe
    pipe(pipefd);
    cpid = fork();

    if(cpid == -1){
        perror("fork");
        exit(1);
    }

    if(cpid == 0){
        close(pipefd[0]);
        printf("hello, I am child (pid:%d)\n", (int) getpid());

        write(pipefd[1], buff, (strlen(buff)+1));
        exit(0);

    }
    else{
        //we are going to close the write we dont need
        close(pipefd[1]);
        read(pipefd[0],rbuff, sizeof(rbuff) );
        printf("%s ,parent of (pid:%d)\n",
        buff, (int) getpid());
    }
    return(0);
}

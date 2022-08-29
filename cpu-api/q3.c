#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types>

int
main( int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buff[] = "goodbye";
    if (argc != 2)
}

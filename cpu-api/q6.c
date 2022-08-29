#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void wait_or_die() {
    int rc = wait(NULL);
    assert(rc > 0);
}

int fork_or_die() {
    int rc = fork();
    assert(rc >= 0);
    return rc;
}

int main(int argc, char *argv[]) {
    // process a
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    if (fork_or_die() == 0) {
        sleep(6);
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // process b
        if (fork_or_die() == 0){
            sleep(6);
        exit(0);
    }
    if (fork_or_die() == 0) {
        sleep(7);
        // process c
        exit(0);
    }
    if (fork_or_die() == 0) {
        sleep(8);
        // process d
        exit(0);
    }
}
    wait_or_die();
    wait_or_die();
    wait_or_die();
    return 0;
}
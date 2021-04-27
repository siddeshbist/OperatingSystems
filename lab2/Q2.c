#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
    if (fork() == 0) printf("child process\n");
    else printf("parent process\n");

    printf("both reach here\n");
    return 0;
}

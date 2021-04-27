#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
    int p1[2], p2[2];
    signed char c_outdata, c_indata, p_indata, sum;
    pid_t childpid;

    pipe(p1);
    pipe(p2);
    childpid = fork();

    if (childpid  == -1) {
        perror("fork");
        exit(0);
    }

    else if (childpid == 0) {

        printf("In Child Process\n\n");
        close(p1[0]);
        close(p2[1]);
        do {
            scanf("%d",&c_outdata);
            printf("\n");
            printf("Child Sending: %d\n",c_outdata);
            write(p1[1], &c_outdata, 1);
        } while (c_outdata != -1);

        read(p2[0], &c_indata, 1);
        printf("Child Recieved: %d\n\n",c_indata);
        printf("Final Sum = %d\n",c_indata);
        exit(0);
    }
    else {

        printf("In Parent Process\n");
        sum = 0;
        close(p1[1]);
        close(p2[0]);
        do {
            read(p1[0], &p_indata, 1);
            printf("Parent Recieved: %d\n",p_indata);
            if (p_indata != -1) sum += p_indata;
            printf("Sum = %d\n\n",sum);
        } while(p_indata != -1);

        printf("Parent Sending: %d\n", sum);
        write(p2[1],&sum, 1);
    }
}

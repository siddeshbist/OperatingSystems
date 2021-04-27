#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// user-defined signal handlers
void ALRM_handler(int sig) {
        if (sig == SIGALRM) {
        printf("Alarm\n");
    }
}

void INT_handler(int sig) {
        if (sig == SIGINT) {
        printf("CNTRL+C pressed!\n");
    }
}

void TSTP_handler(int sig) {
    if (sig == SIGTSTP) {
        printf("CNTRL+Z pressed!\n");
        exit(0);
    }
}

int main(void) {
// register the signal handlers
    if (signal(SIGALRM , ALRM_handler) == SIG_ERR) {
        printf("failed to register ALRM_handler.");
        exit(1);
    } mju

    if (signal(SIGINT , INT_handler) == SIG_ERR) {
        printf("failed to register INT_handler.");
        exit(1);
    }

    if (signal(SIGTSTP , TSTP_handler) == SIG_ERR) {
        printf("failed to register TSTP_handler.");
        exit(1);
    }

    while(1) {
        sleep(2);       //2s delay
        raise(SIGALRM); //Raises SIGALRM, which triggers handler
    }

}

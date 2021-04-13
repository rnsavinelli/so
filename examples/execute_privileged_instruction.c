#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signal) {
    if (signal == SIGSEGV) {
        puts("received SIGSEGV");
        exit(-1);
    }
}

int main(void) {
    signal(SIGSEGV, sig_handler);
    puts("I'm about to execute a privileged instruction...");
    sleep(2);
    __asm__ __volatile__ ("cli");
    puts("Was I able to execute the instruction?");
   return 0;
}

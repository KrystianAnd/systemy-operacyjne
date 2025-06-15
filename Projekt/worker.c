#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char *nazwa_pracownika;

void obsluz_sygnal(int sygnal) {
    if (sygnal == SIGHUP) {
        printf("%s: Odpoczywam\n", nazwa_pracownika);
    } else if (sygnal == SIGUSR1) {
        printf("%s: Startuję!\n", nazwa_pracownika);
    } else if (sygnal == SIGINT) {
        printf("%s: Kończę\n", nazwa_pracownika);
        exit(0);
    }
    fflush(stdout);
}

void start_pracownika(char *imie) {
    nazwa_pracownika = imie;
    printf("%s: Gotowy do pracy\n", nazwa_pracownika);

    signal(SIGHUP, obsluz_sygnal);
    signal(SIGUSR1, obsluz_sygnal);
    signal(SIGINT, obsluz_sygnal);

    char bufor[100];
    while (fgets(bufor, sizeof(bufor), stdin)) {
        if (strstr(bufor, "Podaj imię")) {
            printf("My name is %s\n", nazwa_pracownika);
        } else if (strstr(bufor, "PID?")) {
            printf("%s: My PID is %d\n", nazwa_pracownika, getpid());
        }
        fflush(stdout);
    }
}

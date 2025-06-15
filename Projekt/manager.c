#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

char *imiona[] = {"Alice", "Bob", "Eve", "Tom"};

void utworz_pracownikow(int liczba) {
    for (int i = 0; i < liczba; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            char *args[] = {"./projekt", imiona[i], NULL};
            execvp(args[0], args);
            perror("execvp nie powiodło się");
            exit(1);
        }
    }
    for (int i = 0; i < liczba; ++i) wait(NULL);
}
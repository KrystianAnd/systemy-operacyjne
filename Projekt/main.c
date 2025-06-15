#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"
#include "worker.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        utworz_pracownikow(4);
    } else {
        start_pracownika(argv[1]);
    }
    return 0;
}
/*
    Copyright (c) 2025 Zakaria HARIRA. All rights reserved.

    Author: Zakaria HAIRA <zakaria-with-glasses>
    Created: 2025-07-07
    File: main.c
    Description: The Main app that executes.
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "layout.h"


#define MAX_CWD_SIZE 1024

int main(){
    signal(SIGINT, ctrlc_handler);
    while(1){
        char _unparsed[225];
        char *args[10];
        char cwd[MAX_CWD_SIZE];
        getcwd(cwd, sizeof(cwd));
        fflush(stdin);

        printf("\033[1;31mz\033[0m: \033[1;34m%s\033[0m \033[1;31m$\033[0m ", cwd);
        scanf("%s", &_unparsed);
        
        strip(_unparsed, args, 10);
        
        if (args[0] == NULL) continue;  // empty input
        if (strcmp(args[0], "exit") == 0) break;

        handler(args);

    }
    return 0;
}


/*
    Copyright (c) 2025 Zakaria HARIRA. All rights reserved.

    Author: Zakaria HAIRA <zakaria-with-glasses>
    Created: 2025-07-07
    File: handler.c
    Description: header that stripts newlines and tabs and executes the commands using execvp
*/
#include "layout.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void strip(char *cmd, char **args, int max_args){
    int i = 0;
    args[i] = strtok(cmd, " \t\n");
    while (args[i] != NULL && i < max_args - 1) {
        args[++i] = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

void handler(char **args){
    pid_t pid = fork();
    
    if (pid == 0){
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    }else if (pid > 0){
        wait(NULL);
    }else{
        perror("fork failed");
    }
}
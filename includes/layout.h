/*
    Copyright (c) 2025 Zakaria HARIRA. All rights reserved.

    Author: Zakaria HAIRA <zakaria-with-glasses>
    Created: 2025-07-07
    File: layout.h
    Description: header file that contains the main typedefs and skeletons needed.
*/

#ifndef LAYOUT
#define LAYOUT

typedef struct cmd_t{
    char cmd[25];
    char cmd_args[10][15]; // i will make it such that i can only put 10 args for example
} cmd_t;

void ctrlc_handler(int sig);
void handler(char **args);
void strip(char *cmd, char **args, int max_args); 
#endif 
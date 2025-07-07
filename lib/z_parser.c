/*
    Copyright (c) 2025 Zakaria HARIRA. All rights reserved.

    Author: Zakaria HAIRA <zakaria-with-glasses>
    Created: 2025-07-07
    File: z_parser.c
    Description: a file that parses the inputed command and executes it
*/
#include <stdio.h>
#include <string.h>
#include "layout.h"

cmd_t parse_input(char *__unformated__input){
    cmd_t parsed;
    memset(&parsed, 0, sizeof(parsed)); // this part initializes the struct to zero.

    char *_parsed_str = strtok(__unformated__input, " ");// slice the string into individual strings eg: "ls -al" -> ["ls", "-al"]
    if(_parsed_str != NULL){
        strncpy(parsed.cmd, _parsed_str, sizeof(parsed.cmd) - 1);

        int arg_index = 0;
        while ((_parsed_str = strtok(NULL, " ")) != NULL && arg_index < 10) {
            strncpy(parsed.cmd_args[arg_index], _parsed_str, sizeof(parsed.cmd_args[arg_index]) - 1);
            arg_index++;
        }
    }

    return parsed;
}
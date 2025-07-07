/*
    Copyright (c) 2025 Zakaria HARIRA. All rights reserved.

    Author: Zakaria HAIRA <zakaria-with-glasses>
    Created: 2025-07-07
    File: ctrlc_handler.h
    Description: Handling SIGINT ie: CTRL+C
*/
#include "layout.h"
#include <stdio.h>
#include <stdlib.h>

void ctrlc_handler(int sig){
    printf("\nquitting...");
    exit(sig);
}
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

struct KEYS {
    char key1;
    char key2;
    char key3;
    char key4;
    char key5;
};

extern struct KEYS keyChain;

int enterNorthWing(void);
void enterSouthWing(void);
void enterEastWing(void);
void enterWestWing(void);
void enterSantasLair(void);
unsigned int countKeys();

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "print_array.h"
#include "modes.h"

static void tMode();

static void helpMenu();

static void multMode();

static void sumMode();

void chooseMode(char * arg)
{
    if ( !strcmp(arg, "help") ) {
        helpMenu();
    }
    else if ( !strcmp(arg, "m") ) {
        multMode();
    }
    else if ( !strcmp(arg, "s") ) {
        sumMode();
    }
    else if ( !strcmp(arg, "t") ) {
        tMode();
    }
    else {
        errorOfBoot();
    }
}

void errorOfBoot()
{
    printf("ERROR OF BOOT\n");
    printf("Try \"help\" for information about boot\n");
}

void helpMenu()
{
    printf("Matrix solver\n");
    printf("Flags of run:\n\n");
    printf("    help - help menu (you are here)\n");
    printf("    m    - multiplication of two matrix\n");
    printf("    s    - summary of two matrix\n");
    printf("    t    - transposition of matrix\n");
}

void multMode()
{
    TwoDimensional data1 = readTwoDimensional();
    TwoDimensional data2 = readTwoDimensional();

    TwoDimensional dataMult = multMatrix(data1, data2);
    printTwoDimensionalP(dataMult);
    free(dataMult.pointer);

    free(data1.pointer);
    free(data2.pointer);
}

void sumMode()
{
    TwoDimensional data1 = readTwoDimensional();
    TwoDimensional data2 = readTwoDimensional();

    TwoDimensional dataSum = sumMatrix(data1, data2);
    printTwoDimensionalP(dataSum);
    free(dataSum.pointer);

    free(data1.pointer);
    free(data2.pointer);
}

void tMode()
{
    TwoDimensional data = readTwoDimensional();
    TwoDimensional tdata = TMatrix(data);
    printTwoDimensionalP(tdata);

    free(data.pointer);
    free(tdata.pointer);
}

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "print_array.h"
#include "modes.h"

/**
 * \brief Mode for transposition matrix
 */
static void tMode();

/**
 * \brief Prints help for my program
 */
static void helpMenu();

/**
 * \brief Mode for mutiplication of two matrix
 */
static void multMode();

/**
 * \brief Mode for summ of two matrix
 */
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
    else if ( !strcmp(arg, "torn") ) {
        tornMode();
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

void tornMode()
{
    printf("Enter your array with torn right edge\n");

    const int maxElem = 1000;
    const int maxRows = 100;

    int * elements = (int *)calloc(maxElem, sizeof(int));
    int ** pointers = (int **)calloc(maxRows, sizeof(int *));

    *(pointers) = elements;

    int exit = 0;

    int numOfElements = 0;

    int countElements = 0;
    int countRows = 0;

    while ( exit != -1 ) {
        printf("Enter number of elements in one row or \"-1\" if there are no more rows\n");

        scanf("%d", &numOfElements);

        if (numOfElements == -1) {
            exit = -1;
            break;
        }

        for (; numOfElements > 0; numOfElements--) {
            scanf("%d", (elements + countElements));
            countElements++;
        }

        countRows++;
        *(pointers + countRows) = elements + countElements;
    }

    /*OneDimensional arr = {elements, countElements};
    printOneDimensionalP(arr);*/

    int * actPointer = elements;

    for(int i = 1; i <= countRows; i++) {
        for(; actPointer < pointers[i]; actPointer++) {
            printf("%d ", *actPointer);
        }

        printf("\n");
    }
}

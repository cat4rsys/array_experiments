#include <stdio.h>
#include "print_array.h"
#include <cassert>

#define max(A, B) A >= B ? A : B

void printOneDimensional(int data[], int size)
{
    for( int i = 0; i < size; i++ ) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

OneDimensional readOneDimensional()
{
    OneDimensional data = {};

    printf("Enter number of elements: ");
    scanf("%d", &(data.elements));

    data.pointer = (int *)(calloc(data.elements, sizeof(int)));
    assert(data.pointer != NULL);

    for(int i = 0; i < data.elements; i++) {
        scanf("%d", (data.pointer+i));
    }

    return data;
}

void printOneDimensionalP(OneDimensional data)
{
    for( int i = 0; i < data.elements; i++ ) {
        printf("%d ", *(data.pointer+i));
    }
    printf("\n");
}

void printTwoDimensional(int data[][4], int ysize, int xsize) // not for all arrays
{
    for (int y = 0; y < ysize; y++) {
        for (int x = 0; x < xsize; x++) {
            printf("%d ", data[y][x]);
        }
    printf("\n");
    }
}

TwoDimensional readTwoDimensional()
{
    TwoDimensional data = {};

    printf("Enter number of rows: ");
    scanf("%d", &(data.ysize));
    printf("Enter number of colomns: ");
    scanf("%d", &(data.xsize));

    data.pointer = (int *)(calloc(data.xsize * data.ysize, sizeof(int)));
    assert(data.pointer != NULL);

    for (int y = 0; y < data.ysize; y++) {
        for (int x = 0; x < data.xsize; x++) {
            scanf("%d", (data.pointer + (y * data.xsize) + x));
        }
    }

    return data;
}

void printTwoDimensionalP(TwoDimensional data)
{
    for (int y = 0; y < data.ysize; y++) {
        for (int x = 0; x < data.xsize; x++) {
            printf("%d ", *(data.pointer + (y * data.xsize) + x));
        }
    printf("\n");
    }
}

void printTriangular(TwoDimensional data)
{
    if ( (data.xsize) == (data.ysize) ) {
        printf("Your triangular table:\n");
        for (int y = 0; y < data.ysize; y++) {
            for (int x = 0; x < y; x++) {
                printf("%d ", *(data.pointer + (y * data.xsize + x)));
            }
            printf("#\n");
        }
    }
    else {
        printf("ERROR: your spreadsheet isnt square\n");
    }
}

TwoDimensional sumMatrix(TwoDimensional data1, TwoDimensional data2)
{
    TwoDimensional sumData = {};

    if ( (data1.xsize == data2.xsize) && (data1.ysize == data2.ysize) ) {
        sumData.xsize = data1.xsize;
        sumData.ysize = data1.ysize;

        sumData.pointer = (int *)(calloc(data1.xsize * data1.ysize, sizeof(int)));
        assert(sumData.pointer != NULL);

        for (int y = 0; y < data1.ysize; y++) {
            for (int x = 0; x < data2.xsize; x++) {
                int delta = y * sumData.xsize + x;
                *(sumData.pointer + delta) = *(data1.pointer + delta) + *(data2.pointer + delta);
            }
        }
        printf("Summary of those two matrix:\n");
    }
    else {
        printf("ERROR: can't sum those matrix\n");
    }

    return sumData;
}

TwoDimensional multMatrix(TwoDimensional data1, TwoDimensional data2)
{
    TwoDimensional multData = {};

    if ( (data1.xsize) == (data2.ysize) ) {
        multData.ysize = multData.xsize = data1.ysize;
        int anotherSize = data1.xsize;

        multData.pointer = (int *)(calloc(multData.xsize * multData.ysize, sizeof(int)));
        assert(multData.pointer != NULL);

        for (int y = 0; y < multData.ysize; y++) {
            for (int x = 0; x < multData.xsize; x++) {
                for (int i = 0; i < anotherSize; i++) {
                    *(multData.pointer + y * multData.xsize + x) += (*(data1.pointer + y * data1.xsize + i)) * (*(data2.pointer + i * data2.xsize + x));
                }
            }
        }
        printf("Multiplication of those two matrix:\n");
    }
    else {
        printf("ERROR: can`t multiplicate those matrix");
    }

    return multData;
}

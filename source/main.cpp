#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"
#include "modes.h"

int main(int argc, char *argv[])
{
    /*int data[] = {1, 2, 3, 4, 5};
    int sizeData = sizeof(data) / sizeof(data[0]);
    printOneDimensional(data, sizeData);

    OneDimensional data1 = readOneDimensional();
    printOneDimensionalP(data1);
    free(data1.pointer);

    int data2[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}};
    int rows = sizeof(data2) / sizeof(data2[0]);
    int colomns = sizeof(data2[0]) / sizeof(data2[0][0]);
    printTwoDimensional(data2, rows, colomns);

    TwoDimensional data3 = readTwoDimensional();
    printTwoDimensionalP(data3);
    free(data3.pointer);

    TwoDimensional data4 = readTwoDimensional();
    printTriangular(data4);
    free(data4.pointer);

    TwoDimensional data5 = readTwoDimensional();
    TwoDimensional data6 = readTwoDimensional();

    TwoDimensional dataSum = sumMatrix(data5, data6);
    printTwoDimensionalP(dataSum);
    free(dataSum.pointer);

    TwoDimensional dataMult = multMatrix(data5, data6);
    printTwoDimensionalP(dataMult);
    free(dataMult.pointer);

    free(data5.pointer);
    free(data6.pointer);

    TwoDimensional data7 = readTwoDimensional();
    TwoDimensional tdata7 = TMatrix(data7);
    printTwoDimensionalP(tdata7);

    free(data7.pointer);
    free(tdata7.pointer);*/

    if (argc != 2) {
        errorOfBoot();

        return 0;
    }

    chooseMode(argv[1]);

    return 0;
}

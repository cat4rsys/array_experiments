typedef struct
{
    int * pointer;
    int elements;
} OneDimensional;

typedef struct
{
    int * pointer;
    int ysize;
    int xsize;
} TwoDimensional;

void printOneDimensional(int data[], int size);

OneDimensional readOneDimensional();

void printOneDimensionalP(OneDimensional data);

void printTwoDimensional(int data[][4], int ysize, int xsize);

TwoDimensional readTwoDimensional();

void printTwoDimensionalP(TwoDimensional data);

void printTriangular(TwoDimensional data);

TwoDimensional sumMatrix(TwoDimensional data1, TwoDimensional data2);

TwoDimensional multMatrix(TwoDimensional data1, TwoDimensional data2);

/**
 * \brief Macro of getting maximum from two numbers
 *
 * \param A - first number
 * \param B - second number
 *
 * \return Maximum of A and B
 */
#define max(A, B) A >= B ? A : B

/**
 * \brief Struct for one-dimensional array
 */
typedef struct
{
    int * pointer;                               /**< Pointer to the first element of array */
    int elements;                                /**< Number of elements */
} OneDimensional;

/**
 * \brief Struct for two-dimensional array
 */
typedef struct
{
    int * pointer;                               /**< Pointer to the first element of array */
    int ysize;                                   /**< Number of rows */
    int xsize;                                   /**< Number of colomns */
} TwoDimensional;

/**
 * \brief prints one-dimensional array
 *
 * \param data - pointer on beginning of array
 * \param size - size of array
 */
void printOneDimensional(int data[], int size);

/**
 * \brief Reads one-dimensional array
 *
 * \return Structure with size of array and pointer to the first element of array
 */
OneDimensional readOneDimensional();

/**
 * \brief Prints one-dimensional array
 *
 * \param data - struct with pointer to the array and size of array
 */
void printOneDimensionalP(OneDimensional data);

/**
 * \brief Prints two-dimensional array with 4 colomns
 *
 * \param data - array
 * \param ysize - number of rows
 * \param xsize - number of colomns
 */
void printTwoDimensional(int data[][4], int ysize, int xsize);

/**
 * \brief Reads two-dimensional array
 *
 * \return Struct with number of rows and colomns and pointer to the first element of array
 */
TwoDimensional readTwoDimensional();

/**
 * \brief Prints two-dimensional array
 *
 * \param data - struct with number of rows and colomns and pointer to the first element of array
 */
void printTwoDimensionalP(TwoDimensional data);

/**
 * \brief Prints triangular table from square
 *
 * \param data - struct with number of rows and colomns and pointer to the first element of array
 */
void printTriangular(TwoDimensional data);

/**
 * \brief Sums up two matrix
 *
 * \param data1 - struct with number of rows and colomns and pointer to the first element of first array
 * \param data2 - struct with number of rows and colomns and pointer to the first element of second array
 *
 * \return struct with number of rows and colomns and pointer to the first element of final array*/
TwoDimensional sumMatrix(TwoDimensional data1, TwoDimensional data2);

/**
 * \brief Multiplicates two matrix
 *
 * \param data1 - struct with number of rows and colomns and pointer to the first element of first array
 * \param data2 - struct with number of rows and colomns and pointer to the first element of second array
 *
 * \return struct with number of rows and colomns and pointer to the first element of final array*/
TwoDimensional multMatrix(TwoDimensional data1, TwoDimensional data2);

/**
 * \brief Transposition matrix
 *
 * \param data1 - struct with number of rows and colomns and pointer to the first element of array
 *
 * \return struct with number of rows and colomns and pointer to the first element of transposited array*/
TwoDimensional TMatrix(TwoDimensional data);

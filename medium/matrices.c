/*
 * Some basics functions manipulating matrices
*/

//*****************************************
// Print
void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
    printf("%s =\n",s);
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            printf("%4g", m[i * cols + j]);
        }   
        printf("\n");
    }
}

//*****************************************
// Transpose
void transpose(double m[], size_t rows, size_t cols, double r[])
{
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            r[j * rows + i] = m[i * cols + j];
        }   
    }
}

//*****************************************
// Addition
void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            r[i * cols + j] = m1[i * cols + j] + m2[i * cols + j];
        }
    }
}

//*****************************************
// Multiplication
void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
    for(size_t i = 0; i < r1; ++i){
        for(size_t j = 0; j < c2; ++j){
            r[i * c2 + j] = 0;
            for(size_t k = 0; k < c1; ++k){
                r[i * c2 + j] += m1[i * c1 + k] * m2[k * c2 + j];
            }
        }
    }
}

//*****************************************
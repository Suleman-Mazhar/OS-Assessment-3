/* solving the matrix equation A*x=b using LAPACK function
lapack_int LAPACKE_sgesv( int matrix_layout, lapack_int n,
lapack_int nrh, float* a, lapack_int lda, lapack_int* ipiv, float*
b,lapack_int ldb ); */
#include <stdio.h>
#include <lapacke.h>

#define size 5 /* dimension of matrix */

int main()
{
  lapack_int n=size, nrhs=1, lda=size, ldb=1, info;
  lapack_int ipiv[size];

  float A[size*size] = {-1.9,-2.1,1.2,-0.5,-1.3,
                        -0.1,1.4,-1.3,-0.1,2.6,
                        0.8,-0.1,1.8,0.8,-0.1,
                        1.4,-0.9,0.6,-0.3,0.8,
                        -1.5,-2.1,0.4,0.8,1.8};

  float b[size] = {-2.5,-1.9,-2.1,1.2,-0.5};

  int i;

  info = LAPACKE_sgesv(LAPACK_ROW_MAJOR, n, nrhs, A, lda, ipiv, b, ldb);

  if (info == 0) {
        printf("Solution x:\n");
        for (i = 0; i < n; i++)
            printf("x[%d] = %f\n", i+1, b[i]);
    } else {
        printf("Error: LAPACKE_sgesv returned info = %d\n", info);
    }

  return 0;
}
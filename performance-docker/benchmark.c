#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <lapacke.h>

/* Fill matrix/vector with random floats in [-10, 10] */
void random_fill(float *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = ((float)rand() / RAND_MAX) * 20.0f - 10.0f;
}

double solve_and_time(int n) {
    float *A = malloc(n * n * sizeof(float));
    float *b = malloc(n * sizeof(float));
    lapack_int *ipiv = malloc(n * sizeof(lapack_int));

    random_fill(A, n * n);
    random_fill(b, n);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    LAPACKE_sgesv(LAPACK_ROW_MAJOR, n, 1, A, n, ipiv, b, 1);

    clock_gettime(CLOCK_MONOTONIC, &t1);

    double elapsed = (t1.tv_sec - t0.tv_sec)
                   + (t1.tv_nsec - t0.tv_nsec) / 1e9;

    free(A); free(b); free(ipiv);
    return elapsed;
}

int main() {
    srand(42);

    /* Sizes to benchmark — adjust upper limit to target ~1 hour */
    int sizes[] = {100, 250, 500, 750, 1000, 1500, 2000, 3000, 4000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-10s %-15s\n", "N", "Time (s)");
    printf("%-10s %-15s\n", "----------", "---------------");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        double t = solve_and_time(n);
        printf("%-10d %-15.6f\n", n, t);
        fflush(stdout); /* print as we go in case of long runs */
    }

    return 0;
}
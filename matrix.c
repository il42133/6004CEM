#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
    //initializing matrix
    int mtrx1[500][500], mtrx2[500][500], sum[500][500];
    int i, j, x, y;
    double etime;

    srand(time(NULL));
    for(i = 0; i < 500; i++){ //loop to generate 2 random matrices
        for(j = 0; j < 500; j++){
            mtrx1[i][j] = rand()%500;
            mtrx2[i][j] = rand()%500;
        }
    }
    
    printf("Inner loop parallelized\n");

    etime = omp_get_wtime();
    //#pragma omp for //parallel region to add both matrices
    for(i = 0; i < 500; i++) {
        #pragma omp for
        for(j = 0; j < 500; j++) {
            sum[i][j] = mtrx1[i][j] + mtrx2[i][j];
        }
    }
    etime = omp_get_wtime() - etime;
    printf("%f\n", etime);

    return 0;
}
    

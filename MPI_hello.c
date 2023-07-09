#include <stdio.h>
#include <mpi.h>

main(int argc, char **argv)
{
    int rank, size, i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    printf("Hello world from process %d of %d size\n", rank, size);
    

    MPI_Finalize();
    return 0;
}
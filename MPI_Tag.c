#include <stdio.h>
#include <mpi.h>

const int SERVER_RANK = 0;
//const int MESSAGE_TAG = 0;

main(int argc, char **argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == SERVER_RANK) {
        master(size);
    }    
    else {
        slave(rank);
    }

    MPI_Finalize();
    return 0;
}

void master(int size) {
    const int max_message_length = 256;
    char message[max_message_length];
    int src;
    MPI_Status stat;

    printf("Hello slaves give me your messages\n");

    for(src = 0; src < size; src++) {
        if(src != SERVER_RANK) {
            MPI_Recv(message, max_message_length, MPI_CHAR, src, 100, MPI_COMM_WORLD, &stat);
            printf("Message received from process %s: Hello back\n", message);
        }
    }
}

void slave(rank) {
    const int max_message_length = 256;
    char message[max_message_length];
    int message_length;

    message_length = sprintf(message, "%d", rank);

    MPI_Send(message, message_length, MPI_CHAR, SERVER_RANK, 101, MPI_COMM_WORLD);
}
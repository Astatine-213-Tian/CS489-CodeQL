#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    struct stat st;
    if (stat(argv[1], &st) == 0) {
        printf("%ld\n", st.st_size);
    } else {
        perror("Error accessing file\n");
        return -1;
    }
}

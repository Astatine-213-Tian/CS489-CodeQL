#include <stdlib.h>
#include <stdio.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    
    // Use snprintf instead of strcat for safe string concatenation
    char cmd[BUFSIZE];
    if (snprintf(cmd, BUFSIZE, "wc -c < %s", argv[1]) >= BUFSIZE) {
        fprintf(stderr, "Command too long\n");
        return -1;
    }

    // Execute the command and capture its output
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error executing command\n");
        return -1;
    }

    // Read and print the output
    char output[BUFSIZE];
    if (fgets(output, BUFSIZE, fp) != NULL) {
        printf("%s", output);
    }

    pclose(fp);
}

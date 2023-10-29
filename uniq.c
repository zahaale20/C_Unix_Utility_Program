#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_unique_lines(FILE *in_file) {
    // declare variables
    char *line = NULL;
    char *prev_line = NULL;
    size_t size;

    // loop through lines
    while (getline(&line, &size, in_file) > 0) {
        if (prev_line == NULL) {
            prev_line = strdup(line); // copy the string
            printf("%s", prev_line);
        } else {
            if (strcmp(line, prev_line) != 0) { // if lines are different... https://www.geeksforgeeks.org/strcmp-in-c/#
                printf("%s", line);
                free(prev_line); // free memory
                prev_line = strdup(line); // store current line
            }
        }
    }
    free(line);
    free(prev_line);
    return;
}

int main(int argc, char *argv[]){
    // Declare Variable(s)
    FILE *file = stdin;
    
    // Handling arguments
    if (argc == 2){
        file = fopen(argv[1], "r");
        if (!file){
            printf("Error: Retrieving/Opening the file.\n");
            return 1;
        }
    } else if (argc == 1){
        file = stdin;
    } else {
        printf("Error: Incorrect argument usage. Ex: ./wc temp.txt\n");
    }

    // function to count lines, words, characters
    print_unique_lines(file);

    if (file != stdin){
        fclose(file);
    }
    return 0;
}


/*
To compile:
    gcc -o uniq uniq.c
To run on a specified file:
    /uniq temp.txt
*/
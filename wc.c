#define _GNU_SOURCE
#include <stdio.h>
#include<stdlib.h>

void count(FILE *in_file) {
    // declare variables
    char *line = NULL;
    size_t size;
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;

    // loop to count lines
    while(getline(&line, &size, in_file) > 0) {
        line_count++;

        // loop to count words
        size_t i;
        int inWord = 0;
        for(i = 0; line[i] != '\0'; i++){
            if (!isspace(line[i])) { // Using a flag (inWord) to make sure we only count each word once
                if (inWord == 0) {
                    inWord = 1;
                    word_count++;
                }
            } else {
                inWord = 0;
            }
            // count characters including spaces, but not newline characters
            if (line[i] != '\n'){
                char_count++;
            }
        }
    }
    free(line);
    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);
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
    count(file);

    if (file != stdin){
        fclose(file);
    }
    return 0;
}


/*
To compile:
    gcc -o wc wc.c
To run on a specified file:
    /wc temp.txt
To run using stdin:
    /wc
    <Input your text>
    Press 'Control' + 'D'
*/
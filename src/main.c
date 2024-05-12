#include "funcions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DOTTO_LINE_BUFFER_SIZE 1024
#define DOTTO_ARG_BUFFER_SIZE 64
#define DOTTO_TOKEN_DELIM "\t\r\n\a:"

char* dotto_get_item()
{
    int position = 0;
    char character;
    int buffer_size = DOTTO_LINE_BUFFER_SIZE;
    char* buffer = malloc(sizeof(char)*buffer_size);

    if (buffer == NULL) {
        fprintf(stderr, "Failed to alocate memory\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        character = getchar();

        if (character == EOF || character == '\n' || position >= buffer_size) {
            buffer[position] = '\0';
            return buffer;
        }

        buffer[position] = character;
        position++;

        if (position >= buffer_size) {
            buffer_size += DOTTO_LINE_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);
            if (!buffer) {
                fprintf(stderr, "Dotto: reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return buffer;
}

char** dotto_split_line(char* line)
{
    int buffer_size = DOTTO_ARG_BUFFER_SIZE, position = 0;
    char** tokens = malloc(buffer_size * sizeof(char*));
    char* token;

    if (tokens == NULL)
    {
        fprintf(stderr,"Unable to allocate for tokens");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DOTTO_TOKEN_DELIM );

    while (token != NULL) {

        tokens[position] = token;
        position++;

        if (position >= buffer_size) {
            buffer_size += DOTTO_ARG_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char*));

            if (tokens == NULL) {
                fprintf(stderr,"Unable to grow token size");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DOTTO_TOKEN_DELIM);
    }
    tokens[position] = NULL;    
    return tokens;
}

int dotto_main() 
{
    char* line;
    char** args;
    int status = 1;

    system("clear");
    dotto_wellcome();

    do {
        printf("What do you want to do? Eg \"add: this thing\"\n");

        line = dotto_get_item();
        args = dotto_split_line(line);
        status = dotto_execute (args);

    } while (status);

    return status;
}


int main()
{
    return dotto_main();
}
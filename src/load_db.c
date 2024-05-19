#include "../includes/notes_linked.h"
#include "../includes/functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME_DB "notes_db_file.dotto"

int file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    int is_exist = 0;
    if (fp != NULL)
    {
        is_exist = 1;
        fclose(fp); // close the file
    }
    return is_exist;
}

void dotto_load_from_file()
{
    if (file_exists(FILE_NAME_DB)){
        FILE *fptr;
        fptr = fopen(FILE_NAME_DB, "r");

        char* myString = malloc(300 * sizeof(char*));
        char** args = malloc(2 * sizeof(char*));

        args[0] = "add";
        while (fgets(myString, 300, fptr)) {
            
            char* copy = strdup(myString);
            copy[strcspn(copy, "\n")] = '\0';

            args[1] = copy;
            
            dotto_execute(args);
        }

        fclose(fptr);
        return;
    }
    return;
}

void dotto_save_notes(note_t* tail)
{
    FILE *fptr;
    fptr = fopen(FILE_NAME_DB, "w");

    int index = 1;
    note_t* temporary = tail;

    while (temporary != NULL) {
        fprintf(fptr, "%s\n", temporary->text);
        temporary = temporary->prev;
        index++;
    }

    fclose(fptr);
    return;
}




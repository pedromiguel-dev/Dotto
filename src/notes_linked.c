#include "notes_linked.h"
#include <stdio.h>
#include <stdlib.h>

struct note {
    int index;
    char* text;
    struct note* next;
};

void print_list(note_t* head) 
{
    int index = 1;
    note_t* temporary = head;

    while (temporary != NULL) {
        printf("\nNote %d: %s\n", index, temporary->text);
        temporary = temporary->next;
        index++;
    }
}

int dotto_create_note(note_t** head, char* text)
{
    note_t* result = malloc(sizeof(note_t));
    result->text = text;

    result->next = *head;
    *head = result;

    return result == NULL? 0: 1;
}
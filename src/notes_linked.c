#include "../includes/notes_linked.h"
#include <stdio.h>
#include <stdlib.h>

struct note {
    int index;
    char* text;
    struct note* next;
    struct note* prev;
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

void dotto_print_notes(note_t* tail) 
{
    int index = 1;
    note_t* temporary = tail;

    while (temporary != NULL) {
        printf("\nNote %d: %s\n", index, temporary->text);
        temporary = temporary->prev;
        index++;
    }
}

note_t* dotto_create_note(char* text)
{
    note_t* result = malloc(sizeof(note_t));
    result->text = text;
    result->next = NULL;
    result->prev = NULL;
    return result;
}


note_t* dotto_inset_note_at_head(note_t* note, note_t** head)
{
    note->next = *head;
    if (*head != NULL) {
        (*head)->prev = note;
    }
    *head = note;
    return note;
}

void dotto_remove_note_from_list(note_t* note, note_t** head, note_t** tail)
{
    if (*tail == note) {
        *tail = note->prev;
        if (*tail != NULL) {
            (*tail)->next = NULL;
        }
    } 

    if (*head == note) {
        *head = note->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }

        free(note);
        return;
    } else {
        note->prev->next = note->next;
        if (note->next != NULL) {
            note->next->prev = note->prev;
        }
    }
    note->next = NULL;
    note->prev = NULL;
    return;
}

note_t* dotto_find_note_from_tail(int index, note_t* tail)
{
    note_t* tmp = tail;

    int position = 0;
    while (tmp != NULL) {
        if (position == (index - 1)) {
            return tmp;
        }
        tmp = tmp->prev;
        position++;
    }
    return NULL;
}
#include "../includes/functions.h"
#include "../includes/notes_linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

note_t* DOTTO_LIST_HEAD = NULL;
note_t* DOTTO_LIST_TAIL = NULL;

void dotto_wellcome() 
{
    printf("\nWellcome to dotto\n");
    printf("\n\tadd: Add tasks\n");
    printf("\tsee: Display tasks\n");
    printf("\tditch: Remove tasks\n");
    printf("\tclear: Clears terminal\n\n");
}
int dotto_add(char **args)
{
    printf("Adding this: %s\n", args[1]);
    note_t* note = dotto_create_note(args[1]);

    if (DOTTO_LIST_HEAD == NULL) {
        DOTTO_LIST_TAIL = note;
    }

    return dotto_inset_note_at_head(note, &DOTTO_LIST_HEAD) == NULL? 0 : 1;
}
int dotto_see(char **args)
{;
    dotto_print_notes(DOTTO_LIST_TAIL);
    return 1;
}
int dotto_clear(char **args)
{
    
#ifdef _WIN32
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif

    dotto_wellcome();
    return 1;
}
int dotto_remove(char **args)
{
    int note_index = atoi(args[1]);
    note_t* note = dotto_find_note_from_tail(note_index, DOTTO_LIST_TAIL);

    if (note != NULL) {
        dotto_remove_note_from_list(note, &DOTTO_LIST_HEAD, &DOTTO_LIST_TAIL);
        printf("Remove note %d.\n", note_index);
    } else 
        printf("Index has no notes\n");

    return 1;
}

int (*dotto_bultin_functions[]) (char **) = {
    &dotto_add,
    &dotto_see,
    &dotto_clear,
    &dotto_remove
};
char *dotto_bultin_named_functions[] = {
  "add",
  "see",
  "clear",
  "ditch"
};

int dotto_num_builtins() 
{
  return sizeof(dotto_bultin_named_functions) / sizeof(char *);
}
int dotto_execute(char** args)
{

    if (args[0] == NULL)
    {
        return 1;
    }

    for (int i = 0; i < dotto_num_builtins(); i++)
    {
        if (strcmp(args[0], dotto_bultin_named_functions[i]) == 0)
        {
            return (*dotto_bultin_functions[i])(args);
        }
        
    }

    printf("Funtion not found!\n");
    return 1;
}
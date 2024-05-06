#ifndef NOTES_LIKED_LIST
#define NOTES_LIKED_LIST



typedef struct note note_t;

void print_list(note_t* head);
int dotto_create_note(note_t** head, char* text);

#endif
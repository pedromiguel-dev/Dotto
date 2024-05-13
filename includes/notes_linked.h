#ifndef NOTES_LIKED
#define NOTES_LIKED

typedef struct note note_t;

void dotto_print_notes(note_t* tail);

note_t* dotto_create_note(char* text);

note_t* dotto_inset_note_at_head(note_t* note, note_t** head);

void dotto_remove_note_from_list(note_t* note, note_t** head, note_t** tail);

note_t* dotto_find_note_from_tail(int index, note_t* head);

#endif
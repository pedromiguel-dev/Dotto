#ifndef FUNTIONS_H
#define FUNTIONS_H

#include "notes_linked.h"

extern note_t* DOTTO_LIST_HEAD;
extern note_t* DOTTO_LIST_TAIL;

void dotto_wellcome();
int dotto_execute(char** args);

#endif
#include "./funcions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("adding this\n");
    return 1;
}
int dotto_clear(char **args)
{
    system("clear");
    dotto_wellcome();
    return 1;
}

int (*dotto_bultin_functions[]) (char **) = {
    &dotto_add,
    &dotto_clear
};
char *dotto_bultin_named_functions[] = {
  "add",
  "clear"
};

int dotto_num_builtins() {
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
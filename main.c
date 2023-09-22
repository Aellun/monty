#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    char content[MAX_LINE_LENGTH];
    FILE *file;
    stack_t *stack = NULL;
    unsigned int counter = 0;
    size_t length;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(content, sizeof(content), file))
    {
        bus.content = content;
        counter++;

        length = strlen(content);

        if (length > 0 && content[length - 1] == '\n')
        {
            content[length - 1] = '\0';
        }

        execute(content, &stack, counter, file);
    }

    free_stack(stack);
    fclose(file);
    return (0);
}


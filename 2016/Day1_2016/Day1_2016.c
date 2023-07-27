#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum directions
{
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

enum turn
{
    LEFT,
    RIGHT
};

int main(int argc, char *argv[])
{
    int DirectionFaced = NORTH;
    int turn = LEFT;

    FILE *fptr;
    fptr = fopen(argv[1], "r");

    if (fptr == NULL)
    {
        printf("Error");
        return 1;
    }

    char c;
    char *InputString = (char*) malloc(sizeof(char));
    int StringIndex = 0;

    // Parse text in input file.
    while ((c = fgetc(fptr)) != EOF) {

        InputString = realloc(InputString, StringIndex + 1);
        InputString[StringIndex] = c;
        StringIndex++;
    }

    // Add null terminator to end.
    InputString = realloc(InputString, ++StringIndex);
    InputString[StringIndex] = '\0';

    char *token;

    // Seperate string.
    token = strtok(InputString, ", ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ", ");
    }

    free(InputString);
    fclose(fptr);
    return 0;
}

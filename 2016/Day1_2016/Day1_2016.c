#include <stdio.h>
#include <stdlib.h>

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

    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }

    fclose(fptr);
    return 0;
}

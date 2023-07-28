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

    int x_coordinate = 0;
    int y_coordinate = 0;

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

    char *movement;
    long int DistanceLength;

    // Parse string and retrieve all movement.
    movement = strtok(InputString, ", ");
    while (movement != NULL)
    {

        // Get direction.
        switch(movement[0])
        {
            case 'R':
                DirectionFaced = (DirectionFaced + 1) % 4;
                break;
            case 'L':
                DirectionFaced = (DirectionFaced + 3) % 4;
                break;
            default:
                printf("Invalid direction input: %c", movement[0]);
                return 1;
        }

        // Get distance from string.
        DistanceLength = strtol(&movement[1], NULL, 10);

        switch(DirectionFaced)
        {
            case NORTH:
                y_coordinate += DistanceLength;
                break;
            case EAST:
                x_coordinate += DistanceLength;
                break;
            case SOUTH:
                y_coordinate -= DistanceLength;
                break;
            case WEST:
                x_coordinate -= DistanceLength;
                break;
        }

        movement = strtok(NULL, ", ");
    }

    printf("Outcome: %d\n", (abs(x_coordinate) + abs(y_coordinate)));

    free(InputString);
    fclose(fptr);
    return 0;
}

#include "towers.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Tower
{
    int xCoord;
    int yCoord;
    int height;
};

struct Board
{
    struct Tower *towers;
};

void testSetup(const struct Board *board, const int *numTowers)
{
    //test to see if @board->towers is initialized properly
    for(int i = 0; i < *numTowers; ++i)
    {
        printf("Tower %d: {%d, %d}. Height = %d\n", i + 1, (board->towers)[i].xCoord, 
                (board->towers)[i].yCoord, (board->towers)[i].height);
    }
    printf("=========================\n");
}

struct Board *initializeBoard(const int numTowers, int *xCoords, int *yCoords, int *heights)
{
    struct Board *retBoard = malloc(sizeof(struct Board));
    retBoard->towers = malloc(numTowers * sizeof(struct Tower)); 
    for(int i = 0; i < numTowers; ++i)
    {
        (retBoard->towers)[i].xCoord = xCoords[i];
        (retBoard->towers)[i].yCoord = yCoords[i];
        (retBoard->towers)[i].height = heights[i];
    }
    return retBoard;
}

struct Board *allocateNewTowersArray(struct Board *board, int *numTowers)
{
    //allocate a new @towers array based on the previous @towers array's
    //heights. 
    int amountToMalloc = 0;
    for(int i = 0; i < *numTowers; ++i)
    {
        if(!((board->towers)[i].height == 1))
        {
            ++amountToMalloc;
        }
        else
        {
            ++amountToMalloc;
            continue;
        }

        if((board->towers)[i].height % 2 == 0)
        {
            ++amountToMalloc;
        }
        else
        {
            //odd
            amountToMalloc += 2;
        }
    }
    struct Tower *newTowers = malloc(amountToMalloc * sizeof(struct Tower));
    memcpy(newTowers, board->towers, *numTowers * sizeof(struct Tower));
    *numTowers = amountToMalloc;
    free(board->towers);
    board->towers = newTowers;
    return board;
}

void evenSplit(int *position, const int i, struct Tower *towers)
{
    //create a tower to the left with height of half current height
    (towers)[*position].height = (towers)[i].height / 2;
    (towers)[*position].xCoord = (towers)[i].xCoord - 1;
    (towers)[*position].yCoord = (towers)[i].yCoord;
    *position += 1;
    //change current tower to be the one on the right
    (towers)[i].height = (towers)[i].height / 2;
    (towers)[i].xCoord = (towers)[i].xCoord + 1;    
}

void oddSplit(int *position, const int i, struct Tower *towers)
{
    //create a tower below with height of half current height minus one
    (towers)[*position].height = ((towers)[i].height - 1) / 2;
    (towers)[*position].xCoord = (towers)[i].xCoord;
    (towers)[*position].yCoord = (towers)[i].yCoord - 1;
    *position += 1;
    //create a tower above with height of half current height minus one
    (towers)[*position].height = ((towers)[i].height - 1) / 2;
    (towers)[*position].xCoord = (towers)[i].xCoord;
    (towers)[*position].yCoord = (towers)[i].yCoord + 1;
    *position += 1;
    //change current tower to have a height of 1
    (towers)[i].height = 1;
}

void _splittingTowers(struct Board *board, int *numTowers)
{
    int originalNumTowers = *numTowers;
    int position = originalNumTowers;
    struct Board *retBoard = allocateNewTowersArray(board, numTowers);
    for(int i = 0; i < originalNumTowers; ++i)
    {
        if((retBoard->towers)[i].height == 1)
            continue;
        if((retBoard->towers)[i].height % 2 == 0)
        {
            // do an even split on the board
        }
        else
        {
            // do an odd split on the board
        }
    }
}

int *splittingTowers(int *xCoords, int* yCoords, int* heights, int numTowers, int* maxStars)
{
    if (!xCoords || !yCoords || !heights || !maxStars) return NULL;

    // if any tower has <= 0 stones
    for(int i = 0; i < numTowers; ++i)
        if(heights[i] <= 0)
            return NULL;
    
    struct Board *board = initializeBoard(numTowers, xCoords, yCoords, heights);
    // testSetup(board, &numTowers);
}
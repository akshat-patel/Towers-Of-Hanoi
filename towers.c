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

int *splittingTowers(int *xCoords, int* yCoords, int* heights, int numTowers, int* maxStars)
{
    if (!xCoords || !yCoords || !heights || !maxStars) return NULL;

    // if any tower has <= 0 stones
    for(int i = 0; i < numTowers; ++i)
        if(heights[i] <= 0)
            return NULL;
}
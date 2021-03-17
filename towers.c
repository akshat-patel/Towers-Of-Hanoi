#include "towers.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *splittingTowers(int *xCoords, int* yCoords, int* heights, int numTowers, int* maxStars)
{
    if (!xCoords || !yCoords || !heights || !maxStars) return NULL;

    // if any tower has <= 0 stones
    for(int i = 0; i < numTowers; ++i)
        if(heights[i] <= 0)
            return NULL;
}
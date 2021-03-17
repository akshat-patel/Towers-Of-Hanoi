#include "towers.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void noNullArguments()
{
	{
	    int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {4, 3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(NULL, yCoords, heights, numTowers,&maxStars);

	    assert(!tileCounts);
	    assert(maxStars == -1);
	    //might need to free tileCounts
	    tileCounts = splittingTowers(xCoords, NULL, heights, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, NULL, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, NULL, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers, NULL);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	}
}

void noNegNumStones()
{
    {
        int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {-4, 3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        assert(!tileCounts);
    }

    {
        int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {-4, -3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        assert(!tileCounts);
    }
}

int main()
{
    noNegNumStones();
    noNullArguments();
}
#include <stdio.h>
#include <stdlib.h>

int getRndNum(int nmbOfTurnouts)  // Function to return a random number.
{       
	int rand_nbr = (rand()%nmbOfTurnouts); 
	return rand_nbr;
}

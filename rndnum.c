#include <stdio.h>
#include <stdlib.h>

int getRndNum(int nmbOfTurnouts)  // Function to return a random number.
{       
	srand(time(NULL));
	int rand_nbr = (rand()%nmbOfTurnouts); 
	return rand_nbr;
}

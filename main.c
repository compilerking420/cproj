#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "rndnum.h"


int main()
{
	printf("\nStart\n");
	//Start randomizer
	srand(time(NULL)); 
	
    	usleep(500000);
	printf("\nRunning...\n");
	//Sleep for a randomly varying time.
	usleep(500000 + getRndNum(100000));
	int rndnum = getRndNum(4);
	if(rndnum == 0){
		printf("\nSimulating fail run...\n\n");
		exit(1);
	}
	else{
		printf("\nSuccessful run...\n\n");
		exit(0);
	}
}

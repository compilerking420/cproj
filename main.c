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
	usleep(500000);
	int rndnum = getRndNum(2);
	if(rndnum == 0){
		printf("\nSimulating fail run...\n\n");
		exit(1);
	}
	else{
		printf("\nSuccessful run...\n\n");
		exit(0);
	}
}

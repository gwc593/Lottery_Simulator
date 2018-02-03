//main.cpp
#include <iostream>
#include <stdio.h>
#include "lotto_functions.hpp"
using namespace std;

int main()
{
	ticket myticket;
	int num_draws;
	int matches[7] = {0};
	double progress = 0;

	if(!myticket.set_numbers()){
		return 1;
	}

	printf("How many tickets do you want to draw? \n");
	std::cin >> num_draws;


	for(int i=0;i<num_draws;i++){
		myticket.draw_reset();
		myticket.draw_numbers();
		matches[myticket.number_matched()]++;
		progress++;

		if(progress>=num_draws/100){
			printf("\r%i%% complete",100*i/num_draws);
			progress =0;
			fflush(stdout);
		}
	}

	for(int k=0; k<7; k++){
		printf("\nMatched %i balls: %i times\n",k,matches[k]);
	}
	return 0;
}

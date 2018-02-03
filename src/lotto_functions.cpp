#include "lotto_functions.hpp"
#include <random>
#include<stdio.h>

//random integer generator
int random_number(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
	int random_integer = uni(rng);

	return random_integer;
}

//ticket define function
bool ticket::set_numbers()
{	
	int counter=0;
	bool duplicate = false;

	for(int i=0;i<6;i++){
		printf("number %i:",i+1);
		std::cin >> pick[i];
	}

	for(int i=0;i<6;i++){
		for (int j = i-1; j>=0; j--){
			if(pick[i] == pick[j]){
				counter++;
			}
		}	
		if(counter > 0){
			duplicate = true;
		}
	}
	
	if(duplicate){
		printf("Invalid ticket, contains duplicates\n");
		return false;
	}

	else{
		return true;
	}

}

void ticket::print_numbers()
{
	printf("Your numbers are\n");
	for(int i=0;i<6;i++){
		printf("number %i: %i\n", i+1,pick[i]);
	}
}

void ticket::draw_numbers()
{
	bool generate;
	int counter = 0;
	
	for(int i=0;i<6;i++){
		generate = true;
		while(generate){
			draw[i] = random_number(1,59);
			for (int j = i-1; j>=0; j--){
				if(draw[i] == draw[j]){
					counter++;
				}
			}
			if(counter == 0){
				generate = false;
			}
			counter = 0;
		}
	}
}

void ticket::print_draw()
{
	printf("Draw numbers are\n");
	for(int i=0;i<6;i++){
		printf("number %i: %i\n", i+1,draw[i]);
	} 

}

int ticket::number_matched()
{
	int counter = 0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(pick[i]==draw[j]){
				counter++;
			}
		}
	}	

	return counter;
}


void ticket::draw_reset(){
	for(int i=0;i<6;i++){
		draw[i]=-1;
	}
}

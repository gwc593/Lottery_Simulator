#ifndef LOTTO_FUNCTIONS_INCLUDED
#define LOTTO_FUNCTIONS_INCLUDED
#include<iostream>
int random_number(int min, int max);

class ticket {
	private:
		int pick[6] = {-1};
		int draw[6] = {-1};
	public:
		bool set_numbers();
		void print_numbers();
		void draw_numbers();
		void print_draw();
		int number_matched();
		void draw_reset();
};



#endif // LOTTO_FUNCTIONS_INCLUDED

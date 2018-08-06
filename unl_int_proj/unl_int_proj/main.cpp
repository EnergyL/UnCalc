#include "unl_int.h"

#include <iostream>
#include <ctime>

#define START_TIMER time_t timer = clock()
#define STOP_TIMER time_t r_timer = clock() - timer
#define STD_OUT_TIMER std::cout << "Time: "<<r_timer << " ms" << endl

using namespace std;

int main()
{
	START_TIMER;
	unl_int a = "4", b = "5";
	a = unl_int().factorial(5);
	cout << a.to_string().c_str()<< endl;
	STOP_TIMER;
	STD_OUT_TIMER;
	return 0;
}
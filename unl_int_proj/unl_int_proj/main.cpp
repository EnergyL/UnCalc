#include "unl_int.h"

#include <iostream>

using namespace std;

int main()
{
	unl_int a("123");
	unl_int b("45");
	
	unl_int c = a * b;
	cout << c.to_string().c_str()<<endl;
	return 0;
}
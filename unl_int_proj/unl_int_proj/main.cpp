#include "unl_int.h"

#include <iostream>

using namespace std;

int main()
{
	unl_int a("100"), b("49"), c = a - b;
	cout << c.to_string().c_str()<<endl;
	return 0;
}
#include "unl_int.h"

#include <iostream>

using namespace std;

int main()
{
	unl_int a = "99", b = "78";
	unl_int c = a * b;
	cout << c.to_string().c_str()<<endl;
	return 0;
}
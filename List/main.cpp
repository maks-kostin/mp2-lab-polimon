#include <iostream>
#include "List.h"

using namespace std;

void main()
{
	TPolinom p;
	TMonom a;
	for (int i = 0; i < 3; i++)
	{
		a.coeff = a.x = a.y = a.z = i + 1;
		p.InsMonom(a);
	}
	cout << p;
}
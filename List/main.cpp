#include <iostream>
#include "List.h"

using namespace std;

void main()
{
	TList<int> li;
	for (int i = 0; i < 51; i++)
	{
		li.InsElem(2 * i);
		//cout << 2 * i;
	}
	//������������ � ������� �� ����� ������ ������ ����� �� 0 �� 100
	cout << li << endl;
}
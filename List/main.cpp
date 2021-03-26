#include <iostream>
#include "List.h"

using namespace std;

void main()
{
	int exit = 0;
	TPolinom p;
	TMonom a;
	for (int i = 0; i < 3; i++)
	{
		a.coeff = a.x = a.y = a.z = i + 1;
		p.InsMonom(a);
	}
	cout << p << endl;
	p += p;
	cout << p << endl;

	while (true)
	{
		cout << "Print 1 to add one polinom to another" << endl;
		cout << "Print 2 to multiply one polinom by another" << endl;
		cout << "Print 3 to stop" << endl;
		cin >> exit;

		if (exit == 1)
		{
			TPolinom p, q;
			TMonom tmp;
			int size;
			cout << "Print size of first polinom" << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "Print " << i + 1 << " monom" << endl;
				cin >> tmp;
				p.InsMonom(tmp);
			}
			cout << "Print size of second polinom" << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "Print " << i + 1 << " monom" << endl;
				cin >> tmp;
				q.InsMonom(tmp);
			}
			p += q;
			cout << p << endl;
		}

		if (exit == 2)
		{
			TPolinom p, q;
			TMonom tmp;
			int size1, size2;
			cout << "Print size of first polinom" << endl;
			cin >> size1;
			for (int i = 0; i < size1; i++)
			{
				cout << "Print " << i + 1 << " monom" << endl;
				cin >> tmp;
				p.InsMonom(tmp);
			}
			cout << "Print size of second polinom" << endl;
			cin >> size2;
			for (int i = 0; i < size2; i++)
			{
				cout << "Print " << i + 1 << " monom" << endl;
				cin >> tmp;
				q.InsMonom(tmp);
			}
			if (size1 > size2)
			{
				p *= q;
				cout << p << endl;
			}	
			else
			{
				q *= p;
				cout << q << endl;
			}
		}
		if (exit == 3)
		{
			break;
		}
	}
}
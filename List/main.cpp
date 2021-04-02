#include <iostream>
#include "List.h"

using namespace std;

void main()
{
	int exit = 0;
	TPolinom p;
	TMonom a, b(1, 2, 2, 1);
	for (int i = 0; i < 3; i++)
	{
		a.coeff = a.x = a.y = a.z = i + 1;
		p.InsMonom(a);
	}
	p.InsMonom(b);
	//cout << p << endl;
	//p += p;
	//cout << p << endl;

	TPolinom p1, p2;
	a.coeff = a.x = a.y = a.z = 1;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 3;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 4;
	p1.InsMonom(a);
	a.coeff = a.x = a.y = a.z = 2;
	p2.InsMonom(a);
	a.coeff = 3;
	 a.x = a.y = a.z = 3;
	p2.InsMonom(a);
	a.coeff = -4;
	a.x = a.y = a.z = 4;
	p2.InsMonom(a);
	cout << p1 << endl;
	cout << p2 << endl;
	p1 += p2;
	cout << p1 << endl;

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
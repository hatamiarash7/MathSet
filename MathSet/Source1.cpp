#include <iostream>

using namespace std;

void main()
{
	int n, m, x[50], y[50];
	 int c;
	cout << "Enter the number of first list's elements:";
	cin >> n;
	cout << "Enter the first sorted list:" << endl;
	for ( int i = 0; i<n; i++)
		cin >> x[i];
	cout << "Now enter the number of second list's elements:";
	cin >> m;
	cout << "Enter the second sorted list:" << endl;
	for (c = 0; c<m; c++)
		cin >> y[c];
	//------------------------------------------------------------
	cout << "Union: ";
	char ch;
	int i = 0;
	for (i = 0; i<n; i++)
		if (x[i] != x[i - 1])
			cout << x[i] << "\t";
	for (c = 0; c<m; c++)
		if (y[c] != y[c - 1])
		{
			ch = 0;
			for (i = 0; i<n; i++)
				if (y[c] == x[i])
				{
					ch = 1;
					break;
				}
			if (ch != 1)
				cout << y[c] << "\t";
		}
	cout << endl;
	//------------------------------------------------------------
	cout << "Subscription: ";
	c = 0;
	for (i = 0; i<n; i++)
		if (x[i] != x[i - 1])
			for (; y[c] <= x[i] && c<m; c++)
				if (y[c] != y[c - 1] && x[i] == y[c])
				{
					cout << x[i] << "\t";
					break;
				}
	//-------------------------------------------------------------
}


//end
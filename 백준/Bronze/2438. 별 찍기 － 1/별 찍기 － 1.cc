#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = 1; N >= i; i++)
	{
		for (int ii = 0; i > ii; ii++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}
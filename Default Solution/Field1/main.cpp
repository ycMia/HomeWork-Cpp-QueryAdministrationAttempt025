#include <iostream>
#include <iomanip>

using namespace std;
double arr[5][5][40] = {};

void init()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 40; k++)
				arr[i][j][k] = -1;

	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			arr[i][j][0] = (double)25 * j;

	for (int i = 0; i < 5; i++)
	{
		arr[0][i][0] = 0;
		arr[i][0][0] = 0;
		arr[4][i][0] = 0;
		arr[i][4][0] = 0;
	}
	for (int i = 0; i < 5; i++)
		arr[i][4][0] = 100;
}

double iterate(int i, int j, int k)
{
	if (arr[i][j][k] != -1)
		return arr[i][j][k];

	if(i==0 || i==4 || j==0 || j==4)
	{
		return arr[i][j][0];
	}
	else
		arr[i][j][k]=(double)(0.25)* (
			iterate(i - 1, j, k - 1) +
			iterate(i, j - 1, k - 1) +
			iterate(i + 1, j, k - 1) +
			iterate(i, j + 1, k - 1));
	return arr[i][j][k];
}

void GiveARes(int k)
{
	for (int j = 3; j >= 1; --j)
	{
		for (int i = 1; i < 4; ++i)
			cout << iterate(i, j, k) << ' ';
		cout << endl;
	}
	cout << "--------" << endl;
}

int main()
{
	init();
	GiveARes(31);
	GiveARes(32);
	GiveARes(33);
}

#include <iostream>
#define N 64

using namespace std;


int cells[N][N];




void update(int cells[64][64])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cells[i][j] += 1;
		}
	}

	return;
}


void get_counts(int cells[64][64], int x, int y, int counts[3])
{

	for (int i = x - 1; i < x + 2; i++)
	{
		for (int j = y - 1; j < y + 2; j++)
		{
			if (i > -1 && i < N && j > -1 && j < N && (y != j || x != i))
				{
				if (cells[i][j] == 2)
					counts[2] += 1;
				else if (cells[i][j] == 1)
					counts[1] += 1;
				else
					counts[0] += 1;


				cout << i << ", " << j << endl;
				}
		}
	}

	return;
}





int main()
{

	// initialize cells
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cells[i][j] = 0;
		}
	}




	int counts[3] = { 0,0,0 };

	get_counts(cells, 1, 1, counts);

	cout << counts[0];


	return 0;
}
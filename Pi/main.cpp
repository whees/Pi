#include <iostream>
#define N 64


using namespace std;


int cells[N][N];
int timers[N][N];
int tmax = 100;




void update(int cells[64][64],int timers[64][64])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int counts[3] = { 0,0,0 };
			get_counts(cells, i, j, counts);
			int me = cells[i][j];

			//logic
			if (me == 2)
			{
				// fox branch
				if (timers[i][j] < 1 or counts[2] > 4)
				{
					cells[i][j] = 0;
					timers[i][j] = tmax;
				}
				else if (counts[1] > 0)
				{
					timers[i][j] += tmax / counts[2];
				}
				else
				{
					timers[i][j] -= 1;
				}
				

			}
			else if (me == 1)
			{
				// rab branch
				if (counts[2] > 0 || counts[1] < 1)
				{
					cells[i][j] = 0;
				}
				
			}
			else
			{
				// empty branch
			}
			
		}
	}

	return;
}




void display(int cells[64][64])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//display stuff

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
				}
		}
	}

	return;
}





int main()
{

	// initialize cells and timers
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cells[i][j] = 0;
			timers[i][j] = tmax;
		}
	}

	// main loop
	while (true)
	{
		// update cells
		update(cells,timers);


		// display cells
		display(cells);

	}

	


	return 0;
}
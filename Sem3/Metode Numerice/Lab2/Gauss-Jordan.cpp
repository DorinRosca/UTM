#include <iostream>
using namespace std;
int main()
{
	int i, j, k, n;
	float A[5][6] =
		{
			{0, 0, 0, 0, 0, 0},
			{0, 11.3, -0.2, 1.3, -0.4, 20.3},
			{0, -0.2, 17.6, 2.1, 0.7, -14.6},
			{0, 1.3, 2.1, 20.3, 1.2, 8.9},
			{0, -0.4, 0.7, 1.2, 19.4, 11.3},
		};
	float a[10][10], b, x[10];
	printf("Introduceti numarul de necunoscute in matrice: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= (n + 1); j++)
		{
			a[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			cout << "Determinantul este egal cu 0 si sistemtul nu va avea o singura solutie!";
			return 0;
		}
	}
	for (j = 1; j <= n; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (i != j)
			{
				b = a[i][j] / a[j][j];
				for (k = 1; k <= n + 1; k++)
				{
					a[i][k] = a[i][k] - b * a[j][k];
				}
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= (n + 1); j++)
					{
						printf("%9.5f ", a[i][j]);
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (n + 1); j++)
		{
			printf("%9.5f ", a[i][j]);
		}
		cout << endl;
	}
	cout << endl;

	cout << "Solutiile:";
	for (i = 1; i <= n; i++)
	{
		x[i] = a[i][n + 1] / a[i][i];
		cout << "x" << i << "=" << x[i] << " ";
	}
	return (0);
}
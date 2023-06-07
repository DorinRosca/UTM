#include "bits/stdc++.h"

using namespace std;

int main()
{
	float A[4][4] =
		{
			{11.3, -0.2, 1.3, -0.4},
			{-0.2, 17.6, 2.1, 0.7},
			{1.3, 2.1, 20.3, 1.2},
			{-0.4, 0.7, 1.2, 19.4},
		};
	float B[4] = {20.3, -14.6, 8.9, 11.3};
	int n;
	cout << "Introduceti numarul de necunoscute: ";
	scanf("%d", &n);
	cout << endl;
	int i, j, l;
	float t, x[n], a[n][n], b[n];
	for (i = 0; i < n; i++)
	{
		b[i] = B[i];
		for (j = 0; j < n; j++)
			a[i][j] = A[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			cout << "Determinantul este egal cu 0 si sistemtul nu va avea o singura solutie!";
			return 0;
		}
	}
	l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%9.5f ", a[i][j]);
		}
		cout<<b[i];
		cout << endl;
	}
	cout << endl;
	while (l < n)
	{
		for (i = l + 1; i < n; i++)
		{
			t = a[i][l] / a[l][l];
			for (j = l; j < n; j++)
				a[i][j] -= t * a[l][j];
			b[i] -= t * b[l];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%9.5f ", a[i][j]);
			}

			cout << b[i];
			cout << endl;
		}
		cout << "\n";
		l++;
	}
	for (int i = 0; i < n; i++)
		x[i] = 0;
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	cout << "Solutiile" << endl;
	for (i = n - 1; i >= 0; i--)
	{
		t = 0;
		for (j = n - 1; j > i; j--)
			t += a[i][j] * x[j];
		t = b[i] - t;
		x[i] = t / a[i][i];
	}
	for (i = 0; i < n; i++)
		cout << "x[" << i << "] = " << x[i] << endl;
	return 0;
}
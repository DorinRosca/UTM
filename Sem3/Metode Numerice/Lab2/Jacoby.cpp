#include "bits/stdc++.h"

using namespace std;
int main()
{
	int n;
	int it = 0;
	cout << "Introduceti numarul de necunoscute: ";
	scanf("%d", &n);
	// int n=4;
	float sum, q, x[n], beta[n], s, x1[n], aux;
	float eroarea = 0.001;
	float a[n][n] =
		{
			{11.3, -0.2, 1.3, -0.4},
			{-0.2, 17.6, 2.1, 0.7},
			{1.3, 2.1, 20.3, 1.2},
			{-0.4, 0.7, 1.2, 19.4},
		};
	float c[n][n] =
		{
			{11.3, -0.2, 1.3, -0.4},
			{-0.2, 17.6, 2.1, 0.7},
			{1.3, 2.1, 20.3, 1.2},
			{-0.4, 0.7, 1.2, 19.4},
		};
	float b[n] = {20.3, -14.6, 8.9, 11.3};
	float x0[n] = {0, 0, 0, 0};
	cout << "Matricea A" << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			cout << "Determinantul este egal cu 0 si sistemtul nu va avea o singura solutie!";
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Vectorul B" << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
		beta[i] = b[i] / a[i][i];
	cout << "Vectorul Beta" << endl;
	for (int i = 0; i < n; i++)
		cout << beta[i] << " ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				c[i][j] = c[i][j] / c[i][i] * (-1);
		}
		c[i][i] = 0;
	}
	cout << "Matricea C" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += abs(c[i][j]);
		}
		if (q < sum)
			q = sum;
	}
	cout << endl
		 << "Norma matricei C";
	cout << endl;
	cout << q << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		x[i] = beta[i];
		x1[i] = beta[i];
		x0[i] = beta[i];
	}
	it++;
	/*for(int i=0; i<n; i++)
		{
			cout<<x[i]<<" ";
		}
	cout << endl;
	for(int i=0; i<n; i++)
		{
			cout<<x1[i]<<" ";
		}
	cout << endl;
	for(int i=0; i<n; i++)
		{
			cout<<x0[i]<<" ";
		}
	cout << endl;*/
	aux = x1[0];
	for (int i = 1; i < n; i++)
		if (abs(aux) < abs(x1[i]))
			aux = abs(x1[i]);
	cout << endl
		 << "Norma vectorului x1-x: " << endl
		 << aux << endl;
	cout << endl;
	while ((q / (1 - q)) * aux >= eroarea)//stopare--------------------------------------------------------
	{
		aux = 0;
		for (int i = 0; i < n; i++)
		{
			s = 0;
			for (int j = 0; j < n; j++)
				if (j != i)
					s = s + a[i][j] * x0[j];//x0-Necunoscuta
			x[i] = (b[i] - s) / a[i][i];
		}
		cout << "Vectorul X" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << x[i] << " ";
			x1[i] = x[i] - x0[i];
			x0[i] = x[i];
		}
		aux = abs(x1[0]);
		for (int i = 1; i < n; i++)
			if (aux < abs(x1[i]))
				aux = abs(x1[i]);
		cout << endl
			 << "Norma vectorului x1-x: " << endl
			 << aux << endl;
		cout << endl;
		cout << endl;
		it++;
	}
	cout << "Iteratiile " << it;
	return 0;
}
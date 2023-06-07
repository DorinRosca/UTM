#include <iostream>
#include <iomanip>
#include<math.h>
int n = 7;
int z;
//Lagrange interpolarea valoarea polinomului in punctul x0
float x[] = {-1.104, -0.986, 0.465, 1.235, 2.476, 3.789, 4.987};
float y[] = {4.13567, 2.29876, 0.01238, -2.4587, -1.1154, 0.56478, 2.17854};
using namespace std;
void Lagrange(double alpha)
{
    double l, L = 0;
    
    for (int i = 0; i <= n; i++)
    {
        l = 1;
        for (int j = 0; j <= n; j++)
            if (j != i)
            {
                l = l * (alpha - x[j]) / (x[i] - x[j]);
            }
        L = L + l * y[i];
        float Eroare = L - y[i];

        
        if(i==z)
        {
        
            if (alpha == 4)
                {
                    cout << setw(10) << L << " | " << endl;
                }
                else
                {
                    cout << setw(10) << L << " | " << setw(10) << abs(Eroare) << " |" << endl;
                }
        }
    }
}
int main()
{
    cout << fixed;
    cout << " ------------------------------------------------------------" << endl;
    cout << " | " << setw(4) << "n" << " | " << setw(10) << "x(i)" << " | " << setw(10) << "y(i)" << " | " << setw(10) << "L(i)" << " | " << setw(10) << "L(i)-y[i]" << " |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    for( z=0;z<n;z++)
    {
        cout << " | " << setw(4) << z << " | " << setw(10) << x[z] << " | " << setw(10) << y[z] << " | "; Lagrange(x[z]);
    }
    double alpha=4;
    cout << " ------------------------------------------------------------\n" << endl;
    cout << "Valoarea functiei f(x) in punctul x=" << alpha << " : L(6)(" << alpha << ") = ";
    Lagrange(alpha);
}
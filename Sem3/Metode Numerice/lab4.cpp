#include <iostream>
#include <cmath>
#include<math.h>
using namespace std;
float f(float(x), float(y))
{
    return (pow(2.71828,x)-pow(y,2));
}

int main()
{
    int n, i;
    double a, b;
    float h;
    float k0[25], k1[25], k2[25], k3[25];
    cout << " Ecuatia e^x-y^2" << endl;
    cout << " Intervalul:" << endl
         << " a = 0";
    a=0;
    cout << " b = 1";
    b=1;
    cout << " Pasul h=0.05: ";
    h=0.05;
    n = (b - a) / h;
    double y[10], e[10], x[10], Y[10], L[10];
    cout << "x0:0 ";
    x[0]=0;
    cout << "y0=0\n ";
    y[0]=0;
    cout << " --------------------------------------------" << endl;
    cout << " Metoda Euler " << endl;
    cout << " --------------------------------------------" << endl;
    for (i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }
    for (i = 1; i <= n; i++)
    {
        y[i] = y[i - 1] + (h * f(x[i - 1], y[i - 1]));
    }

    cout << " Iteratii          x     \t   y     \t          f(x,y)" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "   " << i << "\t\t " << x[i] << "\t\t " << y[i] << "\t\t  " << f(x[i], y[i]) << endl;
    }
    cout << " --------------------------------------------" << endl;
    cout << " Metoda Euler Modificata " << endl;
    cout << " --------------------------------------------" << endl;
    for (i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
    }
    for (i = 1; i <= n; i++)
    {
        y[i] = y[i - 1] + (h * f(x[i - 1], y[i - 1]));
        y[i] = y[i - 1] + ((h / 2) * (f(x[i - 1], y[i - 1]) + f(x[i], y[i])));
    }
    cout << " Iteratii          x    \t    y     \t          f(x,y)" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "   " << i << "\t\t " << x[i] << "\t\t " << y[i] << "\t\t  " << f(x[i], y[i]) << endl;
    }
    cout << " --------------------------------------------" << endl;
    cout << " Metoda Runge-Kutta " << endl;
    cout << " --------------------------------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        k0[i - 1] = f(x[i - 1], y[i - 1]);
        k1[i - 1] = f(x[i - 1] + 0.5 * h, y[i - 1] + 0.5 * k0[i - 1]);
        k2[i - 1] = f(x[i - 1] + 0.5 * h, y[i - 1] + 0.5 * k1[i - 1]);
        k3[i - 1] = f(x[i - 1] + h, y[i - 1] + k2[i - 1]);
        y[i] = y[i - 1] + h / 6 * (k0[i - 1] + 2 * k1[i - 1] + 2 * k2[i - 1] + k3[i - 1]);
    }
    cout << " Iteratii          x    \t    y     \t           f(x,y)" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "   " << i << "\t\t " << x[i] << "\t\t " << y[i] << "\t\t  " << f(x[i], y[i]) << endl;
    }
    cin.get();
    cin.get();
    return 0;
}

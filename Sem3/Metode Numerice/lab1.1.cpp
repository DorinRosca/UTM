#define _USE_MATH_DEFINES
#include <iostream>
#include "bits/stdc++.h"
#define epsilon 0.0000001
#define epsiloon 0.001
using namespace std;
int it = 0, it1 = 0, it2 = 0, it3 = 0;
double mx1, mn1, mx2, mn2;

double f(double x){return pow(x,3) + 20 *x - 41;}
double fi(double x){return  (pow(-x,3)+41)/20;}
double fd1(double x) { return 3* pow(x,2) + 20;}
double fd2(double x) {return 6 * x;}

double m1(double a, double b)
{
    if (fd1(a) > fd1(1))
    {
        mx1 = fd1(a);
        mn1 = fd1(b);
    }
    else
    {
        mx1 = fd1(b);
        mn1 = fd1(a);
    }
}
double m2(double a, double b)
{
    if (fd2(a) > fd2(1))
    {
        mx2 = fd2(a);
        mn2 = fd2(b);
    }
    else
    {
        mx2 = fd2(b);
        mn2 = fd2(a);
    }
}

double injumatatire(double a, double b)
{
    double c;
    if ((f(a) * f(b)) < 0)
    {
        while (abs(b - a) > 2 * epsiloon)
        {
            it++;
            c = (a + b) / 2;
            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
        }
        return c;
    }
    else
        return -1;
}
double aproximare(double a, double b)
{
    double x = a, y, q;
    q = (mx1 - mn1) / (mx1 + mn1);
    y = fi(x);
    while (abs(((q / (1 - q)) * (y - x))) >= 0.000001)
    {
        it1++;
        x = y;
        y = fi(x);
    }
    return x;
}
double newton(double a, double b)
{
    double x, x1;
    if ((f(a) * fd2(a)) > 0)
    {
        x = x1 = a;
    }
    else
        x = x1 = b;
    x = x1;
    x1 = x - f(x) / fd1(x);
    it2++;
    while (mx2 / 2 * mn1 * pow((x1 - x), 2) > epsilon)
    {
        x = x1;
        x1 = x - f(x) / fd1(x);
        it2++;
    }
    return x1;
}

double secanta(double a, double b)
{
    int i = 0;
    double x, x1;
    if ((f(a) * fd2(a)) > 0)
    {
        x = a;
        x1 = a;
    }
    else
    {
        x = b;
        x1 = b;
    }
    double c;
    it3++;
    if (x == b)
    {
        x = x1 - f(x1) * ((x1 - a) / (f(x1) - f(a)));
        c = x - x1;
        while ((mx1 - mn1) / mn1 * abs(c) >= epsilon)
        {
            x = x1 - f(x1) * ((x1 - a) / (f(x1) - f(a)));
            c = x - x1;
            x1 = x;
            it3++;
        }
    }
    if (x == a)
    {
        x = x1 - f(x1) * ((b - x1) / (f(b) - f(x1)));
        c = x - x1;
        while ((mx1 - mn1) / mn1 * abs(c) >= epsilon)
        {
            x = x1 - f(x1) * ((b - x1) / (f(b) - f(x1)));
            c = x - x1;
            x1 = x;
            it3++;
        }
    }
    return x;
}
int main()
{
    double a = 1, b = 2;
    m1(a, b);
    m2(a, b);
    cout << "\n\nIntervalul (1,2)" << endl;
    cout << "Metoda injumatatirii intervalului: " << endl
         << "x = " << injumatatire(a, b) << endl;
    cout << "Numarul de iteratii: " << it << endl;
    cout << "Metoda aproximarilor succesive: " << endl
         << "x = " << aproximare(a, b) << endl;
    cout << "Numarul de iteratii: " << it1 << endl;
    cout << "Metoda Newton: " << endl
         << "x = " << newton(a, b) << endl;
    cout << "Numarul de iteratii: " << it2 << endl;
    cout << "Metoda secantei: " << endl
         << "x = " << secanta(a, b) << endl;
    cout << "Numarul de iteratii: " << it3 << endl;
    return 0;
}

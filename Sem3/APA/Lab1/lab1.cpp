#include <iostream>
int count1 = 0;
int count2 = 0;
int count3 = 0;
long long fib1(long long n)//Functia recursiva
{
    if(n < 2)
    {
        count1++;
        return n;
    }
    else
    {
    count1++;
    return fib1(n-1)+fib1(n-2);
    }
}

long long  fib2(long long numar)//Functia for
{
    int i=1,j=0;
    for(int k=1;k <=numar;k++)
    {
        count2++;
        j=i+j;
        i=j-i;
    }

    return j;
}

long long  fib3(long long  numar)//Functia While
{
    int i = 1, j = 0, k = 0, h = 1, t;
    while (numar > 0)
    {
        if (numar % 2 != 0)
        {
            t = j * h;
            j = i * h + j * k + t;
            i = i * k + t;
        }
        t = h * h;
        h = 2 * k * h + t;
        k = k * k + t;
        numar = numar / 2;
        count3++;
    }
    return j;
}
int main()
{
    long long numar;
    std :: cout << "Introduceti numarul din list Fibonaccu: \n";
    std :: cin >> numar;
    std::cout << "Metoda 1-Functia Recursiva: " << std::endl;
    std:: cout << fib1(numar) << std::endl;
    std::cout << "Numarul de Iteratii: " << std::endl;
    std::cout << count1 << std::endl;
    std::cout << "Metoda 2-Functia For: " << std::endl;
    std::cout << fib2(numar) << std::endl;
    std::cout << "Numarul de Iteratii: " << std::endl;
    std::cout << count2 << std::endl;
    std::cout << "Metoda 3-Functia While: " << std::endl;
    std::cout << fib3(numar) << std::endl;
    std::cout << "Numarul de Iteratii: " << std::endl;
    std::cout << count3 << std::endl;
}   
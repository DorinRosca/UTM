using System;
using System.Numerics;

public class RSA
{
    public static void Method()
    {
        // Generarea cheilor
        int p = 5; // Primul număr întreg prim
        int q = 11; // Al doilea număr întreg prim
        int n = p * q; // Produsul celor două numere prime
        int phi = (p - 1) * (q - 1); // Indicatorul lui Euler
       // Un număr întreg astfel încât c.m.m.d.c.(phi, e) = 1, 1 < e < phi
        int e = 2;

        int gcd(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            return gcd(b, a % b);
        }

        bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        int generatePrimeNumber()
        {
            Random rand = new Random();
            int num = rand.Next(100, 1000); // generăm un număr între 100 și 999
            while (!isPrime(num))
            {
                num = rand.Next(100, 1000); // generăm alt număr dacă primul nu este prim
            }
            return num;
        }

        while (gcd(e, phi) != 1)
        {
            e++;
            if (e >= phi)
            {
                // Generăm alte numere p și q pentru a obține un nou φ(n)
                // și resetăm valorile pentru e și phi
                e = 2;
                p = generatePrimeNumber();
                q = generatePrimeNumber();
                n = p * q;
                phi = (p - 1) * (q - 1);
            }
        }
        int d = ModInv(e, phi); // Cheia privată

        // Afisarea cheilor
        Console.WriteLine("Cheia publică: ({0}, {1})", e, n);
        Console.WriteLine("Cheia privată: {0}", d);

        // Criptarea mesajului
        int M = 9; // Mesajul clar
        int C = ModPow(M, e, n); // Mesajul criptat

        Console.WriteLine("Mesajul criptat: {0}", C);

        // Decriptarea mesajului
        int decrypted = ModPow(C, d, n); // Mesajul clar decriptat
        Console.WriteLine("Mesajul decriptat: {0}z", decrypted);

        Console.ReadKey();
    }

    // Implementarea algoritmului extins Euclid pentru a afla inversul modular
    // a unui număr întreg a modulo un număr întreg m
    static int ModInv(int a, int m)
    {
        int m0 = m, t, q;
        int x0 = 0, x1 = 1;

        if (m == 1)
            return 0;

        while (a > 1)
        {
            // q este catul impartirii a/m
            q = a / m;
            t = m;

            // actualizarea m si a
            m = a % m;
            a = t;

            // actualizarea x0 si x1
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        // asigurarea ca x1 este pozitiv
        if (x1 < 0)
            x1 += m0;

        return x1;
    }

    static int ModPow(int a, int b, int m)
    {
        int res = 1;

        while (b > 0)
        {
            // daca b este impar
            if (b % 2 == 1)
                res = (res * a) % m;

            // divizam b la 2
            b /= 2;
            a = (a * a) % m;
        }

        return res;
    }
}
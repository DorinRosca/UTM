#include <iostream>
using namespace std;

typedef struct
{
    int a, b, costul; // Vectorul este format din a-varful1, b-varful2 si costul de pe muchia lor
} muchie;

int viz[30], n, m, c;
muchie varf[30], aux;

// cititm datele problemei sub forma: varf1 -> varf2 – cost

void citire()
{
    int i;
    cout << "Introduceti numarul de varfuri: " << endl;
    cin >> n;
    cout << "Introduceti numarul de muchii: " << endl;
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cout << i <<". "; cin >> varf[i].a >> varf[i].b >> varf[i].costul;
    }
}

// Sortam muchiile in functie de costul lor- Partea „Gready” din algoritm

void sortare()
{
    int k = 0, i;
    while (k == 0)
    {
        k = 1;
        for (i = 1; i <= m - 1; i++)
        {
            if (varf[i].costul > varf[i + 1].costul)
            {
                aux = varf[i + 1];
                varf[i + 1] = varf[i];
                varf[i] = aux;
                k = 0;
            }
        }
    }
}

void kruskal()
{
    int i, j, k;
    i = 1;
    for (k = 1; k <= n - 1; k++)
    { // verificam sa nu vizitam varfuri deja vizitate
        while (viz[varf[i].a] == viz[varf[i].b] && viz[varf[i].a] != 0)
            i++;
        // calculam costul total al arborelui de cost minim
        c += varf[i].costul;
        // afisam cele 2 varfuri
        cout << varf[i].a << " " << varf[i].b << "\n";
        // daca cele 2 varfuri nu sunt vizitate atunci le vizitam si le salvam o valoare din cele 2 //in „viz”
        if (viz[varf[i].a] + viz[varf[i].b] == 0)
            viz[varf[i].a] = viz[varf[i].b] = varf[i].a;
        // daca 1 din cele 2 valori este 0 o completam cu valoarea celeilalte
        else
            // daca ambele valori fac parte deja dintr-un arbore secundar, modificam toate valorile
            // lui cu valorile celuilalt; practic legam cei 2 arbori
            if (viz[varf[i].a] * viz[varf[i].b] == 0)
                viz[varf[i].a] = viz[varf[i].b] = viz[varf[i].a] + viz[varf[i].b];
            else
            {
                for (j = 1; j <= n; j++)
                    if (viz[j] == viz[varf[i].a] && j != varf[i].a)
                        viz[j] = viz[varf[i].b];

                viz[varf[i].a] = viz[varf[i].b];
            }
        i++;
    }
    cout <<"costul minim este:" << c;
}

int main()
{
    citire();
    sortare();
    kruskal();
}
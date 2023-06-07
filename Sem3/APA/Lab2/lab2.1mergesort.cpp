#include <iostream>

using namespace std;
void merge(int *, int, int, int);
void merge_sort(int *tab, int mic, int mare)
{
    int mij;
    if (mic < mare)
    {
        // dividez tabloul la mijloc si sortez independent utilizand mergesort
        mij = (mic + mare) / 2;
        merge_sort(tab, mic, mij);
        merge_sort(tab, mij + 1, mare);
        // merge or conquer sorted tabays
        merge(tab, mic, mare, mij);
    }
}
// Merge sort
void merge(int *tab, int mic, int mare, int mij)
{
    int i, j, k, c[50];
    i = mic;
    k = mic;
    j = mij + 1;
    while (i <= mij && j <= mare)
    {
        if (tab[i] < tab[j])
        {
            c[k] = tab[i];
            k++;
            i++;
        }
        else
        {
            c[k] = tab[j];
            k++;
            j++;
        }
    }
    while (i <= mij)
    {
        c[k] = tab[i];
        k++;
        i++;
    }
    while (j <= mare)
    {
        c[k] = tab[j];
        k++;
        j++;
    }
    for (i = mic; i < k; i++)
    {
        tab[i] = c[i];
    }
}
// citesc rezultatul si afisez
int main()
{
    int mytabay[] = {8, 7, 6, 1, 0, 9, 2};
    int num = 7;
    merge_sort(mytabay, 0, num - 1);
    cout << "Tabelul sortat:\n";
    for (int i = 0; i < num; i++)
    {
        cout << mytabay[i] << "\t";
    }
}

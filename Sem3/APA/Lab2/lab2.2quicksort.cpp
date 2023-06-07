#include <iostream>
using namespace std;

// functia pentru a schimba elementele
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// functie de afisare tablou
void printtabel(int tabel[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << tabel[i] << " ";
    cout << endl;
}

// functe de rearanjare (gasire punctul de repartizare)
int partition(int tabel[], int mic, int mare)
{

    // selectare cel mai din dreapta ca  pivot
    int pivot = tabel[mare];

    // pointer pentru cel mai mare numar
    int i = (mic - 1);

    // traversez fiecare element al tabloului
    // le compar cu pivotul
    for (int j = mic; j < mare; j++)
    {
        if (tabel[j] <= pivot)
        {

            // daca element mai mic ca pivotul e gasit
            // il schimb cu cel mai mare i
            i++;

            // schimb elementele intre j si i
            swap(&tabel[i], &tabel[j]);
        }
    }

    // schimb pivotul cu cel mai mare element
    swap(&tabel[i + 1], &tabel[mare]);

    // returnez elementul de repartizare
    return (i + 1);
}

void quickSort(int tabel[], int mic, int mare)
{
    if (mic < mare)
    {

        // gasesc elemnt c
        // elemente mai mici ca pivot sunt la stanga de acesta
        // elemente mai mare ca pivot este la dreapta de acesta
        int pi = partition(tabel, mic, mare);

        // apel recursiv la stanga de pivot
        quickSort(tabel, mic, pi - 1);

        //  apel recursiv la dreapta de pivot
        quickSort(tabel, pi + 1, mare);
    }
}

int main()
{
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "tabel nesortat: \n";
    printtabel(data, n);

    // quicksort
    quickSort(data, 0, n - 1);

    cout << "Tabel sortat: \n";
    printtabel(data, n);
}
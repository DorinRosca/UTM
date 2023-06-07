#include <iostream>
using namespace std;
int nr_vf, nr_eg;

typedef struct
{
    int beg, end;
    double cost;
} muchie;

muchie *M;

int *APM, *za;

void init()
{
    int i;
    cout << "Introduceti nr. virfurilor: ";
    cin >> nr_vf;
    cout << "Introduceti nr. arcelor: ";
    cin >> nr_eg;
    APM = new int[nr_vf - 1];
    M = new muchie[nr_eg];
    cout << "\nIntroduceti arcul si costul:\n";
    for (int i = 0; i < nr_eg; ++i)
    {
        cin >> M[i].beg >> M[i].end >> M[i].cost;
        M[i].beg--;
        M[i].end--;
    }
    za = new int[nr_vf];
    for (i = 0; i < nr_vf; i++)
        za[i] = 0;
}
int cut_min()
{
    int rm;
    double q = 1.E15;
    for (int i = 0; i < nr_eg; i++)
        if (za[M[i].beg] ^ za[M[i].end])
            if (M[i].cost < q)
            {
                rm = i;
                q = M[i].cost;
            }
    return rm;
}
void apm_Prim(int start)
{
    za[start] = 1;
    for (int i = 0; i < nr_vf - 1; i++)
    {
        int rm = cut_min();
        APM[i] = rm;
        if (za[M[rm].beg])
            za[M[rm].end] = 1;
        else
            za[M[rm].beg] = 1;
    }
}

int main()
{
    double cost_apm = 0;
    int i;
    init();
    cout << "\nIntroduceti varful de plecare: ";
    cin >> i;
    apm_Prim(i - 1);
    cout << "\n-------------------------------\n Rezultatele:\n";
    for (i = 0; i < nr_vf - 1; i++)
    {
        int rm = APM[i];
        cout << (M[rm].beg + 1) << " - " << (M[rm].end + 1) << "\tCost: " << M[rm].cost << endl;
        cost_apm += M[rm].cost;
    }
    cout << "\nCostul minim = " << cost_apm << '\n';
    delete[] APM;
    delete[] M;
    delete[] za;
}
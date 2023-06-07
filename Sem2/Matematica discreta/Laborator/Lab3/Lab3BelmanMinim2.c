#include <stdio.h>
int tabel[100][100];
int varfuri,muchii;
int muchieI[100],muchieF[100];
int varf[100][100];
int count=0;
int numar1,numar=100;
int numarVarfuri=0;
int inceputArc[100],sfarsitArc[100];
int varfFinal;
int matCount[100][100];
int mCount=0;
int mCount1=0;
int count2, count1;
int caut(int varf)
{
  count=0;
  matCount[mCount][mCount1]=varf;
  mCount1++;
  for(int i=1;i<=muchii;i++)
  {
    if(varf==sfarsitArc[i] )
    {
    caut(inceputArc[i]);
    mCount++;
    }
  }
  count=0;
}

int celula(int nrRand, int nrVarf)
{
//Aflarea sumei minime din tot randul unui varf;
  numar=100;//valoare infinita;
  for(int i=1;i<=varfuri;i++)
  {
    numar1=varf[nrVarf-1][i]+tabel[nrRand][i];
    if(numar1<numar)
    {
      numar=numar1;
    }
  }
}
//Aflarea tuturor varfurilor
int varful(int varfcurent)
{
  count=0;//A afla daca randul se repeta sau nu
  for(int j=1;j<=varfuri;j++)
  {
    if(varf[varfcurent-1][j]==varf[varfcurent-2][j] && varfcurent !=2)
    {
      count++;
    }
  }
  if(count !=varfuri)
  {
    for(int a=1;a<=varfuri;a++)
    {
      celula(a,varfcurent);
      varf[varfcurent][a]=numar;
    }
  numarVarfuri++;
  }
}
int main ()
{
//Se introduc numarul de varfuri si muchii de la tastatura
  printf("Introduceti numarul de varfuri ale grafului:");
  scanf("%d",&varfuri);
  int h[varfuri];
  int h2[varfuri];
  printf("Introduceti numarul de muchii ale grafului:");
  scanf("%d",&muchii);
  int pondere[muchii];
  int pondere2[muchii];
//Se introduce fiecare muchie manual de la tastatura sub forma Px y (unde x e prul varf,y al doilea)
  printf("Introduceti  fiecare arc al grafului:\n");
  for(int i=1;i<=muchii;i++)
  {
    printf("P");
    scanf("%d",&muchieI[i]);
    scanf("%d",&muchieF[i]);
  }
//Se introduce ponderea pentru fiecare muchie de la tastatura
  printf("Introduceti  ponderea varfurilor:\n");
  for(int i=1;i<=muchii;i++)
  {
    printf("P(%d,%d)=",muchieI[i],muchieF[i]);
    scanf("%d",&pondere[i]);
  }
//Crearea unui tabel cu varfurile si ponderele
  for(int i=1;i<=varfuri;i++)
  {
    for(int j=1;j<=varfuri;j++)
    {
      if(j==i)
      {
        tabel[i][j]=0;
      }
      else
      {
        tabel[i][j]=100;
      }
    }
  }
//Adaugarea Ponderelor in tabel
  int x;
  for(int i=1;i<=varfuri;i++)
  {
    for(int j=1;j<=varfuri;j++)
    {
      for(int y=1;y<=muchii;y++)
      {
        if(muchieI[y]==i)
        {
          x=muchieF[y];
          tabel[i][x]=pondere[y];
        }
      }
    }
  }
//creare V0
  for(int i=1;i<varfuri;i++)
  {
    varf[1][i]=tabel[i][varfuri];
  }
//creare celalalte Vx
  for(int x=2;x<=varfuri;x++)
  {
    varful(x);
  }
  printf("\n\n\n\n\n\n\n");
//Afisare
  for(int i=1;i<=varfuri;i++)
  {
    printf("  \tx%d", i);
  }
  printf("\n");
  for(int i=1;i<=varfuri;i++)
  {
    printf("x%d\t",i);
    for(int j=1;j<=varfuri;j++)
    {
      if(tabel[i][j]==100)
      {
        printf("inf\t");
      }
      else
      {
        printf("%d\t",tabel[i][j]);
      }
    }
    printf("\n");
  }
  for(int i=0;i<varfuri;i++)
  {
    printf("--------");
  }
  printf("\n");
  for(int i=1;i<=numarVarfuri;i++)
  {
    printf("v%d\t",i-1);
    for(int j=1;j<=varfuri;j++)
    {
      if(varf[i][j]==100)
      {
        printf("inf\t");
      }
      else
      {
        printf("%d\t",varf[i][j]);
      }
    }
    printf("\n");
  }
//Aflarea ce arcuri exista
  printf("Aflare daca exista varfuri:\n");
  int varfad=1;
  for(int i=1;i<=varfuri;i++)
  {
    for(int j=1;j<=varfuri;j++)
    {
      if(j!=i)
      {
        if(varf[numarVarfuri][i]-varf[numarVarfuri][j] ==tabel[i][j])
        {
          printf("%d-%d=%d\n",varf[numarVarfuri][i],varf[numarVarfuri][j],tabel[i][j]);
          inceputArc[varfad]=i;
          sfarsitArc[varfad]=j;
          varfad++;
        }
      }
    }
  }

  printf("Exista arcurile:\n");
  for(int i=1;i<=varfad;i++)
  {
    printf("%d-%d\n",inceputArc[i],sfarsitArc[i]);
  }
  varfFinal=varfuri;
  for(int i=1;i<=muchii;i++)
  {
    if(varfFinal==sfarsitArc[i] && varfFinal != 1)
    {
      caut(inceputArc[i]);
      printf("\n");
    }
  }
//Creare o matrice aparte cu toate drumurile si elementele lor
  int x1;
  int d;
  for(int s=0;s<4;s++)
  {
    for(int i=0;i<mCount;i++)
    {
      x1=0;
      for(int j=0;j<mCount1;j++)
      {
        x1=matCount[i][j]+x1;
      }
      if(x1==0)
      {
        mCount--;
        d=i;
        while(d<mCount)
        {
          for(int h=0;h<mCount1;h++)
          {
            matCount[d][h]=matCount[d+1][h];
          }
          d++;
        }
      }
    x1=0;
    }
  }
//Adaugarea Inceputului Drumului in Matrice
  for(int i=1;i<mCount;i++)
  {
    for(int j=0;j<mCount1;j++)
    {
      if(matCount[i][j]!=0)
      {
        if(matCount[i][j-1]==0)
        {
          for(int u=0;u<muchii;u++)
          {
            if(muchieI[u]==matCount[i][j])
            {
              for(int s=j;s>0;s--)
              {
                if(muchieF[u]==matCount[i-1][s])
                {
                  for(int e=s;e>0;e--)
                  {
                    matCount[i][e]=matCount[i-1][e];
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//selectia drumurilor:
  int count2=0;
  for (int i=0; i<mCount;i++)
  {
    for(int j=0;j<=mCount1;j++)
      if(matCount[i][j] ==1)
      {
        count2++;
      }
      if(count2==0)
      {
        for(int y=0;y<=mCount1;y++)
        {
          matCount[i][y]=0;
          matCount[i][y]=matCount[i+1][y];
          matCount[i+1][y]=0;
        }
        mCount--;
      }
    count2=0;
  }
//Afisare
  count=1;
  for(int i=0;i<mCount;i++)
  {
    printf("Drumul %d:%d",count,varfFinal);
    for(int j=0;j<mCount1;j++)
    {
      if(matCount[i][j]!=0)
      {
        printf("<-%d",matCount[i][j]);
      }
    }
    printf("\n");
    count++;
  }
}
//   9 16    1 2 1 3 1 4 2 3 2 4 3 5 3 6 4 5 4 7 5 6 5 7 5 8 6 8 7 9 8 7 8 9 3 11 7 10 3 9 4 3 8 7 6 7 8 6 3 4

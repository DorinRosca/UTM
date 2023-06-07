#include <stdio.h>
int varfuri,muchii;
int muchieI[100],muchieF[100],muchieI2[100],muchieF2[100];
int matCount[100][100];
int count2, count1;
int sfarsitM,inceputM;
int varfFinal;
int mCount=0;
int mCount1=0;
int count;

int caut(int varf)
{
  count=0;
  matCount[mCount][mCount1]=varf;
  mCount1++;
  for(int i=1;i<=muchii;i++)
  {
    if(varf==muchieF2[i] )
    {
    caut(muchieI2[i]);
    mCount++;
    }
  }
  count=0;
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
//Se initiaza H cu o si respectiv INF(1000)
  h[1]=0;
  for(int i=2;i<=varfuri;i++)
  {
    h[i]=1000;
  }
//Se calculeaza H al fiecarui varf dupa regula daca Hj- Hi>Pij =>Hj=Pij+Hi
  for(int j=1;j<=muchii;j++)
  {
    for(int i=1;i<=muchii;i++)
    {
      inceputM=muchieI[i];
      sfarsitM=muchieF[i];
      if(h[sfarsitM]-h[inceputM]>pondere[i])
      {
        h[sfarsitM]=pondere[i]+h[inceputM];
      }
    }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  }
//Afisare Tabel
  printf("(xi-xj)   Pij   Arc");
  for(int i=1;i<=muchii;i++)
  {
    inceputM=muchieI[i];
    sfarsitM=muchieF[i];
//Sortare daca exista sau nu Drum
    if(h[sfarsitM]-h[inceputM]==pondere[i])
    {
      printf("\n( %d,%d )   %d  Exista  ",muchieI[i],muchieF[i],pondere[i]);
    }
    else
    {
      printf("\n( %d,%d )   %d  Nu Exista  ",muchieI[i],muchieF[i],pondere[i]);
      count1++;
    }
  }
  printf("\n\n\n");
  for(int i=1;i<=varfuri;i++)
  {
    printf("H%d-%d\n",i,h[i]);
  }
  printf("\n");
//Crearea unei noi matrici in care se adauga toate arcurile care exista
  for(int i=1;i<=muchii;i++)
  {
    inceputM=muchieI[i];
    sfarsitM=muchieF[i];
    if(h[sfarsitM]-h[inceputM]==pondere[i])
    {
      count2++;
      muchieI2[count2]=muchieI[i];
      muchieF2[count2]=muchieF[i];
      pondere2[count2]=pondere[i];
    }
  }
//Afisare
  muchii=muchii-count1;
  printf("(xi-xj)   Pij");
  for(int i=1;i<=muchii;i++)
  {
  printf("\n( %d,%d )   %d",muchieI2[i],muchieF2[i],pondere2[i]);
  }
  printf("\n");
varfFinal=varfuri;
  for(int i=1;i<=muchii;i++)
  {
    if(varfFinal==muchieF2[i] && varfFinal != 1)
    {
      caut(muchieI2[i]);
      printf("\n");
    }
  }
//Creare o matrice aparte cu toate drumurile si elementele lor
  int x;
  int d;
  for(int s=0;s<4;s++)
  {
    for(int i=0;i<mCount;i++)
    {
      x=0;
      for(int j=0;j<mCount1;j++)
      {
        x=matCount[i][j]+x;
      }
      if(x==0)
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
    x=0;
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
// 1 2 2 3 2 4 3 4 4 5 2 7 3 9 2

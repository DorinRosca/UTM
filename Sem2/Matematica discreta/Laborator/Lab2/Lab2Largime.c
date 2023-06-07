#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int varfuri;
int tabMA[100][100];
int varfCurent;
int varfuriAdiacente[100];
int x=1;
int varf=0;
void IntroducereListaAdiacenta()
{
  printf("Introduceti numarul de varfuri ale grafului:");
  scanf("%d",&varfuri);
  int varfAdiacent,vecini;
  for(int i=1;i<=varfuri;i++)
  {
    for(int j=1;j<=varfuri;j++)
    {
      tabMA[i][j]=0;
    }
  }
system("cls");
//Crearea Matricei Adiacente---------------------------------------------------------------------
  for(int i=1;i<=varfuri;i++)
  {
    printf("Scrieti numarul de varfuri adiacente varfului: x%d-",i);
    scanf("%d",&vecini);
    if(vecini==0)
    {
      printf("");//nu se efectuiaza nimic
    }
    else
    {
      for(int j=1;j<=vecini;j++)
      {
        printf("Varful Adiacent %d-",j);
        scanf("%d",&varfAdiacent);
        tabMA[i][varfAdiacent]=1;
      }
    }
  }
  system("cls");//curatarea consolei
  printf("\nAfisarea Matricei Adiacente:");
  printf("\n");
  for(int i=1;i<=varfuri;i++)
  {
    printf(" \tX%d",i);
  }
  for(int i=1; i<=varfuri; i++)
  {
    printf("\n");
    printf("X%d",i);
    for(int y=1; y<=varfuri; y++)
      {
        printf("\t%d ",tabMA[i][y]);
      }
  }
}
void ParcLargime(int varf)
{
  for(int i=1;i<=varfuri;i++)
  {
    if(tabMA[varf][i]==1 && tabMA[varf][i]!=0)
    {
      printf("->%d",i);
      tabMA[varf][i]=0;
      tabMA[i][varf]=0;
      varfuriAdiacente[x]=i;
      x++;
    }
  }
}
void ParcLargime2()
{
  for(int h=1;h<x;h++)
  {
    varf=varfuriAdiacente[h];
    for(int i=1;i<=varfuri;i++)
    {
      if(tabMA[varf][i]==1 && tabMA[varf][i]!=0)
      {
        printf("->%d",i);
        tabMA[varf][i]=0;
        tabMA[i][varf]=0;
        varfuriAdiacente[x]=i;
        x++;
      }
    }
  }
}
int main ()
{
  IntroducereListaAdiacenta();
  printf("\nIntroduceti Numarul Varfului de la care doriti sa incepeti parcurgerea in Largime:");
  scanf("%d",&varfCurent);
  printf("%d|%d",varfCurent,varfCurent);
  ParcLargime(varfCurent);
  ParcLargime2();
  return 0;
}

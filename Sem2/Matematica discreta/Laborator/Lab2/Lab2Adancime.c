#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int varfuri;
int tabMA[100][100];
int varfCurent;

void IntroducereListaAdiacenta()
{
  printf("Introduceti numarul de varfuri ale grafului:");
  scanf("%d",&varfuri);
  int varfAdiacent,vecini;
  //Initializarea Matricei Adiacente cu 0
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
//Parcurgerea in Adancime-----------------------------------------------------------------------------------
void ParcAdancime(int varf)
{
  for(int i=1;i<=varfuri;i++)
  {
    if(tabMA[varf][i]==1 && tabMA[varf][i]!=0)
    {
      printf("->%d",i);
      tabMA[varf][i]=0;
      tabMA[i][varf]=0;
      ParcAdancime(i);
    }
  }
}
int main ()
{
  IntroducereListaAdiacenta();
  printf("\nIntroduceti Numarul Varfului de la care doriti sa incepeti parcurgerea in adancime:");
  scanf("%d",&varfCurent);
  printf("%d|%d",varfCurent,varfCurent);
  ParcAdancime(varfCurent);
  return 0;
}

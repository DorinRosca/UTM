#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int varfuri;
int tabMA[100][100];
int arcI[100],arcF[100];
int numarArc=0;
int grafAC[100][100];
int f,r,count2;

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
        arcI[numarArc]=i;
        arcF[numarArc]=varfAdiacent;
        numarArc++;
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
int main ()
{
  IntroducereListaAdiacenta();
  printf("\n");
  printf("toate muchiile posibile sunt:");
  for(int i=0;i<numarArc;i++)
  {
    printf("\n(%d,%d)",arcI[i],arcF[i] );
  }

//stergerea archurilor la care se repeta varful final
  int count;
  for(int i=1;i<=varfuri;i++)
  {
    for(int j=0;j<numarArc;j++)
    {
      if(i==arcF[j])
      {
        count++;
      }
      if(count!=1 &&count!=0 &&i==arcF[j])
      {
        arcI[j]=0;
        arcF[j]=0;
      }
    }
    count=0;
  }
  printf("\nmuchiile fara a se repeta varful final sunt :");
  for(int i=0;i<numarArc;i++)
  {
    if(arcI[i]!=0)
    {
      printf("\n(%d,%d)",arcI[i],arcF[i] );
    }
  }
  /*
  //stergerea muchiile la care se scchimba cu locul doar varfurile
  for(int i=0;i<numarArc;i++)
  {
    for(int j=0;j<numarArc;j++)
    {
      if(arcI[i] == arcF[j] && arcF[i]==arcI[j])
      {
        arcF[i]=0;
        arcI[i]=0;
      }
    }
  }

*/

  printf("\ngraful de acoperire:");
  for(int i=0;i<=numarArc;i++)
  {
    if(arcI[i]!=0 &&arcF[i])
    {
      printf("\n(%d->%d)",arcI[i],arcF[i]);
      f=arcI[i];
      r=arcF[i];
      grafAC[f][r]=1;
      count2++;
    }
  }

  printf("\nMatrice:\n\n");
  for(int i=2;i<=varfuri;i++)
  {
    printf("\tx%d",i);
  }
  printf("\n");
  for(int i=1;i<=varfuri;i++)
  {
    printf("x%d\t",i );
    for(int j=2;j<=varfuri;j++)
    {
      printf("%d\t",grafAC[i][j]);
    }
    printf("\n");
  }

return 0;
}

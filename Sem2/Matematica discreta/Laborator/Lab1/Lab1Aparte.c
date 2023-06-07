#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int firstRun=1;

//--------Crearea Unei Matrici Adiacente--------------------------------------------------------------------
void CreareMatAdiacenta(int varfuri,int matrice[100][100])
  {
  int vecini;
  int varf;
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      matrice[i][j]=0;
      }
    }
  printf("\n\n");
  printf("Crearea unei Matrice Adiacente:\n");
  printf("Scrieti numarul de varfuri adiacente varfului:\n");
  for(int i=0;i<varfuri;i++)
    {
    printf("x%d-",i+1);
    scanf("%d",&vecini);
    if(vecini==0)
      {
      printf("");
      }
    else
      {
      for(int j=0;j<vecini;j++)
        {
        printf("Varful Adiacent %d-",j+1 );
        scanf("%d",&varf);
        matrice[i][varf-1]=1;
        }
      }
    }
  }
//--------Crearea Unei Matrici Incidente--------------------------------------------------------------------
void CreareMatIncidenta(int muchii, int matrice[100][100],int varfuri)
  {
  int y1=0;
  int y2=0;
  int y3,y4;
  for(int i=0;i<muchii;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      matrice[i][j]=0;
      }
    }
  printf("Sunt %d Varfuri\n", varfuri);
  printf("introduceti varfurile [a][b]separandu-le prin Space,unde [a] este varful de unde incepe muchia, iar [b] unde se termina.\n ");
  for(int r=0;r<muchii;r++)
  {
    printf("Varfurile- ");
    scanf("%d",&y3);
    scanf("%d",&y4);
    for(int y1=0;y1<varfuri;y1++)
      {
      for(int y2=0;y2<varfuri;y2++)
        {
        if(y1+1==y3)
          {
          matrice[r][y1]=-1;
          }
        if(y2+1==y4)
          {
          matrice[r][y2]=1;
          }
        }
      }
    }
}
//--------Crearea Unei  Liste  Adiacente--------------------------------------------------------------------
void CreareaListAdiacenta(int varfuri,int tab[100][100])
{
  printf("Crearea unei Liste Adiacente:\n");
  int vecini;
  for(int i=0;i<varfuri;i++)
  {
    printf("Introduceti numarul de vecini al lui %d:",i+1);
    scanf("%d",&vecini);
    for(int y=0;y<vecini;y++)
    {

      printf("%d-",i+1);
      scanf("%d",&tab[i][y]);
    }
  }

}
//-------Afisarea Unei Matrici Adiacente--------------------------------------------------------------------
void AfisareMatAdiacenta(int z[100][100],int varfuri)
  {
  printf("\nAfisarea Matricei de Adiacenta\n");
  for(int i=0;i<varfuri;i++)
    {
    printf(" \tX%d",i+1);
    }
    for(int i=0; i<varfuri; i++)
      {
      printf("\n");
      printf("X%d",i+1);
      for(int y=0; y<varfuri; y++)
        {
        printf("\t%d ",z[i][y]);
        }
      }
      printf("\n");
    }
//-------Afisarea Unei Matrici Incidente--------------------------------------------------------------------
void AfisareMatIncidenta(int muchii,int tab[100][100],int varfuri)
  {
  printf("\nAfisarea Matricei de Incicenta\n");
  for(int i=0;i<varfuri;i++)
    {
    printf(" \tX%d",i+1);
    }
    for(int i=0; i<muchii; i++)
      {
      printf("\n");
      printf("u%d",i+1);
      for(int y=0; y<varfuri; y++)
        {
        printf("\t%d ",tab[i][y]);
        }
      }
    }
//-------Afisarea Unei Liste Adiacente----------------------------------------------------------------------
void AfisareListAdiacenta(int varfuri,int z[100][100])
  {

  printf("Afisarea unei Liste Adiacente:\n");
  for(int i=0;i<varfuri;i++)
    {
    printf("\n");
    printf("%d-",i+1);
    for(int y=0;y<varfuri;y++)
      {
      if(z[i][y]==0)
        {
        printf("");
        }
      else
        {
        printf("%d ",z[i][y]);
        }
      }
      printf("0");
    }
    printf("\n");
  }
//--------Transformarea din Matrice Adiacenta,in Matrice Incidenta------------------------------------------
int ConMA_MI(int varfuri,int tabA[100][100],int tabI[100][100])
  {
        //---Aflarea cate muchii sunt in graf----//
  int nrMuchiilor=0;
  int inceput;
  for(int i=0;i<varfuri;i++)
      {
      for(int j=0;j<varfuri;j++)
        {
        if(tabA[i][j]==1)
          {
            nrMuchiilor++;
          }
        }
      }
  //Convertirea
  printf("Introduceti pe ce loc se afla  varfului de la care incepe muchia");
  int  n=0;
  int  r=-1;
  int u=0;
  for(int i=0;i<varfuri;i++)
    {
    if(n<nrMuchiilor)
      {
      n=n+1;
      for(int j=0;j<varfuri;j++)
        {
          if(tabA[i][j]==1)
            {
              r++;
              tabI[r][i]=1;
              tabI[r][j]=1;
              printf("[%d][%d]-",i+1,j+1);
              scanf("%d",&inceput);
              if( inceput==1)
                {
                tabI[r][i]=-1;
                }
              if( inceput == 2)
                {
                tabI[r][j]=-1;
                }
            }
          }
        }
      }
    return nrMuchiilor;
  }
//--------Transformarea din Matrice Incidenta,in Matrice Adiacenta------------------------------------------
void ConMI_MA(int muchii,int varfuri,int tabA[100][100],int tabI[100][100])
  {
  int rand, coloana;
  for(int i=0;i<muchii;i++)
    {
      int temp1=0;
      int temp2=0;
    for(int j=0;j<varfuri;j++)
      {
      if(tabI[i][j]==-1)
        {
        coloana=j;
        temp1++;
        }
      if(tabI[i][j]==1)
        {
        temp2++;
        rand=j;
        }
        if(temp1==temp2)
        {
      tabA[coloana][rand]=1;
      }
    }
    }
  }
//--------Transformarea din Lista Adiacenta,in Matrice Adiacenta--------------------------------------------
void ConLA_MA(int varfuri,int tabMA[100][100],int tabLA[100][100])
  {
  int var;
  printf("Transformarea din Lista Adiacentain Matrice Adiacenta.");
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      if(tabLA!=0)
        {
          var=tabLA[i][j];
          if(var!=0)
            {
            tabMA[i][var-1]=1;
            }
        }
      }
    }
  }
//--------Transformarea din Matrice Adiacenta,in Lista Adiacenta--------------------------------------------
void ConMA_LA(int varfuri,int tabMA[100][100],int tabLA[100][100])
  {
  int var=0;
  printf("Transformarea din Matrice de Adiacenta in Lista Adiacenta.");
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      if(tabMA[i][j]==1)
        {
        var=j+1;
        tabLA[i][j]=var;
        }
      }
    }
  }
//--------Transformarea din Lista Adiacenta,in Matrice Incidenta--------------------------------------------
int ConLA_MI(int muchii,int varfuri,int tabLA[100][100],int tabMI[100][100])
  {
  int tabTemp[100][100];
int var;
for(int i=0;i<varfuri;i++)
  {
  for(int j=0;j<varfuri;j++)
    {
    if(tabLA!=0)
      {
        var=tabLA[i][j];
        if(var!=0)
          {
          tabTemp[i][var-1]=1;
          }
      }
    }
  }
  int nrMuchiilor=0;
  int inceput;
  for(int i=0;i<varfuri;i++)
      {
      for(int j=0;j<varfuri;j++)
        {
        if(tabTemp[i][j]==1)
          {
            nrMuchiilor++;
          }
        }
      }
  //Convertirea
  printf("Introduceti pe ce loc se afla  varfului de la care incepe muchia");
  int  n=0;
  int  r=-1;
  int u=0;
  for(int i=0;i<varfuri;i++)
    {
    if(n<nrMuchiilor)
      {
      n=n+1;
      for(int j=0;j<varfuri;j++)
        {
          if(tabTemp[i][j]==1)
            {
              r++;
              tabMI[r][i]=1;
              tabMI[r][j]=1;
              printf("[%d][%d]-",i+1,j+1);
              scanf("%d",&inceput);
              if( inceput==1)
                {
                tabMI[r][i]=-1;
                }
              if( inceput == 2)
                {
                tabMI[r][j]=-1;
                }
            }
          }
        }
      }
    return nrMuchiilor;
  }
//--------Transformarea din Matrice Incidenta,in Lista Adiacenta--------------------------------------------
void ConMI_LA(int muchii,int varfuri,int tabLA[100][100],int tabMI[100][100])
  {
    int tabTemp[100][100];
    int rand, coloana;
    for(int i=0;i<muchii;i++)
      {
        int temp1=0;
        int temp2=0;
      for(int j=0;j<varfuri;j++)
        {
        if(tabMI[i][j]==-1)
          {
          coloana=j;
          temp1++;
          }
        if(tabMI[i][j]==1)
          {
          temp2++;
          rand=j;
          }
          if(temp1==temp2)
          {
        tabTemp[coloana][rand]=1;
        }
      }
      }
      int var=0;
      for(int i=0;i<varfuri;i++)
        {
        for(int j=0;j<varfuri;j++)
          {
          if(tabTemp[i][j]==1)
            {
            var=j+1;
            tabLA[i][j]=var;
            }
          }
        }
  }
//------------------------------------------------MENIU-----------------------------------------------------
  int Meniu()
  {
  if(firstRun)
  firstRun = 0;
  else
    {
    system("pause");
    system("cls");
    }
    int nrMeniu;
    printf("\n\n|            MENIUL PROGRAMULUI                          |\n");
    printf("|--------------------------------------------------------|\n");
    printf("|   1. Introducerea numarului de Muchii                  |\n");
    printf("|   2. Introducerea numarului de Varfuri                 |\n");
    printf("|   3. Creare  Matricea de Adiacenta.                    |\n");
    printf("|   4. Creare Matricea de Incidenta.                     |\n");
    printf("|   5. Creare Lista Adiacenta                            |\n");
    printf("|   6. Afisare Matricea de Adiacenta                     |\n");
    printf("|   7. Afisare Matricea de Incidenta                     |\n");
    printf("|   8. Afisare Lista Adiacenta                           |\n");
    printf("|   9. Transformarea din Mat Ad in Mat In                |\n");
    printf("|   10. Transformarea din Mat In in Mat Ad               |\n");
    printf("|   11. Transformarea din Lista Adiacenta in Matrice Ad. |\n");
    printf("|   12. Transformarea din Matrice Ad in Lista Adiacenta  |\n");
    printf("|   13. Transformarea din Lista Ad in Matrice Incidenta  |\n");
    printf("|   14. Transformarea din Matrice In in Lista Adiacenta  |\n");
    printf("|   0. Parasirea Programului                             |\n");
    printf("\nIntroceti numarul operatiei ce doriti sa efectuati!\n");
    scanf("%d", &nrMeniu);
    return nrMeniu;
  }
//----------------------------------------------------------------------------------------------------------
int main ()
  {
  int varfuri,n,r;
  int tabMA[100][100];
  int tabMI[100][100];
  int tabLA[100][100];
  int men;
  int nrMuchii;
  int list[2];
  do{
      men = Meniu();
  switch(men)
      {
      case 1:
      printf("Introduceti numarul de Muchii:");
      scanf("%d",&nrMuchii);
      break;
      case 2:
      printf("Introduceti numarul de Varfuri:");
      scanf("%d",&varfuri);
      break;
      case 3:
          CreareMatAdiacenta(varfuri,tabMA);
      break;
      case 4:
          CreareMatIncidenta(nrMuchii,tabMI,varfuri);
      break;
      case 5:
      CreareaListAdiacenta(varfuri,tabLA);
      break;
      case 6:
      AfisareMatAdiacenta(tabMA,varfuri);
      break;
      case 7:
      AfisareMatIncidenta(nrMuchii,tabMI,varfuri);
      break;
      case 8:
      AfisareListAdiacenta(varfuri,tabLA);
      break;
      case 9:
          nrMuchii=ConMA_MI(varfuri,tabMA,tabMI);
      break;
      case 10:
          ConMI_MA(nrMuchii,varfuri,tabMA,tabMI);
      break;
      case 11:
          ConLA_MA(varfuri,tabMA,tabLA);
      break;
      case 12:
          ConMA_LA(varfuri,tabMA,tabLA);
          list[0]=nrMuchii;
          list[1]=varfuri;
      break;
      case 13:
          nrMuchii=ConLA_MI(nrMuchii,varfuri,tabLA,tabMI);
      break;
      case 14:
          ConMI_LA(nrMuchii,varfuri,tabLA,tabMI);
      break;
      }
    }while(men != 0);
  return 0;
}

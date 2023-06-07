#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int firstRun=1;

void IntroducereMatriceAdiacenta(int varfuri, int muchii,int tabMA[100][100],int tabMI[100][100],int tabLA[100][100],int parametri[2])
 {
       system("cls");
  int varfAdiacent,vecini;
//Egalarea Matricei Adiacente cu 0
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      tabMA[i][j]=0;
      }
    }
    printf("\n\n");
//Crearea Matricei Adiacente---------------------------------------------------------------------
  printf("Introduceti numarul de varfuri ale grafului:");
  scanf("%d",&varfuri);
  for(int i=0;i<varfuri;i++)
    {
    printf("Scrieti numarul de varfuri adiacente varfului: x%d-",i+1);
    scanf("%d",&vecini);
    if(vecini==0)
      {
      printf("");//nu se efectuiaza nimic
      }
    else
      {
      for(int j=0;j<vecini;j++)
        {
        printf("Varful Adiacent %d-",j+1 );
        scanf("%d",&varfAdiacent);
        tabMA[i][varfAdiacent-1]=1;
        }
      }
    }
//--------Transformarea din Matrice Adiacenta,in Matrice Incidenta--------------------------------
//Egalarea Elementelor Matriceii cu 0;
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
        tabMI[i][j]=0;
      }
    }
//Aflarea cate muchii sunt in graf
  muchii=0;
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      if(tabMA[i][j]==1)
        {
        muchii++;
        }
      }
    }
//Convertirea
  int inceput;
  int n=0;
  int r=-1;
  for(int i=0;i<varfuri;i++)
    {
    if(n<muchii)
      {
      n=n+1;
      for(int j=0;j<varfuri;j++)
        {
          if(tabMA[i][j]==1)
            {
              r++;
              tabMI[r][i]=1;
              tabMI[r][j]=-1;

              if(i==j)
                {
                tabMI[r][j]=2;
                }
            }
        }
      }
    }
//-------------Transformarea din Matrice Adiacenta in Lista Adiacenta---------------------------
//Egalarea Elementelor Matriceii cu 0;
  for(int i=0;i<varfuri;i++)
    {
    for(int j=0;j<varfuri;j++)
      {
      tabLA[i][j]=0;
      }
    }
  int var=0;
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
//parametri
parametri[0]=varfuri;
parametri[1]=muchii;
}
void IntroducereMatriceIncidenta(int varfuri,int muchii,int tabMA[100][100],int tabMI[100][100],int tabLA[100][100],int parametri[2])
 {
       system("cls");
//--------Crearea Unei Matrici Incidente---------------------------------
  printf("Introduceti numarul de Muchii:");
  scanf("%d",&muchii );
  printf("Introduceti numarul de Varfuri:");
  scanf("%d",&varfuri );
  int y1=0;
  int y2=0;
  int y3,y4;
  //Egalarea cu 0 a matricei
  for(int i=0;i<muchii;i++)
    {
      for(int j=0;j<varfuri;j++)
      {
      tabMI[i][j]=0;
      }
    }
  printf("introduceti muchiile [a][b]separandu-le prin Space,unde [a] este varful de unde incepe muchia, iar [b] unde se termina in forma a b .\n");
  for(int r=0;r<muchii;r++)
    {
    printf("Varfurile- ");
    scanf("%d",&y3);
    scanf("%d",&y4);
    for(int y1=0;y1<varfuri;y1++)
      {
      for(int y2=0;y2<varfuri;y2++)
        {
        if(y1+1==y3 && y3!=y4)
          {
          tabMI[r][y1]=-1;
          }
        if(y2+1==y4 &&y3!=y4)
          {
          tabMI[r][y2]=1;
          }
        if(y3==y4)
          {
          tabMI[r][y3-1]=2;
          }
        }
      }
    }
//Covertirea in Matrice Adiacenta-----------------------------------------------------
int rand, coloana;
for(int i=0;i<muchii;i++)
  {
    int temp1=0;
    int temp2=0;
  for(int j=0;j<varfuri;j++)
    {
    if(tabMI[i][j]==-1 )
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
    tabMA[coloana][rand]=1;
    }
  }
  }
  for(int i=0;i<muchii;i++)
  {
    for(int j=0;j<muchii;j++)
    {
      if(tabMI[i][j]==2)
      {
        tabMA[j][j]=1;
      }
    }
  }
//transformare din Matrice Incidenta in  Lista Adiacenta------------------------------------------------
  int var=0;
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
//parametri
parametri[0]=varfuri;
parametri[1]=muchii;
}
void IntroducereListaAdiacenta(int varfuri, int muchii,int tabMA[100][100],int tabMI[100][100],int tabLA[100][100],int parametri[2])
 {
      system("cls");
  //Crearea Listei Adiacente-----------------------------------
  printf("Introduceti Numarul de varfuri:");
  scanf("%d",&varfuri);
  int vecini;
  for(int i=0;i<varfuri;i++)
    {
    printf("Introduceti numarul de vecini al lui %d:",i+1);
    scanf("%d",&vecini);
    for(int y=0;y<vecini;y++)
      {
      printf("%d-",i+1);
      scanf("%d",&tabLA[i][y]);
      }
    }
//Transformarea in Matrice Adiacenta-----------------------------------------
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
            tabMA[i][var-1]=1;
            }
        }
      }
    }
//Transformarea in Matrice Incidenta------------------------------------------
//Aflarea cate muchii sunt in graf
  muchii=0;
    for(int i=0;i<varfuri;i++)
        {
        for(int j=0;j<varfuri;j++)
          {
          if(tabMA[i][j]==1)
            {
              muchii++;
            }
          }
        }
    //Convertirea
  int inceput;
  int n=0;
  int r=-1;
  for(int i=0;i<varfuri;i++)
    {
    if(n<muchii)
      {
      n=n+1;
      for(int j=0;j<varfuri;j++)
        {
        if(tabMA[i][j]==1)
          {
          r++;
          tabMI[r][i]=1;
          tabMI[r][j]=1;
          inceput=1;
          if( inceput==1)
            {
            tabMI[r][i]=-1;
            }
          if( inceput == 2)
            {
            tabMI[r][j]=-1;
            }
          if(i==j)
            {
            tabMI[r][j]=2;
            }
          }
        }
      }
  }
//parametri
parametri[0]=varfuri;
parametri[1]=muchii;
}
void Afisare(int varfuri, int muchii,int tabMA[100][100],int tabMI[100][100],int tabLA[100][100])
 {
  system("cls");//curatarea consolei
  printf("\nAfisarea Matricei Adiacente:");
  printf("\n");
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
      printf("\t%d ",tabMA[i][y]);
      }
    }
  printf("\n");
  printf("\nAfisarea Matricei Incidente:" );
  printf("\n");
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
      printf("\t%d ",tabMI[i][y]);
      }
    }
  printf("\n");
  printf("\nAfisarea Listei Adiacente:" );
  printf("\n");
  for(int i=0;i<varfuri;i++)
    {
    printf("\n");
    printf("%d-",i+1);
    for(int y=0;y<varfuri;y++)
      {
      if(tabLA[i][y]==0)
        {
        printf("");
        }
      else
        {
        printf("%d ",tabLA[i][y]);
        }
      }
    printf("0");
    }
printf("\n");
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
    printf("\n\n|                            MENIUL PROGRAMULUI                           |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|                   Introducerea Grafului prin:                           |\n");
    printf("|        1. Matrice de Adiacenta                                          |\n");
    printf("|        2. Matrice de Incidenta                                          |\n");
    printf("|        3. Lista de adiacenta                                            |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|               4. Afisarea rezultatelor                                  |\n");
    printf("|\n\n Introduceti numarul operatiei:");
    scanf("%d", &nrMeniu);
    return nrMeniu;
  }
//----------------------------------------------------------------------------------------------------------
int main ()
  {
  int varfuri;
  int muchii;
  int tabMA[100][100];
  int tabMI[100][100];
  int tabLA[100][100];
  int men;
  int parametri[2];
  do{
      men = Meniu();
  switch(men)
      {
      case 1:
          IntroducereMatriceAdiacenta(varfuri,muchii,tabMA,tabMI,tabLA,parametri);
      break;
      case 2:
          IntroducereMatriceIncidenta(varfuri,muchii,tabMA,tabMI,tabLA,parametri);
      break;
      case 3:
          IntroducereListaAdiacenta(varfuri,muchii,tabMA,tabMI,tabLA,parametri);
      break;
      case 4:
      varfuri=parametri[0];
      muchii=parametri[1];
          Afisare(varfuri,muchii,tabMA,tabMI,tabLA);
          break;
      }
    }while(men != 0);
  return 0;
}

#include <stdio.h>
#define MAX 100
int nrVarfuri,nrMuchii,Inc_Muchie[MAX],Fin_Muchie[MAX];
int InceputRetea,SfarsitRetea;
int min=MAX;
int randMat=0,matDrumuri[MAX][MAX];
int nrDrum=1;
int Fb[MAX],nrFb=0,rezultat=0;
int tabMA[MAX][MAX];
int count1=0, count2=0;
int coloanaMat=0;
int count=0;
int varf[MAX];
//Functie de aflare a  drumurilor posibile din graf 1--------------------------------------------------------------------------------------
int Parcurgere(int varfCurent)
{
  if(count==0)
  {
    matDrumuri[randMat][coloanaMat]=varfCurent;
    coloanaMat++;
    for(int j=1;j<=nrVarfuri;j++)
    {
      if(tabMA[varfCurent][j]==1)
      {
        Parcurgere(j);
      }
    }
    if(varfCurent==SfarsitRetea)
    {
      randMat++;
      return 0;
    }
  }
  count++;
}
//Aflu continuarea drumurilor la care inceput se repeta
int Parcurgere2(int varfCurent)
{
  coloanaMat++;
  matDrumuri[randMat][coloanaMat]=varfCurent;
  for(int j=1;j<=nrVarfuri;j++)
  {
    if(tabMA[varfCurent][j]==1)
    {
      Parcurgere2(j);
    }
  }
}

int cautDrumuriFinal( int varfCurent,int arceVarf)
{
  //coloanaMat++;
  count=0;
  for(int j=1;j<=nrVarfuri;j++)
  {
    if(tabMA[varfCurent][j]==1)
    {
      count++;
      if(count==arceVarf)
      {
      Parcurgere2(j);
      }
    }
  }
}
int cautDrumuriInceput(int varf1,int arceVarf)
{
  for(int i=0;i<randMat;i++)
  {
    for(int j=0;j<nrVarfuri;j++)
    {
      if(matDrumuri[i][j]==varf1)
      {
        for(int k=0;k<=j;k++)
          {
            coloanaMat++;
            matDrumuri[randMat][coloanaMat]=matDrumuri[i][k];
            count=0;
          }
        cautDrumuriFinal(varf1,arceVarf);
      }
    }
  }
  randMat++;
}

int main ()
{
//Egalez cu 0 si -1 Matriciile
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      tabMA[i][j]=0;
    }
  }
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      matDrumuri[i][j]=-1;
    }
  }
//Se introduc numarul de varfuri si muchii(capacitati) de la tastatura si inceputul/sfarsitul relelei------------------------------------------------------------------------
  printf("Introduceti numarul de varfuri ale grafului:");
  scanf("%d",&nrVarfuri);
  printf("Introduceti numarul de Muchii  ale grafului:");
  scanf("%d",&nrMuchii);
  int capacitate[nrMuchii];
  printf("Introduceti fiecarei muchie:\n");
  for(int i=0;i<nrMuchii;i++)
  {
    printf("P");
    scanf("%d",&Inc_Muchie[i]);
    scanf("%d",&Fin_Muchie[i]);
    count1=Inc_Muchie[i];
    count2=Fin_Muchie[i];
    tabMA[count1][count2]=1;
  }
//Se introduce capacitatea pentru fiecare muchie de la tastatura
  printf("Introduceti  capacitatea fiecarei muchii:\n");
  for(int i=0;i<nrMuchii;i++)
  {
    printf("(%d,%d)=",Inc_Muchie[i],Fin_Muchie[i]);
    scanf("%d",&capacitate[i]);
  }
  printf("Introduceti Inceputul si Sfarsitul retelei de transport:\nInceput:");
  scanf("%d",&InceputRetea);
  printf("Sfarsit:");
  scanf("%d",&SfarsitRetea);
  printf("4\n" );
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Aflu de cate cate muchii duc in fiecare varf
  for(int i=0;i<=nrVarfuri;i++)
  {
    for(int j=0;j<=nrVarfuri;j++)
    {
      if(tabMA[i][j]==1)
      {
        varf[i]++;
      }
    }
  }
//Aflu Drumurile principale
  for(int j=1;j<=nrVarfuri;j++)
  {
    if(tabMA[InceputRetea][j]==1)
    {
      coloanaMat=0;
      matDrumuri[randMat][coloanaMat]=InceputRetea;
      coloanaMat++;
      Parcurgere(j);
      count=0;
    }
  }
//Aflu Drumurile Adaugatoare
  for(int i=0;i<=nrVarfuri;i++)
  {
    if(i!=InceputRetea)
    {
      if(varf[i]>1)
      {
        coloanaMat=-1;
        cautDrumuriInceput(i,varf[i]);
      }
    }
  }


//Aflarea Capacitatii de transport///////////////////////////////////////////////////////////////////////////////////////////////////////////
  for(int i=0;i<randMat;i++)
  {
    printf("Drumul %d=(%d",nrDrum,InceputRetea);
    nrDrum++;
    for(int j=1;j<nrVarfuri;j++)
    {
      if(matDrumuri[i][j]!=-1 )
      {
        printf("-%d",matDrumuri[i][j]);
      }
    }
  //Afisare Drumurile-----------------------------------------------------------------------------------------------
    printf("),E=E1min{");
  //Calculul capacitatii maxime a unui drum------------------------------------------------------------------------
    for(int j=0;j<nrVarfuri;j++)
    {
      if(matDrumuri[i][j]!=-1 && matDrumuri[i][j+1] !=-1)
      {
        for(int q=0;q<nrMuchii;q++)
        {
          if(Inc_Muchie[q] == matDrumuri[i][j] && Fin_Muchie[q] == matDrumuri[i][j+1])
          {
            printf("%d;",capacitate[q]);
            if(min>capacitate[q])
            {
            min=capacitate[q];//se afla capacitatea cea mai mica din lant
            }
          }
        }
      }
    }
    printf("}=%d\n",min);
    Fb[nrFb]=min;
    nrFb++;
    rezultat=rezultat+min;
    for(int j=0;j<nrVarfuri;j++)
    {
      if(matDrumuri[i][j]!=-1 && matDrumuri[i][j]+1 !=-1)
      {
        for(int q=0;q<nrMuchii;q++)
        {
          if(Inc_Muchie[q] == matDrumuri[i][j] && Fin_Muchie[q] == matDrumuri[i][j+1])
          {
            capacitate[q]=capacitate[q]-min;//schimb capacitatea maxima in capacitatea maxima-capacitatea transportata deja pe un drum
          }
        }
      }
    }
    min=100;
  }
  printf("\nFb=%d",Fb[0]);
  for(int i=1;i<nrFb;i++)
  {
    printf("+%d",Fb[i]);
  }
  printf("\nFluxul Maxim ale grafului este %d\n",rezultat );
  }
//5 6       1 2 1 3 2 4 2 3 4 5 3 5 4 7 2 2 3 5 1 5

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WinMine.h"

//---------------------------------------------------------------------------
//Constructor
WinMine::WinMine()
  {
    yaSeCreo=false;
    matrix=NULL;
    juegoVigente=false;
    time=0;
  }
//---------------------------------------------------------------

//Destructor
WinMine::~WinMine()
  {
  }
//---------------------------------------------------------------

//-------------------------------------Metodos Privados-----------
//-------------Modificadores-------------
void
WinMine::destruirMatrix()
  {
    for(int i=0;i<numFils;i++)
      {
        delete matrix[i];
        delete matrixClick[i];
      }
    delete matrix;
    delete matrixClick;
  }
//---------------------------------------------------------------

void
WinMine::randomizarMatrix(const int &fils, const int &cols, const int &nivel)
  {
    randomize();
    int nFil,nCol;
    int numMines;
    switch(nivel)
      {
        case 0:
        if(fils==9 && cols ==9)
          {
            numMinas=10;
          }
        else if(fils==16 && cols ==16)
          {
            numMinas=40;
          }
        else if(fils==16 && cols ==30)
          {
            numMinas=99;
          }
        else
          {
            numMinas=((fils*cols)*99)/480;
          }
          break;
        case 1:
          numMinas=10;
          break;
        case 2:
          numMinas=40;
          break;
        case 3:
          numMinas=99;
          break;
        default:
          numMinas=((fils*cols)*99)/480;
          break;
      };
    numMines=numMinas;
    numMinasFlag=numMinas;
    while(numMines>0)
      {
        nFil=random(numFils);
        nCol=random(numCols);
        if(matrix[nFil][nCol]!=-1)
          {
            matrix[nFil][nCol]=-1;
            numMines--;
          }
      }
    int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
    int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
    int filFin,colFin;
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            if(matrix[i][j]!=-1)
              {
                numMines=0;
                for(int vecino=0;vecino<8;vecino++)
                  {
                    filFin=i+deltaFil[vecino];
                    colFin=j+deltaCol[vecino];
                    if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
                      {
                        if(matrix[filFin][colFin]==-1)
                          {
                            numMines++;
                          }
                      }
                  }
                matrix[i][j]=numMines;
              }
          }
      }
  }

//-------------------------------------Metodos Publicos-------------------

//-------------Modificadores-----------

void
WinMine::cambiarSize(const int &nFils, const int &nCols, const int &nivel)
  {
    if (!yaSeCreo)
      {
        matrix=new int*[nFils];
        matrixClick=new int*[nFils];
        for(int i=0;i<nFils;i++)
          {
            matrix[i]=new int[nCols];
            matrixClick[i]=new int[nCols];
          }
        yaSeCreo=true;
      }
    else
      {
        destruirMatrix();
        matrix=new int*[nFils];
        matrixClick=new int*[nFils];
        for(int i=0;i<nFils;i++)
          {
            matrix[i]=new int[nCols];
            matrixClick[i]=new int[nCols];
          }
      }
    level=nivel;
    juegoVigente=true;
    numFils=nFils;
    numCols=nCols;
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            matrix[i][j]=-2;
            matrixClick[i][j]=false;
          }
      }
    randomizarMatrix(nFils,nCols,nivel);
  }
//---------------------------------------------------------------

void
WinMine::setTime(const int &newTime)
  {
    time=newTime;
  }
//---------------------------------------------------------------

void
WinMine::aumentarDisminuirMinesFlag(const int &minesFlag)
  {
    numMinasFlag=numMinasFlag+minesFlag;
  }
//---------------------------------------------------------------

void
WinMine::setMinesFlag(const int &minesFlag)
  {
    numMinasFlag=minesFlag;
  }
//---------------------------------------------------------------

void
WinMine::cambiarEstadoMatrixClick(const int &fil, const int &col, const int &cual)
  {
    matrixClick[fil][col]=cual;
  }
//---------------------------------------------------------------

void
WinMine::acabarJuego()
  {
    juegoVigente=false;
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            if(matrixClick[i][j]==0)
              {
                matrixClick[i][j]=1;
              }
          }
      }
  }
//---------------------------------------------------------------
void
WinMine::reiniciarMatrix(const int &filNo, const int &colNo)
  {
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            matrix[i][j]=-2;
            matrixClick[i][j]=false;
          }
      }
    randomize();
    int nFil,nCol;
    int numMines;
    numMines=numMinas;
    while(numMines>0)
      {
        nFil=random(numFils);
        nCol=random(numCols);
        if(matrix[nFil][nCol]!=-1&&nFil!=filNo &&nCol!=colNo)
          {
            matrix[nFil][nCol]=-1;
            numMines--;
          }
      }
    int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
    int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
    int filFin,colFin;
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            if(matrix[i][j]!=-1)
              {
                numMines=0;
                for(int vecino=0;vecino<8;vecino++)
                  {
                    filFin=i+deltaFil[vecino];
                    colFin=j+deltaCol[vecino];
                    if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
                      {
                        if(matrix[filFin][colFin]==-1)
                          {
                            numMines++;
                          }
                      }
                  }
                matrix[i][j]=numMines;
              }
          }
      }
  }
//---------------------------------------------------------------
void
WinMine::setNivel(const int &nivel)
  {
    level=nivel;
  }
//---------------------------------------------------------------

void
WinMine::setAtributos(const int &nFils,const int &nCols,const int &nMinas,const int m[][MAXCOLS]
                     ,const int mClick[][MAXCOLS],const int &nTime,const int &nMinasFlag,const int &nLevel)
  {
    destruirMatrix();
    numFils=nFils;
    numCols=nCols;
    numMinas=nMinas;
    time=nTime;
    numMinasFlag=nMinasFlag;
    level=nLevel;
    matrix=new int*[numFils];
    matrixClick=new int*[numFils];
    for(int i=0;i<numFils;i++)
      {
        matrix[i]=new int[numCols];
        matrixClick[i]=new int[numCols];
      }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            matrix[i][j]=m[i][j];
            matrixClick[i][j]=mClick[i][j];
          }
      }
    yaSeCreo=true;
    juegoVigente=true;
  }

//-------------Analizadores-----------

int**
WinMine::getInfoMatrix(bool &creo, int &fils,int &cols, int &numMines )
  {
    creo=yaSeCreo;
    fils=numFils;
    cols=numCols;
    numMines=numMinas;
    return matrix;
  }
//---------------------------------------------------------------

int**
WinMine::getInfoMatrixClick()
  {
    return matrixClick;
  }
//---------------------------------------------------------------

int
WinMine::getTime()
  {
    return time;
  }
//---------------------------------------------------------------

bool
WinMine::getVegenciaJuego()
  {
    return juegoVigente;
  }
//---------------------------------------------------------------

int
WinMine::getMinesFlag()
  {
    return numMinasFlag;
  }
//---------------------------------------------------------------

int
WinMine::getNivel()
  {
    return level;
  } 
//---------------------------------------------------------------
#pragma package(smart_init)

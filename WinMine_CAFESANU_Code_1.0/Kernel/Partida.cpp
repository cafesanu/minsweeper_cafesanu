//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Partida.h"
//------------------------------------------------Constructor----------------
Partida::Partida()
  {
    for(int i=0;i<MAXLETRAS;i++)
      {
        estadoJuego[i]='\0'; 
      }
  }

//------------------------------------------------Destructor----------------
Partida::~Partida()
  {
  }

//------------------------------------------------Modificadores----------------

void
Partida::setAtributos(const string &strEstadoJuego,const int &nFils,const int &nCols,const int &nMinas,const int m[][MAXCOLS]
                     ,const int mClick[][MAXCOLS],const int &nTime,const int &nMinasFlag,const int &nLevel)
  {
    numFils=nFils;
    numCols=nCols;
    numMinas=nMinas;
    for (unsigned int i=0;i<strEstadoJuego.size();i++)
      {
        estadoJuego[i]=strEstadoJuego[i];
      }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            matrix[i][j]=m[i][j];
          }
      }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            matrixClick[i][j]=mClick[i][j];
          }
      }
    time=nTime;
    numMinasFlag=nMinasFlag;
    level=nLevel;

  }

//------------------------------------------------Analizadores----------------

void
Partida::getAtributos(string &strEstadoJuego,int &nFils,int &nCols,int &nMinas,int &nTime,int &nMinasFlag,int &nLevel)
  {
    strEstadoJuego=estadoJuego;
    nFils=numFils;
    nCols=numCols;
    nMinas=numMinas;
    nTime=time;
    nMinasFlag=numMinasFlag;
    nLevel=level;
  }
//---------------------------------------------------------------

int
Partida::getValorMatrix(const int &nFils,const int &nCols)
  {
    return matrix[nFils][nCols];
  }
//---------------------------------------------------------------

int
Partida::getValorMatrixClick(const int &nFils,const int &nCols)
  {
    return matrixClick[nFils][nCols];
  }


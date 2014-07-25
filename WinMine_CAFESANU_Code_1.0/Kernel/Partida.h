//---------------------------------------------------------------------------

#ifndef PartidaH
#define PartidaH
//Librerias Estandar
#include <string.h>
#include <iostream.h>

#define MAXFILS 77
#define MAXCOLS 111
#define MAXLETRAS 9
//---------------------------------------------------------------------------
class Partida
{
  private:
    char estadoJuego[MAXLETRAS];
    int numFils;
    int numCols;
    int numMinas;
    int matrix[MAXFILS][MAXCOLS];
    int matrixClick[MAXFILS][MAXCOLS];
    int time;
    int numMinasFlag;
    int level;
  public:
    //Constuctor
    Partida();

    //Destructor
    ~Partida();

    //Modificadores
    void setAtributos(const string &strEstadoJuego,const int &nFils,const int &nCols,const int &nMinas,const int m[][MAXCOLS]
                     ,const int mClick[][MAXCOLS],const int &nTime,const int &nMinasFlag,const int &nLevel);
    // **********************************************************************
    // * Descripcion: Cambia los atributos de Partida..
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              string           strEstadoJuego          Como se encuentra el juego en el momento(perdio, gano o pendiente)
    // *              int              nFils                   Numero de filas del juego
    // *              int              nCols                   Número de columnas del juego
    // *              int              nMinas                  Número de minas del juego
    // *              int              m[][MAXCOLS]            Reparticion del campo de juego
    // *              int              mClick[][MAXCOLS]       Estado visual del juego
    // *              int              nTime                   Tiempo de l apartida
    // *              int              nMinasFlag              Numero de minas sin destapar
    // *              int              nLevel                  Nivel del juego
    // * Pre        : True
    // * Post       : En los atributos del juego quedaron los parametros del metodo.
    // **********************************************************************


    //Analizadores
    void getAtributos(string &strEstadoJuego,int &nFils,int &nCols,int &nMinas,int &nTime,int &nMinasFlag,int &nLevel);
    // **********************************************************************
    // * Descripcion: Da los atributos de la partida.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              string           strEstadoJuego          Como se encuentra el juego en el momento(perdio, gano o pendiente)
    // *              int              nFils                   Numero de filas del juego
    // *              int              nCols                   Número de columnas del juego
    // *              int              nMinas                  Número de minas del juego
    // *              int              nTime                   Tiempo de l apartida
    // *              int              nMinasFlag              Numero de minas sin destapar
    // *              int              nLevel                  Nivel del juego
    // * Pre        : True
    // * Post       : En los parametros quedaron los respectivos atributos de partida.
    // **********************************************************************

    int getValorMatrix(const int &nFils,const int &nCols);
    // **********************************************************************
    // * Descripcion: Da la reparticion del campo de juego.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nFils                   Numero de filas del juego
    // *              int              nCols                   Número de columnas del juego
    // * Pre        : True
    // * Post       : Retornó la reparticion del campo de juego.
    // **********************************************************************


    int getValorMatrixClick(const int &nFils,const int &nCols);
    // **********************************************************************
    // * Descripcion: Da el estado visual del juego
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nFils                   Numero de filas del juego
    // *              int              nCols                   Número de columnas del juego
    // * Pre        : True
    // * Post       : Retornó el estado visual del juego.
    // **********************************************************************

};
#endif

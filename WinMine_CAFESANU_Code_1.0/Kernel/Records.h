//---------------------------------------------------------------------------

#ifndef RecordsH
#define RecordsH
//Librerias Estandar
#include <string.h>
#include <iomanip.h>
#include <iostream.h>
#include <fstream.h>
//---------------------------------------------------------------------------
class Records
{
  private:
    char nick[21][10][30];
    int time[21][10];
  public:
    //Constructor
    Records();
    //Destructor
    ~Records();

    //---------Analizadores
    string getNick(const int &nivel, const int &posTime);
    // **********************************************************************
    // * Descripcion: Retorna el nick que tiene el tiempo Nº posTime en el nivel nivel.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nivel                   Nivel a averiguar nick
    // *              int              posTime                 Posición a averigura nick en el nivle nivel.
    // * Pre        : true.
    // * Post       : retorno el nick que tiene el tiempo Nº posTime en el nivel nivel.
    // *************************************************************************

    int getTime(const int &nivel, const int &posTime);
    // **********************************************************************
    // * Descripcion: Retorna el tiempo que  se tiene el Nº posTime del nivel nivel.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nivel                   Nivel a averiguar tiempo
    // *              int              posTime                 Posición a averiguar tiempo en el nivel nivel.
    // * Pre        : true.
    // * Post       : retorno el tiempo que tiene el Nº posTime en el nivel nivel.
    // *************************************************************************

    //---------Modificadores

    void setNick(const int &nivel, const int &posTime,const string &nNick);
    // **********************************************************************
    // * Descripcion: Cambia el nick que tiene el tiempo Nº posTime en el nivel nivel.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nivel                   Nivel a cambia nick
    // *              int              posTime                 Posición a cambiar nick en el nivel nivel
    // *              string           nNick                   nuevo Nick.
    // * Pre        : true.
    // * Post       : Cambio el nick que tiene el tiempo Nº posTime en el nivel nivel.
    // *************************************************************************

    void setTime(const int &nivel, const int &posTime,const int &nTime);
    // **********************************************************************
    // * Descripcion: Cambia el tiempo que tiene el Nº posTime en el nivel nivel.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              nivel                   Nivel a cambia tiempi
    // *              int              posTime                 Posición a cambiar tiempo en el nivel nivel
    // *              int              nTime                   nuevo Tiempo.
    // * Pre        : true.
    // * Post       : Cambio el tiempo que tiene el Nº posTime en el nivel nivel.
    // *************************************************************************

};
#endif

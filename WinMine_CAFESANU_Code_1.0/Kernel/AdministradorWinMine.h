//---------------------------------------------------------------------------

#ifndef AdministradorWinMineH
#define AdministradorWinMineH
//Clase Kernel
#include "WinMine.h"
#include "Records.h"
#include "Partida.h"
//---------------------------------------------------------------------------

enum CodRes{
             NUM_MAL_MENOS,
             NUM_MAL_MAS,
             NUM_VACIO,
             FILE_INVALIDO,
             FILE_CORRUPTO,
             FILE_VACIO,
             NO_SUPERADO,
             SUPERADO,
             FILE_CANCELAR,
             FILE_GANO,
             FILE_PERDIO,
             SRV_EXITO
           };

class AdministradorWinMine
{
  private:
    WinMine *wm;

    //--------------METODOS PRIVADOS
    void expand(const int &fil, const int &col,const int &numFils, const int &numCols,int **matrix,int ** matrixClick);
    // **********************************************************************
    // * Descripcion: Randomiza la matriz de manera que queden las minas rapartidas por el campo de juego.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              fil                     fila a destapar su alrededor
    // *              int              col                     columna a destapar su alrededor
    // *              int              numFils                 Numero de filas del juego
    // *              int              numCols                 numero de columnas del juego
    // *              int              **matrix                reparticion de la matriz de juego.
    // *              int              **matrixClick           visualizacion de la matriz de juego.
    // * Pre        : matrix[fil][col] es igual a 0.
    // * Post       : Las posiciones matrix[x][y] de alrededor de matrix[fil][col] que son iguales a 0 se destaparon
    // **********************************************************************

  public:
  //----------   Constructor

  AdministradorWinMine();

  //----------   Destructor
  ~AdministradorWinMine();

  //-------------------------------SERVICIOS--------------------
  //IMPORTANTE: PARA LA PROXIMA VERSION, LO PRIMERO QUE SE TIENE QUE HACER ES EL SERVICIO DESTAPAR CUADRO!!!!!
  //            PUES ESO LO ESTAN HACIENDO OTROS METODOS Y EN MOUSEUP ESTA HACIENDO COSAS NO PERTENECIENTES A LA INTERFAZ........
  //            SEGUNDO CAMBIARLE EL CodRes a los que no son servicios
  //----------------------------Analizadores

  CodRes srvDarInfoRecord(const int &nNivel,const int &posTime,string &nNick,int &nTime);
  // **********************************************************************
  // * Descripcion: Da la informacion del record Nº posTime en el nivel nNivel
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              nNivel                  nivel a dar la informacion.
  // *              int              posTime                 pasicion del nivel nNivel a dar la informacion.
  // *              string           nNick                   Nick a averiguar.
  // *              int              nTime                   tiempo del record a averiguar.
  // * Pre        : nNivel>0 && nNivel<=21, posTime>0 && posTime <=10
  // * Post       : Si no se pudo abrir o crear el archivo retorno FILE_INVALIDO.
  // *              De lo contrario en nNick quedo el nick a averiguar y en nTime quedo el tiempo a averiguar y retorno SRV_EXITO.
  // **********************************************************************
  //----------------------------Modificadores

  CodRes srvCrearJuego(const int &numFils, const int &numCols,const int &nivel);
  // **********************************************************************
  // * Descripcion: Crea una partida de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              numFils                 Numero de filas del nuevo juego
  // *              int              numCols                 Numero de columnas del nuevo juego
  // *              int              nivel                   nivel del nuevo juego
  // * Pre        : numFils>0 && NumFils<=77, numCols>0 && NumCols<=111
  // * Post       : Se creo el juego y retorno SRV_EXITO.
  // **********************************************************************

  CodRes srvReiniciarPuntuaciones();
  // **********************************************************************
  // * Descripcion: Reinicia el archivo de puntuaciones
  // * Pre        : true
  // * Post       : Si no se pudo abrir o crear el archivo retorno FILE_INVALIDO.
  // *              De lo contario se reinicio el archivo de puntuaciones y retorno SRV_EXITO.
  // **********************************************************************

  CodRes srvGuardarPartida(const string &estadoJuego,const string &filePartida);
  // **********************************************************************
  // * Descripcion: Crea una partida de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              string           estadoJuego             En que estado se encuentra el juego (pendiente, perdio o gano)
  // *              string           filePartida             Destino directorio de archivo
  // * Pre        : true
  // * Post       : Si filePartida no contiene datos retorno FILE_VACIO
  // *              Si el directorio destino de filepartida no se pudo abrir o crear retorno FILE_INVALIDO
  // *              De lo contario se guardo una partida con toda su informacion, incluyendo el estado estadoJuego. y retorno SRV_EXITO
  // **********************************************************************

  CodRes srvAbrirPartida(const string &fileOpenPartida);
  // **********************************************************************
  // * Descripcion: Crea una partida de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              string           fileOpenPartida         Destino directorio de archivo
  // * Pre        : true
  // * Post       : Si fileOpenPartida no contiene datos retorno FILE_VACIO
  // *              Si el directorio destino de filepartida no se pudo abrir o crear retorno FILE_INVALIDO
  // *              Si el archivo abierto tiene de estado de juego "gano", retorno FILE_GANO
  // *              Si el archivo abierto tiene de estado de juego "perdio", retorno FILE_PERDIO
  // *              Si el archivo abierto tiene de estado de juego alogo diferente a "perdio","gano" o "pendiente" retorno FILE_CORRUPTO
  // *              Si el archivo abierto tiene de numero de filas algo menor que 9 o mayor q MAXFILS retorno FILE_CORRUPTO
  // *              Si el archivo abierto tiene de numero de columnas algo menor que 9 o mayor q MAXCOLS retorno FILE_CORRUPTO
  // *              Si el archivo abierto tiene de nivel algo menor que 0 o mayor que 22 retorno FILE_CORRUPTO
  // *              Si el archivo abierto tiene de un numero de minas difernete que el que deberia tener el juego, retorno FILE_CORRUPTO.
  // *              Si el archivo abierto tiene el tuempo menor que 0 retorno FILE CORRUPTO.
  // *              Si el archivo abierto tiene en la matriz de juego alguna posicion menor que -1 o mayor que 8 retorno FILE_CORRUPTO.
  // *              Si el archivo abierto tiene en la matriz de visualizacion alguna posicion menor que 0 o mayor que 2 retorno FILE_CORRUPTO.
  // *              Si el archivo abierto tiene como numero de minas a descubrir un numero mayo q el número del juego retorno FILE_CORRUPTO.
  // *              Si el archivo abierto tiene como numero de cuadros con bandera un número mayor que el numero de cuadros del campo de juego, retorno FILE_CORRUPTO
  // *              Si el archivo abierto tiene un numero de minas a descubrir difernet que las que verdaderamente deberia tener, retorno FILE_CORRUPTO.
  // *              De lo contario se creo una partida con la informacion del archivo y retorno SRV_EXITO.
  // **********************************************************************


  //-----------------------------NO SERVICIOS-------------------
  //----------------------------Analizadores

  int** srvDarInfoMatrix(bool &yaSeCreo, int &fils,int &cols,int &numMines );
  // **********************************************************************
  // * Descripcion: retorna lo informacio de la matriz de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              bool             yaSecreo                Si o no se ha creado la matriz de juego
  // *              int              fils                    Numero de filas del juego
  // *              int              cols                    Numero de columnas del juego
  // *              int              numMines                numero de minas del juego
  // * Pre        : true
  // * Post       : se retorno la matriz de juego y en los parametros quedaron el tamaño de esta y si ya se habia creado, respectivamente.
  // **********************************************************************

  int** srvDarInfoMatrixClick();
  // **********************************************************************
  // * Descripcion: retorna lo informacio de la matriz de juego
  // * Pre        : true
  // * Post       : se retorno la matriz de visualizacion.
  // **********************************************************************

  bool getVegenciaJuego();
  // **********************************************************************
  // * Descripcion: retorna si el juego esta vigente
  // * Pre        : true
  // * Post       : Si el juego esta vigente retorno true, de lo contrario retorno false.
  // **********************************************************************

  int getTime();
  // **********************************************************************
  // * Descripcion: retorna el tiempo de juego.
  // * Pre        : true
  // * Post       : retorno el tiempo que lleva el juego.
  // **********************************************************************

  int getNivel();
  // **********************************************************************
  // * Descripcion: Retorna el nivel del juego
  // * Pre        : true
  // * Post       : Retornó el nivel del juego
  // **********************************************************************

  int getMinesFlag();
  // **********************************************************************
  // * Descripcion: Retorna el numero de minas a descubrir
  // * Pre        : true
  // * Post       : Retornó el numero de minas a descubrir
  // **********************************************************************

  CodRes verificarTamano(const string &strFils,const string &strCols);
  // **********************************************************************
  // * Descripcion: Verifica que el tamaño a cambiar de la matriz de juego sea correcto
  // * Pre        : true
  // * Post       : Si strFils o strCols esta vacia, retorno NUM_VACIO
  // *              Si algun caracter de strFils o strCols no es un numero retorno NUM_MAL_MENOS
  // *              si strFils o strCols es menor que el minimo tamaño de juego retoró NUM_MAL_MENOS
  // *              si strFils o strCols es mayor que el maximo tamaño de juego retoró NUM_MAL_MAS
  // *              De lo contrario retorno SRV_EXITO
  // **********************************************************************

  string srvVerificarJuego();
  // **********************************************************************
  // * Descripcion: Verifica en que estado esta el juego
  // * Pre        : true
  // * Post       : Si el juego no a terminado retorno "pendiente"
  // *              si el juego ya perdio retorno "perido"
  // *              Si el juego ya se ganó retorno "gano"
  // **********************************************************************

  CodRes srvVerificarRecord(const int &nTime,const int &nNivel);
  // **********************************************************************
  // * Descripcion: verifica si con el tiempo nTiem se supero record en en nivel nNivel
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              nTime                   Tiempo a verificar record en el nivel nNivel
  // *              int              nNivel                  nivel en el que se quiere verificar el record
  // * Pre        : true
  // * Post       : Si el archivo de records no se pudo abrir, retorna FILE_INVALIDO
  // *              Si no se supero record retornó NO_SUPERADO
  // *              De lo contrario se retornó SUPERADO
  // **********************************************************************

  //----------------------------Modificadores

  void srvCambiarEstadoMatrixClick(const int &fil, const int &col, const int &cual);
  // **********************************************************************
  // * Descripcion: Cambia el estado de la posicion (fil,col) en la matriz de visualización  a cual
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              fil                     Posicion en fila a cambiar en matrixClick
  // *              int              col                     Posicion en columna a cambiar en matrixClick
  // *              int              cual                    Que estado se quiere para esa posicion.
  // * Pre        : fil y col estan dentro del campo de juego y cual es mayor que 0 y menor o igual a 4.
  // * Post       : en la posicion (fil,col) de la matriz de visualizacion quedo el valor de cual.
  // **********************************************************************

  void srvAcabarJuego();
  // **********************************************************************
  // * Descripcion: Acaba el juego haciendo que se muestren los cuador que faltan por destaparce
  // * Pre        : Existe el juego
  // * Post       : Los cuadro de la matriz de visualizacion que faltaban por destapar quedaron destapados.
  // **********************************************************************

  CodRes cargarRecords();
  // **********************************************************************
  // * Descripcion: crea el archivo de records en caso de que no exista
  // * Pre        : true
  // * Post       : Si no pudo abrir o crear el archivo de records retono FILE_INVALIDO
  // *              De lo contrario, si no existia el archivo, lo creo con los recrds en 0. Retorno SRV_EXITO
  // **********************************************************************

  CodRes activarRecord(const int &nTime,const int &nNivel, const string &nNick);
  // **********************************************************************
  // * Descripcion: Ingresa el record nTime en el nivel nNivel, con el nick nNick
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              nTime                   tiempo record
  // *              int              nNivel                  nivel en el que se hizo el record.
  // *              string           nNick                   nick con el que se hizo el record.
  // * Pre        : el tiempo nTime es un record del nivel nNivel
  // * Post       : Si no se pudo abrir o crear el archivo de records retono FILE_INVALIDO
  // *              se  reordenaron los recors del nivel nNivel, ingresando el tiempo nTime
  // **********************************************************************

  void srvReiniciarMatrix(const int &filNo, const int &colNo);
  // **********************************************************************
  // * Descripcion: Reinicia la matriz de juego sin dejar mina en la posicion(filNo,colNo)
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              filNo                   posicion de la fila en la que no se debe poner mina
  // *              int              colNo                   posicion de la columna en la que no se debe poner mina
  // * Pre        : Ya existe un juego.
  // * Post       : Se reinicio el juego, y la posicion(filNo,colNo) de la matriz de juego quedo diferente de -1(mina).
  // *************************************************************************

  void setTime(const int &newTime);
  // **********************************************************************
  // * Descripcion: cambia el tiempo de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              newTime                 nuevo Tiempo del juego
  // * Pre        : Ya existe un juego.
  // * Post       : el tiempo de juego quedo igual a newTime.
  // *************************************************************************

  void setnivel(const int &nivel);
  // **********************************************************************
  // * Descripcion: Cambia el nivel del juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              nivel                   nuevo nivel de juego
  // * Pre        : Ya existe un juego.
  // * Post       : el nivel de juego quedo igual a nivel.
  // *************************************************************************

  void setMinesFlag(const int &minesFlag);
  // **********************************************************************
  // * Descripcion: Cambia las minas a descubrir del juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              minesFlag               numero de minas a descubrir en el juego.
  // * Pre        : Ya existe un juego.
  // * Post       : el numero de minas a descubrir del juego quedo igual a minesFlag.
  // *************************************************************************

  void srvAumentarDisminuirMinesFlag(const int &minesFlag);
  // **********************************************************************
  // * Descripcion: aumenta o disminuye, en 1 el número de minas a descubrir en el juego.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              minesFlag               numero a aumentar o disminuir minas.
  // * Pre        : Ya existe el juego.
  // * Post       : Si minesFlag es igual a 1, se aumenta en uno el numero de minas a descubrir.
  // *              Si minesFlag es igual a -1, se disminuye en uno el numero de minas a descubrir.
  // **********************************************************************

  void srvExpand(const int &fil, const int &col);
  // **********************************************************************
  // * Descripcion: expande una seccion del juego, a partir de la posicion (fil,col) hasta que alrededor de esta seccion no  haya cuadros vacios.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              fil                     fila desde que se empieza a expander
  // *              int              col                     columna desde la que se empieza a expander
  // * Pre        : fil y col son cuadros vacios.
  // * Post       : se expandio la seccion del juego.
  // *************************************************************************





};

#endif

//---------------------------------------------------------------------------

#ifndef WinMineH
#define WinMineH
//Librerias Estandar
#include <string.h>
#include <iostream.h>

#define MAXFILS 77
#define MAXCOLS 111
//---------------------------------------------------------------------------

class WinMine
{
  private:
    //Atributos
    bool yaSeCreo;      //si se ha creado el juego o no.
    int numFils;        //Número de filas del campo de juego
    int numCols;        //Numero de columnas del campo de juego
    int numMinas;       //Numero de minas del campo de juego
    int **matrix;       //----MATRIZ DE JUEGO------
                        //Si matrix[x][y]==-1 ahí hay mina
                        //Si matrix[x][y]== 0 no tiene minas alrededor y no es una mina
                        //Si matrix[x][y]== 1 significa que tiene una mina alrededor.
                        //Si matrix[x][y]== 2 significa que tiene dos minas alrededor.
                        //Si matrix[x][y]== 3 significa que tiene tres minas alrededor.
                        //Si matrix[x][y]== 4 significa que tiene cuatro minas alrededor.
                        //Si matrix[x][y]== 5 significa que tiene cinco minas alrededor.
                        //Si matrix[x][y]== 6 significa que tiene seis minas alrededor.
                        //Si matrix[x][y]== 7 significa que tiene siete minas alrededor.
                        //Si matrix[x][y]== 8 significa que tiene ocho minas alrededor.

    int **matrixClick;  //----MATRIZ DE VISUALIZACION------
                        //Si matrixClick[x][y]==0 visualmente significa que esta tapado el cuadro
                        //Si matrixClick[x][y]==1 visualmente significa que esta destapado el cuadro
                        //Si matrixClick[x][y]==2 visualmente significa que esta con bandera el cuadro
                        //Si matrixClick[x][y]==3 visualmente significa que esta con mina tachada el cuadro
                        //Si matrixClick[x][y]==4 visualmente significa que esta con mina rodeada de rojo el cuadro

    bool juegoVigente;  //si el juego ya se acabo o no.
    int time;           //Tiempo que lleva el juego.
    int numMinasFlag;   //numero de minas a descubrir del campo de juego.
    int level;          //nivel del juego.

    //Metodos Privados
    void destruirMatrix();
    // **********************************************************************
    // * Descripcion: Destruye la matríz de juego.
    // * Pre        : Existe la matríz de juego
    // * Post       : Se destruyo la matríz.
    // **********************************************************************
    
    void randomizarMatrix(const int &fils, const int &cols, const int &nivel);
    // **********************************************************************
    // * Descripcion: Randomiza la matriz de manera que queden las minas rapartidas por el campo de juego.
    // * Parametros : Tipo             Nombre                  Descripcion
    // *              int              fils                    Numero de filas del juego
    // *              int              cols                    Número de columnas del juego
    // *              int              nivel                   Nivel del juego.
    // *                                                       Si es personalizado el nivel es 0,
    // *                                                       Si es pantalla completa el nivel es 22.
    // * Pre        : True
    // * Post       : Se randomizo las minas por todo el campo de juego y quedaron los numeros adyacentes a las minas.
    // **********************************************************************

  public:
  //----------   Constructor

  WinMine();

  //----------   Destructor
  ~WinMine();
  
 
  //----- Modificadores
  void cambiarSize(const int &numFils, const int &numCols, const int &nivel);
  // **********************************************************************
  // * Descripcion: Cambia el tamaño de la matriz y la deja lista para el juego.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              numFils                 Numero de filas del nuevo juego
  // *              int              numCols                 Número de columnas del nuevo juego
  // *              int              nivel                   Nivel del nuevo juego
  // * Pre        : Ya existe una matríz.
  // * Post       : Se cambio el tamaño de juego y se randomizo el juego.
  // **********************************************************************

  void setTime(const int &newTime);
  // **********************************************************************
  // * Descripcion: Cambia el tamaño de la matriz y la deja lista para el juego.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              newTime                 nuevo tiempo del juego
  // * Pre        : Ya existe el juego.
  // * Post       : Se cambio el tiempo del juego.
  // **********************************************************************

  void aumentarDisminuirMinesFlag(const int &minesFlag);
  // **********************************************************************
  // * Descripcion: aumenta o disminuye, en 1 el número de minas a descubrir en el juego.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              minesFlag               numero a aumentar o disminuir minas.
  // * Pre        : Ya existe el juego.
  // * Post       : Si minesFlag es igual a 1, se aumenta en uno el numero de minas a descubrir.
  // *              Si minesFlag es igual a -1, se disminuye en uno el numero de minas a descubrir.
  // **********************************************************************

  void setMinesFlag(const int &minesFlag);
  // **********************************************************************
  // * Descripcion: Cambia el número de minas a descubir en el juego, por minesFlag
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              minesFlag               nuevo numero de minas a descubrir en el juego.
  // * Pre        : Ya existe el juego.
  // * Post       : Se cambio el número de minas adescubir en el juego, a minesFlag.
  // **********************************************************************

  void cambiarEstadoMatrixClick(const int &fil, const int &col, const int &cual);
  // **********************************************************************
  // * Descripcion: Cambia matrixClick[fil][col] del juego por cual.
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              fil                     Posicion en fila a cambiar en matrixClick
  // *              int              col                     Posicion en columna a cambiar en matrixClick
  // *              int              cual                    Que estado se quiere para esa posicion.
  // * Pre        : Ya existe el juego.
  // * Post       : Si cual es igual a 0, se cambio matrixClick[fil][col] a 0.
  // *              Si cual es igual a 1, se cambio matrixClick[fil][col] a 1.
  // *              Si cual es igual a 2, se cambio matrixClick[fil][col] a 2.
  // *              Si cual es igual a 3, se cambio matrixClick[fil][col] a 3.
  // *              Si cual es igual a 4, se cambio matrixClick[fil][col] a 4.
  // *************************************************************************

  void acabarJuego();
  // **********************************************************************
  // * Descripcion: Acaba el juego.
  // * Pre        : Existe un juego sin acabar.
  // * Post       : Acaba la vigencia del juego y destapa todo el campo de juego.
  // *************************************************************************

  void reiniciarMatrix(const int &filNo, const int &colNo);
  // **********************************************************************
  // * Descripcion: Reinicia el juego sin dejar mina en la posicion(filNo,colNo)
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              filNo                   posicion de la fila en laque no se debe poner mina
  // *              int              colNo                   posicion de la columna la en que no se debe poner mina
  // * Pre        : Ya existe un juego.
  // * Post       : Se reinicio el juego, y matrix[filNo][colNo] quedo diferente de -1(mina).
  // *************************************************************************

  void setNivel(const int &nivel);
  // **********************************************************************
  // * Descripcion: Cambia el nivel del juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              int              nivel                   nuevo nivel del juego
  // * Pre        : Ya existe el juego.
  // * Post       : Nuevo nivel del juego igual a nivel.
  // *************************************************************************


  void setAtributos(const int &nFils,const int &nCols,const int &nMinas,const int m[][MAXCOLS]
                     ,const int mClick[][MAXCOLS],const int &nTime,const int &nMinasFlag,const int &nLevel);
  // **********************************************************************
  // * Descripcion: Cambia los atributos del juego.
  // * Parametros : Tipo             Nombre                  Descripcion
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

  //------------------ Analizadores
  int** getInfoMatrix(bool &creo, int &fils,int &cols, int &numMines );
  // **********************************************************************
  // * Descripcion: Retorna el estado de juego
  // * Parametros : Tipo             Nombre                  Descripcion
  // *              bool             creo                    Se se creo el juego o no.
  // *              int              fils                    Numero de filas del juego.
  // *              int              cols                    Numero de columnas del juego.
  // *              int              numMines                Numero de minas del juego.
  // * Pre        : Ya existe el juego.
  // * Post       : retorno matrix[][] y en los parametros quedaron los respectivos atributos
  // *************************************************************************

  int** getInfoMatrixClick();
  // **********************************************************************
  // * Descripcion: Retorna el estado visual del juego
  // * Pre        : Ya existe el juego.
  // * Post       : retorno matrixClick[][],que significa el estado visual del juego.
  // *************************************************************************

  int getTime();
  // **********************************************************************
  // * Descripcion: Retorna el tiempo de la partida de juego
  // * Pre        : Ya existe el juego.
  // * Post       : Retornó el tiempo de la partida de juego
  // *************************************************************************

  bool getVegenciaJuego();
  // **********************************************************************
  // * Descripcion: Retorna la vigencia de la partida de juego
  // * Pre        : Ya existe el juego.
  // * Post       : Retornó la vigencia de la partida de juego
  // *************************************************************************

  int getMinesFlag();
  // **********************************************************************
  // * Descripcion: Retorna el numero de minas a descubrirde la partida de juego
  // * Pre        : Ya existe el juego.
  // * Post       : Retornó el numero de minas a descubrirde la partida de juego
  // *************************************************************************
  
  int getNivel();
  // **********************************************************************
  // * Descripcion: Retorna el nivel de la partida de juego
  // * Pre        : Ya existe el juego.
  // * Post       : Retornó el nivel de la partida de juego
  // *************************************************************************

};

#endif

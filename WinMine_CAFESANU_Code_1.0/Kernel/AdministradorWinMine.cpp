//---------------------------------------------------------------------------

#include <vcl.h>                   
#pragma hdrstop

#include "AdministradorWinMine.h"

//---------------------------------------------------------------------------

//---------- Constructor                          


AdministradorWinMine::AdministradorWinMine()
  {
    wm=new WinMine();

  }

//---------- Destructor
AdministradorWinMine::~AdministradorWinMine()
  {
  }

//-------------------------------SERVICIOS--------------------
  //IMPORTANTE: PARA LA PROXIMA VERSION, LO PRIMERO QUE SE TIENE QUE HACER ES EL SERVICIO DESTAPAR CUADRO!!!!!
  //            PUES ESO LO ESTAN HACIENDO OTROS METODOS Y EN MOUSEUP ESTA HACIENDO COSAS NO PERTENECIENTES A LA INTERFAZ........
  //            SEGUNDO CAMBIARLE EL CodRes a los que no son servicios
  //----------------------------Analizadores

CodRes
AdministradorWinMine::srvDarInfoRecord(const int &nNivel,const int &posTime,string &nNick,int &nTime)
  {
     AnsiString rutaArchivo=ExtractFilePath(Application->ExeName)+ "Datos\\reg.wmcr";
     string strRutaArchivo =string(rutaArchivo.c_str());
     fstream fileReg( strRutaArchivo.c_str(), ios::in | ios::out| ios::binary );
     if(!fileReg)
       {
         return FILE_INVALIDO;
       }
     Records r;
     fileReg.read( (char *)&r, sizeof(Records));
     nNick=r.getNick(nNivel,posTime);
     nTime=r.getTime(nNivel,posTime);
     fileReg.close();
     return SRV_EXITO;
  }
//----------------------------Modificadores

CodRes
AdministradorWinMine::srvCrearJuego(const int &numFils, const int &numCols,const int &nivel)
  {
    wm->cambiarSize(numFils,numCols,nivel);
    return SRV_EXITO;
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::srvReiniciarPuntuaciones()
  {
    AnsiString rutaArchivo=ExtractFilePath(Application->ExeName)+ "Datos\\reg.wmcr";
    string strRutaArchivo =string(rutaArchivo.c_str());
    fstream fileReg( strRutaArchivo.c_str(), ios::in | ios::out| ios::binary );
    if(!fileReg)
      {
        return FILE_INVALIDO;
      }
    Records r;
    fileReg.write( (const char * )&r,sizeof(Records));
    fileReg.close();
    return SRV_EXITO;
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::srvGuardarPartida(const string &estadoJuego,const string &filePartida)
  {
    if(filePartida=="")
      {
        return FILE_VACIO;
      }
    fstream fileSave(filePartida.c_str(),  ios::out| ios::binary );
    if(!fileSave)
      {
        return FILE_INVALIDO;
      }
    bool yaSeCreo;
    int m[MAXFILS][MAXCOLS];
    int mClick[MAXFILS][MAXCOLS];
    int numFils; //
    int numCols; //
    int numMinas; //
    int **matrix; //
    int **matrixClick; //
    int time;   //
    int numMinasFlag;   //
    int nivel;      //
    matrix=srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMinas);
    matrixClick=srvDarInfoMatrixClick();
    time=wm->getTime();
    numMinasFlag=wm->getMinesFlag();
    nivel=wm->getNivel();
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            m[i][j]=matrix[i][j];
            mClick[i][j]=matrixClick[i][j];
          }
      }
    Partida p;
    p.setAtributos(estadoJuego,numFils,numCols,numMinas,m,mClick,time,numMinasFlag,nivel);
    string strEstadoJuego;
    p.getAtributos(strEstadoJuego,numFils,numCols,numMinas,time,numMinasFlag,nivel);
    fileSave.seekp(0);
    fileSave.write( (const char * )&p,sizeof(Partida));
    fileSave.close();
    return SRV_EXITO;
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::srvAbrirPartida(const string &fileOpenPartida)
  {
    if(fileOpenPartida=="")
      {
        return FILE_CANCELAR;
      }
    fstream fileOpen(fileOpenPartida.c_str(), ios::in | ios::binary );
    if(!fileOpen)
      {
        return FILE_INVALIDO;
      }
    string strEstadoJuego;
    int minasTemp;
    int m[MAXFILS][MAXCOLS];
    int mClick[MAXFILS][MAXCOLS];
    int **matrix;
    int **matrixClick;
    int numFils;//
    int numCols;//
    int numMinas;//
    int time;    //
    int numMinasFlag,numMinasFlagTemp;//
    int nivel;       //
    Partida p;
    fileOpen.read( (char *)&p, sizeof(Partida));
    p.getAtributos(strEstadoJuego,numFils,numCols,numMinas,time,numMinasFlag,nivel);
    if(strEstadoJuego=="gano")
      {
        return FILE_GANO;
      }
    else if(strEstadoJuego=="perdio")
      {
        return FILE_PERDIO;
      }
    else if(strEstadoJuego!="pendiente")
      {
        return FILE_CORRUPTO;
      }
    if(numFils<9 ||numFils>MAXFILS)
      {
        return FILE_CORRUPTO;
      }
    if(numCols<9 ||numCols>MAXCOLS)
      {
        return FILE_CORRUPTO;
      }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            m[i][j]=p.getValorMatrix(i,j);
            mClick[i][j]=p.getValorMatrixClick(i,j);
          }
      }
    if(nivel<0 || nivel>22)
      {
        return FILE_CORRUPTO;
      }
    switch(nivel)
      {
        case 0:
        if(numFils==9 && numCols ==9)
          {
            minasTemp=10;
          }
        else if(numFils==16 && numCols ==16)
          {
            minasTemp=40;
          }
        else if(numFils==16 && numCols ==30)
          {
            minasTemp=99;
          }
        else
          {
            minasTemp=((numFils*numCols)*99)/480;
          }
          break;
        case 1:
          minasTemp=10;
          break;
        case 2:
          minasTemp=40;
          break;
        case 3:
          minasTemp=99;
          break;
        default:
          minasTemp=((numFils*numCols)*99)/480;
          break;
      };
    if(minasTemp!=numMinas)
      {
        return FILE_CORRUPTO;
      }
    numMinasFlagTemp=numMinas;
    if(time<0)
      {
        return FILE_CORRUPTO;
      }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            if(m[i][j]<-1 ||m[i][j]>8)
              {
                return FILE_CORRUPTO;
              }
            if(mClick[i][j]<0 ||mClick[i][j]>2)
              {
                return FILE_CORRUPTO;
              }
            if(mClick[i][j]==2)
              {
                numMinasFlagTemp--;
              }
          }
      }
    if(numMinasFlag>numMinas)
      {
        return FILE_CORRUPTO;
      }
    if(numMinasFlag<(numFils*numCols*-1))
      {
        return FILE_CORRUPTO;
      }
    if(numMinasFlag!=numMinasFlagTemp)
      {
        return FILE_CORRUPTO;
      }
    wm->setAtributos(numFils,numCols,numMinas,m,mClick,time,numMinasFlag,nivel);
    fileOpen.close();
    return SRV_EXITO;
  }

//-----------------------------NO SERVICIOS-------------------
  //----------------------------Analizadores
int**
AdministradorWinMine::srvDarInfoMatrix(bool &yaSeCreo, int &fils,int &cols, int &numMines )
  {
    return wm->getInfoMatrix(yaSeCreo,fils,cols,numMines);
  }
//---------------------------------------------------------------------------

int**
AdministradorWinMine::srvDarInfoMatrixClick()
  {
    return wm->getInfoMatrixClick();
  }
//---------------------------------------------------------------------------

bool
AdministradorWinMine::getVegenciaJuego()
  {
    return wm->getVegenciaJuego();
  }
//---------------------------------------------------------------------------

int
AdministradorWinMine::getTime()
  {
    return wm->getTime();
  }
//---------------------------------------------------------------------------

int
AdministradorWinMine::getNivel()
  {
    return wm->getNivel();
  }
//---------------------------------------------------------------------------

int
AdministradorWinMine::getMinesFlag()
  {
    return wm->getMinesFlag();
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::verificarTamano(const string &strFils,const string &strCols)
  {
    int nFils,nCols;
    sscanf(strFils.c_str(),"%d",&nFils);
    sscanf(strCols.c_str(),"%d",&nCols);
    if(strFils=="" ||strCols=="")
      {
        return NUM_VACIO;
      }
    for(unsigned int i=0;i<strFils.size();i++)
      {
        if( strFils[i]<'0' || strFils[i]>'9')
          {
            return NUM_MAL_MENOS;
          }
      }
    for(unsigned int i=0;i<strCols.size();i++)
      {
        if( strCols[i]<'0' || strCols[i]>'9')
          {
            return NUM_MAL_MENOS;
          }
      }
    if(nFils<9 || nCols<10)
      {
        return NUM_MAL_MENOS;
      }
    if(nFils>77 || nCols>111)
      {
        return NUM_MAL_MAS;
      }
    return SRV_EXITO;
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::srvVerificarRecord(const int &nTime,const int &nNivel)
  {
    int arrayTime[10];
    AnsiString rutaArchivo=ExtractFilePath(Application->ExeName)+ "Datos\\reg.wmcr";
    string strRutaArchivo =string(rutaArchivo.c_str());
    fstream fileReg( strRutaArchivo.c_str(), ios::in | ios::out| ios::binary );
    if(!fileReg)
      {
        return FILE_INVALIDO;
      }
    Records r;
    fileReg.read( (char *)&r, sizeof(Records));
    for( int i=0;i<10;i++)
      {
        arrayTime[i]=r.getTime(nNivel-1,i);
      }
    int posMayorNoMenos1=10;
    int i=9;
    bool hayMayor=false;;
    while(arrayTime[i]==-1)
      {
        i--;
        posMayorNoMenos1=i;
      }
    posMayorNoMenos1++;
    for(int i=0;i<10;i++)
       {
        if(arrayTime[i]>nTime)
          {
            hayMayor=true;
            i=10;
          }
       }
    if(posMayorNoMenos1>=10&& hayMayor==false)
      {
        if(nTime>=arrayTime[9])
          {
            return NO_SUPERADO;
          }
      }
    return SUPERADO;
  }
//---------------------------------------------------------------------------

string
AdministradorWinMine::srvVerificarJuego()
  {
    bool yaSeCreo;
    int numFils,numCols,numMines;
    int** matrix=srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
    int ** matrixClick=srvDarInfoMatrixClick();
    int numCeldasHideFlag=numFils*numCols;
    string retornar;
    for(int i=0;i<numFils;i++)
     {
       for(int j=0;j<numCols;j++)
         {
           if(matrixClick[i][j]==3 || matrixClick[i][j]==4)
             {
               retornar="perdio";
               return retornar;
             }
         }
     }
    for(int i=0;i<numFils;i++)
      {
        for(int j=0;j<numCols;j++)
          {
            if(matrixClick[i][j]==1)
              {
                numCeldasHideFlag--;
              }
          }
      }
    if(numCeldasHideFlag==numMines)
      {
        retornar= "gano";
        return retornar;
      }
    retornar="pendiente";
    return retornar;
  }

//----------------------------Modificadores

void
AdministradorWinMine::srvCambiarEstadoMatrixClick(const int &fil, const int &col, const int &cual)
  {
    wm->cambiarEstadoMatrixClick(fil,col,cual);
  }
//---------------------------------------------------------------------------

void
AdministradorWinMine::srvAcabarJuego()
  {
    wm->acabarJuego();
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::cargarRecords()
  {
    AnsiString rutaArchivo=ExtractFilePath(Application->ExeName)+ "Datos\\reg.wmcr";
    string strRutaArchivo =string(rutaArchivo.c_str());
    fstream fileReg( strRutaArchivo.c_str(), ios::in | ios::out| ios::binary );
    if(!fileReg)
      {
        return FILE_INVALIDO;
      }
    int pos;
    fileReg.seekp(0,ios::end);
    pos=fileReg.tellp();
    fileReg.seekg(0,ios::end);
    Records r;
    if(pos==0)
      {
        fileReg.seekg(0);
        fileReg.seekp(0);
        fileReg.write( (const char *)&r, sizeof(Records));
      }
    fileReg.close();
    return SRV_EXITO;
  }
//---------------------------------------------------------------------------

CodRes
AdministradorWinMine::activarRecord(const int &nTime,const int &nNivel, const string &nNick)
  {
    int arrayTime[10];
    string arrayNick[10];
    AnsiString rutaArchivo=ExtractFilePath(Application->ExeName)+ "Datos\\reg.wmcr";
    string strRutaArchivo =string(rutaArchivo.c_str());
    fstream fileReg( strRutaArchivo.c_str(), ios::in | ios::out| ios::binary );
    if(!fileReg)
      {
        return FILE_INVALIDO;
      }
    Records r;
    fileReg.read( (char *)&r, sizeof(Records));
    for( int i=0;i<10;i++)
      {
        arrayTime[i]=r.getTime(nNivel-1,i);
        arrayNick[i]= r.getNick(nNivel-1,i);
        arrayNick[i]=arrayNick[i].substr(0,30);
      }
    bool hayMenos1=false;
    int posMenos1;
    for( int i=0;i<10;i++)
      {
        if(arrayTime[i]==-1)
          {
            hayMenos1=true;
            arrayTime[i]=nTime;
            arrayNick[i]=nNick;
            posMenos1=i;
            i=10;
          }
      }
    if(hayMenos1)
      {
        for(int i=0;i<posMenos1;i++)
          {
            for(int j=0;j<posMenos1;j++)
              {
                if(arrayTime[j]>arrayTime[j+1])
                  {
                    int temp=arrayTime[j];
                    arrayTime[j]=arrayTime[j+1];
                    arrayTime[j+1]=temp;
                    string strTemp=arrayNick[j];
                    arrayNick[j]=arrayNick[j+1];
                    arrayNick[j+1]=strTemp;
                  }
              }
          }
      }
    else
      {
        arrayTime[9]=nTime;
        arrayNick[9]=nNick;
        for(int i=0;i<9;i++)
          {
            for(int j=0;j<9;j++)
              {
                if(arrayTime[j]>arrayTime[j+1])
                  {
                    int temp=arrayTime[j];
                    arrayTime[j]=arrayTime[j+1];
                    arrayTime[j+1]=temp;
                    string strTemp=arrayNick[j];
                    arrayNick[j]=arrayNick[j+1];
                    arrayNick[j+1]=strTemp;
                  }
              }
          }
      }
    for( int i=0;i<10;i++)
      {
        r.setTime(nNivel-1,i,arrayTime[i]);
        r.setNick(nNivel-1,i,arrayNick[i]);
      }
    fileReg.seekp(0);
    fileReg.write( (const char * )&r,sizeof(Records));
    fileReg.close();
    return SUPERADO;
  }
//---------------------------------------------------------------------------

void
AdministradorWinMine::srvReiniciarMatrix(const int &filNo, const int &colNo)
  {
    wm->reiniciarMatrix(filNo,colNo);
  } 
//---------------------------------------------------------------------------

void
AdministradorWinMine::setTime(const int &newTime)
  {
    wm->setTime(newTime);
  } 
//---------------------------------------------------------------------------

void
AdministradorWinMine::setnivel(const int &nivel)
  {
    wm->setNivel(nivel);
  } 
//---------------------------------------------------------------------------

void
AdministradorWinMine::setMinesFlag(const int &minesFlag)
  {
    wm->setMinesFlag(minesFlag);
  }
//---------------------------------------------------------------------------

void
AdministradorWinMine::srvAumentarDisminuirMinesFlag(const int &minesFlag)
  {
    wm->aumentarDisminuirMinesFlag(minesFlag);
  }
//---------------------------------------------------------------------------
  
void
AdministradorWinMine::srvExpand(const int &fil, const int &col)
  {
    bool yaSeCreo;
    int numFils,numCols,numMines;
    int** matrixClick=srvDarInfoMatrixClick();
    int** matrix=srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
    expand(fil,col,numFils,numCols,matrix,matrixClick);
  }
//---------------------------------------------------------------------------

void
AdministradorWinMine::expand(const int &fil, const int &col,const int &numFils, const int &numCols,int **matrix,int ** matrixClick)
  {

    int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
    int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
    int filFin,colFin;
    for(int vecino=0;vecino<8;vecino++)
      {
        filFin=fil+deltaFil[vecino];
        colFin=col+deltaCol[vecino];
        if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
          {
            if(matrix[filFin][colFin]>0 && matrix[filFin][colFin]<=8 &&matrixClick[filFin][colFin]==0)
              {
                srvCambiarEstadoMatrixClick(filFin,colFin,1);
              }
            else if(matrix[filFin][colFin]==0 && matrixClick[filFin][colFin]==0)
              {
                srvCambiarEstadoMatrixClick(filFin,colFin,1);
                expand(filFin,colFin,numFils,numCols,matrix,matrixClick);
              }
          }
      }
  }
#pragma package(smart_init)

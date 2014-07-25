//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop                                            

#include "WinMineGUI.h"
//--------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormWinMine *FormWinMine;
//---------------------------------------------------------------------------
__fastcall TFormWinMine::TFormWinMine(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::FormCreate(TObject *Sender)
{
  f=new AdministradorWinMine();
  seHaHechoAlgo=true;
  fileNombrePartida="";
  f->cargarRecords();
  Timer1->Enabled = false; 
  Pausa1->Enabled=false;
  estaEnPausa = false;
  f->setTime(0);
  ratonClick=false;
  botonRightPress=false;
  botonLeftPress=false;
  primerClick=true;
  AnsiString temp;
  int aWidth=16*9;
  int aHeight= 16 * 9;
  ClientHeight = 40+aHeight;
  ClientWidth = aWidth;
  PanelManejo->Width=aWidth;
  SBImgSmiles->Left=PanelManejo->Width/2-13;
  imgMine1->Left=7;
  imgMine2->Left=20;
  imgMine3->Left=33;
  imgMine4->Left=46;
  imgTime4->Left=PanelManejo->Width-7-13;
  imgTime3->Left=PanelManejo->Width-7-26;
  imgTime2->Left=PanelManejo->Width-7-39;
  imgTime1->Left=PanelManejo->Width-7-52;
  mine=new Graphics::TBitmap*[9];
  for(int i=1;i<9;i++)
    {
      mine[i]= new Graphics::TBitmap();
      temp=ExtractFilePath(Application->ExeName)+ "images\\Mine"+i+".bmp";
      mine[i]->LoadFromFile(temp);
    }
  number=new Graphics::TBitmap*[10];
  for(int i=0;i<10;i++)
    {
      number[i]= new Graphics::TBitmap();
      temp=ExtractFilePath(Application->ExeName)+ "images\\"+i+".bmp";
      number[i]->LoadFromFile(temp);
    }
  mineHide= new Graphics::TBitmap();
  mineHide->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineHide.bmp");
  mineBombRed= new Graphics::TBitmap();
  mineBombRed->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineBombRed.bmp");
  mineBombBad= new Graphics::TBitmap();
  mineBombBad->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineBombBad.bmp");
  mineBomb= new Graphics::TBitmap();
  mineBomb->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineBomb.bmp");
  mineClick= new Graphics::TBitmap();
  mineClick->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineClick.bmp");
  mineFlag= new Graphics::TBitmap();
  mineFlag->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\MineFlag.bmp");
  smileHappy=new Graphics::TBitmap();
  smileHappy->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\SmileHappy.bmp");
  smileOh=new Graphics::TBitmap();
  smileOh->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\SmileOh.bmp");
  smileSad=new Graphics::TBitmap();
  smileSad->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\SmileSad.bmp");
  smileGlasses=new Graphics::TBitmap();
  smileGlasses->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\SmileGlasses.bmp");
  negative=new Graphics::TBitmap();
  negative->LoadFromFile(ExtractFilePath(Application->ExeName)+ "images\\Negative.bmp");
  SBImgSmiles->Glyph=smileHappy;
  Nivel11Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::FormPaint(TObject *Sender)
{
  int **matrix;
  int **matrixClick;
  bool yaSeCreo;
  bool estaVigenteElJuego=f->getVegenciaJuego();
  int numFils,numCols,numMines;
  matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
  int aHeight=16 * numFils;     //Ancho
  int aWidth= 16 * numCols;//alto
  ClientHeight = 40+aHeight;
  ClientWidth = aWidth;
  int numMinasFlag=f->getMinesFlag();
  ShowNumberMines(numMinasFlag);
  matrixClick=f->srvDarInfoMatrixClick();
  int numMine;
      if(yaSeCreo==false)
        {
          for(int fil=0;fil<9;fil++)
            {
              for(int col=0;col<9;col++)
                {
                  Canvas->Draw(col*16, 40+fil*16, mineHide);
                }
            }
        }
      else
        {
          randomize();
          for(int fil=0;fil<numFils;fil++)
            {
              for(int col=0;col<numCols;col++)
                {
                  if(estaEnPausa)
                    {
                      Canvas->Draw(col*16, 40+fil*16, mineClick);
                    }
                  else
                    {
                      numMine=matrix[fil][col];
                      switch(numMine)
                        {
                          case -1:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBomb);
                              }
                            else  if(matrixClick[fil][col]==2)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineFlag);
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 0:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineClick);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                     Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 1:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[1]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 2:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[2]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                 if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 3:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[3]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                               }
                            else
                              {
                                 Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 4:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[4]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                   {
                                     Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                   }
                                else
                                   {
                                     Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                   }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 5:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[5]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                 Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                 Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 6:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[6]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 7:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[7]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                          case 8:
                            if(matrixClick[fil][col]==1)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mine[8]);
                              }
                            else if(matrixClick[fil][col]==2)
                              {
                                if(!estaVigenteElJuego)
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                                  }
                                else
                                  {
                                    Canvas->Draw(col*16, 40+fil*16, mineFlag);
                                  }
                              }
                            else  if(matrixClick[fil][col]==3)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombBad);
                              }
                            else  if(matrixClick[fil][col]==4)
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineBombRed);
                              }
                            else
                              {
                                Canvas->Draw(col*16, 40+fil*16, mineHide);
                              }
                            break;
                         };
                    }
               }
            }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      bool yaSeCreo;
      int numFils,numCols,numMines;
      int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
      int** matrixClick=f->srvDarInfoMatrixClick();
      int fil,col;
      if(X<0 || X>ClientWidth)
        {
          col=-1;
        }
      else
        {
          col=((X/16)*16)/16;
        }
      if(Y>40 && Y<ClientHeight)
        {
          fil=(((Y-40)/16)*16)/16;
        }
      else
        {
          fil=-1;
        }
      if(ratonClick==true)
        {
          if(botonLeftPress==true && botonRightPress==true)
            {
              if (fil==-1 || col==-1)
                {
                  FormPaint(Owner);
                }
              else if(fil<posFil || fil>posFil || col<posCol || col>posCol)
                {
                  FormPaint(Owner);
                  int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
                  int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
                  int filFin,colFin;
                  if(matrixClick[fil][col]==0)
                    {
                      Canvas->Draw(col*16, 40+fil*16, mineClick);
                    }
                  for(int vecino=0;vecino<8;vecino++)
                    {
                      filFin=fil+deltaFil[vecino];
                      colFin=col+deltaCol[vecino];
                      if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols && matrixClick[filFin][colFin]==0)
                        {
                          Canvas->Draw(colFin*16, 40+filFin*16, mineClick);
                        }
                    }
                }
            }
          else
            {
              if(botonLeftPress==true)
                {
                  if (fil==-1 || col==-1)
                    {
                      FormPaint(Owner);
                    }
                  else if(fil<posFil || fil>posFil || col<posCol || col>posCol)
                    {
                      FormPaint(Owner);
                      if(matrixClick[fil][col]==0)
                        {
                          Canvas->Draw(col*16, 40+fil*16, mineClick);
                        }
                    }
                }
            }
        }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      if(Button==mbLeft)
        {
          SBImgSmiles->Glyph=smileOh;
        }
      bool yaSeCreo;
      int numFils,numCols,numMines;
      int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
      int ** matrixClick=f->srvDarInfoMatrixClick();
      int fil,col;
      if(X<0 || X>ClientWidth)
        {
          col=-1;
        }
      else
        {
          col=((X/16)*16)/16;
        }
      if(Y>40 && Y<ClientHeight)
       {
         fil=(((Y-40)/16)*16)/16;
       }
     else
       {
         fil=-1;
       }
     if(fil>=0 && fil<numFils && col>=0 && col<numCols &&matrixClick[fil][col]==0)
       {
         Canvas->Draw(col*16, 40+fil*16, mineClick);
       }
     ratonClick=true;
     posFil=fil;
     posCol=col;
     if(Button==mbLeft)
       {
         botonLeftPress=true;
       }
     else if(Button==mbRight)
       {
         botonRightPress=true;
       }
     if(botonLeftPress==true && botonRightPress==true)
       {
         int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
         int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
         int filFin,colFin;
         if(fil!=-1 && col!=-1)
           {
             if(matrixClick[fil][col]==0)
               {
                 Canvas->Draw(col*16, 40+fil*16, mineClick);
               }
           }
         for(int vecino=0;vecino<8;vecino++)
           {
             filFin=fil+deltaFil[vecino];
             colFin=col+deltaCol[vecino];
             if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols && matrixClick[filFin][colFin]==0 )
               {
                 Canvas->Draw(colFin*16, 40+filFin*16, mineClick);
               }
           }
       }
     else if(botonLeftPress==false && botonRightPress==true)
       {
         if(fil!=-1 && col!=-1 && matrixClick[fil][col]!=1)
           {
             if(matrixClick[fil][col]==1)
               {
               }
             else if(matrixClick[fil][col]==2)
               {
                 f->srvCambiarEstadoMatrixClick(fil,col,0);
                 Canvas->Draw(col*16, 40+fil*16, mineHide);
                 f->srvAumentarDisminuirMinesFlag(1);
               }
             else
               {
                 f->srvCambiarEstadoMatrixClick(fil,col,2);
                 Canvas->Draw(col*16, 40+fil*16, mineFlag);
                f->srvAumentarDisminuirMinesFlag(-1);
               }
             verificarJuego();
           }
       }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
       seHaHechoAlgo=true;
       bool yaSeCreo;
       int numFils,numCols,numMines;
       int** matrixClick=f->srvDarInfoMatrixClick();
       int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
       SBImgSmiles->Glyph=smileHappy;
       FormPaint(Owner);
       int fil,col;
       if(X<0 || X>ClientWidth)
         {
           col=-1;
         }
       else
         {
           col=((X/16)*16)/16;
         }
       if(Y>40 && Y<ClientHeight)
         {
           fil=(((Y-40)/16)*16)/16;
         }
       else
         {
           fil=-1;
         }
       if(fil>=0 && fil<numFils && col>=0 && col<numCols)
         {
           if(botonLeftPress==true && botonRightPress==false)
             {
               if(primerClick==true)
                 {
                   f->srvReiniciarMatrix(fil,col);
                   Guardar1->Enabled=true;
                   Guardarcomo1->Enabled=true;
                   Pausa1->Enabled=true;
                   primerClick=false;
                   Timer1->Enabled = true;
                 }
               matrixClick=f->srvDarInfoMatrixClick();
               matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
               if(matrixClick[fil][col]==0)
                 {
                   f->srvCambiarEstadoMatrixClick(fil,col,1);
                 }
               if(matrix[fil][col]==0 && Button==mbLeft)
                 {
                   f->srvExpand(fil,col);
                 }
               if(matrix[fil][col]==-1 && Button==mbLeft && matrixClick[fil][col]!=2)
                 {
                   f->srvCambiarEstadoMatrixClick(fil,col,4);
                   SBImgSmiles->Glyph=smileSad;
                   f->srvAcabarJuego();
                 }
               FormPaint(Owner);
             }
           else if(botonLeftPress==true && botonRightPress==true)
             {
               if(matrix[fil][col]>0 && matrix[fil][col]<=8 &&matrixClick[fil][col]==1)
                 {
                   int deltaFil[]={-1,-1,0,1,1, 1, 0,-1};
                   int deltaCol[]={ 0, 1,1,1,0,-1,-1,-1};
                   int filFin,colFin;
                   int numMines=matrix[fil][col];
                   int numMinesTotal=matrix[fil][col];
                   int nMines=0,nMinesTachadas=0;
                   for(int vecino=0;vecino<8;vecino++)
                     {
                       filFin=fil+deltaFil[vecino];
                       colFin=col+deltaCol[vecino];
                       if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
                         {
                           if(matrixClick[filFin][colFin]==2)
                             {
                               if(matrix[filFin][colFin]==-1)
                                 {
                                   numMines--;
                                 }
                               numMinesTotal--;
                               nMinesTachadas++;
                             }
                           if(matrix[filFin][colFin]==-1)
                             {
                               nMines++;
                             }
                         }
                     }
                   if(nMines>nMinesTachadas)
                     {
                     }
                   else if(numMines==0 && numMinesTotal==0)
                     {
                       for(int vecino=0;vecino<8;vecino++)
                        {
                          filFin=fil+deltaFil[vecino];
                          colFin=col+deltaCol[vecino];
                          if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
                            {
                              if(matrixClick[filFin][colFin]!=2)
                                {
                                  if(matrix[filFin][colFin]==0)
                                    {
                                      f->srvCambiarEstadoMatrixClick(filFin,colFin,1);
                                      f->srvExpand(filFin,colFin);
                                    }
                                  else
                                    {
                                      f->srvCambiarEstadoMatrixClick(filFin,colFin,1);
                                    }
                                }
                            }
                        }
                    }
                  else if(numMinesTotal<0)
                    {
                    }
                  else if(numMines>0 &&numMines!=numMinesTotal)
                    {
                      for(int vecino=0;vecino<8;vecino++)
                        {
                          filFin=fil+deltaFil[vecino];
                          colFin=col+deltaCol[vecino];
                          if(filFin>=0 && filFin<numFils && colFin>=0 && colFin<numCols)
                            {
                              if(matrixClick[filFin][colFin]==2 &&matrix[filFin][colFin]!=-1)
                                {
                                  Canvas->Draw(colFin*16, 40+filFin*16, mineBombBad);
                                  f->srvCambiarEstadoMatrixClick(filFin,colFin,3);
                                }
                              else if(matrixClick[filFin][colFin]==0 &&matrix[filFin][colFin]==-1)
                                {
                                  Canvas->Draw(colFin*16, 40+filFin*16, mineBombRed);
                                  f->srvCambiarEstadoMatrixClick(filFin,colFin,4);
                                }
                           }
                        }
                      f->srvAcabarJuego();
                      SBImgSmiles->Glyph=smileSad;
                      FormPaint(Owner);
                    }
                 }
             }
         }
       verificarJuego();
       ratonClick=false;
       botonRightPress=false;
      botonLeftPress=false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  bool estaVigente=f->getVegenciaJuego();
  if(estaVigente && primerClick==false &&seHaHechoAlgo)
    {
      pausar(NULL);
      TFormSaveGame *s;
      s=new TFormSaveGame(NULL);
      s->ShowModal();
      s->Update();
      if(s->getSi()==true)
        {
          Guardar1Click(NULL);
          if(seGuardo=="vacio")
            {
              CanClose=false;
            }
          else if(seGuardo=="invalido")
            {
              MessageDlg("El archivo que se pudo guardar.", mtError, TMsgDlgButtons() << mbOK, 0);
            }
          else
            {
              CanClose=true;
            }
        }
      else if(s->getNo()==true)
        {
          CanClose=true;
        }
      else if(s->getCancelar()==true)
        {
          CanClose=false;
        }
      delete s;
      reanudar(NULL);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::FormShow(TObject *Sender)
{
  FormSplashScreen = new TFormSplashScreen(NULL);
  FormSplashScreen->Show();
  FormSplashScreen->Repaint();
  ::Sleep(1500);
  if(FormSplashScreen)
    {
      delete FormSplashScreen;
      FormSplashScreen = NULL;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::PanelManejoMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileOh;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::PanelManejoMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileHappy;
    }
  
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::imgMine3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileOh;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::imgMine3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileHappy;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::imgTime3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileOh;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::imgTime3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  bool juegoVigente=f->getVegenciaJuego();
  if(juegoVigente==true && estaEnPausa==false)
    {
      SBImgSmiles->Glyph=smileHappy;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::SBImgSmilesClick(TObject *Sender)
{
  int nivel=f->getNivel();
  switch(nivel)
    {
      case 0:  //Reiniciar personalizado
        Nivel0Click();
        break;
      case 1:
        Nivel11Click(Sender);
        break;
      case 2:
        Nivel21Click(Sender);
        break;
      case 3:
        Nivel31Click(Sender);
        break;
      case 4:
        Nivel41Click(Sender);
        break;
      case 5:
        Nivel51Click(Sender);
        break;
      case 6:
        Nivel61Click(Sender);
        break;
      case 7:
        Nivel71Click(Sender);
        break;
      case 8:
        Nivel81Click(Sender);
        break;
      case 9:
        Nivel91Click(Sender);
        break;
      case 10:
        Nivel101Click(Sender);
        break;
      case 11:
        Nivel111Click(Sender);
        break;
      case 12:
        Nivel121Click(Sender);
        break;
      case 13:
        Nivel131Click(Sender);
        break;
      case 14:
        Nivel141Click(Sender);
        break;
      case 15:
        Nivel151Click(Sender);
        break;
      case 16:
        Nivel161Click(Sender);
        break;
      case 17:
        Nivel171Click(Sender);
        break;
      case 18:
        Nivel181Click(Sender);
        break;
      case 19:
        Nivel191Click(Sender);
        break;
      case 20:
        Nivel201Click(Sender);
        break;
      case 21:
        Nivel211Click(Sender);
        break;
      case 22:
       PantallaCompleta1Click(Sender);
        break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::Nuevo1Click(TObject *Sender)
{
  SBImgSmilesClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Pausa1Click(TObject *Sender)
{
  if (estaEnPausa==true)
    {
      reanudar(NULL);
    }
  else
    {
      pausar(NULL);
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::reanudar(TObject *Sender)
{
  if (estaEnPausa==true)
      {
        estaEnPausa = false;
        Pausa1->Caption = "&Pausa";
        Timer1->Enabled = true;
        FormPaint(Owner);
      }
}

void __fastcall TFormWinMine::pausar(TObject *Sender)
  {
    if (estaEnPausa==false)
      {
        estaEnPausa = true;
        Pausa1->Caption = "&Continuar";
        Timer1->Enabled = false;
        FormPaint(Owner);
      }
  }
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::Guardarcomo1Click(TObject *Sender)
{
  pausar(NULL);
  CodRes resultado;
  if (SaveWinMine->Execute())
    {
      fileNombrePartida=SaveWinMine->FileName;
    }
  reanudar(NULL);
  string filePartida=string(fileNombrePartida.c_str());
  string estado="pendiente";
  resultado=f->srvGuardarPartida(estado,filePartida);
  if(resultado==FILE_VACIO)
    {
      seGuardo="vacio";
    }
  else if(resultado==FILE_INVALIDO)
    {
      seGuardo="invalido";
    }
  else
    {
      seGuardo="guardado";
      seHaHechoAlgo=false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::Guardar1Click(TObject *Sender)
{
  CodRes resultado;
  if(fileNombrePartida=="")
    {
      Guardarcomo1Click(NULL);
    }
  else
    {
      string filePartida=string(fileNombrePartida.c_str());
      string estado="pendiente";
      resultado=f->srvGuardarPartida(estado,filePartida);
      if(resultado==FILE_INVALIDO)
        {
          seGuardo="invalido";
        }
      else
        {
          seGuardo="guardado";
          seHaHechoAlgo=false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Abrir1Click(TObject *Sender)
{
  AnsiString fileOpen;
  CodRes resultado;
  if (OpenWinMine->Execute())
    {
      fileOpen=OpenWinMine->FileName;
    }
  string fileOpenPartida=string(fileOpen.c_str());
  resultado=f->srvAbrirPartida(fileOpenPartida);
  if(resultado==SRV_EXITO)
    {
      ShowNumberTime(0,0,0,0);
      fileNombrePartida=AnsiString(fileOpenPartida.c_str());
      Timer1->Enabled = true;
      Pausa1->Enabled=true;
      Guardar1->Enabled=true;
      Guardarcomo1->Enabled=true;
      estaEnPausa = false;
      Pausa1->Caption = "&Pausa";
      SBImgSmiles->Glyph=smileHappy;
      primerClick=false;
      bool yaSeCreo;
      int numFils,numCols,numMines;
      int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
      int aWidth=16*numCols;
      int aHeight= 16*numFils;
      ClientHeight = 40+aHeight;
      ClientWidth = aWidth;
      PanelManejo->Width=aWidth;
      SBImgSmiles->Left=PanelManejo->Width/2-11;
      imgTime4->Left=PanelManejo->Width-7-13;
      imgTime3->Left=PanelManejo->Width-7-26;
      imgTime2->Left=PanelManejo->Width-7-39;
      imgTime1->Left=PanelManejo->Width-7-52;
      FormPaint(Owner);
    }
  else if(resultado==FILE_GANO || FILE_PERDIO)
    {
      TFormWinLost *wl;
      wl=new TFormWinLost(NULL);
      wl->ShowModal();
      wl->Update();
      delete wl;
    }
  else if(resultado==FILE_CANCELAR)
    {
    }
  else
    {
      MessageDlg("Archivo incorrecto , favor ingrese uno válido", mtError, TMsgDlgButtons() << mbOK, 0);
    }
}
//---------------------------------------------------------------------------
void TFormWinMine::Nivel0Click()
  {
    bool sePuedeReiniciar=comunNiveles();
    if(sePuedeReiniciar)
      {
        f->setnivel(0);
        bool yaSeCreo;
        int fils,cols,numMines;
        int** matrix=f->srvDarInfoMatrix(yaSeCreo,fils,cols,numMines);
        int aWidth=16*cols;
        int aHeight= 16 * fils;
        ClientHeight = 40+aHeight;
        ClientWidth = aWidth;
        PanelManejo->Width=aWidth;
        SBImgSmiles->Left=PanelManejo->Width/2-13;
        imgTime4->Left=PanelManejo->Width-7-13;
        imgTime3->Left=PanelManejo->Width-7-26;
        imgTime2->Left=PanelManejo->Width-7-39;
        imgTime1->Left=PanelManejo->Width-7-52;
        f->srvCrearJuego(fils,cols,0);
        FormPaint(Owner);
     }
  }

//-----------------------------------

void __fastcall TFormWinMine::Nivel11Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*9;     //Ancho
      int aHeight= 16 * 9;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          f->setnivel(1);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(9,9,1);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel21Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*16;     //Ancho
      int aHeight= 16 * 16;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          f->setnivel(2);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(16,16,2);
          FormPaint(Owner);
        }
    }
}
//--------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel31Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*30;     //Ancho
      int aHeight= 16 * 16;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          f->setnivel(3);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(16,30,3);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel41Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*30;     //Ancho
      int aHeight= 16 * 24;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          f->setnivel(4);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(24,30,4);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel51Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*38;     //Ancho
      int aHeight= 16 * 24;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          f->setnivel(5);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(24,38,5);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel61Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*38;     //Ancho
      int aHeight= 16 * 32;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(6);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(32,38,6);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel71Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*46;     //Ancho
      int aHeight= 16 * 32;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(7);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(32,46,7);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel81Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*46;     //Ancho
      int aHeight= 16 * 40;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(8);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(40,46,8);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel91Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*54;     //Ancho
      int aHeight= 16 * 40;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(9);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(40,54,9);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel101Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*54;     //Ancho
      int aHeight= 16 * 48;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(10);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(48,54,10);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TFormWinMine::Nivel111Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*62;     //Ancho
      int aHeight= 16 * 48;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(11);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(48,62,11);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel121Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*62;     //Ancho
      int aHeight= 16 * 56;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(12);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(56,62,12);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::Nivel131Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*70;     //Ancho
      int aHeight= 16 * 56;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(13);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(56,70,13);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel141Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*70;     //Ancho
      int aHeight= 16 * 60;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(14);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(60,70,14);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel151Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*78;     //Ancho
      int aHeight= 16 * 60;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(15);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(60,78,15);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel161Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*78;     //Ancho
      int aHeight= 16 * 68;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(16);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(68,78,16);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel171Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*86;     //Ancho
      int aHeight= 16 * 68;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(17);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(68,86,17);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel181Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*86;     //Ancho
      int aHeight= 16 * 76;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(18);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(76,86,18);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel191Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*94;     //Ancho
      int aHeight= 16 * 76;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(19);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(76,94,19);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel201Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*102;     //Ancho
      int aHeight= 16 * 76;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(20);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(76,102,20);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Nivel211Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      int aWidth=16*110;     //Ancho
      int aHeight= 16 * 76;//alto
      int nHeight=Screen->DesktopHeight-32-81;
      int nWidth=Screen->DesktopWidth;
      if(aWidth>nWidth || aHeight>nHeight)
        {
          mostrarMensajeBadResolution();
        }
      else
        {
          reiniciar();
          Left=0;
          Top=0;
          f->setnivel(21);
          ClientHeight = 40+aHeight;
          ClientWidth = aWidth;
          PanelManejo->Width=aWidth;
          SBImgSmiles->Left=PanelManejo->Width/2-13;
          imgTime4->Left=PanelManejo->Width-7-13;
          imgTime3->Left=PanelManejo->Width-7-26;
          imgTime2->Left=PanelManejo->Width-7-39;
          imgTime1->Left=PanelManejo->Width-7-52;
          f->srvCrearJuego(76,110,21);
          FormPaint(Owner);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormWinMine::Personalizado1Click(TObject *Sender)
{
  bool yaSeCreo;
  int numFils,numCols,numMines;
  int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
  FormTam = new  TFormTam( NULL,f );
  FormTam->edtFils->Text=IntToStr(numFils);
  FormTam->edtCols->Text=IntToStr(numCols);
  FormTam->ShowModal();
  FormTam->Update();
  if(FormTam->getAceptar()==true)
    {
      string strFils,strCols;
      int aFils,aCols;
      strFils=string(FormTam->edtFils->Text.c_str());
      strCols=string(FormTam->edtCols->Text.c_str());
      sscanf(strFils.c_str(),"%d",&aFils);
      sscanf(strCols.c_str(),"%d",&aCols);
      CodRes resultado;
      resultado=f->verificarTamano(strFils,strCols);
      bool sePuedeReiniciar=comunNiveles();
      if(sePuedeReiniciar)
        {
          if(resultado==NUM_MAL_MENOS)
            {
              aFils=9;
              aCols=9;
            }
          int aWidth=16*aFils;     //Ancho
          int aHeight= 16 * aCols;//alto
          int nHeight=Screen->DesktopHeight-32-81;
          int nWidth=Screen->DesktopWidth;
          if(aWidth>nWidth || aHeight>nHeight)
            {
              mostrarMensajeBadResolution();
            }
          else
            {
              reiniciar();
              Left=0;
              Top=0;
              f->setnivel(0);
              ClientHeight = 40+aHeight;
              ClientWidth = aWidth;
              PanelManejo->Width=aWidth;
              SBImgSmiles->Left=PanelManejo->Width/2-13;
              imgTime4->Left=PanelManejo->Width-7-13;
              imgTime3->Left=PanelManejo->Width-7-26;
              imgTime2->Left=PanelManejo->Width-7-39;
              imgTime1->Left=PanelManejo->Width-7-52;
              if (resultado==SRV_EXITO)
                {
                  f->srvCrearJuego(aFils,aCols,0);
                }
              else if (resultado==NUM_MAL_MENOS)
                {
                  f->srvCrearJuego(9,9,0);
                }
              FormPaint(Owner);
            }
        }
    }
  delete FormTam;
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::PantallaCompleta1Click(TObject *Sender)
{
  bool sePuedeReiniciar=comunNiveles();
  if(sePuedeReiniciar)
    {
      reiniciar();
      Left=0;
      Top=0;
      int nHeight=Screen->DesktopHeight;
      int nWidth=Screen->DesktopWidth;
      f->setnivel(22);
      f->setTime(0);
      int cols=(nWidth/16)-1;
      int fils=((nHeight-81)/16)-2;
      AnsiString temp;
      int aWidth=16*cols;
      int aHeight= 16 * fils;
      ClientHeight = 40+aHeight;
      ClientWidth = aWidth;
      PanelManejo->Width=aWidth;
      SBImgSmiles->Left=PanelManejo->Width/2-13;
      imgTime4->Left=PanelManejo->Width-7-13;
      imgTime3->Left=PanelManejo->Width-7-26;
      imgTime2->Left=PanelManejo->Width-7-39;
      imgTime1->Left=PanelManejo->Width-7-52;
      f->srvCrearJuego(fils,cols,22);
      FormPaint(Owner);
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::MejoresTiempos1Click(TObject *Sender)
{
  bool estaVigente=f->getVegenciaJuego();
  if(estaVigente && primerClick==false)
    {
      pausar(NULL);
    }
  FormShowRecs = new  TFormShowRecs( NULL,f );
  FormShowRecs->TabControl1_7Change(Sender);
  FormShowRecs->TabControl8_14Change(Sender);
  FormShowRecs->TabControl15_21Change(Sender);
  FormShowRecs->ShowModal();
  FormShowRecs->Update();
  delete FormShowRecs;
  if(estaVigente)
    {
      reanudar(NULL);
    }
}

//---------------------------------------------------------------------------

void __fastcall TFormWinMine::Salir1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormWinMine::Timer1Timer(TObject *Sender)
{
  int temp;
  int n1,n2,n3,n4;
  int time=f->getTime();
  time++;
  f->setTime(time);
  temp = time;
  if(temp%10==0)
    {
      temp/=10;
      n1=temp/1000;
      temp = temp - (temp/1000)*1000;
      n2= temp/100;
      temp = temp - (temp/100)*100;
      n3=temp/10;
      temp = temp - (temp/10)*10;
      n4=temp;
      ShowNumberTime(n1,n2,n3,n4);
    }
}
//---------------------------------------------------------------------------

void TFormWinMine::ShowNumberTime(const int &number1,const int &number2, const int &number3, const int &number4)
{

  imgTime1->Canvas->Draw(0, 0, number[number1]);
  imgTime2->Canvas->Draw(0, 0, number[number2]);
  imgTime3->Canvas->Draw(0, 0, number[number3]);
  imgTime4->Canvas->Draw(0, 0, number[number4]);

}

void TFormWinMine::ShowNumberMines(const int numMines)
{
  int temp;
  int n1,n2,n3,n4;
  temp = numMines;
  n1=temp/1000;
  temp = temp - (temp/1000)*1000;
  n2= temp/100;
  temp = temp - (temp/100)*100;
  n3=temp/10;
  temp = temp - (temp/10)*10;
  n4=temp;
  if(numMines>=0)
    {
      imgMine1->Canvas->Draw(0, 0, number[n1]);
      imgMine2->Canvas->Draw(0, 0, number[n2]);
      imgMine3->Canvas->Draw(0, 0, number[n3]);
      imgMine4->Canvas->Draw(0, 0, number[n4]);
    }
  else
    {
      if(n2<0)
        {
          n2*=-1;
        }
      if(n3<0)
        {
          n3*=-1;
        }
      if(n4<0)
        {
          n4*=-1;
        }
      imgMine1->Canvas->Draw(0, 0, negative);
      imgMine2->Canvas->Draw(0, 0, number[n2]);
      imgMine3->Canvas->Draw(0, 0, number[n3]);
      imgMine4->Canvas->Draw(0, 0, number[n4]);


    }

}



void __fastcall TFormWinMine::Contenido1Click(TObject *Sender)
{
  Application->HelpCommand(15,-3);
}
//---------------------------------------------------------------------------

void __fastcall TFormWinMine::AcercadeWinMineCafesanu1Click(
      TObject *Sender)
{
  bool estaVigente=f->getVegenciaJuego();
  if(estaVigente  && primerClick==false)
    {
      pausar(NULL);
    }
  FormAcerca = new  TFormAcerca( NULL );
  FormAcerca->ShowModal();
  FormAcerca->Update();
  delete FormAcerca;
  if(estaVigente)
    {
      reanudar(NULL);
    }
}
//---------------------------------------------------------------------------

void TFormWinMine::verificarJuego()
  {

    bool yaSeCreo;
    int numFils,numCols,numMines;
    int** matrix=f->srvDarInfoMatrix(yaSeCreo,numFils,numCols,numMines);
    int ** matrixClick=f->srvDarInfoMatrixClick();
    string retornar=f->srvVerificarJuego();
    if(retornar== "perdio")
      {
        if(fileNombrePartida!="")
          {

            string filePartida=string(fileNombrePartida.c_str());
            CodRes res;
            res=f->srvGuardarPartida(retornar,filePartida);
            if(res==SRV_EXITO)
              {
                seHaHechoAlgo=false;
              }

          }
        Timer1->Enabled = false;
        Pausa1->Enabled=false;
        Guardar1->Enabled=false;
        Guardarcomo1->Enabled=false;
        estaEnPausa = false;
        f->setTime(0);
      }
    else if(retornar=="gano")
      {
        if(fileNombrePartida!="")
          {
            string filePartida=string(fileNombrePartida.c_str());
            CodRes res=f->srvGuardarPartida(retornar,filePartida);
            if(res==SRV_EXITO)
              {
                seHaHechoAlgo=false;
              }
          }
        Application->OnMinimize=0;
        Application->OnRestore = 0;
        Timer1->Enabled = false;
        Pausa1->Enabled=false;
        Guardar1->Enabled=false;
        Guardarcomo1->Enabled=false;
        estaEnPausa = false;
        SBImgSmiles->Glyph=smileGlasses;
        f->setMinesFlag(0);
        for(int i=0;i<numFils;i++)
          {
            for(int j=0;j<numCols;j++)
              {
                if(matrixClick[i][j]==0)
                  {
                    f->srvCambiarEstadoMatrixClick(i,j,2);
                  }
              }
          }
        FormPaint(Owner);
        f->srvAcabarJuego();
        verificarRecords();
      }
    else if(retornar=="pendiente")
      {
        if(fileNombrePartida!="")
          {
            string filePartida=string(fileNombrePartida.c_str());
            CodRes  res=f->srvGuardarPartida(retornar,filePartida);
            if(res==SRV_EXITO)
              {
                seHaHechoAlgo=false;
              }
          }
      }

  }

void TFormWinMine::verificarRecords() 
  {
    int nTime,nNivel;
    CodRes resultado;
    nTime=f->getTime();
    nNivel=f->getNivel();
    if(nNivel>0 && nNivel<=21)
      {
        resultado=f->srvVerificarRecord(nTime/10, nNivel);
        if(resultado==SUPERADO)
          {
            FormRec = new  TFormRec( NULL,f );
            FormRec->setTimeNivel(nTime/10,nNivel);
            FormRec->ShowModal();
            FormRec->Update();
            delete FormRec;
            FormShowRecs = new  TFormShowRecs( NULL,f );
            if(nNivel>0 &&nNivel<=7)
              {
                FormShowRecs->TabControl1_7->TabIndex=nNivel-1;
              }
            else if(nNivel>7 &&nNivel<=14)
              {
                FormShowRecs->TabControl8_14->TabIndex=nNivel-1;
              }

            else
              {
                FormShowRecs->TabControl15_21->TabIndex=nNivel-1;
              }
            FormShowRecs->TabControl1_7Change(NULL);
            FormShowRecs->TabControl8_14Change(NULL);
            FormShowRecs->TabControl15_21Change(NULL);
            FormShowRecs->ShowModal();
            FormShowRecs->Update();
            delete FormShowRecs;
          }
      }

  }
//---------------------------------------------------------------------------

bool TFormWinMine::comunNiveles()
{
  bool estaVigente=f->getVegenciaJuego();
  bool sePuedeReiniciar=true;
  if(estaVigente && primerClick==false && seHaHechoAlgo)
    {
      pausar(NULL);
      TFormSaveGame *s;
      s=new TFormSaveGame(NULL);
      s->ShowModal();
      s->Update();
      if(s->getSi()==true)
        {
          Guardar1Click(NULL);
          if(seGuardo=="vacio")
            {
              sePuedeReiniciar=false;
            }
          else if(seGuardo=="invalido")
            {
              MessageDlg("El archivo que se pudo guardar.", mtError, TMsgDlgButtons() << mbOK, 0);
              sePuedeReiniciar=false;
            }
          else
            {
              sePuedeReiniciar=true;
            }
        }
      else if(s->getNo()==true)
        {
          sePuedeReiniciar=true;
        }
      else if(s->getCancelar()==true)
        {
          sePuedeReiniciar=false;
        }
      delete s;
      reanudar(NULL);
    }
  if(sePuedeReiniciar)
    {
      return true;
    }
  else
    {
      return false;
    }

}

void TFormWinMine::reiniciar()
  {
    Application->OnMinimize = pausar;
    Application->OnRestore = reanudar;
    fileNombrePartida="";
    f->setTime(0);
    Pausa1->Enabled=false;
    Guardar1->Enabled=false;
    Guardarcomo1->Enabled=false;
    estaEnPausa = false;
    Pausa1->Caption = "&Pausa";
    Timer1->Enabled = false;
    ShowNumberTime(0,0,0,0);
    SBImgSmiles->Glyph=smileHappy;
    primerClick=true;
  }

void TFormWinMine::mostrarMensajeBadResolution()
  {
      TFormBadRes *br;
      br=new TFormBadRes(NULL);
      br->ShowModal();
      br->Update();
      delete br;
  }


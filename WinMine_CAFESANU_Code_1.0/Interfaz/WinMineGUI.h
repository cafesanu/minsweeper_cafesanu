//---------------------------------------------------------------------------

#ifndef WinMineGUIH
#define WinMineGUIH
//---------------------------------------------------------------------------
//Librerias Borland
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//Clases Interfaz
#include"FormTamano.h"
#include"FormRecord.h"
#include"FormShowRecords.h"
#include"FormSave.h"
#include "FormSplash.h"
#include "FormAbout.h"
#include "FormBadResolution.h"
#include "FormLostWin.h"
//Clases Kernel
#include"AdministradorWinMine.h"
//---------------------------------------------------------------------------
class TFormWinMine : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TTimer *Timer1;
        TMenuItem *Juego1;
        TMenuItem *Help;
        TMenuItem *Nivel11;
        TPanel *PanelManejo;
        TImage *imgMine1;
        TImage *imgMine2;
        TImage *imgMine3;
        TSpeedButton *SBImgSmiles;
        TMenuItem *Nivel21;
        TMenuItem *Nivel31;
        TMenuItem *Nivel41;
        TMenuItem *Nivel51;
        TMenuItem *Nivel61;
        TMenuItem *Nivel71;
        TMenuItem *Nivel81;
        TMenuItem *Nivel91;
        TMenuItem *Nivel101;
        TMenuItem *Nivel111;
        TImage *imgMine4;
        TImage *imgTime4;
        TImage *imgTime3;
        TImage *imgTime2;
        TImage *imgTime1;
        TMenuItem *N1;
        TMenuItem *Nuevo1;
        TMenuItem *Personalizado1;
        TMenuItem *N2;
        TMenuItem *MejoresTiempos1;
        TMenuItem *N3;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *Guardarcomo1;
        TMenuItem *N4;
        TMenuItem *Salir1;
        TMenuItem *Pausa1;
        TMenuItem *Nivel121;
        TMenuItem *Nivel131;
        TMenuItem *Nivel141;
        TMenuItem *Nivel151;
        TMenuItem *Nivel161;
        TMenuItem *Nivel171;
        TMenuItem *Nivel181;
        TMenuItem *Nivel191;
        TMenuItem *Nivel201;
        TMenuItem *Nivel211;
        TMenuItem *PantallaCompleta1;
        TMenuItem *AnchoxAlto1;
        TSaveDialog *SaveWinMine;
        TOpenDialog *OpenWinMine;
        TMenuItem *AcercadeWinMineCafesanu1;
        TMenuItem *Contenido1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall imgMine3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall imgMine3MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall imgTime3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall imgTime3MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PanelManejoMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PanelManejoMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Nivel11Click(TObject *Sender);
        void __fastcall Nivel21Click(TObject *Sender);
        void __fastcall SBImgSmilesClick(TObject *Sender);
        void __fastcall Nivel31Click(TObject *Sender);
        void __fastcall Nivel41Click(TObject *Sender);
        void __fastcall Nivel51Click(TObject *Sender);
        void __fastcall Nivel61Click(TObject *Sender);
        void __fastcall Nivel71Click(TObject *Sender);
        void __fastcall Nivel81Click(TObject *Sender);
        void __fastcall Nivel91Click(TObject *Sender);
        void __fastcall Nivel101Click(TObject *Sender);
        void __fastcall Nivel111Click(TObject *Sender);
        void __fastcall Nivel121Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Pausa1Click(TObject *Sender);
        void __fastcall Personalizado1Click(TObject *Sender);
        void __fastcall PantallaCompleta1Click(TObject *Sender);
        void __fastcall Nivel131Click(TObject *Sender);
        void __fastcall Nivel141Click(TObject *Sender);
        void __fastcall Nivel151Click(TObject *Sender);
        void __fastcall Nivel161Click(TObject *Sender);
        void __fastcall Nivel171Click(TObject *Sender);
        void __fastcall Nivel181Click(TObject *Sender);
        void __fastcall Nivel191Click(TObject *Sender);
        void __fastcall Nivel201Click(TObject *Sender);
        void __fastcall Nivel211Click(TObject *Sender);
        void __fastcall MejoresTiempos1Click(TObject *Sender);
        void __fastcall Nuevo1Click(TObject *Sender);
        void __fastcall Guardarcomo1Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall AcercadeWinMineCafesanu1Click(TObject *Sender);
        void __fastcall Contenido1Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Salir1Click(TObject *Sender);
private:	// User declarations
  AdministradorWinMine *f;
  Graphics::TBitmap ** mine;
  Graphics::TBitmap ** number;
  Graphics::TBitmap * mineHide;
  Graphics::TBitmap * mineBombRed;
  Graphics::TBitmap * mineBombBad;
  Graphics::TBitmap * mineBomb;
  Graphics::TBitmap * mineClick;
  Graphics::TBitmap * mineFlag;
  Graphics::TBitmap * smileHappy;
  Graphics::TBitmap * smileOh;
  Graphics::TBitmap * smileSad;
  Graphics::TBitmap * smileGlasses;
  Graphics::TBitmap * negative;
  AnsiString fileNombrePartida;
  string seGuardo;
  bool ratonClick;
  bool estaEnPausa;
  int posFil,posCol;
  bool seHaHechoAlgo;
  bool primerClick;
  bool botonRightPress,botonLeftPress;
  void verificarJuego();
  void ShowNumberTime(const int &number1,const int &number2, const int &number3, const int &number4);
  void ShowNumberMines(const int numMines);
  void mostrarMensajeBadResolution();
  void Nivel01Click();
  void Nivel0Click();
  void verificarRecords() ;
  void __fastcall pausar(TObject *Sender);
  void __fastcall reanudar(TObject *Sender);
  bool comunNiveles();
  void reiniciar();


public:		// User declarations
        __fastcall TFormWinMine(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWinMine *FormWinMine;
//---------------------------------------------------------------------------
#endif

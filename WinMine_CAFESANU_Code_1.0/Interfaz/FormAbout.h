//---------------------------------------------------------------------------

#ifndef FormAboutH
#define FormAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAcerca : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TImage *Image2;
        TBitBtn *BitBtn1;
        TLabel *Label7;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Label7MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TFormAcerca(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAcerca *FormAcerca;
//---------------------------------------------------------------------------
#endif

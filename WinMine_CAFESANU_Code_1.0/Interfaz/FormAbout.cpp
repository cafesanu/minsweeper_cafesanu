//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TFormAcerca *FormAcerca;
//---------------------------------------------------------------------------
__fastcall TFormAcerca::TFormAcerca(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormAcerca::BitBtn1Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------


void __fastcall TFormAcerca::Label7MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  String St = "http://www.cafesanusoft.cjb.net";
ShellExecute(Handle,"open",St.c_str(),0,0,SW_SHOW);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormLostWin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormWinLost *FormWinLost;
//---------------------------------------------------------------------------
__fastcall TFormWinLost::TFormWinLost(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormWinLost::Button1Click(TObject *Sender)
{
  Close();               
}
//---------------------------------------------------------------------------
void __fastcall TFormWinLost::Button2Click(TObject *Sender)
{
  Application->HelpCommand(1,3);        
}
//---------------------------------------------------------------------------

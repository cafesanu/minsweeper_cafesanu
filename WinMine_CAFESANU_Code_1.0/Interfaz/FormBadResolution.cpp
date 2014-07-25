//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormBadResolution.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBadRes *FormBadRes;
//---------------------------------------------------------------------------
__fastcall TFormBadRes::TFormBadRes(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBadRes::Button1Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormBadRes::Button2Click(TObject *Sender)
{
  Application->HelpCommand(1,2);
}
//---------------------------------------------------------------------------


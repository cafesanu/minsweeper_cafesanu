//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTamano.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTam *FormTam;
//---------------------------------------------------------------------------
__fastcall TFormTam::TFormTam(TComponent* Owner,AdministradorWinMine *fach)
        : TForm(Owner)
{
  f=fach;
}
//---------------------------------------------------------------------------

void __fastcall TFormTam::Button1Click(TObject *Sender)
{
  aceptar=true;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormTam::Button2Click(TObject *Sender)
{
  aceptar=false;
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormTam::edtColsKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==13)
    {
      Button1Click(NULL);
    }        
}
//---------------------------------------------------------------------------

bool TFormTam::getAceptar()
  {
    return aceptar;
  }


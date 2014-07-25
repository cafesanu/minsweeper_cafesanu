//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Questions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormQuestionRP *FormQuestionRP;
//---------------------------------------------------------------------------
__fastcall TFormQuestionRP::TFormQuestionRP(TComponent* Owner,AdministradorWinMine *fach)
        : TForm(Owner)
{
  f=fach; 
}
//---------------------------------------------------------------------------
void __fastcall TFormQuestionRP::CancelBtnClick(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormQuestionRP::OKBtnClick(TObject *Sender)
{
  f->srvReiniciarPuntuaciones();
}
//---------------------------------------------------------------------------

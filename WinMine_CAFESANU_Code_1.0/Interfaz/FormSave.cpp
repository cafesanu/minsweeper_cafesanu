//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSave.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSaveGame *FormSaveGame;
//---------------------------------------------------------------------------
__fastcall TFormSaveGame::TFormSaveGame(TComponent* Owner)
        : TForm(Owner)
{
  si=false;
  no=false;
  cancelar=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormSaveGame::Button1Click(TObject *Sender)
{
  si=true;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSaveGame::Button2Click(TObject *Sender)
{
  no=true;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSaveGame::Button3Click(TObject *Sender)
{
  cancelar=true;
  Close();        
}
//---------------------------------------------------------------------------
bool
TFormSaveGame::getSi()
  {
    return si;
  }

bool 
TFormSaveGame::getNo()
  {
    return no;
  }

bool
TFormSaveGame::getCancelar()
  {
    return cancelar;
  }

void __fastcall TFormSaveGame::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  cancelar=true;
  CanClose=true;
  Close();
}
//---------------------------------------------------------------------------


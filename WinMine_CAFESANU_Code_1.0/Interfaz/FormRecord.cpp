//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormRecord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRec *FormRec;
//---------------------------------------------------------------------------
__fastcall TFormRec::TFormRec(TComponent* Owner,AdministradorWinMine *fach)
        : TForm(Owner)
{
  f=fach; 
}
//---------------------------------------------------------------------------
void __fastcall TFormRec::edtRecKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  string strNick;
  strNick=string(edtRec->Text.c_str());
  if(strNick.size()>30)
    {
      strNick.erase(strNick.size()-1,1);
    }
  edtRec->Text=AnsiString(strNick.c_str());
  if(Key==13)
    {
      Button1Click(NULL);
    }
      
}
//---------------------------------------------------------------------------
void
TFormRec::setTimeNivel(const int &nTime, const int &nNivel)
  {
    time=nTime;
    nivel=nNivel;
  }
void __fastcall TFormRec::Button1Click(TObject *Sender)
{
  string strNick;
  strNick=string(edtRec->Text.c_str());
  if(strNick!="")
    {
      if(strNick.size()>30)
        {
          strNick.erase(strNick.size()-1,1);
        }
      edtRec->Text=AnsiString(strNick.c_str());
      f->activarRecord(time,nivel,strNick);
      Close();
    }

}
//---------------------------------------------------------------------------






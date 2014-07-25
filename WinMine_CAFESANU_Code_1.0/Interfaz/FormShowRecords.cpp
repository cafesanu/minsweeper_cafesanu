//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormShowRecords.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormShowRecs *FormShowRecs;
//---------------------------------------------------------------------------
__fastcall TFormShowRecs::TFormShowRecs(TComponent* Owner,AdministradorWinMine *fach)
        : TForm(Owner)
{
  f=fach; 
}
//---------------------------------------------------------------------------


void __fastcall TFormShowRecs::Button2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------




void __fastcall TFormShowRecs::TabControl1_7Change(TObject *Sender)
{
  int arrayTime[10];
  string strArrayTime[10];
  string arrayNick[10];
  if(TabControl1_7->TabIndex == 0)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(0,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 1)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(1,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 2)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(2,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 3)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(3,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 4)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(4,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 5)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(5,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl1_7->TabIndex == 6)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(6,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  for( int i=0;i<10;i++)
    {
      strArrayTime[i]=string((IntToStr(arrayTime[i])).c_str());
    }
  if(arrayTime[0]!=-1)
    {
      Label21->Caption = AnsiString(arrayNick[0].c_str());
      Label31->Caption = AnsiString(strArrayTime[0].c_str());
    }
  else
    {
      Label21->Caption = "";
      Label31->Caption = "";
    }
  if(arrayTime[1]!=-1)
    {
      Label22->Caption = AnsiString(arrayNick[1].c_str());
      Label32->Caption = AnsiString(strArrayTime[1].c_str());
    }
  else
   {
      Label22->Caption = "";
      Label32->Caption = "";
   }
  if(arrayTime[2]!=-1)
    {
      Label23->Caption = AnsiString(arrayNick[2].c_str());
      Label33->Caption = AnsiString(strArrayTime[2].c_str());
    }
  else
    {
      Label23->Caption = "";
      Label33->Caption = "";
    }
  if(arrayTime[3]!=-1)
    {
      Label24->Caption = AnsiString(arrayNick[3].c_str());
      Label34->Caption = AnsiString(strArrayTime[3].c_str());
    }
  else
    {
      Label24->Caption = "";
      Label34->Caption = "";
    }
  if(arrayTime[4]!=-1)
    {
      Label25->Caption = AnsiString(arrayNick[4].c_str());
      Label35->Caption = AnsiString(strArrayTime[4].c_str());
    }
  else
    {
      Label25->Caption = "";
      Label35->Caption = "";
    }
  if(arrayTime[5]!=-1)
    {
      Label26->Caption = AnsiString(arrayNick[5].c_str());
      Label36->Caption = AnsiString(strArrayTime[5].c_str());
    }
  else
    {
      Label26->Caption = "";
      Label36->Caption = "";
    }
  if(arrayTime[6]!=-1)
    {
      Label27->Caption = AnsiString(arrayNick[6].c_str());
      Label37->Caption = AnsiString(strArrayTime[6].c_str());
    }
  else
    {
      Label27->Caption = "";
      Label37->Caption = "";
    }
  if(arrayTime[7]!=-1)
    {
      Label28->Caption = AnsiString(arrayNick[7].c_str());
      Label38->Caption = AnsiString(strArrayTime[7].c_str());
    }
  else
    {
      Label28->Caption = "";
      Label38->Caption = "";
    }
  if(arrayTime[8]!=-1)
    {
      Label29->Caption = AnsiString(arrayNick[8].c_str());
      Label39->Caption = AnsiString(strArrayTime[8].c_str());
    }
  else
    {
      Label29->Caption = "";
      Label39->Caption = "";
    }
  if(arrayTime[9]!=-1)
    {
      Label30->Caption = AnsiString(arrayNick[9].c_str());
      Label40->Caption = AnsiString(strArrayTime[9].c_str());
    }
  else
    {
      Label30->Caption = "";
      Label40->Caption = "";
    }
}
//---------------------------------------------------------------------------





void __fastcall TFormShowRecs::TabControl8_14Change(TObject *Sender)
{
  int arrayTime[10];
  string strArrayTime[10];
  string arrayNick[10];
  if(TabControl8_14->TabIndex == 0)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(7,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 1)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(8,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 2)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(9,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 3)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(10,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 4)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(11,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 5)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(12,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl8_14->TabIndex == 6)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(13,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  for( int i=0;i<10;i++)
    {
      strArrayTime[i]=string((IntToStr(arrayTime[i])).c_str());
    }
  if(arrayTime[0]!=-1)
    {
      Label61->Caption = AnsiString(arrayNick[0].c_str());
      Label71->Caption = AnsiString(strArrayTime[0].c_str());
    }
  else
    {
      Label61->Caption = "";
      Label71->Caption = "";
    }
  if(arrayTime[1]!=-1)
    {
      Label62->Caption = AnsiString(arrayNick[1].c_str());
      Label72->Caption = AnsiString(strArrayTime[1].c_str());
    }
  else
   {
      Label62->Caption = "";
      Label72->Caption = "";
   }
  if(arrayTime[2]!=-1)
    {
      Label63->Caption = AnsiString(arrayNick[2].c_str());
      Label73->Caption = AnsiString(strArrayTime[2].c_str());
    }
  else
    {
      Label63->Caption = "";
      Label73->Caption = "";
    }
  if(arrayTime[3]!=-1)
    {
      Label64->Caption = AnsiString(arrayNick[3].c_str());
      Label74->Caption = AnsiString(strArrayTime[3].c_str());
    }
  else
    {
      Label64->Caption = "";
      Label74->Caption = "";
    }
  if(arrayTime[4]!=-1)
    {
      Label65->Caption = AnsiString(arrayNick[4].c_str());
      Label75->Caption = AnsiString(strArrayTime[4].c_str());
    }
  else
    {
      Label65->Caption = "";
      Label75->Caption = "";
    }
  if(arrayTime[5]!=-1)
    {
      Label66->Caption = AnsiString(arrayNick[5].c_str());
      Label76->Caption = AnsiString(strArrayTime[5].c_str());
    }
  else
    {
      Label66->Caption = "";
      Label76->Caption = "";
    }
  if(arrayTime[6]!=-1)
    {
      Label67->Caption = AnsiString(arrayNick[6].c_str());
      Label77->Caption = AnsiString(strArrayTime[6].c_str());
    }
  else
    {
      Label67->Caption = "";
      Label77->Caption = "";
    }
  if(arrayTime[7]!=-1)
    {
      Label68->Caption = AnsiString(arrayNick[7].c_str());
      Label78->Caption = AnsiString(strArrayTime[7].c_str());
    }
  else
    {
      Label68->Caption = "";
      Label78->Caption = "";
    }
  if(arrayTime[8]!=-1)
    {
      Label69->Caption = AnsiString(arrayNick[8].c_str());
      Label79->Caption = AnsiString(strArrayTime[8].c_str());
    }
  else
    {
      Label69->Caption = "";
      Label79->Caption = "";
    }
  if(arrayTime[9]!=-1)
    {
      Label70->Caption = AnsiString(arrayNick[9].c_str());
      Label80->Caption = AnsiString(strArrayTime[9].c_str());
    }
  else
    {
      Label70->Caption = "";
      Label80->Caption = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormShowRecs::TabControl15_21Change(TObject *Sender)
{
  int arrayTime[10];
  string strArrayTime[10];
  string arrayNick[10];
  if(TabControl15_21->TabIndex == 0)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(15,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 1)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(15,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 2)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(16,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 3)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(17,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 4)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(18,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 5)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(19,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  if(TabControl15_21->TabIndex == 6)
    {
      for( int i=0;i<10;i++)
        {
          f->srvDarInfoRecord(20,i,arrayNick[i],arrayTime[i]);
          arrayNick[i]=arrayNick[i].substr(0,30);
        }
    }
  for( int i=0;i<10;i++)
    {
      strArrayTime[i]=string((IntToStr(arrayTime[i])).c_str());
    }
  if(arrayTime[0]!=-1)
    {
      Label101->Caption = AnsiString(arrayNick[0].c_str());
      Label111->Caption = AnsiString(strArrayTime[0].c_str());
    }
  else
    {
      Label101->Caption = "";
      Label111->Caption = "";
    }
  if(arrayTime[1]!=-1)
    {
      Label102->Caption = AnsiString(arrayNick[1].c_str());
      Label112->Caption = AnsiString(strArrayTime[1].c_str());
    }
  else
   {
      Label102->Caption = "";
      Label112->Caption = "";
   }
  if(arrayTime[2]!=-1)
    {
      Label103->Caption = AnsiString(arrayNick[2].c_str());
      Label113->Caption = AnsiString(strArrayTime[2].c_str());
    }
  else
    {
      Label103->Caption = "";
      Label113->Caption = "";
    }
  if(arrayTime[3]!=-1)
    {
      Label104->Caption = AnsiString(arrayNick[3].c_str());
      Label114->Caption = AnsiString(strArrayTime[3].c_str());
    }
  else
    {
      Label104->Caption = "";
      Label114->Caption = "";
    }
  if(arrayTime[4]!=-1)
    {
      Label105->Caption = AnsiString(arrayNick[4].c_str());
      Label115->Caption = AnsiString(strArrayTime[4].c_str());
    }
  else
    {
      Label105->Caption = "";
      Label115->Caption = "";
    }
  if(arrayTime[5]!=-1)
    {
      Label106->Caption = AnsiString(arrayNick[5].c_str());
      Label116->Caption = AnsiString(strArrayTime[5].c_str());
    }
  else
    {
      Label106->Caption = "";
      Label116->Caption = "";
    }
  if(arrayTime[6]!=-1)
    {
      Label107->Caption = AnsiString(arrayNick[6].c_str());
      Label117->Caption = AnsiString(strArrayTime[6].c_str());
    }
  else
    {
      Label107->Caption = "";
      Label117->Caption = "";
    }
  if(arrayTime[7]!=-1)
    {
      Label108->Caption = AnsiString(arrayNick[7].c_str());
      Label118->Caption = AnsiString(strArrayTime[7].c_str());
    }
  else
    {
      Label108->Caption = "";
      Label118->Caption = "";
    }
  if(arrayTime[8]!=-1)
    {
      Label109->Caption = AnsiString(arrayNick[8].c_str());
      Label119->Caption = AnsiString(strArrayTime[8].c_str());
    }
  else
    {
      Label109->Caption = "";
      Label119->Caption = "";
    }
  if(arrayTime[9]!=-1)
    {
      Label110->Caption = AnsiString(arrayNick[9].c_str());
      Label120->Caption = AnsiString(strArrayTime[9].c_str());
    }
  else
    {
      Label110->Caption = "";
      Label120->Caption = "";
    }
}
//---------------------------------------------------------------------------



void __fastcall TFormShowRecs::Button1Click(TObject *Sender)
{
  TFormQuestionRP *t;
  t=new TFormQuestionRP(NULL, f);
  t->ShowModal();
  t->Update();
  delete t;
  TabControl1_7Change(NULL);
  TabControl8_14Change(NULL);
  TabControl15_21Change(NULL);
}
//---------------------------------------------------------------------------




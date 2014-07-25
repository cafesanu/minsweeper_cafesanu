//---------------------------------------------------------------------------

#ifndef FormRecordH
#define FormRecordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include"AdministradorWinMine.h"
//---------------------------------------------------------------------------
class TFormRec : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *edtRec;
        TButton *Button1;
        void __fastcall edtRecKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
  AdministradorWinMine *f;
  int time,nivel;
public:		// User declarations
        __fastcall TFormRec(TComponent* Owner,AdministradorWinMine *fach);
        void setTimeNivel(const int &nTime, const int &nNivel);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRec *FormRec;
//---------------------------------------------------------------------------
#endif

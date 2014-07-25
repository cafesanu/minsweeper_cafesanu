//---------------------------------------------------------------------------

#ifndef FormTamanoH
#define FormTamanoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include"AdministradorWinMine.h"
//---------------------------------------------------------------------------
class TFormTam : public TForm
{
__published:	// IDE-managed Components
        TEdit *edtFils;
        TEdit *edtCols;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall edtColsKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
  AdministradorWinMine *f;
  bool aceptar;
public:		// User declarations
        __fastcall TFormTam(TComponent* Owner,AdministradorWinMine *fach);
        bool getAceptar();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTam *FormTam;
//---------------------------------------------------------------------------
#endif

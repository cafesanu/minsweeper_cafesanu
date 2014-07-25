//---------------------------------------------------------------------------

#ifndef QuestionsH
#define QuestionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include"AdministradorWinMine.h"
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormQuestionRP : public TForm
{
__published:	// IDE-managed Components
        TButton *OKBtn;
        TButton *CancelBtn;
        TLabel *Label1;
        TImage *Image1;
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
private:	// User declarations
  AdministradorWinMine *f;
public:		// User declarations
        __fastcall TFormQuestionRP(TComponent* Owner,AdministradorWinMine *fach);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormQuestionRP *FormQuestionRP;
//---------------------------------------------------------------------------
#endif

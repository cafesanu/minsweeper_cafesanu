//---------------------------------------------------------------------------

#ifndef FormLostWinH
#define FormLostWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormWinLost : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormWinLost(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWinLost *FormWinLost;
//---------------------------------------------------------------------------
#endif

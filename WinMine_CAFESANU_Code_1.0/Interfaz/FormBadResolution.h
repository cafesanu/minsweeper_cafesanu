//---------------------------------------------------------------------------

#ifndef FormBadResolutionH
#define FormBadResolutionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormBadRes : public TForm
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
        __fastcall TFormBadRes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBadRes *FormBadRes;
//---------------------------------------------------------------------------
#endif

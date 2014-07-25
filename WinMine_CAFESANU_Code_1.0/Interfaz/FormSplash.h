//---------------------------------------------------------------------------

#ifndef FormSplashH
#define FormSplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormSplashScreen : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
private:	// User declarations
public:		// User declarations
        __fastcall TFormSplashScreen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSplashScreen *FormSplashScreen;
//---------------------------------------------------------------------------
#endif

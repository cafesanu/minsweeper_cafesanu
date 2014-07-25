//---------------------------------------------------------------------------

#ifndef FormSaveH
#define FormSaveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormSaveGame : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TImage *Image1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
  bool si;
  bool no;
  bool cancelar;
public:		// User declarations
  __fastcall TFormSaveGame(TComponent* Owner);
  bool getSi();
  bool getNo();
  bool getCancelar();


};
//---------------------------------------------------------------------------
extern PACKAGE TFormSaveGame *FormSaveGame;
//---------------------------------------------------------------------------
#endif

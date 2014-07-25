//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "FormSplash.h" 
USERES("WinMineCAFESANU.res");
USEFORM("Interfaz\WinMineGUI.cpp", FormWinMine);
USEUNIT("Kernel\AdministradorWinMine.cpp");
USEUNIT("Kernel\WinMine.cpp");
USEFORM("Interfaz\FormTamano.cpp", FormTam);
USEUNIT("Kernel\Records.cpp");
USEFORM("Interfaz\FormRecord.cpp", FormRec);
USEFORM("Interfaz\FormShowRecords.cpp", FormShowRecs);
USEUNIT("Kernel\Partida.cpp");
USEFORM("Interfaz\FormSplash.cpp", FormSplashScreen);
USEFORM("Interfaz\FormAbout.cpp", FormAcerca);
USEFORM("Interfaz\Questions.cpp", FormQuestionRP);
USEFORM("Interfaz\FormSave.cpp", FormSaveGame);
USEFORM("Interfaz\FormBadResolution.cpp", FormBadRes);
USEFORM("Interfaz\FormLostWin.cpp", FormWinLost);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "WinMine CAFESANU";
                 Application->HelpFile = "D:\\CAFESANU Soft\\WinMine CAFESANU\\WinMine CAFESANU Code 1.0\\WINMINE CAFESANU.HLP";
                 Application->CreateForm(__classid(TFormWinMine), &FormWinMine);
                 Application->CreateForm(__classid(TFormTam), &FormTam);
                 Application->CreateForm(__classid(TFormRec), &FormRec);
                 Application->CreateForm(__classid(TFormShowRecs), &FormShowRecs);
                 Application->CreateForm(__classid(TFormSplashScreen), &FormSplashScreen);
                 Application->CreateForm(__classid(TFormAcerca), &FormAcerca);
                 Application->CreateForm(__classid(TFormQuestionRP), &FormQuestionRP);
                 Application->CreateForm(__classid(TFormSaveGame), &FormSaveGame);
                 Application->CreateForm(__classid(TFormBadRes), &FormBadRes);
                 Application->CreateForm(__classid(TFormWinLost), &FormWinLost);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }

        return 0;
}
//---------------------------------------------------------------------------

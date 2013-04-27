//---------------------------------------------------------------------------

#ifndef memofindmainH
#define memofindmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoScript;
	TFindDialog *FindDialog1;
	void __fastcall FindDialog1Find(TObject *Sender);
	void __fastcall MemoScriptKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

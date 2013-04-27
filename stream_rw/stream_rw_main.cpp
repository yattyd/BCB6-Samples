//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include <vcl.h>
#pragma hdrstop

#include "stream_rw_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	TResourceStream *rs;
	char exefile[100], bin_local[100];
	strcpy(bin_local, "bin\\local");

	{
		snprintf(exefile, 100, "%s\\%s", bin_local, "YaTTYD.exe");

		if (!FileExists(exefile)) {
			try {
				rs = new TResourceStream( (int)HInstance, AnsiString("YaTTYD_EXE"), "EXEFILE" );
				rs->SaveToFile( AnsiString(exefile) ) ;
			}

			__finally {
				delete rs ;
			}
		}
	}
	{
		snprintf(exefile, 100, "%s\\%s", bin_local, "YaTTYD.ini");

		if (!FileExists(exefile)) {
			try {
				rs = new TResourceStream( (int)HInstance, AnsiString("YaTTYD_INI"), "INIFILE" );
				rs->SaveToFile( AnsiString(exefile) ) ;
			}

			__finally {
				delete rs ;
			}
		}
	}
	{
		/*
		http://www.cnblogs.com/del/category/118249.html
		*/
		TMemoryStream *pms;

		try {
			char buf[256];
			rs = new TResourceStream( (int)HInstance, AnsiString("YaTTYD_INI"), "INIFILE" );
			pms = new TMemoryStream();
			pms->LoadFromStream(rs);
			pms->Seek(3000, soFromBeginning);

			while (pms->Position < pms->Size) {
				int nr = pms->Read(buf, sizeof(buf) - 1);
				buf[nr] = '\0';
				ShowMessage(IntToStr(nr)+"\r\n"+buf);
			}
		}

		__finally {
			delete rs;
			delete pms;
		}
	}
}
//---------------------------------------------------------------------------
 
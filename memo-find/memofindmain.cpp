//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "memofindmain.h"
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TMemo *MemoFinding;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	char ver_str[128];
	snprintf(ver_str, sizeof(ver_str),
	         "Memo finding sample Ver 0.0.1 "
	         "weixxll`at'gmail`dot'com build %s %s",
	         __TIME__, __DATE__);
	TForm *form       = dynamic_cast <TForm*>(Sender);
	form->Caption 	  = ver_str;
	MemoScript->Align = alClient;
}
//---------------------------------------------------------------------------
static size_t
strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	if (n == 0) {
		if (siz != 0)
			*d = '\0';

		while (*s++)
			;
	}

	return(s - src - 1);
}

static int
strncasecmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return 0;

	do {
		unsigned char c1 = (unsigned char) * s1++;
		unsigned char c2 = (unsigned char) * s2++;

		if (c1 != c2) {
			if (c1 >= 'A' && c1 <= 'Z' &&
			    c2 >= 'a' && c2 <= 'z')
				c1 += 'a' - 'A';
			else if (c1 >= 'a' && c1 <= 'z' &&
			         c2 >= 'A' && c2 <= 'Z')
				c2 += 'a' - 'A';

			if (c1 != c2)
				return c1 - c2;
		}

		if (c1 == 0)
			break;
	} while (--n != 0);

	return 0;
}

static const char*
strcasestr(const char *str, const char *substr)
{
	const char *p = str;
	int len = strlen(substr);

	if (len == 0) {
		return NULL;
	}

	while (*p) {
		if (strncasecmp(p, substr, len) == 0) {
			return p;
		}

		p++;
	}

	return NULL;
}

static int Find_Memo(TMemo *memo, AnsiString substr, bool caseSensitive)
{
	int i, j, PosReturn, SkipChars;
	int row = memo->CaretPos.y;
	int col = memo->CaretPos.x;
	const char *p = NULL;
	char src[1024], needle[256];

	//p = strcasestr("1234 sms ssss 5678", "sms");

	for (i = row; i < memo->Lines->Count; i++) {
		strlcpy(src, memo->Lines->Strings[i].c_str(), sizeof(src));
		strlcpy(needle, substr.c_str(), sizeof(needle));

		if ( caseSensitive ) {
			//PosReturn = memo->Lines->Strings[i].Pos(str);
			p = strstr(src, needle);
		} else {
			p = strcasestr(src, needle);
		}

		if (NULL == p) {
			continue;
		}

		PosReturn = p - src + 1;

		if ((PosReturn <= col) && (i == row)) {
			PosReturn = 0;
		}

		if (PosReturn != 0) { /* found! */
			SkipChars = 0;

			for (j = 0; j < i; j++) {
				SkipChars = SkipChars + memo->Lines->Strings[j].Length();
			}

			SkipChars = SkipChars + (i * 2);
			SkipChars = SkipChars + PosReturn - 1;

			memo->SetFocus();
			memo->SelStart = SkipChars;
			memo->SelLength = substr.Length();
			return 1;  /* found */
		}
	}

	return 0; /* not found */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindDialog1Find(TObject *Sender)
{
	if (Find_Memo(MemoFinding, FindDialog1->FindText,
	              FindDialog1->Options.Contains(frMatchCase)) == 0) {
		::MessageBox(0, "Not found!", "Warning", MB_OK );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoScriptKeyDown(TObject *Sender, WORD &Key,
                TShiftState Shift)
{
	if (Shift.Contains(ssCtrl)) {
		switch (Key) {
		case 70:
			MemoFinding = dynamic_cast <TMemo*>(Sender);
			FindDialog1->Execute();
			break;
		default:
			break;
		} // switch (Key)
	}
}
//---------------------------------------------------------------------------



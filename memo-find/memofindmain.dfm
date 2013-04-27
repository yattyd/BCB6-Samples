object Form1: TForm1
  Left = 286
  Top = 87
  Width = 615
  Height = 410
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object MemoScript: TMemo
    Left = 64
    Top = 24
    Width = 511
    Height = 335
    Hint = 'Scripts'
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -11
    Font.Name = 'Fixedsys'
    Font.Style = []
    Lines.Strings = (
      '======= Ctrl-F to start searching ============'
      '=============================================='
      ''
      'How to search and replace strings in a TMemo'
      ''
      'Problem/Question/Abstract:'
      ''
      'How to search and replace strings in a TMemo'
      ''
      'Answer:'
      ''
      'Doing search and replace on strings has been made trivial '
      'because of '
      'these 3 functions: Pos(), Delete(), and Insert(). Pos() takes '
      'two '
      'parameters, a pattern search string, and a string to find the '
      'pattern in - it returns the location of the string, or 0 if it '
      'does '
      'not exist. Delete() takes three parameters, the string to '
      'delete '
      'from, location of where to start deleting, and how much to '
      'delete. '
      'Similarly, Insert() takes three parameters too. The string that '
      'will '
      'be inserted, the string to insert into, the location to insert.'
      ''
      'Many class properties use strings to store values, so one can '
      'use '
      'this method on any of them. For instance, the searching and '
      'replacing of an entire TMemo component might look like this:'
      ''
      'procedure TForm1.Button2Click(Sender: TObject);'
      'var'
      '  i: integer;'
      '  s1: string;'
      '  SearchStr: string;'
      '  NewStr: string;'
      '  place: integer;'
      'begin'
      '  SearchStr := '#39'line'#39';'
      '  NewStr := '#39'OneEye'#39';'
      '  for i := 0 to Memo1.Lines.Count - 1 do'
      '  begin'
      '    s1 := Memo1.Lines[i];'
      '    repeat'
      '      Place := pos(SearchStr, s1);'
      '      if place > 0 then'
      '      begin'
      '        Delete(s1, Place, Length(SearchStr));'
      '        Insert(NewStr, s1, Place);'
      '        Memo1.Lines[i] := s1;'
      '      end;'
      '    until'
      '      place = 0;'
      '  end;'
      'end; ')
    ParentFont = False
    TabOrder = 0
    OnKeyDown = MemoScriptKeyDown
  end
  object FindDialog1: TFindDialog
    Options = [frDown, frHideWholeWord, frHideUpDown, frDisableUpDown, frDisableWholeWord]
    OnFind = FindDialog1Find
    Left = 264
    Top = 32
  end
end

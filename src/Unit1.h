//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "table.h"
#include "filter.h"
#include "search.h"
#include "sort.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TOpenDialog *OpenDialog1;
        TStringGrid *StringGrid1;
        TSaveDialog *SaveDialog1;
        TMenuItem *N15;
        TMenuItem *Excel1;
        TMenuItem *csv1;
        TMenuItem *N16;
        TSaveDialog *SaveDialog2;
        void __fastcall Open(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall Save(TObject *Sender);
        void __fastcall SaveAs(TObject *Sender);
        void __fastcall Close(TObject *Sender);
        void __fastcall AddRow(TObject *Sender);
        void __fastcall DelRow(TObject *Sender);
        void __fastcall AddCol(TObject *Sender);
        void __fastcall DelCol(TObject *Sender);
        void __fastcall Create(TObject *Sender);
        void __fastcall Filter(TObject *Sender);
        void __fastcall Excel1Click(TObject *Sender);
        void __fastcall csv1Click(TObject *Sender);
        void __fastcall Search(TObject *Sender);
        void __fastcall Sort(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall StringGrid1SetEditText(TObject *Sender, int ACol,
          int ARow, const AnsiString Value);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        bool TForm1::database_opened;
        bool TForm1::filters_on;
        void TForm1::update_stringgrid();
        void TForm1::update_struct();
        void TForm1::check_edit(int ACol, int ARow);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 
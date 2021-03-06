//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;

//---------------------------------------------------------------------------
int start_row;
int start_col;
coordinates crds;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void set_crds(){
        Form1->StringGrid1->Col = crds.col + 1;
        Form1->StringGrid1->Row = crds.row + 1;
        start_col = crds.col + 1;
        start_row = crds.row;
        if(start_col == shown_db.cols_n){
                start_col = 0;
                start_row += 1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
if(Edit1->Text == ""){
        MessageDlg("?? ??????? ????? ??? ??????",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        if(ComboBox1->Text == "????????"){
                if(start_row < shown_db.rows_n && search_equals(start_row, start_col, Edit1->Text.c_str())){
                        set_crds();
                }
                else{
                        ShowMessage("????? ?????????");
                        start_row = -1;
                        start_col = -1;
                };
        }
        else if(ComboBox1->Text == "̳?????"){
                if(start_row < shown_db.rows_n && search_contains(start_row, start_col, Edit1->Text.c_str())){
                        set_crds();
                }
                else{
                        ShowMessage("????? ?????????");
                        start_row = 0;
                        start_col = -1;
                        crds.col = 0;
                        crds.row = 0;
                };
        }
        else if(ComboBox1->Text == "??????????? ??"){
                if(start_row < shown_db.rows_n && search_starts(start_row, start_col, Edit1->Text.c_str())){
                        set_crds();
                }
                else{
                        ShowMessage("????? ?????????");
                        start_row = 0;
                        start_col = -1;
                        crds.col = 0;
                        crds.row = 0;
                };
        }
        else{
                if(start_row < shown_db.rows_n && search_ends(start_row, start_col, Edit1->Text.c_str())){
                        set_crds();
                }
                else{
                        ShowMessage("????? ?????????");
                        start_row = 0;
                        start_col = -1;
                        crds.col = 0;
                        crds.row = 0;
                };
        }
}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormShow(TObject *Sender)
{
        Edit1->Text = "";
        ComboBox1->ItemIndex = 0;
        start_row = 0;
        start_col = -1;
        crds.col = 0;
        crds.row = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit1Change(TObject *Sender)
{
        start_row = 0;
        start_col = -1;
        crds.col = 0;
        crds.row = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::ComboBox1Change(TObject *Sender)
{
        start_row = 0;
        start_col = -1;
        crds.col = 0;
        crds.row = 0;
}
//---------------------------------------------------------------------------

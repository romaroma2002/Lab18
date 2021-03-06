//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
CheckListBox1->Clear();
for(int i = 0; i < Form1->StringGrid1->ColCount - 1; i++){
        CheckListBox1->Items->Add(db.cols[i].name.c_str());
}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
buf_db.rows_n = db.rows_n;
buf_db.cols_n = 0;

for(int i = 0; i < db.cols_n; i++){
if(!CheckListBox1->Checked[i]){
        buf_db.cols[buf_db.cols_n].name = db.cols[i].name;
        buf_db.cols[buf_db.cols_n].datatype = db.cols[i].datatype;
        for(int j = 0; j < db.rows_n; j++){
                buf_db.cols[buf_db.cols_n].values[j] = db.cols[i].values[j];
        }
        buf_db.cols_n += 1;
}
}

db = buf_db;
shown_db = db;
Form1->update_stringgrid();
Form4->Close();
}
//---------------------------------------------------------------------------
 
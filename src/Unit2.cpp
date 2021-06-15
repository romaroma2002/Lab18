//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
CheckListBox1->Clear();
for(int i = 1; i <= Form1->StringGrid1->RowCount - 1; i++){
        CheckListBox1->Items->Add(IntToStr(i));
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
buf_db.rows_n = 0;
buf_db.cols_n = db.cols_n;

for(int i = 0; i < db.cols_n; i++){
        buf_db.cols[i].name = db.cols[i].name;
        buf_db.cols[i].datatype = db.cols[i].datatype;
}

for(int j = 0; j < db.rows_n; j++){
        if(!CheckListBox1->Checked[j]){
                for(int i = 0; i < buf_db.cols_n; i++)
                        buf_db.cols[i].values[buf_db.rows_n] = db.cols[i].values[j];
                buf_db.rows_n+=1;
        }
}
db = buf_db;
shown_db = db;
Form1->update_stringgrid();
Form2->Close();
}
//---------------------------------------------------------------------------

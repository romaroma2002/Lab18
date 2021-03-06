//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormShow(TObject *Sender)
{
ComboBox1->Clear();
ComboBox2->Clear();
for(int i = 0; i < shown_db.cols_n; i++){
        ComboBox1->Items->Add(shown_db.cols[i].name.c_str());
}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ComboBox1Change(TObject *Sender)
{

int index = ComboBox1->ItemIndex;
ComboBox2->Clear();
if(shown_db.cols[index].datatype == "string"){
        ComboBox2->Items->Add("³? ? ?? ?");
        ComboBox2->Items->Add("³? ? ?? ?");
}
else if(shown_db.cols[index].datatype == "int" || shown_db.cols[index].datatype == "double"){
        ComboBox2->Items->Add("?????????");
        ComboBox2->Items->Add("????????");
}
else if(shown_db.cols[index].datatype == "bool"){
        ComboBox2->Items->Add("???????? true");
        ComboBox2->Items->Add("???????? false");
}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
if(ComboBox1->Text == "" || ComboBox2->Text == ""){
        MessageDlg("?? ??? ???? ?????????", mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        int index = ComboBox1->ItemIndex;
        sort_decision(index, ComboBox2->Text.c_str());
        shown_db = db;
        Form1->update_stringgrid();
}
}
//---------------------------------------------------------------------------

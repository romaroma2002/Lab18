//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TForm6::update_filters(){
        if(CheckListBox1->Items->Count > 0){
                Form1->filters_on = true;
                Form1->StringGrid1->Enabled = false;
        }
        else{
                Form1->filters_on = false;
                Form1->StringGrid1->Enabled = true;
        }
}

//---------------------------------------------------------------------------

void TForm6::update_shown_db(){
        shown_db = db;
        for(int i = 0; i < filter_vector.size(); i++){
                decicion(filter_vector[i]);
        }

        Form1->update_stringgrid();
}  
    

//---------------------------------------------------------------------------

bool is_int(AnsiString input){
        for(int i = 0; i < strlen(input.c_str()); i++)
                if((input.c_str()[i] < '0' || input.c_str()[i] > '9')
                && input.c_str()[i] != '-')
                        return false;
        return true;
}

//---------------------------------------------------------------------------

bool is_double(AnsiString input){
        for(int i = 0; i < strlen(input.c_str()); i++)
                if((input.c_str()[i] < '0' || input.c_str()[i] > '9')
                && (input.c_str()[i] != '-' || input.c_str()[i] != '.'))
                        return false;
        return true;
}

//---------------------------------------------------------------------------

void __fastcall TForm6::FormShow(TObject *Sender)
{
ComboBox1->Clear();
ComboBox2->Clear();
Edit1->Text = "";
for(int i = 0; i < shown_db.cols_n; i++){
        ComboBox1->Items->Add(shown_db.cols[i].name.c_str());
}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::ComboBox1Change(TObject *Sender)
{
int index = ComboBox1->ItemIndex;
Edit1->Text = "";
Edit1->Enabled = true;
ComboBox2->Clear();
if(shown_db.cols[index].datatype == "string"){
        ComboBox2->Items->Add("????????");
        ComboBox2->Items->Add("?? ????????");
        ComboBox2->Items->Add("???????");
        ComboBox2->Items->Add("?? ???????");
        ComboBox2->Items->Add("??????????? ??");
        ComboBox2->Items->Add("?? ??????????? ??");
        ComboBox2->Items->Add("???????????? ??");
        ComboBox2->Items->Add("?? ???????????? ??");
}
else if(shown_db.cols[index].datatype == "int"){
        ComboBox2->Items->Add("????????");
        ComboBox2->Items->Add("?? ????????");
        ComboBox2->Items->Add("??????");
        ComboBox2->Items->Add("??????-?????");
        ComboBox2->Items->Add("?????");
        ComboBox2->Items->Add("?????-?????");
        ComboBox2->Items->Add("???????? ??");
        ComboBox2->Items->Add("?? ???????? ??");
}
else if(shown_db.cols[index].datatype == "double"){
        ComboBox2->Items->Add("????????");
        ComboBox2->Items->Add("?? ????????");
        ComboBox2->Items->Add("??????");
        ComboBox2->Items->Add("??????-?????");
        ComboBox2->Items->Add("?????");
        ComboBox2->Items->Add("?????-?????");
}
else if(shown_db.cols[index].datatype == "bool"){
        ComboBox2->Items->Add("true");
        ComboBox2->Items->Add("false");
        Edit1->Enabled = false;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
int index = ComboBox1->ItemIndex;
string dtype = shown_db.cols[index].datatype;

if(ComboBox1->Text == "" || ComboBox2->Text == "" || (Edit1->Text == "" && dtype != "bool")){
        MessageDlg("?? ??? ???? ?????????",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(dtype == "int" && !is_int(Edit1->Text)){
        MessageDlg("?????????? int ? ????? ????? ?????",
        mtError, TMsgDlgButtons()<<mbOK,0);

}
else if(dtype == "double" && !is_double(Edit1->Text)){
        MessageDlg("?????????? double ? ????? ????? ?????",
        mtError, TMsgDlgButtons()<<mbOK,0);

}
else{
        filt.col_name = ComboBox1->Text.c_str();
        filt.filter_name = ComboBox2->Text.c_str();
        filt.dtype = dtype;
        filt.value = Edit1->Text.c_str();
        CheckListBox1->Items->Add((filt.col_name+" "+filt.filter_name+" "+filt.value).c_str());
        filter_vector.push_back(filt);
        ComboBox1->ItemIndex = -1;
        ComboBox2->ItemIndex = -1;
        Edit1->Text = "";
        update_filters();
}
update_shown_db();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
        for(int i = CheckListBox1->Items->Count - 1; i >= 0; i--)
                if(CheckListBox1->Checked[i]){
                        CheckListBox1->Items->Delete(i);
                        filter_vector.erase(filter_vector.begin() + i);
                }
        update_shown_db();   
        update_filters();
}
//---------------------------------------------------------------------------


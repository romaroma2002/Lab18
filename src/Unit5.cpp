//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool is_int(AnsiString input){
        for(int i = 0; i < strlen(input.c_str()); i++)
                if(input.c_str()[i] < '0' || input.c_str()[i] > '9')
                        return false;
        return true;
}

//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
        if(CheckListBox1->Items->Count == 0){
                MessageDlg("????? ??????? ???????",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(Edit1->Text == ""){
                MessageDlg("?? ??????? ????????? ??????",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(!is_int(Edit1->Text)){
                MessageDlg("??????? ?? ???? ??????? ?????",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(strlen(Edit1->Text.c_str()) > 4){
                MessageDlg("????? ??????? ???? ?????? ?? 10000",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(StrToInt(Edit1->Text)==0){
                MessageDlg("????? ??????? ???? ??????? ?? 0",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else{
                db.rows_n = StrToInt(Edit1->Text);
                shown_db = db;
                Form1->update_stringgrid();
                Form1->StringGrid1->Visible = true;
                Form1->database_opened = true;
                Form5->Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
if(Edit2->Text == "" && ComboBox1->Text == ""){
        MessageDlg("?? ??? ???? ?????????", mtError, TMsgDlgButtons()<<mbOK,0);
}
else{

        string dtype;
        string name;
        bool dublicate = false;
        if(ComboBox1->Text == "ֳ?? ????? - int") dtype = "int";
        else if(ComboBox1->Text == "??????? ????? - double") dtype = "double";
        else if(ComboBox1->Text == "????? - string") dtype = "string";
        else if(ComboBox1->Text == "???????? - bool") dtype = "bool";
        name = Edit2->Text.c_str();
        for(int i = 0; i < db.cols_n; i++){
                if(db.cols[i].name == name){
                        dublicate = true;
                        break;
                }
        }
        if(dublicate){
                MessageDlg("???????? ? ????? ?????? ??? ?????",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else{
                db.cols[db.cols_n].name = name;
                db.cols[db.cols_n].datatype = dtype;
                db.cols_n += 1;

                CheckListBox1->Clear();
                for(int i = 0; i < db.cols_n; i++){
                        CheckListBox1->Items->Add((db.cols[i].name + " (" + db.cols[i].datatype + ")").c_str());
                }
        }
}
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Button2Click(TObject *Sender)
{
        buf_db.cols_n = 0;
        for(int i = 0; i < db.cols_n; i++){
                if(!CheckListBox1->Checked[i]){
                        buf_db.cols[buf_db.cols_n].name = db.cols[i].name;
                        buf_db.cols[buf_db.cols_n].datatype = db.cols[i].datatype;
                        buf_db.cols_n += 1;
                }
        }

        db = buf_db;

        CheckListBox1->Clear();
        for(int i = 0; i < db.cols_n; i++){
               CheckListBox1->Items->Add(db.cols[i].name.c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormShow(TObject *Sender)
{
Edit1->Text = "";
Edit2->Text = "";
CheckListBox1->Clear();
ComboBox1->ItemIndex = -1;
db.cols_n = 0;
db.rows_n = 0;
}
//---------------------------------------------------------------------------


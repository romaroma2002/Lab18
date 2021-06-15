//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
if(Edit1->Text == "" || ComboBox1->Text == ""){
        MessageDlg("Не всі поля заповнені", mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        string dtype;
        string name;
        bool dublicate = false;
        if(ComboBox1->Text == "Ціле число - int") dtype = "int";
        else if(ComboBox1->Text == "Дробове число - double") dtype = "double";
        else if(ComboBox1->Text == "Текст - string") dtype = "string";
        else if(ComboBox1->Text == "Логічний - bool") dtype = "bool";
        name = Edit1->Text.c_str();
        for(int i = 0; i < db.cols_n; i++){
                if(db.cols[i].name == name){
                        dublicate = true;
                        break;
                }
        }
        if(dublicate){
                MessageDlg("Стовбець з такою назвою уже існує",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else{
                db.cols[db.cols_n].name = name;
                db.cols[db.cols_n].datatype = dtype;
                db.cols_n += 1;
                shown_db = db;
                Form1->update_stringgrid();
                Form3->Close();
        }
}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
Edit1->Clear();
ComboBox1->ItemIndex = -1;
}
//---------------------------------------------------------------------------

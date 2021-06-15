//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// для типу даних string
#include <iostream>
using namespace std;  
#include <ComObj.hpp>
#include <utilcls.h>
//---------------------------------------------------------------------------
table db, shown_db, buf_db;
AnsiString filename;
bool database_opened = false;
bool filters_on = false;
bool FEdited;
int EditedCol, EditedRow;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void TForm1::update_stringgrid(){
	StringGrid1->ColCount = shown_db.cols_n + 1;
        StringGrid1->RowCount = shown_db.rows_n + 1;

	string dtype;
	for(int i = 0; i < shown_db.cols_n; i++){
			if(shown_db.cols[i].datatype == "int") dtype=" (i)";
			else if (shown_db.cols[i].datatype == "double") dtype=" (d)";
			else if (shown_db.cols[i].datatype == "string") dtype=" (s)";
			else if (shown_db.cols[i].datatype == "bool") dtype=" (b)";
			StringGrid1->Cells[i + 1][0] = (shown_db.cols[i].name + dtype).c_str();
	}

	for(int j = 0; j < StringGrid1->RowCount; j++){
			StringGrid1->Cells[0][j + 1] = IntToStr(j + 1);
			for(int i = 0; i < shown_db.cols_n; i++)
					StringGrid1->Cells[i + 1][j + 1] = shown_db.cols[i].values[j].c_str();
	}
}

//---------------------------------------------------------------------------

void TForm1::update_struct(){
	db.cols_n = StringGrid1->ColCount - 1;
	db.rows_n = StringGrid1->RowCount - 1;

	string text;
	string dtype;
	for(int i = 0; i < db.cols_n; i++){
			text = StringGrid1->Cells[i + 1][0].c_str();
			dtype = text.substr(text.length()-4);
			if( dtype==" (i)") db.cols[i].datatype = "int";
			else if (dtype==" (d)") db.cols[i].datatype = "double";
			else if (dtype==" (s)") db.cols[i].datatype = "string";
			else if (dtype==" (b)") db.cols[i].datatype = "bool";
			db.cols[i].name = text.substr(0, text.length()-4);
	}

	for(int j = 0; j < db.rows_n; j++){
			for(int i = 0; i < db.cols_n; i++)
					db.cols[i].values[j] = StringGrid1->Cells[i + 1][j + 1].c_str();
	}
        shown_db = db;
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
void load_from_file(char * filename){
	FILE * file;
	file = fopen(filename, "rb");
	
	fread(&db.cols_n, sizeof(db.cols_n), 1, file); 
	fread(&db.rows_n, sizeof(db.rows_n), 1, file);
	
	char buffer[1000];
	for(int i = 0; i < db.cols_n; i++){
		fread(&buffer, sizeof(buffer), 1, file);
		db.cols[i].name = string(buffer);
		fread(&buffer, sizeof(buffer), 1, file);
		db.cols[i].datatype = string(buffer);
	} 
	
	for(int i = 0; i < db.cols_n; i++){
		for(int j = 0; j < db.rows_n; j++){
			fread(&buffer, sizeof(buffer), 1, file);
			db.cols[i].values[j] = string(buffer);
		}
	}
	fclose(file);
        shown_db = db;
}

//---------------------------------------------------------------------------

int save_to_file(char * filename){
	FILE * file;
	
	file = fopen(filename, "wb");
	
	fwrite(&db.cols_n, sizeof(db.cols_n), 1, file);
	fwrite(&db.rows_n, sizeof(db.rows_n), 1, file);
	
	
	char buffer[1000];
	
	for(int i = 0; i < db.cols_n; i++){
		strcpy(buffer, db.cols[i].name.c_str());
		fwrite(&buffer, sizeof(buffer), 1, file);
		strcpy(buffer, db.cols[i].datatype.c_str());
		fwrite(&buffer, sizeof(buffer), 1, file);
	} 

	for(int i = 0; i < db.cols_n; i++){
		for(int j = 0; j < db.rows_n; j++){
			strcpy(buffer, db.cols[i].values[j].c_str());
			fwrite(&buffer, sizeof(buffer), 1, file);
		}
	}
	fclose(file);
	return 0;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Open(TObject *Sender)
{
if(database_opened){
        Save(Sender);
}
if(OpenDialog1->Execute()){
        if(FileExists(OpenDialog1->FileName)){
                filename = OpenDialog1->FileName;
                database_opened = true;
                load_from_file(OpenDialog1->FileName.c_str());
                update_stringgrid();
                StringGrid1->Visible = true;
        }
        else{
                MessageDlg(
                "Файл \""+ExtractFileName(OpenDialog1->FileName)+"\" не існує",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
        StringGrid1->Width = Form1->Width-32;
        StringGrid1->Height = Form1->Height-76;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save(TObject *Sender)
{
if(filename==""){
        SaveAs(Sender);
}
else if(database_opened)
{
        if(MessageDlg("Зберегти зміни у файлі?",
        mtConfirmation, TMsgDlgButtons()<<mbYes<<mbNo,0) == IDYES){
                update_struct();
                save_to_file(filename.c_str());
        };
}
else{
        MessageDlg(
        "База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SaveAs(TObject *Sender)
{
if(database_opened){
        if(SaveDialog1->Execute()){
                if(FileExists(SaveDialog1->FileName)){
                if(MessageDlg("Замінити файл у місці призначення?",
                mtConfirmation, TMsgDlgButtons()<<mbYes<<mbNo,0) == IDYES){
                        filename = SaveDialog1->FileName;
                        update_struct();
                        save_to_file(filename.c_str());
                }
                }
                else{
                filename = SaveDialog1->FileName;
                filename += ".cdb";
                update_struct();
                save_to_file(filename.c_str());
                }
        }
}
else{
        MessageDlg(
        "База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close(TObject *Sender)
{
        if(database_opened){
                Save(Sender);
        }
        database_opened = false;
        filename = "";
        db.cols_n = 0;
        db.rows_n = 0;
        StringGrid1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddRow(TObject *Sender)
{
if(!database_opened){
        MessageDlg(
        "База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(filters_on){
        MessageDlg(
        "Заборонено змінювати базу даних при включених фільтрах",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(db.rows_n == 10000){
        MessageDlg(
        "Досягнуто обмеження по кількості рядків",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        db.rows_n += 1;
        shown_db = db;
        StringGrid1->RowCount += 1;
        update_stringgrid();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DelRow(TObject *Sender)
{
if(!database_opened){
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(filters_on){
        MessageDlg(
        "Заборонено змінювати базу даних при включених фільтрах",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        Form2->ShowModal();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddCol(TObject *Sender)
{
if(!database_opened){
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(filters_on){
        MessageDlg(
        "Заборонено змінювати базу даних при включених фільтрах",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        Form3->ShowModal();
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DelCol(TObject *Sender)
{
if(!database_opened){
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(filters_on){
        MessageDlg(
        "Заборонено змінювати базу даних при включених фільтрах",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        Form4->ShowModal();
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Create(TObject *Sender)
{
if(database_opened){
        Close(Sender);
}
Form5->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Filter(TObject *Sender)
{
if(database_opened){
        Form6->ShowModal();
}
else{
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Excel1Click(TObject *Sender)
{
Variant
        ExcelApp,
        WorkBook,
        WorkSheet;
        try{
                ExcelApp=CreateOleObject("Excel.Application");
        }
        catch(...){
                ShowMessage("Виникла помилка");
        }

        ExcelApp.OlePropertySet("Visible",true);
        ExcelApp.OlePropertySet("SheetsInNewWorkBook",3);
        ExcelApp.OlePropertyGet("WorkBooks").OleFunction("Add",1);
        WorkBook=ExcelApp.OlePropertyGet("WorkBooks",1);
        WorkSheet=ExcelApp.OlePropertyGet("WorkSheets",1);

        for (int j=0; j < StringGrid1->RowCount; j++){
                for (int i=0; i<StringGrid1->ColCount; i++) {
                        WorkSheet.OlePropertyGet("Cells", j+1, i+1).OlePropertySet("Value", WideString(StringGrid1->Cells[i][j]));
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::csv1Click(TObject *Sender)
{
if(SaveDialog2->Execute()){
        FILE * file;
        if(FileExists(SaveDialog2->FileName)){
                if(MessageDlg("Замінити файл у місці призначення?",
                mtConfirmation, TMsgDlgButtons()<<mbYes<<mbNo,0) == IDYES){
                file = fopen(SaveDialog2->FileName.c_str(), "w");
                AnsiString str="";
                for(int j=0; j < StringGrid1->RowCount; j++)    {
                        for (int i = 1; i < StringGrid1->ColCount; i++) {
                                str=str+StringGrid1->Cells[i][j]+";";
                        }
                        str += "\n";
                        fputs(str.c_str(), file);
                        str="";
                }
                fclose(file);

                }
        }
        else{
                file = fopen((SaveDialog2->FileName+".csv").c_str(), "w");
                AnsiString str="";
                for(int j=0; j < StringGrid1->RowCount; j++)    {
                        for (int i = 0; i < StringGrid1->ColCount; i++) {
                                str=str+StringGrid1->Cells[i][j]+";";
                        }
                        fputs(str.c_str(), file);
                        str="";
                }
                fclose(file);
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Search(TObject *Sender)
{
if(database_opened){
        Form7->ShowModal();
}
else{
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Sort(TObject *Sender)
{
if(!database_opened){
        MessageDlg("База даних не відкрита",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else if(filters_on){
        MessageDlg(
        "Заборонено сортувати базу даних при включених фільтрах",
        mtError, TMsgDlgButtons()<<mbOK,0);
}
else{
        Form8->ShowModal();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender){
ShellExecute(Handle, "open", "https://github.com/romaroma2002/Lab18", 0, 0, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void TForm1::check_edit(int ACol, int ARow){
        string dtype = db.cols[ACol-1].datatype;
        string value = StringGrid1->Cells[ACol][ARow].c_str();
        if(dtype=="int" && !is_int(value.c_str())){
                MessageDlg("Введено не ціле число",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(dtype=="double" && !is_double(value.c_str())){
                MessageDlg("Введено не число",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else if(dtype=="bool" && !(value == "true" || value == "false")){
                MessageDlg("Введено не true/false",
                mtError, TMsgDlgButtons()<<mbOK,0);
        }
        else{
                db.cols[ACol-1].values[ARow-1] = StringGrid1->Cells[ACol][ARow].c_str();
                shown_db = db;
        }
        update_stringgrid();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1SetEditText(TObject *Sender, int ACol,
        int ARow, const AnsiString Value){
        FEdited = true;
        EditedCol = ACol;
        EditedRow = ARow;
        if(!StringGrid1->EditorMode){
                check_edit(EditedCol, EditedRow);
                FEdited = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
        int ARow, bool &CanSelect){
        if(FEdited){
                check_edit(EditedCol, EditedRow);
                FEdited = false;
        }

}
//---------------------------------------------------------------------------


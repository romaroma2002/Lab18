//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "Unit1.h"
#include <Forms.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TCheckListBox *CheckListBox1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        void TForm6::update_shown_db();
        void TForm6::update_filters();
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
 
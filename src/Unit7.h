//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>  
#include "Unit1.h"
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
 
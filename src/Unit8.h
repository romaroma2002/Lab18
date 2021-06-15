//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include "Unit1.h"
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TButton *Button1;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
 
//---------------------------------------------------------------------------

#ifndef radstudioH
#define radstudioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TTabControl *TabControl1;
	TButton *BtnEdit;
	TButton *BtnDelete;
	TButton *BtnAdd;
	TEdit *EditName;
	TCheckBox *CheckBoxFilterAsistencia;
	TCheckBox *CheckBoxFilterVIP;
	TCheckBox *CheckBoxFilterInscrito;
	TCheckBox *CheckBoxInscrito;
	TCheckBox *CheckBoxVIP;
	TCheckBox *CheckBoxAsistencia;
	void __fastcall FormCreate(TObject *Sender);
    void __fastcall BtnAddClick(TObject *Sender);
    void __fastcall BtnDeleteClick(TObject *Sender);
    void __fastcall BtnEditClick(TObject *Sender);
    void __fastcall CheckBoxFilterAsistenciaClick(TObject *Sender);
    void __fastcall CheckBoxFilterVIPClick(TObject *Sender);
	void __fastcall CheckBoxFilterInscritoClick(TObject *Sender);
private:	// User declarations
   void __fastcall ApplyFilters();
public:		// User declarations
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif

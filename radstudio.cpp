//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "radstudio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm10::FormCreate(TObject *Sender)
{
ADOConnection1->ConnectionString = "Driver={PostgreSQL ODBC Driver};Server=localhost;Port=5432;Database=invitados;Uid=postgres;Pwd=1234;";
	ADOConnection1->LoginPrompt = false;
	try {
		ADOConnection1->Connected = true;
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = "SELECT * FROM invitados";
        ADOQuery1->Open();
    } catch (Exception &e) {
        ShowMessage("Error connecting to database: " + e.Message);
    }

    DataSource1->DataSet = ADOQuery1;
    DBGrid1->DataSource = DataSource1;
}
void __fastcall TForm10::BtnAddClick(TObject *Sender)
{
    ADOQuery1->Append();
    ADOQuery1->FieldByName("Nombre")->AsString = EditName->Text;
    ADOQuery1->FieldByName("Asistencia")->AsBoolean = CheckBoxAsistencia->Checked;
    ADOQuery1->FieldByName("VIP")->AsBoolean = CheckBoxVIP->Checked;
    ADOQuery1->FieldByName("Inscrito")->AsBoolean = CheckBoxInscrito->Checked;
    ADOQuery1->Post();
    ADOQuery1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm10::BtnDeleteClick(TObject *Sender)
{
    if (!ADOQuery1->IsEmpty()) {
        ADOQuery1->Delete();
        ADOQuery1->Refresh();
    }
}
void __fastcall TForm10::BtnEditClick(TObject *Sender)
{
    if (!ADOQuery1->IsEmpty()) {
        ADOQuery1->Edit();
        ADOQuery1->FieldByName("Nombre")->AsString = EditName->Text;
        ADOQuery1->FieldByName("Asistencia")->AsBoolean = CheckBoxAsistencia->Checked;
        ADOQuery1->FieldByName("VIP")->AsBoolean = CheckBoxVIP->Checked;
        ADOQuery1->FieldByName("Inscrito")->AsBoolean = CheckBoxInscrito->Checked;
        ADOQuery1->Post();
        ADOQuery1->Refresh();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm10::ApplyFilters()
{
    String filter = "";

    if (CheckBoxFilterAsistencia->Checked) {
        filter += "Asistencia = 1";
    }
    if (CheckBoxFilterVIP->Checked) {
        if (filter != "") filter += " AND ";
        filter += "VIP = 1";
    }
    if (CheckBoxFilterInscrito->Checked) {
        if (filter != "") filter += " AND ";
        filter += "Inscrito = 1";
    }

    ADOQuery1->Filter = filter;
    ADOQuery1->Filtered = (filter != "");
}
     void __fastcall TForm10::CheckBoxFilterAsistenciaClick(TObject *Sender)
{
    ApplyFilters();
}
         void __fastcall TForm10::CheckBoxFilterInscritoClick(TObject *Sender)
{
    ApplyFilters();
}
void __fastcall TForm10::CheckBoxFilterVIPClick(TObject *Sender)
{
    ApplyFilters();
}
//---------------------------------------------------------------------------


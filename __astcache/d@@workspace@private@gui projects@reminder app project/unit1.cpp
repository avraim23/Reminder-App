//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

const int milliSecondsPerDay = 86400000 ;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	timer->Enabled = false ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::setReminderButtonClick(TObject *Sender)
{
	TDate reminderDate = dateEdit->Date ;
	TTime reminderTime = timeEdit->Time ;
	TDateTime reminderDateTime = reminderDate + reminderTime ;
	TDateTime remainingTime = reminderDateTime - Now() ;
	double remainingTimeInMilliSeconds = static_cast<double> (remainingTime) * milliSecondsPerDay ;
	timer->Interval = remainingTimeInMilliSeconds ;
	timer->Enabled = true ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerTimer(TObject *Sender)
{
	timer->Enabled = false ;
	ShowMessage ( messageEdit->Text ) ;

}
//---------------------------------------------------------------------------

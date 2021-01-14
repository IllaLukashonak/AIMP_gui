#include "MyForm.h"
#include "MyForm1.h"
#include "PlayerConnection.h"
#include "SettingsForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    AIMPgui::MyForm form;
    Application::Run(% form);
}

System::Void AIMPgui::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Interval = System::Convert::ToInt32(System::Configuration::ConfigurationManager::AppSettings["interval"]);
	
	UpdateAll();
	
}

System::Void AIMPgui::MyForm::toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm1^ about_form = gcnew MyForm1();
    about_form->Show(this);
    return System::Void();
}

System::Void AIMPgui::MyForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Visible = true;
	this->TopLevel = true;
    this->notify_icon->Visible = false;
}

System::Void AIMPgui::MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}

System::Void AIMPgui::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (e->CloseReason == CloseReason::UserClosing)
    {
        e->Cancel = true;
        this->Visible = false;
        this->notify_icon->Visible = true;
    }
}

System::Void AIMPgui::MyForm::settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	AIMPgui::SettingsForm^ sett_win = gcnew AIMPgui::SettingsForm;
	sett_win->Show(this);
}

System::Void AIMPgui::MyForm::UpdateAll() {
	String^ temp = L"";
    PlayerConnection::TakeSong();

	if (lb_SongName->Text == PlayerConnection::Wcstos(PlayerConnection::song.title, temp)) return;
	
	String^ artist = PlayerConnection::Wcstos(PlayerConnection::song.artist, temp);
	String^ title = PlayerConnection::Wcstos(PlayerConnection::song.title, temp);

	if (System::Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings["balloon"])) {
		TreyBalloon(artist, title);
	}
	
	UpdateInfo(artist, title);
	SendLcd(artist, title);
}

System::Void AIMPgui::MyForm::UpdateInfo(String^ artist, String^ title) {
	lb_author->Text = artist;
	lb_SongName->Text = title;
}

System::Void AIMPgui::MyForm::SendLcd(String^ artist, String^ title) {
	serialPort1->PortName = System::Configuration::ConfigurationManager::AppSettings["com"];
	serialPort1->Open();
	serialPort1->Write("start_trans|" + artist + "|" + title + "|");
	serialPort1->Close();
}

System::Void AIMPgui::MyForm::TreyBalloon(String^ artist, String^ title) {
	notify_icon->BalloonTipTitle = artist;
	notify_icon->BalloonTipText = title;
	notify_icon->ShowBalloonTip(System::Convert::ToInt32(System::Configuration::ConfigurationManager::AppSettings["balloon_time"]));
}

cli::array<String^>^ AIMPgui::MyForm::available_coms() {
	return serialPort1->GetPortNames();
}

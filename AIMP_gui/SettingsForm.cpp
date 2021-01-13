#include "SettingsForm.h"

#include "MyForm.h"



System::Void AIMPgui::SettingsForm::cb_com_selection_Click(System::Object^ sender, System::EventArgs^ e) {
	AIMPgui::MyForm^ root_form = (AIMPgui::MyForm^)this->Owner;
	cb_com_selection->Items->Clear();
	cli::array<String^>^ coms = root_form->available_coms();

	if (coms->Length == 0) {
		MessageBox::Show(L"No COM ports found");
		return;
	}
	
	for each (String^ com_port in coms) {
		cb_com_selection->Items->Add(com_port);
	}
}

System::Void AIMPgui::SettingsForm::SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	tb_timer_interval->Text = System::Configuration::ConfigurationManager::AppSettings["interval"];
	cb_com_selection->Text = System::Configuration::ConfigurationManager::AppSettings["com"];
	cb_start->Checked = System::Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings["in_tray"]);
	cb_balloon->Checked = System::Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings["balloon"]);
	tb_baloon_time->Text = System::Configuration::ConfigurationManager::AppSettings["balloon_time"];
}

System::Void AIMPgui::SettingsForm::btn_save_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Configuration::Configuration^ config = System::Configuration::ConfigurationManager::OpenExeConfiguration(Application::ExecutablePath);
	config->AppSettings->Settings->Remove("interval");
	
	config->AppSettings->Settings->Remove("com");

	config->AppSettings->Settings->Remove("in_tray");
	config->AppSettings->Settings->Remove("balloon");
	config->AppSettings->Settings->Remove("balloon_time");
	
	config->AppSettings->Settings->Add("interval",tb_timer_interval->Text);
	
	config->AppSettings->Settings->Add("com",cb_com_selection->Text);

	config->AppSettings->Settings->Add("in_tray", System::Convert::ToString(cb_start->Checked));
	config->AppSettings->Settings->Add("balloon",System::Convert::ToString(cb_balloon->Checked));
	config->AppSettings->Settings->Add("balloon_time",tb_baloon_time->Text);
	
	config->Save(System::Configuration::ConfigurationSaveMode::Full);
	System::Configuration::ConfigurationManager::RefreshSection("appSettings");
	Close();
}

System::Void AIMPgui::SettingsForm::btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}

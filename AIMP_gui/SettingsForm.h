#pragma once

namespace AIMPgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ settings_tabs;
	protected:

	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ btn_save;
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_timer_interval;

	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cb_com_selection;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tb_baloon_time;
	private: System::Windows::Forms::CheckBox^ cb_balloon;
	private: System::Windows::Forms::CheckBox^ cb_start;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->settings_tabs = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_timer_interval = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cb_com_selection = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_baloon_time = (gcnew System::Windows::Forms::TextBox());
			this->cb_balloon = (gcnew System::Windows::Forms::CheckBox());
			this->cb_start = (gcnew System::Windows::Forms::CheckBox());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->settings_tabs->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->SuspendLayout();
			// 
			// settings_tabs
			// 
			this->settings_tabs->Appearance = System::Windows::Forms::TabAppearance::Buttons;
			this->settings_tabs->Controls->Add(this->tabPage1);
			this->settings_tabs->Controls->Add(this->tabPage2);
			this->settings_tabs->Controls->Add(this->tabPage3);
			this->settings_tabs->Location = System::Drawing::Point(-2, 0);
			this->settings_tabs->Name = L"settings_tabs";
			this->settings_tabs->SelectedIndex = 0;
			this->settings_tabs->Size = System::Drawing::Size(288, 220);
			this->settings_tabs->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(280, 191);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Main settings";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->label3);
			this->splitContainer1->Panel2->Controls->Add(this->tb_timer_interval);
			this->splitContainer1->Size = System::Drawing::Size(274, 185);
			this->splitContainer1->SplitterDistance = 91;
			this->splitContainer1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Interval of update";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(110, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"milisec";
			// 
			// tb_timer_interval
			// 
			this->tb_timer_interval->Location = System::Drawing::Point(4, 4);
			this->tb_timer_interval->Name = L"tb_timer_interval";
			this->tb_timer_interval->Size = System::Drawing::Size(100, 20);
			this->tb_timer_interval->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(280, 191);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"COM port";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->label2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->cb_com_selection);
			this->splitContainer2->Size = System::Drawing::Size(274, 185);
			this->splitContainer2->SplitterDistance = 91;
			this->splitContainer2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"COM number";
			// 
			// cb_com_selection
			// 
			this->cb_com_selection->FormattingEnabled = true;
			this->cb_com_selection->Location = System::Drawing::Point(3, 1);
			this->cb_com_selection->Name = L"cb_com_selection";
			this->cb_com_selection->Size = System::Drawing::Size(121, 21);
			this->cb_com_selection->TabIndex = 0;
			this->cb_com_selection->Click += gcnew System::EventHandler(this, &SettingsForm::cb_com_selection_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->splitContainer3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(280, 191);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Tray";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(3, 3);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->label4);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->label5);
			this->splitContainer3->Panel2->Controls->Add(this->tb_baloon_time);
			this->splitContainer3->Panel2->Controls->Add(this->cb_balloon);
			this->splitContainer3->Panel2->Controls->Add(this->cb_start);
			this->splitContainer3->Size = System::Drawing::Size(274, 185);
			this->splitContainer3->SplitterDistance = 111;
			this->splitContainer3->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Balloon showed time";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(110, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"milisec";
			// 
			// tb_baloon_time
			// 
			this->tb_baloon_time->Location = System::Drawing::Point(4, 47);
			this->tb_baloon_time->Name = L"tb_baloon_time";
			this->tb_baloon_time->Size = System::Drawing::Size(100, 20);
			this->tb_baloon_time->TabIndex = 2;
			// 
			// cb_balloon
			// 
			this->cb_balloon->AutoSize = true;
			this->cb_balloon->Checked = true;
			this->cb_balloon->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cb_balloon->Location = System::Drawing::Point(4, 25);
			this->cb_balloon->Name = L"cb_balloon";
			this->cb_balloon->Size = System::Drawing::Size(89, 17);
			this->cb_balloon->TabIndex = 1;
			this->cb_balloon->Text = L"Show Baloon";
			this->cb_balloon->UseVisualStyleBackColor = true;
			// 
			// cb_start
			// 
			this->cb_start->AutoSize = true;
			this->cb_start->Location = System::Drawing::Point(4, 1);
			this->cb_start->Name = L"cb_start";
			this->cb_start->Size = System::Drawing::Size(79, 17);
			this->cb_start->TabIndex = 0;
			this->cb_start->Text = L"Start in tray";
			this->cb_start->UseVisualStyleBackColor = true;
			// 
			// btn_save
			// 
			this->btn_save->Location = System::Drawing::Point(116, 226);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(75, 23);
			this->btn_save->TabIndex = 1;
			this->btn_save->Text = L"Save";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &SettingsForm::btn_save_Click);
			// 
			// btn_close
			// 
			this->btn_close->Location = System::Drawing::Point(197, 226);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(75, 23);
			this->btn_close->TabIndex = 2;
			this->btn_close->Text = L"Close";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &SettingsForm::btn_close_Click);
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->btn_save);
			this->Controls->Add(this->settings_tabs);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SettingsForm";
			this->Text = L"SettingsForm";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->settings_tabs->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void cb_com_selection_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e);
};
}

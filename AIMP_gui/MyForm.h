#pragma once
namespace AIMPgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			if (System::Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings["in_tray"])){
				this->Visible = false;
			}
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ pl_Main;

	private: System::Windows::Forms::Label^ lb_author;
	private: System::Windows::Forms::Label^ lb_SongName;
	private: System::Windows::Forms::Button^ btn_reload;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::NotifyIcon^ notify_icon;
	private: System::Windows::Forms::ContextMenuStrip^ context_menu_trey;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ updateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;



	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pl_Main = (gcnew System::Windows::Forms::Panel());
			this->lb_SongName = (gcnew System::Windows::Forms::Label());
			this->lb_author = (gcnew System::Windows::Forms::Label());
			this->btn_reload = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->notify_icon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->context_menu_trey = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->settingsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pl_Main->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->context_menu_trey->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pl_Main
			// 
			this->pl_Main->Controls->Add(this->lb_SongName);
			this->pl_Main->Controls->Add(this->lb_author);
			this->pl_Main->Location = System::Drawing::Point(13, 27);
			this->pl_Main->Name = L"pl_Main";
			this->pl_Main->Size = System::Drawing::Size(291, 103);
			this->pl_Main->TabIndex = 2;
			// 
			// lb_SongName
			// 
			this->lb_SongName->Location = System::Drawing::Point(4, 52);
			this->lb_SongName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_SongName->Name = L"lb_SongName";
			this->lb_SongName->Size = System::Drawing::Size(283, 16);
			this->lb_SongName->TabIndex = 2;
			this->lb_SongName->Text = L"Song Name";
			this->lb_SongName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lb_author
			// 
			this->lb_author->Location = System::Drawing::Point(4, 36);
			this->lb_author->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_author->Name = L"lb_author";
			this->lb_author->Size = System::Drawing::Size(283, 16);
			this->lb_author->TabIndex = 1;
			this->lb_author->Text = L"Author";
			this->lb_author->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_reload
			// 
			this->btn_reload->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_reload.Image")));
			this->btn_reload->Location = System::Drawing::Point(270, 136);
			this->btn_reload->Name = L"btn_reload";
			this->btn_reload->Size = System::Drawing::Size(34, 34);
			this->btn_reload->TabIndex = 3;
			this->btn_reload->UseVisualStyleBackColor = true;
			this->btn_reload->Click += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem1,
					this->settingsToolStripMenuItem, this->exitToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(316, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(52, 20);
			this->toolStripMenuItem1->Text = L"About";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::settingsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem1->Text = L"Exit";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// notify_icon
			// 
			this->notify_icon->ContextMenuStrip = this->context_menu_trey;
			this->notify_icon->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notify_icon.Icon")));
			this->notify_icon->Text = L"LCDAIMP";
			this->notify_icon->DoubleClick += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// context_menu_trey
			// 
			this->context_menu_trey->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->openToolStripMenuItem,
					this->updateToolStripMenuItem, this->toolStripSeparator1, this->settingsToolStripMenuItem1, this->toolStripSeparator2, this->aboutToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->context_menu_trey->Name = L"context_menu_trey";
			this->context_menu_trey->Size = System::Drawing::Size(117, 126);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// updateToolStripMenuItem
			// 
			this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
			this->updateToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->updateToolStripMenuItem->Text = L"Update";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(113, 6);
			// 
			// settingsToolStripMenuItem1
			// 
			this->settingsToolStripMenuItem1->Name = L"settingsToolStripMenuItem1";
			this->settingsToolStripMenuItem1->Size = System::Drawing::Size(116, 22);
			this->settingsToolStripMenuItem1->Text = L"Settings";
			this->settingsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::settingsToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(113, 6);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(316, 180);
			this->Controls->Add(this->btn_reload);
			this->Controls->Add(this->pl_Main);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"LCDAIMP";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->pl_Main->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->context_menu_trey->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void settingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void UpdateAll();

	private: System::Void UpdateInfo(String^ artist, String^ title);
	private: System::Void SendLcd(char* artist, char* title);
	private: System::Void TreyBalloon(String^ artist, String^ title);
		
	
	public: cli::array<String^>^ available_coms();
	
};
}

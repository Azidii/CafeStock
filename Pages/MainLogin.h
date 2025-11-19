#pragma once
ref class Menumain;



namespace CafeStock {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainLogin
	/// </summary>
	public ref class MainLogin : public System::Windows::Forms::Form
	{
	public:
		MainLogin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainLogin()
		{
			if (components)
			{
				if (components) delete components;
			}
		}

	protected:
	private: System::Void bttnLogin_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e);






	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblRegister;
	private: System::Windows::Forms::PictureBox^ picBoxPassword;


	private: System::Windows::Forms::PictureBox^ picBoxUsername;

	private: System::Windows::Forms::Button^ bttnLogin;
	private: System::Windows::Forms::TextBox^ txtPassword;



	private: System::Windows::Forms::TextBox^ txtUsername;

	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblUsername;
	private: System::Windows::Forms::Label^ lblAdmin;





	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ bttnMinimize;
	private: System::Windows::Forms::Button^ bttnExit;
	private: System::Windows::Forms::CheckBox^ chkbxShowPass;
	private: System::Windows::Forms::PictureBox^ pictureBox1;







	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainLogin::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->chkbxShowPass = (gcnew System::Windows::Forms::CheckBox());
			this->bttnMinimize = (gcnew System::Windows::Forms::Button());
			this->bttnExit = (gcnew System::Windows::Forms::Button());
			this->lblRegister = (gcnew System::Windows::Forms::Label());
			this->picBoxPassword = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxUsername = (gcnew System::Windows::Forms::PictureBox());
			this->bttnLogin = (gcnew System::Windows::Forms::Button());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblAdmin = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxPassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxUsername))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(975, 582);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(76, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(298, 419);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->chkbxShowPass);
			this->panel2->Controls->Add(this->bttnMinimize);
			this->panel2->Controls->Add(this->bttnExit);
			this->panel2->Controls->Add(this->lblRegister);
			this->panel2->Controls->Add(this->picBoxPassword);
			this->panel2->Controls->Add(this->picBoxUsername);
			this->panel2->Controls->Add(this->bttnLogin);
			this->panel2->Controls->Add(this->txtPassword);
			this->panel2->Controls->Add(this->txtUsername);
			this->panel2->Controls->Add(this->lblPassword);
			this->panel2->Controls->Add(this->lblUsername);
			this->panel2->Controls->Add(this->lblAdmin);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel2->Location = System::Drawing::Point(451, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(524, 582);
			this->panel2->TabIndex = 3;
			// 
			// chkbxShowPass
			// 
			this->chkbxShowPass->AutoSize = true;
			this->chkbxShowPass->BackColor = System::Drawing::Color::Transparent;
			this->chkbxShowPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chkbxShowPass->Location = System::Drawing::Point(297, 327);
			this->chkbxShowPass->Name = L"chkbxShowPass";
			this->chkbxShowPass->Size = System::Drawing::Size(101, 17);
			this->chkbxShowPass->TabIndex = 18;
			this->chkbxShowPass->Text = L"Show password";
			this->chkbxShowPass->UseVisualStyleBackColor = false;
			this->chkbxShowPass->CheckedChanged += gcnew System::EventHandler(this, &MainLogin::chkbxShowPass_CheckedChanged);
			// 
			// bttnMinimize
			// 
			this->bttnMinimize->BackColor = System::Drawing::Color::Transparent;
			this->bttnMinimize->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bttnMinimize->FlatAppearance->BorderSize = 0;
			this->bttnMinimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bttnMinimize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttnMinimize->ForeColor = System::Drawing::Color::Red;
			this->bttnMinimize->Location = System::Drawing::Point(448, 0);
			this->bttnMinimize->Name = L"bttnMinimize";
			this->bttnMinimize->Size = System::Drawing::Size(35, 35);
			this->bttnMinimize->TabIndex = 12;
			this->bttnMinimize->Text = L"—";
			this->bttnMinimize->UseVisualStyleBackColor = false;
			this->bttnMinimize->Click += gcnew System::EventHandler(this, &MainLogin::BttnMinimize_Click);
			// 
			// bttnExit
			// 
			this->bttnExit->BackColor = System::Drawing::Color::Transparent;
			this->bttnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bttnExit->FlatAppearance->BorderSize = 0;
			this->bttnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bttnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttnExit->ForeColor = System::Drawing::Color::Red;
			this->bttnExit->Location = System::Drawing::Point(489, 0);
			this->bttnExit->Name = L"bttnExit";
			this->bttnExit->Size = System::Drawing::Size(35, 35);
			this->bttnExit->TabIndex = 11;
			this->bttnExit->Text = L"X";
			this->bttnExit->UseVisualStyleBackColor = false;
			this->bttnExit->Click += gcnew System::EventHandler(this, &MainLogin::BttnExit_Click);
			// 
			// lblRegister
			// 
			this->lblRegister->AutoSize = true;
			this->lblRegister->BackColor = System::Drawing::Color::Transparent;
			this->lblRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lblRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.5F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblRegister->ForeColor = System::Drawing::Color::Firebrick;
			this->lblRegister->Location = System::Drawing::Point(185, 452);
			this->lblRegister->Name = L"lblRegister";
			this->lblRegister->Size = System::Drawing::Size(155, 19);
			this->lblRegister->TabIndex = 10;
			this->lblRegister->Text = L"Don\'t have an account\?";
			this->lblRegister->Click += gcnew System::EventHandler(this, &MainLogin::label7_Click);
			// 
			// picBoxPassword
			// 
			this->picBoxPassword->BackColor = System::Drawing::Color::Transparent;
			this->picBoxPassword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxPassword.Image")));
			this->picBoxPassword->Location = System::Drawing::Point(90, 292);
			this->picBoxPassword->Name = L"picBoxPassword";
			this->picBoxPassword->Size = System::Drawing::Size(30, 30);
			this->picBoxPassword->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picBoxPassword->TabIndex = 9;
			this->picBoxPassword->TabStop = false;
			// 
			// picBoxUsername
			// 
			this->picBoxUsername->BackColor = System::Drawing::Color::Transparent;
			this->picBoxUsername->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxUsername.Image")));
			this->picBoxUsername->Location = System::Drawing::Point(90, 212);
			this->picBoxUsername->Name = L"picBoxUsername";
			this->picBoxUsername->Size = System::Drawing::Size(30, 30);
			this->picBoxUsername->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picBoxUsername->TabIndex = 8;
			this->picBoxUsername->TabStop = false;
			// 
			// bttnLogin
			// 
			this->bttnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bttnLogin->FlatAppearance->BorderSize = 0;
			this->bttnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bttnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttnLogin->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->bttnLogin->Location = System::Drawing::Point(187, 382);
			this->bttnLogin->Name = L"bttnLogin";
			this->bttnLogin->Size = System::Drawing::Size(150, 40);
			this->bttnLogin->TabIndex = 6;
			this->bttnLogin->Text = L"Login";
			this->bttnLogin->UseVisualStyleBackColor = false;
			this->bttnLogin->Click += gcnew System::EventHandler(this, &MainLogin::bttnLogin_Click);
			// 
			// txtPassword
			// 
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(130, 292);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(268, 29);
			this->txtPassword->TabIndex = 5;
			this->txtPassword->UseSystemPasswordChar = true;
			this->txtPassword->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainLogin::txtPassword_KeyDown);
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(130, 216);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(268, 29);
			this->txtUsername->TabIndex = 4;
			this->txtUsername->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainLogin::txtUsername_KeyDown);
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->BackColor = System::Drawing::Color::Transparent;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPassword->Location = System::Drawing::Point(143, 268);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(82, 21);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Password";
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->BackColor = System::Drawing::Color::Transparent;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsername->Location = System::Drawing::Point(141, 192);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(87, 21);
			this->lblUsername->TabIndex = 2;
			this->lblUsername->Text = L"Username";
			// 
			// lblAdmin
			// 
			this->lblAdmin->AutoSize = true;
			this->lblAdmin->BackColor = System::Drawing::Color::Transparent;
			this->lblAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 26.25F, System::Drawing::FontStyle::Bold));
			this->lblAdmin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblAdmin->Location = System::Drawing::Point(208, 112);
			this->lblAdmin->Name = L"lblAdmin";
			this->lblAdmin->Size = System::Drawing::Size(108, 47);
			this->lblAdmin->TabIndex = 1;
			this->lblAdmin->Text = L"Login\r\n";
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-390, 227);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(362, 39);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Login";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(975, 582);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"MainLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainLogin";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxPassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxUsername))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void BttnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result =
		System::Windows::Forms::MessageBox::Show(
			"Are you sure you want to exit?", // Message
			"Exit Application",              // Title
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Question
		);

	// Check if the user clicked "Yes"
	if (result == System::Windows::Forms::DialogResult::Yes) {
		System::Windows::Forms::Application::Exit(); // Exit the application
	}
}
private: System::Void BttnMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
}
private: System::Void chkbxShowPass_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (chkbxShowPass->Checked) {
		txtPassword->UseSystemPasswordChar = false; 
	}
	else {
		txtPassword->UseSystemPasswordChar = true;  
	}
}
private: System::Void txtUsername_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Enter)
	{
		bttnLogin->PerformClick();
	}
}
private: System::Void txtPassword_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Enter)
	{
		bttnLogin->PerformClick();
	}
}
};
}

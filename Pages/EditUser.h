#pragma once
namespace CafeStock {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for EditUser
	/// </summary>
	public ref class EditUser : public System::Windows::Forms::Form
	{
	public:
		EditUser(int selectedUserID, String^ username, String^ password) {
			InitializeComponent();
			userID = selectedUserID;
			txtUsername->Text = username;
			txtPass->Text = password;
		}

	private:
		int userID;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnBack;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPass;

	private: System::Windows::Forms::Label^ lblQuant;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ txtUsername;

	private: System::Windows::Forms::Label^ lblName;
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditUser::typeid));
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->lblQuant = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBack.BackgroundImage")));
			this->btnBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBack->FlatAppearance->BorderSize = 0;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->ForeColor = System::Drawing::Color::Transparent;
			this->btnBack->Location = System::Drawing::Point(12, 12);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(35, 35);
			this->btnBack->TabIndex = 25;
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &EditUser::btnBack_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 73);
			this->label1->Margin = System::Windows::Forms::Padding(3, 41, 3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(322, 36);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Edit User";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtPass
			// 
			this->txtPass->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPass->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtPass->Location = System::Drawing::Point(34, 235);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(284, 29);
			this->txtPass->TabIndex = 23;
			// 
			// lblQuant
			// 
			this->lblQuant->AutoSize = true;
			this->lblQuant->BackColor = System::Drawing::Color::Transparent;
			this->lblQuant->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblQuant->Location = System::Drawing::Point(29, 207);
			this->lblQuant->Name = L"lblQuant";
			this->lblQuant->Size = System::Drawing::Size(97, 25);
			this->lblQuant->TabIndex = 22;
			this->lblQuant->Text = L"Password";
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSave->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnSave->Location = System::Drawing::Point(84, 292);
			this->btnSave->Margin = System::Windows::Forms::Padding(75, 3, 75, 41);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(178, 45);
			this->btnSave->TabIndex = 17;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &EditUser::btnSave_Click);
			// 
			// txtUsername
			// 
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(34, 155);
			this->txtUsername->Margin = System::Windows::Forms::Padding(19, 3, 19, 15);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(284, 29);
			this->txtUsername->TabIndex = 21;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(29, 127);
			this->lblName->Margin = System::Windows::Forms::Padding(20, 0, 3, 0);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(101, 25);
			this->lblName->TabIndex = 18;
			this->lblName->Text = L"Username";
			// 
			// EditUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(346, 432);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->lblQuant);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->lblName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"EditUser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditUser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show a confirmation dialog
		System::Windows::Forms::DialogResult result =
			System::Windows::Forms::MessageBox::Show(
				"Close without saving changes?", // Message
				"Save Changes",              // Title
				System::Windows::Forms::MessageBoxButtons::YesNo,
				System::Windows::Forms::MessageBoxIcon::Question
			);
		// Check if the user clicked "Yes"
		if (result == System::Windows::Forms::DialogResult::Yes) {
			this->Close(); // Close EditInventory
		}
	}
};
}

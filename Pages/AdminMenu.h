#include "Dashboard.h"
#include "InventoryMenu.h"
#include "HistoryControll.h" 
#include "AdminUsers.h"
ref class MainLogin;

#pragma once

namespace CafeStock {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminMenu
	/// </summary>
	public ref class AdminMenu : public System::Windows::Forms::Form
	{
	public:
		AdminMenu(void)
		{
			InitializeComponent();
			LoadUserControl(gcnew Dashboard("admin", true));
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->btnAdDash->MouseEnter += gcnew System::EventHandler(this, &AdminMenu::btnAdDash_MouseEnter);
			this->btnAdDash->MouseLeave += gcnew System::EventHandler(this, &AdminMenu::btnAdDash_MouseLeave);
			this->btnAdInventory->MouseEnter += gcnew System::EventHandler(this, &AdminMenu::btnAdInventory_MouseEnter);
			this->btnAdInventory->MouseLeave += gcnew System::EventHandler(this, &AdminMenu::btnAdInventory_MouseLeave);
			this->btnAdHistory->MouseEnter += gcnew System::EventHandler(this, &AdminMenu::btnAdHistory_MouseEnter);
			this->btnAdHistory->MouseLeave += gcnew System::EventHandler(this, &AdminMenu::btnAdHistory_MouseLeave);
			this->btnAdLogout->MouseEnter += gcnew System::EventHandler(this, &AdminMenu::btnAdLogout_MouseEnter);
			this->btnAdLogout->MouseLeave += gcnew System::EventHandler(this, &AdminMenu::btnAdLogout_MouseLeave);
			this->btnUsers->MouseEnter += gcnew System::EventHandler(this, &AdminMenu::btnUsers_MouseEnter);
			this->btnUsers->MouseLeave += gcnew System::EventHandler(this, &AdminMenu::btnUsers_MouseLeave);
			this->AllowDrop = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Void btnAdLogout_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ btnAdDash;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnAdInventory;

	private: System::Windows::Forms::Panel^ panel7;

	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ btnAdHistory;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btnUsers;
	private: System::Windows::Forms::Button^ btnAdLogout;



	private: System::Windows::Forms::Panel^ mainPanel;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminMenu::typeid));
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnAdDash = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnUsers = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnAdInventory = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->btnAdHistory = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->btnAdLogout = (gcnew System::Windows::Forms::Button());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flowLayoutPanel1.BackgroundImage")));
			this->flowLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->flowLayoutPanel1->Controls->Add(this->pictureBox1);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel8);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->flowLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(217, 544);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(214, 98);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Transparent;
			this->panel5->Controls->Add(this->btnAdDash);
			this->panel5->Location = System::Drawing::Point(3, 107);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(214, 50);
			this->panel5->TabIndex = 4;
			// 
			// btnAdDash
			// 
			this->btnAdDash->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->btnAdDash->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnAdDash->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdDash->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdDash->ForeColor = System::Drawing::Color::White;
			this->btnAdDash->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdDash.Image")));
			this->btnAdDash->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAdDash->Location = System::Drawing::Point(0, 4);
			this->btnAdDash->Name = L"btnAdDash";
			this->btnAdDash->Size = System::Drawing::Size(214, 43);
			this->btnAdDash->TabIndex = 2;
			this->btnAdDash->Text = L"Dashboard";
			this->btnAdDash->UseVisualStyleBackColor = false;
			this->btnAdDash->Click += gcnew System::EventHandler(this, &AdminMenu::btnAdDash_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->btnUsers);
			this->panel2->Location = System::Drawing::Point(3, 163);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(214, 50);
			this->panel2->TabIndex = 9;
			// 
			// btnUsers
			// 
			this->btnUsers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->btnUsers->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUsers->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUsers->ForeColor = System::Drawing::Color::White;
			this->btnUsers->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUsers.Image")));
			this->btnUsers->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnUsers->Location = System::Drawing::Point(0, 4);
			this->btnUsers->Name = L"btnUsers";
			this->btnUsers->Size = System::Drawing::Size(214, 43);
			this->btnUsers->TabIndex = 2;
			this->btnUsers->Text = L"Users";
			this->btnUsers->UseVisualStyleBackColor = false;
			this->btnUsers->Click += gcnew System::EventHandler(this, &AdminMenu::btnUsers_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->btnAdInventory);
			this->panel1->Location = System::Drawing::Point(3, 219);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(214, 50);
			this->panel1->TabIndex = 5;
			// 
			// btnAdInventory
			// 
			this->btnAdInventory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->btnAdInventory->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnAdInventory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdInventory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdInventory->ForeColor = System::Drawing::Color::White;
			this->btnAdInventory->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdInventory.Image")));
			this->btnAdInventory->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAdInventory->Location = System::Drawing::Point(0, 4);
			this->btnAdInventory->Name = L"btnAdInventory";
			this->btnAdInventory->Size = System::Drawing::Size(214, 43);
			this->btnAdInventory->TabIndex = 2;
			this->btnAdInventory->Text = L"Inventory Menu";
			this->btnAdInventory->UseVisualStyleBackColor = false;
			this->btnAdInventory->Click += gcnew System::EventHandler(this, &AdminMenu::btnAdInventory_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Controls->Add(this->btnAdHistory);
			this->panel7->Location = System::Drawing::Point(3, 275);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(214, 50);
			this->panel7->TabIndex = 7;
			// 
			// btnAdHistory
			// 
			this->btnAdHistory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->btnAdHistory->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnAdHistory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdHistory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdHistory->ForeColor = System::Drawing::Color::White;
			this->btnAdHistory->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdHistory.Image")));
			this->btnAdHistory->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAdHistory->Location = System::Drawing::Point(0, 4);
			this->btnAdHistory->Name = L"btnAdHistory";
			this->btnAdHistory->Size = System::Drawing::Size(214, 43);
			this->btnAdHistory->TabIndex = 3;
			this->btnAdHistory->Text = L"History";
			this->btnAdHistory->UseVisualStyleBackColor = false;
			this->btnAdHistory->Click += gcnew System::EventHandler(this, &AdminMenu::btnAdHistory_Click);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Transparent;
			this->panel8->Controls->Add(this->btnAdLogout);
			this->panel8->Location = System::Drawing::Point(3, 331);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(214, 50);
			this->panel8->TabIndex = 8;
			// 
			// btnAdLogout
			// 
			this->btnAdLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->btnAdLogout->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnAdLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdLogout->ForeColor = System::Drawing::Color::White;
			this->btnAdLogout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdLogout.Image")));
			this->btnAdLogout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAdLogout->Location = System::Drawing::Point(0, 3);
			this->btnAdLogout->Name = L"btnAdLogout";
			this->btnAdLogout->Size = System::Drawing::Size(214, 43);
			this->btnAdLogout->TabIndex = 2;
			this->btnAdLogout->Text = L"Logout";
			this->btnAdLogout->UseVisualStyleBackColor = false;
			this->btnAdLogout->Click += gcnew System::EventHandler(this, &AdminMenu::btnAdLogout_Click);
			// 
			// mainPanel
			// 
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(217, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(745, 544);
			this->mainPanel->TabIndex = 8;
			// 
			// AdminMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(962, 544);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->flowLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AdminMenu";
			this->Text = L"AdminMenu";
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private:
	void LoadUserControl(System::Windows::Forms::UserControl^ control) {
		mainPanel->Controls->Clear(); // Clear any existing controls
		control->Dock = System::Windows::Forms::DockStyle::Fill; // Fill the panel
		mainPanel->Controls->Add(control); // Add the new control
	}
private: System::Void btnAdDash_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadUserControl(gcnew Dashboard("admin", true));
}
private: System::Void btnAdInventory_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadUserControl(gcnew InventoryMenu());
}
private: System::Void btnAdHistory_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadUserControl(gcnew HistoryControll());
}
private: System::Void btnUsers_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadUserControl(gcnew AdminUsers());
}
private: System::Void btnAdDash_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnAdDash->BackColor = System::Drawing::Color::Black;
}
private: System::Void btnAdDash_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnAdDash->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
}
private: System::Void btnAdInventory_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnAdInventory->BackColor = System::Drawing::Color::Black;
}
private: System::Void btnAdInventory_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnAdInventory->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
}
private: System::Void btnAdHistory_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnAdHistory->BackColor = System::Drawing::Color::Black;
}
private: System::Void btnAdHistory_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnAdHistory->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
}
private: System::Void btnAdLogout_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnAdLogout->BackColor = System::Drawing::Color::Black;
}
private: System::Void btnAdLogout_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnAdLogout->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
}
private: System::Void btnUsers_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnUsers->BackColor = System::Drawing::Color::Black;
}
private: System::Void btnUsers_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnUsers->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
}
};
}

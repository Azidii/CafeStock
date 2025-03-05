#include "InventoryMenu.h"
#pragma once

namespace CafeStock {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PopupEdit : public System::Windows::Forms::Form
	{
	public:
		PopupEdit(void)
		{
			InitializeComponent();
			
			// Populate the ComboBox with predefined values
			this->cmbItemType->Items->Add("Beverage");
			this->cmbItemType->Items->Add("Snacks");
			this->cmbItemType->Items->Add("Fruits");
			this->cmbItemType->Items->Add("Dairy Products");
			this->cmbItemType->Items->Add("Bakery Items");
			this->cmbItemType->Items->Add("Main Courses");
			this->cmbItemType->Items->Add("Frozen Foods");
			this->cmbItemType->Items->Add("Vegetables");
			this->cmbItemType->Items->Add("Condiments & Sauces");
			this->cmbItemType->Items->Add("Disposable Items");
			this->cmbItemType->Items->Add("Specialty Items");
			this->cmbItemType->Items->Add("Cleaning Supplies");

			// Set default selection (optional)
			this->cmbItemType->SelectedIndex = 0;
			
		}

	protected:

		~PopupEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		System::Void UpdateInventoryCapacity();
	private: System::Windows::Forms::Button^ PopupBack;
	private: System::Windows::Forms::Button^ bttnMinimize;
	private: System::Windows::Forms::Button^ bttnExit;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txtQuantity;
	private: System::Windows::Forms::Label^ lblQuant;
	public: System::Windows::Forms::Button^ bttnAdd;
	private:

	private:


	private: System::Windows::Forms::TextBox^ txtItemName;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::ComboBox^ cmbItemType;
	private: System::Windows::Forms::Label^ lblType;

	protected:
	protected:
	protected:
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Void PopupBack_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void bttnAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void editCombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	protected:
	private:
	
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PopupEdit::typeid));
			this->PopupBack = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->lblQuant = (gcnew System::Windows::Forms::Label());
			this->bttnAdd = (gcnew System::Windows::Forms::Button());
			this->txtItemName = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->cmbItemType = (gcnew System::Windows::Forms::ComboBox());
			this->lblType = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// PopupBack
			// 
			this->PopupBack->BackColor = System::Drawing::Color::Transparent;
			this->PopupBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PopupBack.BackgroundImage")));
			this->PopupBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PopupBack->FlatAppearance->BorderSize = 0;
			this->PopupBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PopupBack->ForeColor = System::Drawing::Color::Black;
			this->PopupBack->Location = System::Drawing::Point(12, 12);
			this->PopupBack->Name = L"PopupBack";
			this->PopupBack->Size = System::Drawing::Size(35, 35);
			this->PopupBack->TabIndex = 11;
			this->PopupBack->UseVisualStyleBackColor = false;
			this->PopupBack->Click += gcnew System::EventHandler(this, &PopupEdit::PopupBack_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 54);
			this->label1->Margin = System::Windows::Forms::Padding(3, 41, 3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(322, 36);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Add Item";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtQuantity
			// 
			this->txtQuantity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtQuantity->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtQuantity->Location = System::Drawing::Point(34, 280);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(104, 29);
			this->txtQuantity->TabIndex = 22;
			this->txtQuantity->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &PopupEdit::txtQuantity_KeyPress);
			// 
			// lblQuant
			// 
			this->lblQuant->AutoSize = true;
			this->lblQuant->BackColor = System::Drawing::Color::Transparent;
			this->lblQuant->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblQuant->Location = System::Drawing::Point(29, 252);
			this->lblQuant->Name = L"lblQuant";
			this->lblQuant->Size = System::Drawing::Size(94, 25);
			this->lblQuant->TabIndex = 21;
			this->lblQuant->Text = L"Quantity:";
			// 
			// bttnAdd
			// 
			this->bttnAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bttnAdd->FlatAppearance->BorderSize = 0;
			this->bttnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bttnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttnAdd->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->bttnAdd->Location = System::Drawing::Point(84, 337);
			this->bttnAdd->Margin = System::Windows::Forms::Padding(75, 3, 75, 41);
			this->bttnAdd->Name = L"bttnAdd";
			this->bttnAdd->Size = System::Drawing::Size(178, 45);
			this->bttnAdd->TabIndex = 16;
			this->bttnAdd->Text = L"Add";
			this->bttnAdd->UseVisualStyleBackColor = false;
			this->bttnAdd->Click += gcnew System::EventHandler(this, &PopupEdit::bttnAdd_Click);
			// 
			// txtItemName
			// 
			this->txtItemName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtItemName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtItemName->Location = System::Drawing::Point(34, 136);
			this->txtItemName->Margin = System::Windows::Forms::Padding(19, 3, 19, 15);
			this->txtItemName->Name = L"txtItemName";
			this->txtItemName->Size = System::Drawing::Size(284, 29);
			this->txtItemName->TabIndex = 20;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(29, 108);
			this->lblName->Margin = System::Windows::Forms::Padding(20, 0, 3, 0);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(114, 25);
			this->lblName->TabIndex = 17;
			this->lblName->Text = L"Item Name:";
			// 
			// cmbItemType
			// 
			this->cmbItemType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbItemType->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->cmbItemType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbItemType->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->cmbItemType->FormattingEnabled = true;
			this->cmbItemType->Location = System::Drawing::Point(34, 208);
			this->cmbItemType->Margin = System::Windows::Forms::Padding(3, 3, 3, 15);
			this->cmbItemType->Name = L"cmbItemType";
			this->cmbItemType->Size = System::Drawing::Size(214, 29);
			this->cmbItemType->TabIndex = 19;
			// 
			// lblType
			// 
			this->lblType->AutoSize = true;
			this->lblType->BackColor = System::Drawing::Color::Transparent;
			this->lblType->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblType->Location = System::Drawing::Point(29, 180);
			this->lblType->Name = L"lblType";
			this->lblType->Size = System::Drawing::Size(104, 25);
			this->lblType->TabIndex = 18;
			this->lblType->Text = L"Item Type:";
			// 
			// PopupEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(346, 432);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtQuantity);
			this->Controls->Add(this->lblQuant);
			this->Controls->Add(this->bttnAdd);
			this->Controls->Add(this->txtItemName);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->cmbItemType);
			this->Controls->Add(this->lblType);
			this->Controls->Add(this->PopupBack);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"PopupEdit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PopupEdit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void bttnExit_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void bttnMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblName_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtItemName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblType_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtQuantity_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
		e->Handled = true; // Suppress the key
	}
}
};
}

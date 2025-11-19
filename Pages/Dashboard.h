#pragma once
#include "Dashboard.h"
#include "../EnvConfig.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;


namespace CafeStock {

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::UserControl
	{
	private:
		String^ connString = CafeStockConfig::EnvConfig::GetConnectionString();

	public:
		Dashboard(String^ username, bool isAdmin)
		{
			InitializeComponent();
			LoadCapacity();
			LoadUserCount();

			if (isAdmin) {
				LoadUserCount(); // Show number of users for admin
				lblNumUsers->Visible = true;
				lblUsers->Visible = true;
			}
			else {
				lblNumUsers->Visible = false; // Hide the label for regular users
				lblUsers->Visible = false;
				picUser->Visible = false;
			}

			DisplayWelcomeMessage(username, isAdmin);
			//
			//TODO: Add the constructor code here
			//
			//this->lblText->BackColor = System::Drawing::Color::Transparent;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitle;

	protected:
	protected:
	private: System::Windows::Forms::Label^ lblHeader;
	private: System::Windows::Forms::Button^ bttnExit;

	private: System::Windows::Forms::Button^ bttnMinimize;
	private: System::Windows::Forms::Label^ lblNumUsers;

	private: System::Windows::Forms::Label^ lblCapacity;
	private: System::Windows::Forms::Label^ lblUsers;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ picUser;
	private: System::Windows::Forms::PictureBox^ picStore;





	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblHeader = (gcnew System::Windows::Forms::Label());
			this->bttnExit = (gcnew System::Windows::Forms::Button());
			this->bttnMinimize = (gcnew System::Windows::Forms::Button());
			this->lblNumUsers = (gcnew System::Windows::Forms::Label());
			this->lblCapacity = (gcnew System::Windows::Forms::Label());
			this->lblUsers = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->picUser = (gcnew System::Windows::Forms::PictureBox());
			this->picStore = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUser))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStore))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->BackColor = System::Drawing::Color::Transparent;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblTitle->Location = System::Drawing::Point(54, 101);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(248, 37);
			this->lblTitle->TabIndex = 5;
			this->lblTitle->Text = L"Welcome User!";
			// 
			// lblHeader
			// 
			this->lblHeader->AutoSize = true;
			this->lblHeader->BackColor = System::Drawing::Color::Transparent;
			this->lblHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblHeader->Location = System::Drawing::Point(113, 390);
			this->lblHeader->Name = L"lblHeader";
			this->lblHeader->Size = System::Drawing::Size(212, 29);
			this->lblHeader->TabIndex = 3;
			this->lblHeader->Text = L"Storage Capacity";
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
			this->bttnExit->Location = System::Drawing::Point(710, 0);
			this->bttnExit->Name = L"bttnExit";
			this->bttnExit->Size = System::Drawing::Size(35, 35);
			this->bttnExit->TabIndex = 8;
			this->bttnExit->Text = L"X";
			this->bttnExit->UseVisualStyleBackColor = false;
			this->bttnExit->Click += gcnew System::EventHandler(this, &Dashboard::bttnExit_Click);
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
			this->bttnMinimize->Location = System::Drawing::Point(669, 0);
			this->bttnMinimize->Name = L"bttnMinimize";
			this->bttnMinimize->Size = System::Drawing::Size(35, 35);
			this->bttnMinimize->TabIndex = 9;
			this->bttnMinimize->Text = L"—";
			this->bttnMinimize->UseVisualStyleBackColor = false;
			this->bttnMinimize->Click += gcnew System::EventHandler(this, &Dashboard::bttnMinimize_Click);
			// 
			// lblNumUsers
			// 
			this->lblNumUsers->AutoSize = true;
			this->lblNumUsers->BackColor = System::Drawing::Color::Transparent;
			this->lblNumUsers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNumUsers->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblNumUsers->Location = System::Drawing::Point(411, 434);
			this->lblNumUsers->Name = L"lblNumUsers";
			this->lblNumUsers->Size = System::Drawing::Size(93, 29);
			this->lblNumUsers->TabIndex = 10;
			this->lblNumUsers->Text = L"[users]";
			// 
			// lblCapacity
			// 
			this->lblCapacity->AutoSize = true;
			this->lblCapacity->BackColor = System::Drawing::Color::Transparent;
			this->lblCapacity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCapacity->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblCapacity->Location = System::Drawing::Point(113, 434);
			this->lblCapacity->Name = L"lblCapacity";
			this->lblCapacity->Size = System::Drawing::Size(124, 29);
			this->lblCapacity->TabIndex = 11;
			this->lblCapacity->Text = L"[capacity]";
			// 
			// lblUsers
			// 
			this->lblUsers->AutoSize = true;
			this->lblUsers->BackColor = System::Drawing::Color::Transparent;
			this->lblUsers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUsers->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblUsers->Location = System::Drawing::Point(411, 390);
			this->lblUsers->Name = L"lblUsers";
			this->lblUsers->Size = System::Drawing::Size(217, 29);
			this->lblUsers->TabIndex = 12;
			this->lblUsers->Text = L"Registered Users";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(57, 152);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(633, 140);
			this->label1->TabIndex = 13;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(56, 331);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(204, 29);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Inventory Status:";
			// 
			// picUser
			// 
			this->picUser->BackColor = System::Drawing::Color::Transparent;
			this->picUser->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picUser.Image")));
			this->picUser->Location = System::Drawing::Point(358, 390);
			this->picUser->Name = L"picUser";
			this->picUser->Size = System::Drawing::Size(47, 38);
			this->picUser->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picUser->TabIndex = 15;
			this->picUser->TabStop = false;
			// 
			// picStore
			// 
			this->picStore->BackColor = System::Drawing::Color::Transparent;
			this->picStore->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picStore.Image")));
			this->picStore->Location = System::Drawing::Point(61, 381);
			this->picStore->Name = L"picStore";
			this->picStore->Size = System::Drawing::Size(47, 38);
			this->picStore->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picStore->TabIndex = 16;
			this->picStore->TabStop = false;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->picStore);
			this->Controls->Add(this->picUser);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblUsers);
			this->Controls->Add(this->lblCapacity);
			this->Controls->Add(this->lblNumUsers);
			this->Controls->Add(this->bttnMinimize);
			this->Controls->Add(this->bttnExit);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblHeader);
			this->Name = L"Dashboard";
			this->Size = System::Drawing::Size(745, 544);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picUser))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picStore))->EndInit();
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
	System::Windows::Forms::Form^ parentForm = this->FindForm(); // Get the parent form
	if (parentForm != nullptr) {
		parentForm->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
}

private:
	void LoadCapacity()
	{
		int totalCapacity = 50000; // Maximum capacity
		int usedCapacity = GetUsedCapacity();

		if (totalCapacity > 0)
		{
			double percentage = (static_cast<double>(usedCapacity) / totalCapacity) * 100;

			// Debug: Show the percentage in MessageBox for testing
			// MessageBox::Show("Percentage: " + percentage.ToString());

			if (percentage < 75)
			{
				lblCapacity->Text = "Optimum";
				lblCapacity->ForeColor = Color::Green;
			}
			else if (percentage >= 75 && percentage < 90)
			{
				lblCapacity->Text = "Mid";
				lblCapacity->ForeColor = Color::Orange;
			}
			else
			{
				lblCapacity->Text = "Full";
				lblCapacity->ForeColor = Color::Red;
			}
		}
		else
		{
			lblCapacity->Text = "No Data";
			lblCapacity->ForeColor = Color::Gray;
		}
	}

	int GetUsedCapacity()
	{
		int usedCapacity = 0;
		try
		{
			SqlConnection^ conn = gcnew SqlConnection(connString);
			conn->Open();

			SqlCommand^ cmd = gcnew SqlCommand("SELECT SUM(Item_Quantity) FROM dbo.tblItems", conn);
			Object^ result = cmd->ExecuteScalar();

			if (result != nullptr && result != DBNull::Value)
			{
				usedCapacity = Convert::ToInt32(result);
			}

			conn->Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message);
		}

		return usedCapacity;
	}


	void LoadUserCount()
	{
		int userCount = GetUserCount();
		lblNumUsers->Text = userCount.ToString(); // Display user count in lblNumUsers
	}

	int GetUserCount()
	{
		int userCount = 0;

		SqlConnection^ conn = gcnew SqlConnection(connString);

		try
		{
			conn->Open();
			String^ query = "SELECT COUNT(*) FROM dbo.Users"; // Replace with your actual user table name
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);

			Object^ result = cmd->ExecuteScalar();
			if (result != nullptr && result->ToString() != "")
				userCount = Convert::ToInt32(result);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error: " + ex->Message);
		}
		finally
		{
			conn->Close();
		}

		return userCount;
	}

	void DisplayWelcomeMessage(String^ username, bool isAdmin)
	{
		if (isAdmin)
		{
			lblTitle->Text = "Welcome, Admin!";
		}
		else
		{
			lblTitle->Text = "Welcome, " + username + "!";
		}
	}
};
}

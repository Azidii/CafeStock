#pragma once
#include "Dashboard.h"
#include "InventoryMenu.h"
#include "HistoryControll.h" 
ref class MainLogin;

namespace CafeStock {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Menumain
	/// </summary>
	public ref class Menumain : public System::Windows::Forms::Form
	{
	private:
		String^ loggedInUsername;

	public:
		Menumain(String^ username)
		{
			InitializeComponent();
			// Store username and role
			this->loggedInUsername = username;

			// Load Dashboard and pass username and role
			LoadUserControl(gcnew Dashboard(username, false));
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->button5->MouseEnter += gcnew System::EventHandler(this, &Menumain::button5_MouseEnter);
			this->button5->MouseLeave += gcnew System::EventHandler(this, &Menumain::button5_MouseLeave);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &Menumain::button1_MouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &Menumain::button1_MouseLeave);
			this->button7->MouseEnter += gcnew System::EventHandler(this, &Menumain::button7_MouseEnter);
			this->button7->MouseLeave += gcnew System::EventHandler(this, &Menumain::button7_MouseLeave);
			this->button8->MouseEnter += gcnew System::EventHandler(this, &Menumain::button8_MouseEnter);
			this->button8->MouseLeave += gcnew System::EventHandler(this, &Menumain::button8_MouseLeave);
			this->AllowDrop = false;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Menumain()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Timer^ menuTransition;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Panel^ mainPanel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menumain::typeid));
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->menuTransition = (gcnew System::Windows::Forms::Timer(this->components));
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flowLayoutPanel1.BackgroundImage")));
			this->flowLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->flowLayoutPanel1->Controls->Add(this->pictureBox1);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel8);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->flowLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Segoe MDL2 Assets", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(217, 544);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Menumain::flowLayoutPanel1_Paint);
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
			this->panel5->Controls->Add(this->button5);
			this->panel5->Location = System::Drawing::Point(3, 107);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(214, 50);
			this->panel5->TabIndex = 4;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(0, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(214, 43);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Dashboard";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Menumain::button5_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(3, 163);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(214, 50);
			this->panel1->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(0, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 43);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Inventory Menu";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Menumain::button1_Click_1);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Transparent;
			this->panel7->Controls->Add(this->button7);
			this->panel7->Location = System::Drawing::Point(3, 219);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(214, 50);
			this->panel7->TabIndex = 7;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(-3, 4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(217, 43);
			this->button7->TabIndex = 2;
			this->button7->Text = L"History";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Menumain::button7_Click);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Transparent;
			this->panel8->Controls->Add(this->button8);
			this->panel8->Location = System::Drawing::Point(3, 275);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(214, 50);
			this->panel8->TabIndex = 8;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(-3, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(217, 43);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Logout";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Menumain::button8_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(3, 337);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(214, 50);
			this->panel2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button2->Location = System::Drawing::Point(6, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(205, 43);
			this->button2->TabIndex = 2;
			this->button2->Text = L"History";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->Controls->Add(this->button4);
			this->panel4->Location = System::Drawing::Point(3, 393);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(214, 50);
			this->panel4->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(6, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(205, 43);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Logout";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Menumain::button4_Click);
			// 
			// menuTransition
			// 
			this->menuTransition->Interval = 10;
			this->menuTransition->Tick += gcnew System::EventHandler(this, &Menumain::timer1_Tick);
			// 
			// mainPanel
			// 
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(217, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(745, 544);
			this->mainPanel->TabIndex = 7;
			// 
			// Menumain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(962, 544);
			this->Controls->Add(this->mainPanel);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Menumain";
			this->Text = L"Menumain";
			this->Load += gcnew System::EventHandler(this, &Menumain::Menumain_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void LoadUserControl(System::Windows::Forms::UserControl^ control) {
			mainPanel->Controls->Clear(); // Clear any existing controls
			control->Dock = System::Windows::Forms::DockStyle::Fill; // Fill the panel
			mainPanel->Controls->Add(control); // Add the new control
		}
	private: System::Void Menumain_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void menuContainer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadUserControl(gcnew Dashboard(this->loggedInUsername, false));
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadUserControl(gcnew HistoryControll());
	}
	private: System::Void button5_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		button5->BackColor = System::Drawing::Color::Black;
	}
	private: System::Void button5_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button5->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
	}
	private: System::Void button1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		button1->BackColor = System::Drawing::Color::Black;
	}
	private: System::Void button1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button1->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
	}
	private: System::Void button7_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		button7->BackColor = System::Drawing::Color::Black;
	}

	private: System::Void button7_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button7->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
	}
	private: System::Void button8_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		button8->BackColor = System::Drawing::Color::Black;
	}

		   // MouseLeave event handler
	private: System::Void button8_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		button8->BackColor = System::Drawing::Color::FromArgb(162, 0, 23);
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		LoadUserControl(gcnew InventoryMenu());
	}
	};
}
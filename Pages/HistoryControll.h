#pragma once
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
	/// Summary for HistoryControll
	/// </summary>
	public ref class HistoryControll : public System::Windows::Forms::UserControl
	{
	public:
		HistoryControll(void)
		{
			InitializeComponent();
			LoadDataFromDatabase();
		}

	protected:
		~HistoryControll()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: DataTable^ dataTable;		
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ bttnMinimize;
	private: System::Windows::Forms::Button^ bttnExit;



	protected:

	protected:





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HistoryControll::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->bttnMinimize = (gcnew System::Windows::Forms::Button());
			this->bttnExit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridView1->Location = System::Drawing::Point(68, 106);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(609, 390);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &HistoryControll::dataGridView1_CellFormatting);
			// 
			// txtSearch
			// 
			this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearch->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtSearch->Location = System::Drawing::Point(113, 58);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(565, 24);
			this->txtSearch->TabIndex = 9;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &HistoryControll::txtSearch_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(68, 50);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(40, 36);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
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
			this->bttnMinimize->Location = System::Drawing::Point(668, 0);
			this->bttnMinimize->Name = L"bttnMinimize";
			this->bttnMinimize->Size = System::Drawing::Size(35, 35);
			this->bttnMinimize->TabIndex = 17;
			this->bttnMinimize->Text = L"—";
			this->bttnMinimize->UseVisualStyleBackColor = false;
			this->bttnMinimize->Click += gcnew System::EventHandler(this, &HistoryControll::bttnMinimize_Click);
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
			this->bttnExit->TabIndex = 16;
			this->bttnExit->Text = L"X";
			this->bttnExit->UseVisualStyleBackColor = false;
			this->bttnExit->Click += gcnew System::EventHandler(this, &HistoryControll::bttnExit_Click);
			// 
			// HistoryControll
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->bttnMinimize);
			this->Controls->Add(this->bttnExit);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"HistoryControll";
			this->Size = System::Drawing::Size(745, 544);
			this->Load += gcnew System::EventHandler(this, &HistoryControll::HistoryControll_Load);
			this->Click += gcnew System::EventHandler(this, &HistoryControll::HistoryControll_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void HistoryExit_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show a confirmation dialog
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

	private:
		public:
			void LoadDataFromDatabase() {
				String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();
				String^ query = "SELECT * FROM dbo.tblItems";

				try {
					// Confirm connection string exists
					if (String::IsNullOrEmpty(connectionString)) {
						MessageBox::Show("Connection string is null or empty.");
						return;
					}

					// Ensure DataGridView is initialized
					if (dataGridView1 == nullptr) {
						MessageBox::Show("DataGridView is not initialized.");
						return;
					}

					// Connect to the database
					SqlConnection^ con = gcnew SqlConnection(connectionString);
					con->Open();

					SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, con);
					DataTable^ dt = gcnew DataTable();
					adapter->Fill(dt);

					if (dt == nullptr || dt->Columns->Count == 0) {
						MessageBox::Show("No data found or DataTable is empty.");
						con->Close();
						return;
					}

					dataTable = dt;
					dataGridView1->DataSource = dataTable->DefaultView;

					con->Close();

					// Apply column header safely only if column exists
					if (dataGridView1->Columns->Contains("Item_Name"))
						dataGridView1->Columns["Item_Name"]->HeaderText = "Item Name";

					if (dataGridView1->Columns->Contains("Item_Category"))
						dataGridView1->Columns["Item_Category"]->HeaderText = "Item Type";

					if (dataGridView1->Columns->Contains("Item_Quantity"))
						dataGridView1->Columns["Item_Quantity"]->HeaderText = "Quantity";

					if (dataGridView1->Columns->Contains("Date_Modified"))
						dataGridView1->Columns["Date_Modified"]->HeaderText = "Date Created/Modified";

					if (dataGridView1->Columns->Contains("Item_ID"))
						dataGridView1->Columns["Item_ID"]->Visible = false;

					// Styling, safe since grid now has columns
					dataGridView1->EnableHeadersVisualStyles = false;
					dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Silver;
					dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::Black;
					dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);
					dataGridView1->ColumnHeadersDefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
					dataGridView1->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::Silver;
					dataGridView1->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
				}
				catch (SqlException^ ex) {
					MessageBox::Show("Database error: " + ex->Message);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error loading data: " + ex->Message);
				}
			}
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ searchText = txtSearch->Text;
	if (dataTable == nullptr) return;
	if (String::IsNullOrEmpty(searchText)) {
		dataTable->DefaultView->RowFilter = "";
	}
	else {
		dataTable->DefaultView->RowFilter = String::Format("Item_Name LIKE '%{0}%'", searchText->Replace("'", "''"));
	}
}
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
private: System::Void dataGridView1_CellFormatting(System::Object^ sender,
	System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e)
{
	// Ensure we are on the Item_Quantity column
	if (dataGridView1->Columns[e->ColumnIndex]->HeaderText == "Quantity")
	{
		// Get the cell value
		System::String^ valueStr = e->Value != nullptr ? e->Value->ToString() : "";

		int quantity = 0;
		bool success = Int32::TryParse(valueStr, quantity);

		if (success)
		{
			if (quantity <= 1500)
			{
				e->CellStyle->BackColor = System::Drawing::Color::FromArgb(198, 12, 48);
				e->CellStyle->ForeColor = System::Drawing::Color::White;
			}
			else if (quantity > 1500 && quantity <= 2500)
			{
				e->CellStyle->BackColor = System::Drawing::Color::Orange;
				e->CellStyle->ForeColor = System::Drawing::Color::White;
			}
			else
			{
				e->CellStyle->BackColor = System::Drawing::Color::White;
				e->CellStyle->ForeColor = System::Drawing::Color::Black;
			}
		}
	}
}

private: System::Void HistoryControll_Load(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
	dataGridView1->CurrentCell = nullptr;

	CustomizeDataGridView();
}
private: System::Void CustomizeDataGridView() {
	// Change background color when row is selected
	dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGray; 
	dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;   
}
private: System::Void HistoryControll_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
	dataGridView1->CurrentCell = nullptr;
}
};
}

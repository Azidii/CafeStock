#pragma once
#include "EditUser.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;

namespace CafeStock {

	/// <summary>
	/// Summary for AdminUsers
	/// </summary>
	public ref class AdminUsers : public System::Windows::Forms::UserControl
	{
	public:
		AdminUsers(void)
		{
			InitializeComponent();
			LoadDataFromDatabase();
			UpdateUserCount();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminUsers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bttnMinimize;

	private: DataTable^ dataTable;
	protected:
	private: System::Windows::Forms::Button^ bttnExit;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ lblUserCount;
	private: System::Windows::Forms::Button^ txtRemoveUsers;
	private: System::Windows::Forms::Button^ btnEdit;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminUsers::typeid));
			this->bttnMinimize = (gcnew System::Windows::Forms::Button());
			this->bttnExit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->lblUserCount = (gcnew System::Windows::Forms::Label());
			this->txtRemoveUsers = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
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
			this->bttnMinimize->TabIndex = 22;
			this->bttnMinimize->Text = L"—";
			this->bttnMinimize->UseVisualStyleBackColor = false;
			this->bttnMinimize->Click += gcnew System::EventHandler(this, &AdminUsers::bttnMinimize_Click);
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
			this->bttnExit->TabIndex = 21;
			this->bttnExit->Text = L"X";
			this->bttnExit->UseVisualStyleBackColor = false;
			this->bttnExit->Click += gcnew System::EventHandler(this, &AdminUsers::bttnExit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(68, 42);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(40, 36);
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(113, 50);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(426, 20);
			this->txtSearch->TabIndex = 19;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &AdminUsers::txtSearch_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlLight;
			this->dataGridView1->Location = System::Drawing::Point(68, 122);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(609, 390);
			this->dataGridView1->TabIndex = 18;
			// 
			// lblUserCount
			// 
			this->lblUserCount->AutoSize = true;
			this->lblUserCount->BackColor = System::Drawing::Color::Transparent;
			this->lblUserCount->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUserCount->Location = System::Drawing::Point(73, 80);
			this->lblUserCount->Name = L"lblUserCount";
			this->lblUserCount->Size = System::Drawing::Size(148, 32);
			this->lblUserCount->TabIndex = 23;
			this->lblUserCount->Text = L"User Count:";
			// 
			// txtRemoveUsers
			// 
			this->txtRemoveUsers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->txtRemoveUsers->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->txtRemoveUsers->FlatAppearance->BorderSize = 0;
			this->txtRemoveUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->txtRemoveUsers->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"txtRemoveUsers.Image")));
			this->txtRemoveUsers->Location = System::Drawing::Point(562, 42);
			this->txtRemoveUsers->Name = L"txtRemoveUsers";
			this->txtRemoveUsers->Size = System::Drawing::Size(40, 40);
			this->txtRemoveUsers->TabIndex = 24;
			this->txtRemoveUsers->UseVisualStyleBackColor = false;
			this->txtRemoveUsers->Click += gcnew System::EventHandler(this, &AdminUsers::txtRemoveUsers_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnEdit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEdit->FlatAppearance->BorderSize = 0;
			this->btnEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEdit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEdit.Image")));
			this->btnEdit->Location = System::Drawing::Point(637, 42);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(40, 40);
			this->btnEdit->TabIndex = 25;
			this->btnEdit->UseVisualStyleBackColor = false;
			this->btnEdit->Click += gcnew System::EventHandler(this, &AdminUsers::btnEdit_Click);
			// 
			// AdminUsers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->btnEdit);
			this->Controls->Add(this->txtRemoveUsers);
			this->Controls->Add(this->lblUserCount);
			this->Controls->Add(this->bttnMinimize);
			this->Controls->Add(this->bttnExit);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"AdminUsers";
			this->Size = System::Drawing::Size(745, 544);
			this->Load += gcnew System::EventHandler(this, &AdminUsers::AdminUsers_Load);
			this->Click += gcnew System::EventHandler(this, &AdminUsers::AdminUsers_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	void LoadDataFromDatabase() {
		String^ connectionString = "Data Source=cafestock.c5cmiu400v99.ap-northeast-2.rds.amazonaws.com;Initial Catalog=dboInventory;User ID=sa;Password=CafeStock1234";
		String^ query = "SELECT * FROM Users";
		String^ countQuery = "SELECT COUNT(*) FROM Users";

		try {
			SqlConnection^ con = gcnew SqlConnection(connectionString);
			con->Open();

			
			SqlCommand^ countCmd = gcnew SqlCommand(countQuery, con);
			int userCount = Convert::ToInt32(countCmd->ExecuteScalar());
			lblUserCount->Text = "User Count: " + userCount.ToString();  

			
			SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, con);
			DataTable^ dt = gcnew DataTable();
			adapter->Fill(dt);
			dataTable = dt;
			dataGridView1->DataSource = dataTable->DefaultView;

			con->Close();

			dataGridView1->Columns["Id"]->HeaderText = "User ID";
			dataGridView1->Columns["username"]->HeaderText = "User Name";
			dataGridView1->Columns["password"]->HeaderText = "Password";
			dataGridView1->Columns["datecreated"]->HeaderText = "Date Created";


			dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Silver;
			dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);
			dataGridView1->ColumnHeadersDefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridView1->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::Silver;
			dataGridView1->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
			dataGridView1->EnableHeadersVisualStyles = false;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error loading data: " + ex->Message);
		}
	}
private: System::Void bttnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result =
		System::Windows::Forms::MessageBox::Show(
			"Are you sure you want to exit?", 
			"Exit Application",             
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
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ searchText = txtSearch->Text;
	if (dataTable == nullptr) return;
	if (String::IsNullOrEmpty(searchText)) {
		dataTable->DefaultView->RowFilter = "";
	}
	else {
		dataTable->DefaultView->RowFilter = String::Format("Username LIKE '%{0}%'", searchText->Replace("'", "''"));
	}
}
private: System::Void AdminUsers_Load(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
	dataGridView1->CurrentCell = nullptr;

	CustomizeDataGridView();
}
private: System::Void UpdateUserCount() {
	lblUserCount->Text = "User Count: " + dataGridView1->Rows->Count.ToString();
}

private: System::Void CustomizeDataGridView() {
	// Change background color when row is selected
	dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGray; 
	dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;  
}

private: System::Void InventoryMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
	dataGridView1->CurrentCell = nullptr;
}
private: System::Void AdminUsers_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
	dataGridView1->CurrentCell = nullptr;
}
private: System::Void txtRemoveUsers_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a user to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Get the selected row
	int selectedIndex = dataGridView1->SelectedRows[0]->Index;
	int userID = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells["Id"]->Value);

	// Confirmation dialog
	System::Windows::Forms::DialogResult dialogResult = MessageBox::Show(
		"Are you sure you want to delete this user?",
		"Confirm Deletion",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (dialogResult == System::Windows::Forms::DialogResult::Yes) {
		try {
			// Database connection
			String^ connectionString = "Data Source=cafestock.c5cmiu400v99.ap-northeast-2.rds.amazonaws.com;Initial Catalog=dboInventory;User ID=sa;Password=CafeStock1234";
			SqlConnection^ conn = gcnew SqlConnection(connectionString);
			conn->Open();

			// Delete query
			String^ deleteQuery = "DELETE FROM Users WHERE Id = @UserID";
			SqlCommand^ cmd = gcnew SqlCommand(deleteQuery, conn);
			cmd->Parameters->AddWithValue("@UserID", userID);
			int rowsAffected = cmd->ExecuteNonQuery();
			conn->Close();

			// ✅ Remove from DataGridView
			if (rowsAffected > 0) {
				dataGridView1->Rows->RemoveAt(selectedIndex);
				MessageBox::Show("User deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// ✅ Update user count after deletion
				UpdateUserCount();
			}
			else {
				MessageBox::Show("User not found or already deleted.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting user: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {

	if (dataGridView1->SelectedRows->Count > 0) {
		int selectedIndex = dataGridView1->SelectedRows[0]->Index;
		int selectedItemID = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells["Id"]->Value);  // ✅ Use correct column name

		String^ username = dataGridView1->Rows[selectedIndex]->Cells["username"]->Value->ToString();
		String^ password = dataGridView1->Rows[selectedIndex]->Cells["password"]->Value->ToString();

		// Open EditUser form
		EditUser^ edituser = gcnew EditUser(selectedItemID, username, password);
		edituser->ShowDialog();

		// Refresh data after editing
		LoadDataFromDatabase();
	}
	else {
		MessageBox::Show("Please select a row to edit.");
	}
}
};
}

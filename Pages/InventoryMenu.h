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

		public ref class InventoryMenu : public System::Windows::Forms::UserControl
		{
		public:
			InventoryMenu(void)
			{
				InitializeComponent();
				LoadDataFromDatabase();
				UpdateInventoryCapacity();
				
			}

		protected:
			~InventoryMenu()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ bttnMinimize;
		protected:
		private: System::Windows::Forms::Button^ bttnExit;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Label^ lblInvCapacity;

		private: System::Windows::Forms::Button^ btnEdit;
		private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e);
		protected:

		protected:

		protected:


		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::TextBox^ textBox1;
		public: System::Windows::Forms::DataGridView^ dataGridView1;

		private: DataTable^ dataTable;
		private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			   void InitializeComponent(void)
			   {
				   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InventoryMenu::typeid));
				   this->btnEdit = (gcnew System::Windows::Forms::Button());
				   this->button1 = (gcnew System::Windows::Forms::Button());
				   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
				   this->bttnMinimize = (gcnew System::Windows::Forms::Button());
				   this->bttnExit = (gcnew System::Windows::Forms::Button());
				   this->button2 = (gcnew System::Windows::Forms::Button());
				   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				   this->lblInvCapacity = (gcnew System::Windows::Forms::Label());
				   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				   this->SuspendLayout();
				   // 
				   // btnEdit
				   // 
				   this->btnEdit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					   static_cast<System::Int32>(static_cast<System::Byte>(0)));
				   this->btnEdit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				   this->btnEdit->FlatAppearance->BorderSize = 0;
				   this->btnEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				   this->btnEdit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEdit.Image")));
				   this->btnEdit->Location = System::Drawing::Point(637, 45);
				   this->btnEdit->Name = L"btnEdit";
				   this->btnEdit->Size = System::Drawing::Size(40, 40);
				   this->btnEdit->TabIndex = 7;
				   this->btnEdit->UseVisualStyleBackColor = false;
				   this->btnEdit->Click += gcnew System::EventHandler(this, &InventoryMenu::btnEdit_Click);
				   // 
				   // button1
				   // 
				   this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					   static_cast<System::Int32>(static_cast<System::Byte>(0)));
				   this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				   this->button1->FlatAppearance->BorderSize = 0;
				   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				   this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
				   this->button1->Location = System::Drawing::Point(570, 45);
				   this->button1->Name = L"button1";
				   this->button1->Size = System::Drawing::Size(40, 40);
				   this->button1->TabIndex = 6;
				   this->button1->UseVisualStyleBackColor = false;
				   this->button1->Click += gcnew System::EventHandler(this, &InventoryMenu::button1_Click);
				   // 
				   // textBox1
				   // 
				   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0)));
				   this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					   static_cast<System::Int32>(static_cast<System::Byte>(0)));
				   this->textBox1->Location = System::Drawing::Point(113, 54);
				   this->textBox1->Name = L"textBox1";
				   this->textBox1->Size = System::Drawing::Size(374, 24);
				   this->textBox1->TabIndex = 5;
				   this->textBox1->TextChanged += gcnew System::EventHandler(this, &InventoryMenu::textBox1_TextChanged);
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
				   this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableAlwaysIncludeHeaderText;
				   this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
				   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				   this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
				   this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlLight;
				   this->dataGridView1->Location = System::Drawing::Point(68, 136);
				   this->dataGridView1->MultiSelect = false;
				   this->dataGridView1->Name = L"dataGridView1";
				   this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
				   this->dataGridView1->RowHeadersVisible = false;
				   this->dataGridView1->RowHeadersWidth = 51;
				   this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				   this->dataGridView1->Size = System::Drawing::Size(609, 390);
				   this->dataGridView1->TabIndex = 4;
				   this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &InventoryMenu::dataGridView1_CellContentClick);
				   this->dataGridView1->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &InventoryMenu::dataGridView1_CellFormatting);
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
				   this->bttnMinimize->Click += gcnew System::EventHandler(this, &InventoryMenu::bttnMinimize_Click);
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
				   this->bttnExit->Click += gcnew System::EventHandler(this, &InventoryMenu::bttnExit_Click);
				   // 
				   // button2
				   // 
				   this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					   static_cast<System::Int32>(static_cast<System::Byte>(0)));
				   this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				   this->button2->FlatAppearance->BorderSize = 0;
				   this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				   this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
				   this->button2->Location = System::Drawing::Point(504, 45);
				   this->button2->Name = L"button2";
				   this->button2->Size = System::Drawing::Size(40, 40);
				   this->button2->TabIndex = 18;
				   this->button2->UseVisualStyleBackColor = false;
				   this->button2->Click += gcnew System::EventHandler(this, &InventoryMenu::button2_Click);
				   // 
				   // pictureBox1
				   // 
				   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
				   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
				   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				   this->pictureBox1->Location = System::Drawing::Point(68, 45);
				   this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
				   this->pictureBox1->Name = L"pictureBox1";
				   this->pictureBox1->Size = System::Drawing::Size(40, 40);
				   this->pictureBox1->TabIndex = 19;
				   this->pictureBox1->TabStop = false;
				   // 
				   // lblInvCapacity
				   // 
				   this->lblInvCapacity->AutoSize = true;
				   this->lblInvCapacity->BackColor = System::Drawing::Color::Transparent;
				   this->lblInvCapacity->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0)));
				   this->lblInvCapacity->Location = System::Drawing::Point(63, 87);
				   this->lblInvCapacity->Name = L"lblInvCapacity";
				   this->lblInvCapacity->Size = System::Drawing::Size(204, 30);
				   this->lblInvCapacity->TabIndex = 20;
				   this->lblInvCapacity->Text = L"Inventory Capacity:";
				   // 
				   // InventoryMenu
				   // 
				   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				   this->Controls->Add(this->lblInvCapacity);
				   this->Controls->Add(this->pictureBox1);
				   this->Controls->Add(this->button2);
				   this->Controls->Add(this->bttnMinimize);
				   this->Controls->Add(this->bttnExit);
				   this->Controls->Add(this->btnEdit);
				   this->Controls->Add(this->button1);
				   this->Controls->Add(this->textBox1);
				   this->Controls->Add(this->dataGridView1);
				   this->Name = L"InventoryMenu";
				   this->Size = System::Drawing::Size(745, 544);
				   this->Load += gcnew System::EventHandler(this, &InventoryMenu::InventoryMenu_Load);
				   this->Click += gcnew System::EventHandler(this, &InventoryMenu::InventoryMenu_Click);
				   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				   this->ResumeLayout(false);
				   this->PerformLayout();

			   }
#pragma endregion
		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}
		private: System::Void InventExit_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show("Are you sure you want to exit?", "Exit Application", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				System::Windows::Forms::Application::Exit();
			}
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count == 0) {
				// Show a message if no row is selected
				MessageBox::Show("Please select a row to delete.", "No Selection", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return; // Exit the method early if no row is selected
			}

			// Proceed with deletion if a row is selected
			int selectedIndex = dataGridView1->SelectedRows[0]->Index;
			int itemID = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells["Item_ID"]->Value);

			// Confirm deletion using a MessageBox
			System::Windows::Forms::DialogResult dialogResult = MessageBox::Show(
				"Are you sure you want to delete this record?", "Confirm Deletion",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (dialogResult == System::Windows::Forms::DialogResult::Yes) {
				try {
					// Supabase REST API URL (or SQL Server connection string if using local DB)
					String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();

					// Open connection
					SqlConnection^ conn = gcnew SqlConnection(connectionString);
					conn->Open();

					// SQL delete command
					String^ deleteQuery = "DELETE FROM dbo.tblItems WHERE Item_ID = @ItemID";
					SqlCommand^ cmd = gcnew SqlCommand(deleteQuery, conn);
					cmd->Parameters->AddWithValue("@ItemID", itemID);

					// Execute command
					cmd->ExecuteNonQuery();
					conn->Close();

					// Remove row from DataGridView
					dataGridView1->Rows->RemoveAt(selectedIndex);
					UpdateInventoryCapacity();
					// Display success message
					MessageBox::Show("Record deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (Exception^ ex) {
					// Display error message
					MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			String^ searchText = textBox1->Text;
			if (dataTable == nullptr) return;
			if (String::IsNullOrEmpty(searchText)) {
				dataTable->DefaultView->RowFilter = "";
			}
			else {
				dataTable->DefaultView->RowFilter = String::Format("Item_Name LIKE '%{0}%'", searchText->Replace("'", "''"));
			}
		}
		public:
			void LoadDataFromDatabase() {
				String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();
				String^ query = "SELECT * FROM dbo.tblItems";

				try {
					if (dataGridView1 == nullptr) {
						MessageBox::Show("DataGridView is not initialized.");
						return;
					}

					SqlConnection^ con = gcnew SqlConnection(connectionString);
					con->Open();

					SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, con);
					DataTable^ dt = gcnew DataTable();
					adapter->Fill(dt);

					dataTable = dt;
					dataGridView1->DataSource = dataTable->DefaultView;
					con->Close();

					// Safely set column headers only if the columns exist
					if (dataGridView1->Columns->Contains("Item_Name"))
						dataGridView1->Columns["Item_Name"]->HeaderText = "Item Name";

					if (dataGridView1->Columns->Contains("Item_Category"))
						dataGridView1->Columns["Item_Category"]->HeaderText = "Item Type";

					if (dataGridView1->Columns->Contains("Item_Quantity"))
						dataGridView1->Columns["Item_Quantity"]->HeaderText = "Quantity";

					if (dataGridView1->Columns->Contains("Item_ID"))
						dataGridView1->Columns["Item_ID"]->Visible = false;

					if (dataGridView1->Columns->Contains("Date_Modified"))
						dataGridView1->Columns["Date_Modified"]->Visible = false;

					// Apply styling safely
					dataGridView1->EnableHeadersVisualStyles = false;
					dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::Silver;
					dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::Black;
					dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);
					dataGridView1->ColumnHeadersDefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
					dataGridView1->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::Silver;
					dataGridView1->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;

					// ✅ Call UpdateInventoryCapacity after loading data, but check it's valid
					if (dataTable != nullptr && dataTable->Rows->Count > 0)
						UpdateInventoryCapacity();
					else
						MessageBox::Show("There are no Items as of the Moment!, Capacity Check Skipped");
				}
				catch (SqlException^ ex) {
					MessageBox::Show("Database error: " + ex->Message);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error loading data: " + ex->Message);
				}
			}
	private: System::Void bttnMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::Form^ parentForm = this->FindForm(); // Get the parent form
		if (parentForm != nullptr) {
			parentForm->WindowState = System::Windows::Forms::FormWindowState::Minimized;
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
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView1_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
		// Skip formatting if the row is flagged as highlighted.
		if (dataGridView1->Rows[e->RowIndex]->Tag != nullptr &&
			dataGridView1->Rows[e->RowIndex]->Tag->ToString() == "highlighted") {
			return;
		}

		// Ensure it's a valid row and we're formatting the "Item_Quantity" column.
		if (e->RowIndex >= 0 && dataGridView1->Columns[e->ColumnIndex]->Name == "Item_Quantity") {
			System::String^ value = dataGridView1->Rows[e->RowIndex]->Cells["Item_Quantity"]->Value != nullptr
				? dataGridView1->Rows[e->RowIndex]->Cells["Item_Quantity"]->Value->ToString()
				: "";
			int quantity;
			if (!String::IsNullOrEmpty(value) && Int32::TryParse(value, quantity) && quantity <= 10) {
				dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
				dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			}
			else {
				dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
				dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			}
		}
	}
		public: System::Void CafeStock::InventoryMenu::UpdateInventoryCapacity() {
			   int totalQuantity = 0;
			   int maxCapacity = 50000;

			   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
				   if (row->Cells["Item_Quantity"]->Value != nullptr) {
					   int quantity = Convert::ToInt32(row->Cells["Item_Quantity"]->Value);
					   totalQuantity += quantity;
				   }
			   }

			   lblInvCapacity->Text = "Inventory Capacity: " + totalQuantity.ToString() + "/" + maxCapacity.ToString();

			   // Apply color coding based on usage
			   double percentage = (double)totalQuantity / maxCapacity * 100;
			   if (percentage >= 90) {
				   lblInvCapacity->ForeColor = System::Drawing::Color::Red;  // Over 90% capacity
			   }
			   else if (percentage >= 75) {
				   lblInvCapacity->ForeColor = System::Drawing::Color::Orange;  // Over 75% capacity
			   }
			   else {
				   lblInvCapacity->ForeColor = System::Drawing::Color::Black;
			   }
		   }
	private: System::Void InventoryMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->ClearSelection();
		dataGridView1->CurrentCell = nullptr;

		CustomizeDataGridView();
	}

	private: System::Void CustomizeDataGridView() {
		// Change background color when row is selected
		dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGray; // Background color
		dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;   // Text color
	}

	private: System::Void InventoryMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->ClearSelection();
		dataGridView1->CurrentCell = nullptr;
	}
	};
	}
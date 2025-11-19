#include "EditInventory.h"
#include "InventoryMenu.h"
#include "Menumain.h"
#include "../EnvConfig.h"

using namespace System::Data::SqlClient;

int CafeStock::EditInventory::GetItemID(String^ itemName) {
    int itemID = -1; // Default value if not found
    String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();
    String^ query = "SELECT Item_ID FROM dbo.tblItems WHERE Item_Name = @ItemName";

    try {
        // Open connection
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        conn->Open();

        // Prepare SQL command
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@ItemName", itemName);

        // Execute and read results
        SqlDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read()) {
            itemID = reader->GetInt32(0); // Get the first column value (Item_ID)
        }

        // Close connection
        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error retrieving item ID: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    return itemID;
}

System::Void CafeStock::EditInventory::btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
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

// EditInventory.h

System::Void CafeStock::EditInventory::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ itemName = txtItemName->Text;

    if (cmbItemType->SelectedItem == nullptr) {
        MessageBox::Show("Please select an item type.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    String^ itemType = cmbItemType->SelectedItem->ToString();
    String^ itemQuantityStr = txtQuantity->Text;

    if (String::IsNullOrEmpty(itemName) || String::IsNullOrEmpty(itemQuantityStr)) {
        MessageBox::Show("Please fill in all fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    int quantity;
    if (!Int32::TryParse(itemQuantityStr, quantity) || quantity <= 0) {
        MessageBox::Show("Please enter a valid quantity.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (this->itemID <= 0) {
        MessageBox::Show("Invalid item ID. Cannot update record.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();

    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        conn->Open();

        // ✅ Calculate the current total quantity excluding the quantity of the item being updated
        String^ totalQuery = "SELECT SUM(Item_Quantity) FROM dbo.tblItems WHERE Item_ID != @ItemID";
        SqlCommand^ totalCmd = gcnew SqlCommand(totalQuery, conn);
        totalCmd->Parameters->AddWithValue("@ItemID", this->itemID);

        Object^ result = totalCmd->ExecuteScalar();
        int currentTotal = (result != nullptr && result != DBNull::Value) ? Convert::ToInt32(result) : 0;
        int maxCapacity = 50000;

        // ✅ Check if the updated quantity exceeds the maximum capacity
        if (currentTotal + quantity > maxCapacity) {
            MessageBox::Show("Updating this item would exceed the inventory capacity of 50,000.", "Capacity Exceeded", MessageBoxButtons::OK, MessageBoxIcon::Error);
            conn->Close();
            return;
        }

        // ✅ Proceed with the update if within capacity
        String^ query = "UPDATE dbo.tblItems SET Item_Name = @ItemName, Item_Category = @ItemType, Item_Quantity = @ItemQuantity WHERE Item_ID = @ItemID";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@ItemName", itemName);
        cmd->Parameters->AddWithValue("@ItemType", itemType);
        cmd->Parameters->AddWithValue("@ItemQuantity", quantity);
        cmd->Parameters->AddWithValue("@ItemID", this->itemID);

        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        if (rowsAffected > 0) {
            MessageBox::Show("Item updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            Form^ mainForm = Application::OpenForms["Menumain"];
            if (mainForm != nullptr) {
                Menumain^ menu = dynamic_cast<Menumain^>(mainForm);
                if (menu != nullptr) {
                    for each (Control ^ ctrl in menu->Controls) {
                        InventoryMenu^ inventory = dynamic_cast<InventoryMenu^>(ctrl);
                        if (inventory != nullptr) {
                            inventory->LoadDataFromDatabase();
                            inventory->UpdateInventoryCapacity();  // <-- Update capacity
                            menu->BringToFront();
                            break;
                        }
                    }
                }
            }

            this->Close();
        }
        else {
            MessageBox::Show("No record was updated. Please check the item ID.", "Update Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error updating item: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

void CafeStock::EditInventory::LoadItemDetails() {
    String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();

    String^ query = "SELECT Item_Name, Item_Category, Item_Quantity FROM dbo.tblItems WHERE Item_ID = @ItemID";

    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        conn->Open();

        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@ItemID", this->itemID);
        SqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            txtItemName->Text = reader["Item_Name"]->ToString();
            cmbItemType->Text = reader["Item_Category"]->ToString();
            txtQuantity->Text = reader["Item_Quantity"]->ToString();
        }

        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error loading item details: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
} 


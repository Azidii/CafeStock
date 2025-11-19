#include "PopupEdit.h"
#include "InventoryMenu.h"
#include "Menumain.h"
#include "../EnvConfig.h"
using namespace System::Data::SqlClient;

void CafeStock::PopupEdit::UpdateInventoryCapacity() {
    Form^ mainForm = Application::OpenForms["Menumain"];
    if (mainForm != nullptr) {
        Menumain^ menu = dynamic_cast<Menumain^>(mainForm);
        if (menu != nullptr) {
            for each (Control ^ ctrl in menu->Controls) {
                InventoryMenu^ inventory = dynamic_cast<InventoryMenu^>(ctrl);
                if (inventory != nullptr) {
                    inventory->UpdateInventoryCapacity();  // ✅ Call InventoryMenu's method
                    break;
                }
            }
        }
    }
}

System::Void CafeStock::PopupEdit::PopupBack_Click(System::Object^ sender, System::EventArgs^ e) {
    Form^ mainForm = Application::OpenForms["Menumain"];
    if (mainForm != nullptr) {
        mainForm->Show();
    }
    this->Close();
}

System::Void CafeStock::PopupEdit::editCombo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    // Implementation for when the combo box selection changes
    if (cmbItemType->SelectedItem != nullptr) {
        String^ selectedType = cmbItemType->SelectedItem->ToString();
        
    }
}

System::Void CafeStock::PopupEdit::bttnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
    // ✅ Get values from input fields
    String^ itemName = txtItemName->Text;
    String^ quantityText = txtQuantity->Text;

    if (String::IsNullOrWhiteSpace(itemName) || String::IsNullOrWhiteSpace(quantityText)) {
        MessageBox::Show("Please fill in all fields.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    if (cmbItemType->SelectedItem == nullptr) {
        MessageBox::Show("Please select an item type.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    String^ itemType = cmbItemType->SelectedItem->ToString();
    int quantity;
    if (!Int32::TryParse(quantityText, quantity) || quantity <= 0) {
        MessageBox::Show("Please enter a valid quantity.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    String^ connectionString = CafeStockConfig::EnvConfig::GetConnectionString();

    try {
        SqlConnection^ con = gcnew SqlConnection(connectionString);
        con->Open();

        // ✅ Check total inventory capacity
        String^ capacityQuery = "SELECT SUM(Item_Quantity) FROM dbo.tblItems";
        SqlCommand^ capacityCmd = gcnew SqlCommand(capacityQuery, con);
        Object^ result = capacityCmd->ExecuteScalar();
        int currentTotal = (result != nullptr && result != DBNull::Value) ? Convert::ToInt32(result) : 0;
        int maxCapacity = 50000;

        // ✅ Prevent adding items if capacity is exceeded
        if (currentTotal + quantity > maxCapacity) {
            MessageBox::Show("Inventory is full. Cannot add more items.", "Capacity Exceeded", MessageBoxButtons::OK, MessageBoxIcon::Error);
            con->Close();
            return;
        }

        // ✅ Proceed with insertion if capacity is not exceeded
        String^ query = "INSERT INTO dbo.tblItems (Item_Name, Item_Category, Item_Quantity) VALUES (@name, @type, @quantity)";
        SqlCommand^ cmd = gcnew SqlCommand(query, con);

        cmd->Parameters->AddWithValue("@name", itemName);
        cmd->Parameters->AddWithValue("@type", itemType);
        cmd->Parameters->AddWithValue("@quantity", quantity);

        int rowsAffected = cmd->ExecuteNonQuery();
        con->Close();

        if (rowsAffected > 0) {
            MessageBox::Show("Item added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            Form^ mainForm = Application::OpenForms["Menumain"];
            if (mainForm != nullptr) {
                Menumain^ menu = dynamic_cast<Menumain^>(mainForm);
                if (menu != nullptr) {
                    for each (Control ^ ctrl in menu->Controls) {
                        InventoryMenu^ inventory = dynamic_cast<InventoryMenu^>(ctrl);
                        if (inventory != nullptr) {
                            inventory->LoadDataFromDatabase();
                            inventory->UpdateInventoryCapacity();  // ✅ Refresh capacity
                            menu->BringToFront();
                            break;
                        }
                    }
                }
            }

            this->Close();
        }
        else {
            MessageBox::Show("Failed to add item.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (SqlException^ ex) {
        if (ex->Number == 2627) {
            MessageBox::Show("This item name already exists. Please enter a different name.", "Duplicate Item", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
        else {
            MessageBox::Show("Database Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

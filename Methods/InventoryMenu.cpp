#include "InventoryMenu.h"
#include "PopupEdit.h"
#include "EditInventory.h"

using namespace System::Data::SqlClient;

System::Void CafeStock::InventoryMenu::btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
    // Open PopupEdit
    PopupEdit^ editPopup = gcnew PopupEdit();
    editPopup->ShowDialog();

    // Show InventoryMenu again after PopupEdit is closed
    this->Show();

    // Refresh DataGridView after editing
    LoadDataFromDatabase();
}

System::Void CafeStock::InventoryMenu::button2_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        int selectedIndex = dataGridView1->SelectedRows[0]->Index;
        int selectedItemID = Convert::ToInt32(
            dataGridView1->Rows[selectedIndex]->Cells["Item_ID"]->Value
        );

        // Call the new constructor that takes an int
        EditInventory^ editInventory = gcnew EditInventory(selectedItemID);
        editInventory->ShowDialog();
    }
    else {
        MessageBox::Show("Please select a row to edit.");
    }

    LoadDataFromDatabase();
}





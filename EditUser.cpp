#include "EditUser.h"
#include "AdminUsers.h"

using namespace System::Data::SqlClient;

System::Void CafeStock::EditUser::btnSave_Click(System::Object^ sender, System::EventArgs^ e){
    String^ username = txtUsername->Text;
    String^ password = txtPass->Text;
    // Validate username length
    if (username->Trim()->Length > 15) {
        MessageBox::Show("Username is too long! Please keep it under 15 characters.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Validate password length (at least 8 characters)
    if (password->Length < 8) {
        MessageBox::Show("Password must be at least 8 characters long!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    // Validate input fields (ensure they're not empty)
    if (String::IsNullOrWhiteSpace(username) || String::IsNullOrWhiteSpace(password)) {
        MessageBox::Show("Please fill in all fields.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Database connection
    String^ connectionString = "Data Source=cafestock.c5cmiu400v99.ap-northeast-2.rds.amazonaws.com;Initial Catalog=dboInventory;User ID=sa;Password=CafeStock1234";

    try {
        SqlConnection^ conn = gcnew SqlConnection(connectionString);
        conn->Open();

        // Update query (only username & password)
        String^ query = "UPDATE Users SET username = @Username, password = @Password WHERE Id = @UserID";
        SqlCommand^ cmd = gcnew SqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@Username", username);
        cmd->Parameters->AddWithValue("@Password", password);
        cmd->Parameters->AddWithValue("@UserID", userID);

        int rowsAffected = cmd->ExecuteNonQuery();
        conn->Close();

        if (rowsAffected > 0) {
            MessageBox::Show("User details updated successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // ✅ Refresh `AdminUsers` data (update the user list or parent form)
            Control^ parentControl = this->Parent;
            while (parentControl != nullptr && parentControl->GetType() != AdminUsers::typeid) {
                parentControl = parentControl->Parent;
            }

            if (parentControl != nullptr) {
                AdminUsers^ adminUsers = dynamic_cast<AdminUsers^>(parentControl);
                if (adminUsers != nullptr) {
                    adminUsers->LoadDataFromDatabase();  // Refresh data in the parent form (AdminUsers)
                }
            }

            this->Close();  // Close the EditUser form
        }
        else {
            MessageBox::Show("No record was updated. Please check the user ID.", "Update Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error updating user: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
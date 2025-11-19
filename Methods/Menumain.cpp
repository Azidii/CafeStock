#include "Menumain.h"
#include "MainLogin.h"
//test//
using namespace System;
using namespace System::Windows::Forms;

System::Void CafeStock::Menumain::button8_Click(System::Object^ sender, System::EventArgs^ e) {
    // Show a confirmation message before logging out
    System::Windows::Forms::DialogResult result =
        System::Windows::Forms::MessageBox::Show(
            "Are you sure you want to log out?", "Logout Confirmation",
            System::Windows::Forms::MessageBoxButtons::YesNo,
            System::Windows::Forms::MessageBoxIcon::Question
        );

    // Check if the user clicked "Yes"
    if (result == System::Windows::Forms::DialogResult::Yes) {
        this->Hide();  // Hide the current menu form

        // Create an instance of MainLogin and show it
        MainLogin^ loginForm = gcnew MainLogin();
        loginForm->ShowDialog();

        // Close the menu form
        this->Close();
    }
}

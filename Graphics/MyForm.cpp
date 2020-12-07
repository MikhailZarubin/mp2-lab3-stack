#include "MyForm.h"

#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Graphics::MyForm form;
    Application::Run(% form);
    return 0;
}
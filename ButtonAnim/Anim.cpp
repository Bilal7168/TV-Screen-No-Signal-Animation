#include "Anim.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ButtonAnim::Anim form;
	Application::Run(% form);
}

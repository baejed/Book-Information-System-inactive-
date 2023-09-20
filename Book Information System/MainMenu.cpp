#include "MainMenu.h"
#include <wx/wx.h>



MainMenu::MainMenu(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	this->SetClientSize(clientSizeX, clientSizeY);
	this->Center();
}
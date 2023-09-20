#include "DeleteBookWindow.h"
#include <wx/wx.h>

DeleteBookWindow::DeleteBookWindow(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	this->SetClientSize(clientSizeX, clientSizeY);
	this->Center();
}
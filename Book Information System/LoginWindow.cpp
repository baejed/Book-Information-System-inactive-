#include "LoginWindow.h"
#include <wx/wx.h>

LoginWindow::LoginWindow(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//button binds
	clearButton->Bind(wxEVT_BUTTON, &LoginWindow::ClearFields, this);

	//textfield binds
	usernameField->Bind(wxEVT_TEXT, &LoginWindow::UsernameInput, this);
	passwordField->Bind(wxEVT_TEXT, &LoginWindow::PasswordInput, this);

	this->SetClientSize(clientSizeX, clientSizeY);
	this->Center();
	this->CreateStatusBar();
}

void LoginWindow::ClearFields(wxCommandEvent& evt)
{
	usernameField->Destroy();
	passwordField->Destroy();

	passwordInput = "";
	usernameInput = "";

	usernameField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(190, 100), wxSize(200, -1));
	passwordField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(190, 140), wxSize(200, -1), wxTE_PASSWORD);

	usernameField->Bind(wxEVT_TEXT, &LoginWindow::UsernameInput, this);
	passwordField->Bind(wxEVT_TEXT, &LoginWindow::PasswordInput, this);
}

void LoginWindow::UsernameInput(wxCommandEvent& evt)
{
	usernameInput = wxString::Format("%s", evt.GetString());
}

void LoginWindow::PasswordInput(wxCommandEvent& evt)
{
	passwordInput = wxString::Format("%s", evt.GetString());
}
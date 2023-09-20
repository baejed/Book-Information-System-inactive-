#pragma once
#include <wx/wx.h>

class LoginWindow : public wxFrame
{
public:
	const int clientSizeX = 480;
	const int clientSizeY = 480;
	wxString usernameInput = "";
	wxString passwordInput = "";

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "BOOK INFORMATION SYSTEM", wxPoint(0, 50), wxSize(clientSizeX, -1), wxALIGN_CENTRE_HORIZONTAL);

	//controls
	wxTextCtrl* usernameField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(190, 100), wxSize(200, -1));
	wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "USERNAME:", wxPoint(120, 103));

	wxTextCtrl* passwordField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(190, 140), wxSize(200, -1), wxTE_PASSWORD);
	wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "PASSWORD:", wxPoint(120, 143));

	wxButton* loginbutton = new wxButton(panel, wxID_ANY, "LOGIN", wxPoint(190, 170));
	wxButton* clearButton = new wxButton(panel, wxID_ANY, "CANCEL", wxPoint(315, 170));

public:
	LoginWindow(const wxString& title);
	void Login(wxCommandEvent& evt);

private:
	void ClearFields(wxCommandEvent& evt);
	void UsernameInput(wxCommandEvent& evt);
	void PasswordInput(wxCommandEvent& evt);
};


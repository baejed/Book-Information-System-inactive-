#pragma once
#include <wx/wx.h>

class MainMenu : public wxFrame
{
public:
	const int clientSizeX = 400;
	const int clientSizeY = 400;

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "BOOK INFORMATION SYSTEM", wxPoint(0, 50), wxSize(clientSizeX, -1), wxALIGN_CENTRE_HORIZONTAL);

	wxButton* addUpdateBookButton = new wxButton(panel, wxID_ANY, "ADD/UPDATE\nBOOK", wxPoint(150, 100), wxSize(100, 50));
	wxButton* viewBookButton = new wxButton(panel, wxID_ANY, "VIEW BOOK", wxPoint(150, 160), wxSize(100, 50));
	wxButton* deleteBookButton = new wxButton(panel, wxID_ANY, "DELETE", wxPoint(150, 220), wxSize(100, 50));

public:
	MainMenu(const wxString& title);
};


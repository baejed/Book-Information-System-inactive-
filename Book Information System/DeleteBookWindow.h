#pragma once
#include <wx/wx.h>

class DeleteBookWindow : public wxFrame
{
public:
	const int clientSizeX = 500;
	const int clientSizeY = 320;

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "BOOK INFORMATION SYSTEM", wxPoint(0, 30), wxSize(clientSizeX, -1), wxALIGN_CENTRE_HORIZONTAL);

	//ISBN input
	wxTextCtrl* isbnInputField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(130, 70), wxSize(150, -1));
	wxStaticText* isbnLabel = new wxStaticText(panel, wxID_ANY, "ISBN: ", wxPoint(95, 73));
	wxButton* searchButton = new wxButton(panel, wxID_ANY, "SEARCH", wxPoint(285, 70));

	//book title output
	wxStaticText* bookTitleLabel = new wxStaticText(panel, wxID_ANY, "BOOK TITLE: ", wxPoint(95, 120));
	wxStaticText* bookTitleText;

	//author output
	wxStaticText* authorLabel = new wxStaticText(panel, wxID_ANY, "AUTHOR: ", wxPoint(95, 150));
	wxStaticText* authorText;

	wxButton* deleteButton = new wxButton(panel, wxID_ANY, "DELETE", wxPoint(90, 190));
	wxButton* cancelButton = new wxButton(panel, wxID_ANY, "CANCEL", wxPoint(170, 190));

public:
	DeleteBookWindow(const wxString& title);
};


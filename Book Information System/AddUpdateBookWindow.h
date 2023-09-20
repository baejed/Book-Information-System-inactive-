#pragma once
#include <wx/wx.h>

class AddUpdateBookWindow : public wxFrame
{
public:
	const int clientSizeX = 450;
	const int clientSizeY = 450;

	wxString isbnInput = "";
	wxString bookTitleInput = "";
	wxString authorInput = "";

	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "BOOK INFORMATION SYSTEM", wxPoint(0, 50), wxSize(clientSizeX, -1), wxALIGN_CENTRE_HORIZONTAL);
	
	wxTextCtrl* isbnField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(150, 100), wxSize(200, -1));
	wxTextCtrl* bookTitleField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(150, 150), wxSize(200, -1));
	wxTextCtrl* authorField = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(150, 200), wxSize(200, -1));

	wxStaticText* isbn = new wxStaticText(panel, wxID_ANY, "ISBN:", wxPoint(80, 103));
	wxStaticText* bookTitle = new wxStaticText(panel, wxID_ANY, "BOOK TITLE:", wxPoint(80, 153));
	wxStaticText* author = new wxStaticText(panel, wxID_ANY, "AUTHOR:", wxPoint(80, 203));

	wxButton* saveButton = new wxButton(panel, wxID_ANY, "SAVE", wxPoint(160, 240));
	wxButton* backButton = new wxButton(panel, wxID_ANY, "BACK", wxPoint(260, 240));

public:
	AddUpdateBookWindow(const wxString& title);

private:
	void IsbnInput(wxCommandEvent& evt);
	void BookTitleInput(wxCommandEvent& evt);
	void AuthorInput(wxCommandEvent& evt);

};
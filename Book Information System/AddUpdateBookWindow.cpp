#include "AddUpdateBookWindow.h"
#include <wx/wx.h>

AddUpdateBookWindow::AddUpdateBookWindow(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	this->SetClientSize(clientSizeX, clientSizeY);
	this->Center();

	//input field bindings
	isbnField->Bind(wxEVT_TEXT, &AddUpdateBookWindow::IsbnInput, this);
	bookTitleField->Bind(wxEVT_TEXT, &AddUpdateBookWindow::BookTitleInput, this);
	authorField->Bind(wxEVT_TEXT, &AddUpdateBookWindow::AuthorInput, this);
}

void AddUpdateBookWindow::IsbnInput(wxCommandEvent& evt)
{
	isbnInput = wxString::Format("%s", evt.GetString());;
}

void AddUpdateBookWindow::BookTitleInput(wxCommandEvent& evt)
{
	bookTitleInput = wxString::Format("%s", evt.GetString());
}

void AddUpdateBookWindow::AuthorInput(wxCommandEvent& evt)
{
	authorInput = wxString::Format("%s", evt.GetString());
}
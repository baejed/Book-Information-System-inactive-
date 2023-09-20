#include <wx/wx.h>
#include "LoginWindow.h"
#include "MainMenu.h"
#include "AddUpdateBookWindow.h"
#include "Database.h"
#include "DeleteBookWindow.h"

class App : public wxApp {

    const wxString title = "BOOK INFORMATION SYSTEM";
    sql::Connection* databaseConnection = getDatabaseConnection();

    LoginWindow* loginWindow = new LoginWindow(title);
    MainMenu* mainMenu = new MainMenu(title);
    AddUpdateBookWindow* addUpdateBookWindow = new AddUpdateBookWindow(title);
    DeleteBookWindow* deleteBookWindow = new DeleteBookWindow(title);

public:
    bool OnInit()
    {
        loginWindow->loginbutton->Bind(wxEVT_BUTTON, &App::Login, this);

        mainMenu->addUpdateBookButton->Bind(wxEVT_BUTTON, &App::OpenAddUpdateBookWindow, this);

        addUpdateBookWindow->saveButton->Bind(wxEVT_BUTTON, &App::SaveBook, this);
        addUpdateBookWindow->backButton->Bind(wxEVT_BUTTON, &App::BackButton, this);


        deleteBookWindow->Show();
        return true;
    }

    void Login(wxCommandEvent& evt)
    {
        //The input field in the window returns a wxString type
        wxString wxStringUsername = loginWindow->usernameInput;
        wxString wxStringPassword = loginWindow->passwordInput;

        //The wxString types has to be converted to a standard string
        std::string usernameInput = std::string(wxStringUsername.mb_str());
        std::string passwordInput = std::string(wxStringPassword.mb_str());

        if (CheckLoginInfo(usernameInput, passwordInput, databaseConnection))
        {
            loginWindow->Close();
            mainMenu->Show();
        }
        else
        {
            wxLogMessage("Invalid username or passsword");
        }
    }

    void SaveBook(wxCommandEvent& evt)
    {
        //The input field in the window returns a wxString type
        wxString wxStringIsbn = addUpdateBookWindow->isbnInput;
        wxString wxStringBookTitle = addUpdateBookWindow->bookTitleInput;
        wxString wxStringAuthor = addUpdateBookWindow->authorInput;

        //The wxString types has to be converted to a standard string
        std::string isbnInput = std::string(wxStringIsbn.mb_str());
        std::string bookTitleInput = std::string(wxStringBookTitle.mb_str());
        std::string authorInput = std::string(wxStringAuthor.mb_str());

        bool bookExists = BookExists(isbnInput, databaseConnection);

        AddOrUpdateBook(isbnInput, bookTitleInput, authorInput, databaseConnection);
        
        if (bookExists && HasCompleteInput(isbnInput, bookTitleInput, authorInput))
            wxLogMessage("Book Updated");
        else if(HasCompleteInput(isbnInput, bookTitleInput, authorInput))
            wxLogMessage("Book Added");
    }

    void OpenAddUpdateBookWindow(wxCommandEvent& evt)
    {
        addUpdateBookWindow->Show();
    }

    void BackButton(wxCommandEvent& evt)
    {
        addUpdateBookWindow->Hide();
        mainMenu->Show();
    }
};

wxIMPLEMENT_APP(App);
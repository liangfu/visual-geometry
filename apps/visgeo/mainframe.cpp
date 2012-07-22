
#include "common.h"
#include "mainframe.h"


MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame( NULL, -1, title, pos, size )
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( wxID_ANY, _("&Open\tCtrl-O") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_QUIT, _("&Exit\tCtrl-Q") );

    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append( wxID_ANY, _("&Undo\tCtrl-Z") );

    wxMenu *menuAbout = new wxMenu;
    menuAbout->Append( ID_ABOUT, _("&About...") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );
    menuBar->Append( menuEdit, _("&Edit") );
    menuBar->Append( menuAbout, _("&About") );

    SetMenuBar( menuBar );

    CreateStatusBar(1);
    SetStatusText( _("Welcome to "APPLICATION_TITLE"!"));

	Connect(ID_QUIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));
	Connect(ID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnAbout));
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("This is a wxWidgets Hello world sample"),
                  _("About "APPLICATION_TITLE),
                  wxOK | wxICON_INFORMATION, this);
}
